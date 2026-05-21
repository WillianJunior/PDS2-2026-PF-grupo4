#include "SalaEscolha.hpp"

SalaEscolha::SalaEscolha(std::string nome)
    : SalaBase(nome), _nome(nome) {}

std::string SalaEscolha::getNome() const {
    return this->_nome;
}

void SalaEscolha::encerrarSala(){
}

void SalaEscolha::proximaSala(){
}

void SalaEscolha::mostrarSala(){
}

void SalaEscolha::mostrarOpcoes(){
}

void SalaEscolha::executarEvento(){
}