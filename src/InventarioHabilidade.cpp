#include "InventarioHabilidade.hpp"
#include "Excecoes.hpp"

void InventarioHabilidade::mostrarInventario(){
    int larguraInterna = 37;

    std::cout << "    ╔═════════════════════════════════════╗\n";
    std::cout << "    ║           SUAS HABILIDADES          ║\n";
    std::cout << "    ╠═════════════════════════════════════╣\n";

    for (long unsigned int i = 0; i < listaHabilidades.size(); i++) {
        std::string linha = " [ " + std::to_string(i + 1) + " ] - " + listaHabilidades[i].getNome() + " ";
        int espacosFaltando = larguraInterna - linha.length() - 1;
        if (espacosFaltando < 0) {
            linha = linha.substr(0, larguraInterna - 4) + "... ";
            espacosFaltando = 0;
        }
        std::string padding(espacosFaltando, '.');
        Utils::coutDigitado(0) << "    ║" << linha << padding << " ║\n";
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