#include "InventarioItem.hpp"
#include "Excecoes.hpp"

void InventarioItem::mostrarInventario(){
    int larguraInterna = 60;

    std::cout << "    ╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "    ║                         SEUS ITENS                         ║\n";
    std::cout << "    ╠════════════════════════════════════════════════════════════╣\n";

    for (long unsigned int i = 0; i < _itens.size(); i++) {
        std::string textoNome = _itens[i].getNome();

        std::string linha = " [ " + std::to_string(i + 1) + " ] - " + textoNome + " ";
        int espacosFaltando = larguraInterna - linha.length() - 1;
        if (espacosFaltando < 0) {
            linha = linha.substr(0, larguraInterna - 4) + "... ";
            espacosFaltando = 0;
        }
        std::string padding(espacosFaltando, '.');
        Utils::coutDigitado(0) << "    ║" << linha << padding << " ║\n";

        // Descrição do item
        std::string descricaoIt = "       > " + _itens[i].mostrarDescricao() + " ";
        int espacosFaltandoDescricao = larguraInterna - descricaoIt.length() - 1;

        if (espacosFaltandoDescricao < 0) {
            descricaoIt = descricaoIt.substr(0, larguraInterna - 4) + "... ";
            espacosFaltandoDescricao = 0;
        }

        std::string paddingDesc(espacosFaltandoDescricao, ' ');
        Utils::coutDigitado(0) << "    ║" << descricaoIt << paddingDesc << " ║\n";

        // Separar os itens por uma linha em branco
        if (i < _itens.size() - 1) {
            std::string linhaVazia(larguraInterna - 1, ' ');
            Utils::coutDigitado(0) << "    ║ " << linhaVazia << "║\n";
        }
    }
    std::cout << "    ╚════════════════════════════════════════════════════════════╝\n";
}


void InventarioItem::novaAcao(Item item){
    this->_itens.push_back(item);
}

void InventarioItem::trocarAcao(int posicao, Item novoItem){
    _itens[posicao] = novoItem;
}

void InventarioItem::descartarAcao(int posicao){
    _itens.erase(_itens.begin() + posicao);
}

int InventarioItem::getTamanho(){
    return _itens.size();
}

Item InventarioItem::getItem(int posicao){
    if (posicao < 0 || posicao >= (int)_itens.size()){
        throw IndiceInvalidoException();
    }
    return _itens[posicao];
}

bool InventarioItem::operator==(const InventarioItem& outro) const{
    return (this->_itens == outro._itens);
}

bool InventarioItem::operator!=(const InventarioItem& outro) const{
    return (this->_itens != outro._itens);
}