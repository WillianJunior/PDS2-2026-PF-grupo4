#include "InventarioHabilidade.hpp"

void InventarioHabilidade::mostrarInventario(){
}

void InventarioHabilidade::novaAcao(Habilidade habilidade){
}

void InventarioHabilidade::trocarAcao(int posicao, Habilidade novaHabilidade){
}

void InventarioHabilidade::descartarAcao(int posicao){
}

int InventarioHabilidade::getTamanho(){
    return listaHabilidades.size();
}

Habilidade InventarioHabilidade::getHabilidade(int posicao){
    return listaHabilidades[posicao];
}

bool InventarioHabilidade::operator==(const InventarioHabilidade& outro) const{
    return true; 
}