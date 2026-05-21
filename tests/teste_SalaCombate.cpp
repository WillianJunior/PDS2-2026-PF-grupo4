#include "doctest.h"
#include "SalaCombate.hpp"

TEST_CASE("Teste 01: Teste de construção da sala combate"){
    SalaCombate SalaTeste("SalaCombate");

    CHECK(SalaTeste.getNome() == "SalaCombate");
}

TEST_CASE("Teste 02: Teste de encerramento da sala"){
    SalaCombate SalaTeste("Sala Combate");
    SalaTeste.encerrarSala();
}

TEST_CASE("Teste 03: Prosseguir para a próxima sala"){
    SalaCombate SalaTeste("Sala Combate");
    SalaTeste.proximaSala();
}

TEST_CASE("Teste 03: Teste para imprimir a sala na tela"){
    SalaCombate SalaTeste("Sala Combate");
    SalaTeste.mostrarSala();
}

TEST_CASE("Teste 03: Teste do gerenciamento dos turnos do jogador e inimigo"){
    SalaCombate SalaTeste("Sala Combate");
    SalaTeste.controleDeTurnos();
}

TEST_CASE("Teste 03: Teste de instanciação de inimigos"){
    SalaCombate SalaTeste("Sala Combate");
    SalaTeste.alocarInimigo();
}

