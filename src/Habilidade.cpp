#include "Habilidade.hpp"

Habilidade::Habilidade(std::string nome, bool tipo, int valor, bool alvo, Efeito efeito, int cooldown)
    : Acao(nome, tipo, valor, efeito, alvo), _cooldown(cooldown), _cooldownAtual(0){}

bool Habilidade::operator==(const Habilidade& outro) const{

return (this->_nome == outro._nome && 
            this->_tipo == outro._tipo && 
            this->_valor == outro._valor && 
            this->_alvo == outro._alvo && 
            this->_efeito == outro._efeito &&
            this->_cooldown == outro._cooldown);
            
}

int Habilidade::getCooldown(){
    return this->_cooldown;
}

int Habilidade::getCooldownAtual(){
    return this->_cooldownAtual;
}

void Habilidade::iniciarCooldown(){
    this->_cooldownAtual = this->_cooldown;
}

void Habilidade::atualizarCooldown(){
    if(this->_cooldownAtual > 0){
        this->_cooldownAtual -= 1;
    }
}

Habilidade::~Habilidade(){
}