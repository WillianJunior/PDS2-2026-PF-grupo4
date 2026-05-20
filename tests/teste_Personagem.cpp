#include "doctest.h"
#include "Personagem.hpp"

TEST_CASE("Teste 1: inicialização da classe Personagem"){
    Personagem vaz(10, InventarioHabilidade(), "Vaz", InventarioItem());

    CHECK(vaz.getVida() == 10);
    CHECK(vaz.getInventarioHabilidade() == InventarioHabilidade());
    CHECK(vaz.getNome() == "Vaz");
    CHECK(vaz.getInventarioItem() == InventarioItem());
}

TEST_CASE("Teste 2: escolha de Habilidade dentro do inventario"){
    Personagem isaque(20, InventarioHabilidade(), "Vaz", InventarioItem());
    isaque.escolherHabilidade(2);
    //forçando o erro do teste, já q não possui implementação ainda
    CHECK(isaque.escolherHabilidade(2) == 30);
}

TEST_CASE("Teste 3: escolha de Item dentro do inventario"){
    Personagem nicole(20, InventarioHabilidade(), "Vaz", InventarioItem());
    nicole.escolherItem(2);

    //Nao possui CHECK, apenas para cobertura do código
}

TEST_CASE("Teste 4: alterar a vida"){
    Personagem maycon(20, InventarioHabilidade(), "Vaz", InventarioItem());
    maycon.alterarVida(-20);

    //Nao possui CHECK, apenas para cobertura do código
}

TEST_CASE("Teste 5: conferir se está morto"){
    Personagem marcos(20, InventarioHabilidade(), "Vaz", InventarioItem());
    marcos.isMorto();
    //forçando o erro do teste, já q não possui implementação ainda
    CHECK(marcos.isMorto() == true);
}