#include "doctest.h"
#include "Personagem.hpp"

TEST_CASE("Teste 01: Inicialização da classe Personagem"){
    Personagem vaz(10, InventarioHabilidade(), "Vaz", InventarioItem());

    CHECK(vaz.getVida() == 10);
    CHECK(vaz.getInventarioHabilidade() == InventarioHabilidade());
    CHECK(vaz.getNome() == "Vaz");
    CHECK(vaz.getInventarioItem() == InventarioItem());
}

TEST_CASE("Teste 02: Escolha de Habilidade dentro do inventario"){
    InventarioHabilidade inventarioHabilidade;
    Efeito efeitoTeste("EfeitoTeste", 10, 10);
    Habilidade habilidadeTeste1("HabilidadeTeste1", 1, 10, 1, efeitoTeste, 0);
    Habilidade habilidadeTeste2("HabilidadeTeste2", 1, 20, 1, efeitoTeste, 0);
    inventarioHabilidade.novaAcao(habilidadeTeste1);
    inventarioHabilidade.novaAcao(habilidadeTeste2);
    Personagem isaque(20, inventarioHabilidade, "Vaz", InventarioItem());

    CHECK(isaque.escolherHabilidade(1).getValor() == 20);
}

TEST_CASE("Teste 03: Escolha de Item dentro do inventario"){
    InventarioItem inventarioItem;
    Efeito efeitoTeste("EfeitoTeste", 10, 10);
    Item itemTeste1("ItemTeste1", 1, 10, efeitoTeste, 1);
    Item itemTeste2("ItemTeste2", 1, 20, efeitoTeste, 1);
    inventarioItem.novaAcao(itemTeste1);
    inventarioItem.novaAcao(itemTeste2);
    Personagem nicole(20, InventarioHabilidade(), "Vaz", inventarioItem);

    CHECK(nicole.escolherItem(1).getValor() == 20);
}

TEST_CASE("Teste 04: Alterar a vida"){
    Personagem maycon(20, InventarioHabilidade(), "Vaz", InventarioItem());
    maycon.alterarVida(-10);
    maycon.alterarVida(5);

    CHECK(maycon.getVida() == 15);
}

TEST_CASE("Teste 05: Testar limite de vida maxima"){
    Personagem personagemTeste(20, InventarioHabilidade(), "Vaz", InventarioItem());
    personagemTeste.alterarVida(-10);
    personagemTeste.alterarVida(20);

    CHECK(personagemTeste.getVida() == 20);
}

TEST_CASE("Teste 06: Conferir se está morto"){
    Personagem marcos(20, InventarioHabilidade(), "Vaz", InventarioItem());
    marcos.alterarVida(-20);

    CHECK(marcos.isMorto() == true);
}