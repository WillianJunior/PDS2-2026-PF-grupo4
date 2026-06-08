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
    InventarioHabilidade inventarioHabilidade;
    Efeito efeitoTeste("EfeitoTeste", 10, 10);
    Habilidade habilidadeTeste1("HabilidadeTeste1", 1, 10, 1, efeitoTeste);
    Habilidade habilidadeTeste2("HabilidadeTeste2", 1, 20, 1, efeitoTeste);
    inventarioHabilidade.novaAcao(habilidadeTeste1);
    inventarioHabilidade.novaAcao(habilidadeTeste2);
    Inimigo inimigo_teste(20, inventarioHabilidade, "Vaz", false);

    CHECK(inimigo_teste.escolherHabilidade(1) == 20);
}

TEST_CASE("Teste 3: alterar a vida"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz", false);
    inimigo_teste.alterarVida(-10);
    inimigo_teste.alterarVida(5);

    CHECK(inimigo_teste.getVida() == 15);
}

TEST_CASE("Teste 4: testar limite de vida maxima"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz", false);
    inimigo_teste.alterarVida(-10);
    inimigo_teste.alterarVida(20);

    CHECK(inimigo_teste.getVida() == 20);
}

TEST_CASE("Teste 5: conferir se está morto"){
    Inimigo inimigo_teste(20, InventarioHabilidade(), "Vaz", false);
    inimigo_teste.alterarVida(-20);
    
    CHECK(inimigo_teste.isMorto() == true);
}