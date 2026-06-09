#include "SalaEscolha.hpp"

SalaEscolha::SalaEscolha(std::string nome, std::string historia) 
    : SalaBase(nome), _historia(historia) {}

std::string SalaEscolha::getNome() const {
    return this->_nome;
}
void SalaEscolha::mostrarSala(){
    std::cout << "\n========================================" << std::endl;
    std::cout << "          " << this->_nome << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << _historia << std::endl;
}

int SalaEscolha::executarSala(Personagem* Personagem){
    std::cout <<"Sala de Escolhas" << std::endl;
    return 3; //proxima sala exemplo 3 sala de combate
}

void SalaEscolha::mostrarOpcoes(){
}

void SalaEscolha::executarEvento(){
}

void SalaEscolha::encerrarSala(){
}
