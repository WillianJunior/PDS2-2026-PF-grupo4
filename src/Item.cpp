#include "Item.hpp"

Item::Item(std::string nome, bool tipo, int valor, Efeito efeito, bool alvo)
    : Acao(nome, tipo, valor, efeito, alvo){}

Item::~Item() {
}