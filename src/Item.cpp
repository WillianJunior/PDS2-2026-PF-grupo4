#include "Item.hpp"

Item::Item(std::string nome, bool alvo, bool tipo, int valor, Efeito efeito)
    : Acao(nome, true, valor, efeito, alvo){}

Item::~Item() {
}