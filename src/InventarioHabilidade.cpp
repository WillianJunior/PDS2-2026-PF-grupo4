#include "InventarioHabilidade.hpp"

void InventarioHabilidade::mostrarInventario(){
    for (long unsigned int i = 0; i < listaHabilidades.size(); i++)
    {
        Utils::coutDigitado(15) << std::to_string(i+1) << ". "<< listaHabilidades[i].getNome() << "\n";
    }
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

Habilidade InventarioHabilidade::getHabilidade(int posicao){
    return listaHabilidades[posicao];
}

bool InventarioHabilidade::operator==(const InventarioHabilidade& outro) const{
    return (this->listaHabilidades == outro.listaHabilidades);
}

bool InventarioHabilidade::operator!=(const InventarioHabilidade& outro) const{
    return (this->listaHabilidades != outro.listaHabilidades);
}