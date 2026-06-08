#include "Efeito.hpp"

Efeito::Efeito(std::string nome, int valor, int duracao)
    : _nome(nome), _valor(valor), _duracao(duracao){}

void Efeito::mostrarEfeito(){
    if(!this->isEncerrado()){
        std::cout << "O alvo está " << this->_nome << " (" << this->_valor << " de impacto por turno)\n";
    }
}

void Efeito::atualizarDuracao(){
    if(this->_duracao > 0){
        this->_duracao--;
    }
}

bool Efeito::isEncerrado(){
    return this->_duracao <= 0;
}

std::string Efeito::getNome(){
    return this->_nome;
}

int Efeito::getValor(){
    return this->_valor;
}

int Efeito::getDuracao(){
    return this->_duracao;
}

bool Efeito::operator==(const Efeito& outro) const{
    return (this->_nome == outro._nome && 
            this->_valor == outro._valor && 
            this->_duracao == outro._duracao);
}

Efeito::~Efeito(){}