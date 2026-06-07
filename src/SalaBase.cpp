#include "SalaBase.hpp"

SalaBase::SalaBase(std::string nome)
    : _nome(nome){}

std::string SalaBase::getNome(){
    return this->_nome;
}

SalaBase::~SalaBase(){
    
}