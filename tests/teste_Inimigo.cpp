#include "doctest.h"
#include "Inimigo.hpp"

TEST_CASE("Teste 01: Inicialização da classe Inimigo"){
    Inimigo inimigo_teste(100, InventarioHabilidade(), "teste");

    CHECK(inimigo_teste.getVida() == 100);
    CHECK(inimigo_teste.getInventarioHabilidade() == InventarioHabilidade());
    CHECK(inimigo_teste.getNome() == "teste");
}

TEST_CASE("Teste 02: Escolha de Habilidade"){
    InventarioHabilidade inventarioHabilidade;
    Efeito efeitoTeste("EfeitoTeste", 10, 10);
    Habilidade habilidadeTeste1("HabilidadeTeste1", 1, 10, 1, efeitoTeste, 0);
    Habilidade habilidadeTeste2("HabilidadeTeste2", 1, 20, 1, efeitoTeste, 0);
    inventarioHabilidade.novaAcao(habilidadeTeste1);
    inventarioHabilidade.novaAcao(habilidadeTeste2);
    Inimigo inimigo_teste(20, inventarioHabilidade, "Vaz");

    CHECK(inimigo_teste.escolherHabilidade(1).getValor() == 20);
}

TEST_CASE("Teste 03: Alterar a vida"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz");
    inimigo_teste.alterarVida(-10);
    inimigo_teste.alterarVida(5);

    CHECK(inimigo_teste.getVida() == 15);
}

TEST_CASE("Teste 04: Testar limite de vida maxima"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz");
    inimigo_teste.alterarVida(-10);
    inimigo_teste.alterarVida(20);

    CHECK(inimigo_teste.getVida() == 20);
}

TEST_CASE("Teste 05: Conferir se está morto"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz");
    inimigo_teste.alterarVida(-20);
    
    CHECK(inimigo_teste.isMorto() == true);
}