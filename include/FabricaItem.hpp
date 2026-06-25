#ifndef FABRICAITEM_HPP
#define FABRICAITEM_HPP
#include <string>
#include <memory>
#include "Item.hpp"

namespace FabricaItem{
    /**
     * @brief Cria o item que realmente será utilizado no jogo baseado no txt dos itens
     * @param nomeDoItem O nome do item que deve ser criado
     */
    Item criarItem(std::string nomeDoItem);
}
#endif