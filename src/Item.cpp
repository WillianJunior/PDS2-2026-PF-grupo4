#include "Item.hpp"

Item::Item(std::string nome, bool alvo, int valor, Efeito efeito)
    : Acao(nome, true, valor, efeito, alvo){}

Item::~Item() {
}