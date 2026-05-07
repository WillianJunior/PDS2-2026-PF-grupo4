#ifndef ITEM_H
#define ITEM_H

#include "Acao.hpp"

class Item : public Acao {
    public:
        Item(std::string nome, bool alvo, int valor, Efeito efeito);
        ~Item();
};

#endif