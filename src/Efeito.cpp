#include "Efeito.hpp"

Efeito::Efeito(std::string nome, int valor, int duracao)
    : _nome(nome), _valor(valor), _duracao(duracao){}

void Efeito::mostrarEfeito(){
    if(!this->isEncerrado()){
        //confere se eh dano ou cura pelo sinal do valor, nao tem calculo de impacto aqui
        std::string tipoEfeito = (this->_valor < 0)? "de dano" : "de cura";
        Utils::coutDigitado() << "O alvo está com " << this->_nome << " (" << std::abs(this->_valor) << " " << tipoEfeito << " por turno)\n";
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

Efeito Efeito::criarEfeito(std::string nomeEfeito){
    if (nomeEfeito == "Veneno") {
            return Efeito("Veneno", -5, 4);
        }
        else if(nomeEfeito == "Queimadura"){
            return Efeito("Queimadura", -15, 2);
        }
        else if (nomeEfeito == "Regeneracao"){
            return Efeito("Regeneracao", 10, 3);
        }
        return Efeito("Nenhum", 0, 0);
}

Efeito::~Efeito(){}