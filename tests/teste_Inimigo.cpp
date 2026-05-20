#include "doctest.h"
#include "Inimigo.hpp"

TEST_CASE("Teste 1: inicialização da classe Inimigo"){
    Inimigo inimigo_teste(100, InventarioHabilidade(), "teste", false);

    CHECK(inimigo_teste.getVida() == 100);
    CHECK(inimigo_teste.getInventarioHabilidade() == InventarioHabilidade());
    CHECK(inimigo_teste.getNome() == "teste");
    CHECK(inimigo_teste.getTipo() == false);
}

TEST_CASE("Teste 2: escolha de Habilidade"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz", false);
    inimigo_teste.escolherHabilidade(2);
    //forçando o erro do teste, já q não possui implementação ainda
    CHECK(inimigo_teste.escolherHabilidade(2) == 40);
}

TEST_CASE("Teste 3: alterar a vida"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz", false);
    inimigo_teste.alterarVida(35);

    //Nao possui CHECK, apenas para cobertura do código
}

TEST_CASE("Teste 4: conferir se está morto"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz", false);
    inimigo_teste.isMorto();
    //forçando o erro do teste, já q não possui implementação ainda
    CHECK(inimigo_teste.isMorto() == true);
}