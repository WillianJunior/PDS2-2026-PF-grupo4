#include "Habilidade.hpp"

Habilidade::Habilidade(std::string nome, bool tipo, int valor, bool alvo, Efeito efeito)
    : Acao(nome, tipo, valor, efeito, alvo){}

Habilidade::~Habilidade(){
}