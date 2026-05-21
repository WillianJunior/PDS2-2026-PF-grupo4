#include "InventarioHabilidade.hpp"

void InventarioHabilidade::mostrarInventario(){
    for (auto i = 0; i < listaHabilidades.size(); i++)
    {
        std::cout << std::to_string(i+1) << ". "<< listaHabilidades[i].getNome() << std::endl;
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