#include "InventarioHabilidade.hpp"
#include "Excecoes.hpp"

void InventarioHabilidade::mostrarInventario(){
    int larguraInterna = 60;

    std::cout << "    ╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "    ║                      SUAS HABILIDADES                      ║\n";
    std::cout << "    ╠════════════════════════════════════════════════════════════╣\n";

    for (long unsigned int i = 0; i < listaHabilidades.size(); i++) {
        std::string textoNome = listaHabilidades[i].getNome();

        //aviso se estiver em Cooldown
        if(listaHabilidades[i].getCooldownAtual() > 0){
            textoNome += " [Em cooldown: " + std::to_string(listaHabilidades[i].getCooldownAtual()) + "]";
        }

        std::string linha = " [ " + std::to_string(i + 1) + " ] - " + textoNome + " ";
        int espacosFaltando = larguraInterna - linha.length() - 1;
        if (espacosFaltando < 0) {
            linha = linha.substr(0, larguraInterna - 4) + "... ";
            espacosFaltando = 0;
        }
        std::string padding(espacosFaltando, '.');
        Utils::coutDigitado(0) << "    ║" << linha << padding << " ║\n";

        //descriçao da habilidade
        std::string descricaoHab = "       > " + listaHabilidades[i].mostrarDescricao() + " ";
        int espacosFaltandoDescricao = larguraInterna - descricaoHab.length() - 1;

        if (espacosFaltandoDescricao < 0) {
            descricaoHab = descricaoHab.substr(0, larguraInterna - 4) + "... ";
            espacosFaltandoDescricao = 0;
        }

        std::string paddingDesc(espacosFaltandoDescricao, ' ');
        Utils::coutDigitado(0) << "    ║" << descricaoHab << paddingDesc << " ║\n";

        //separar as habilidades por uma linha em branco
        if (i < listaHabilidades.size() - 1) {
            std::string linhaVazia(larguraInterna - 1, ' ');
            Utils::coutDigitado(0) << "    ║ " << linhaVazia << "║\n";
        }
    }
    std::cout << "    ╚═════════════════════════════════════╝\n";
}

void InventarioHabilidade::novaAcao(Habilidade habilidade){
    this->listaHabilidades.push_back(habilidade);
}

void InventarioHabilidade::trocarAcao(int posicao, Habilidade novaHabilidade){
    listaHabilidades[posicao] = novaHabilidade;
}

void InventarioHabilidade::descartarAcao(int posicao){
    listaHabilidades.erase(listaHabilidades.begin() + posicao);
}

int InventarioHabilidade::getTamanho(){
    return listaHabilidades.size();
}

Habilidade& InventarioHabilidade::getHabilidade(int posicao){
    if (posicao < 0 || posicao >= (int)listaHabilidades.size()) {
        throw IndiceInvalidoException();
    }
    return listaHabilidades[posicao];
}

void InventarioHabilidade::atualizarCooldowns(){
    for(size_t i = 0; i < listaHabilidades.size(); i++){
        listaHabilidades[i].atualizarCooldown();
    }
}

bool InventarioHabilidade::operator==(const InventarioHabilidade& outro) const{
    return (this->listaHabilidades == outro.listaHabilidades);
}

bool InventarioHabilidade::operator!=(const InventarioHabilidade& outro) const{
    return (this->listaHabilidades != outro.listaHabilidades);
}