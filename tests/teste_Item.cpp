#include "doctest.h"
#include "Item.hpp"
#include "Efeito.hpp"
#include <string>
// nome alvo valor efeito

TEST_CASE("Teste 01: Testando construcao de item e getters"){
    std::string nomeTeste = "Farinha de mandioca";
    bool alvoTeste = true;
    bool tipoTeste = true;
    int valorTeste = 50;
    Efeito efeitoTeste = Efeito("Envenenado", 10, 3);
    Item itemTeste(nomeTeste, tipoTeste, valorTeste, efeitoTeste, alvoTeste);

    CHECK(itemTeste.getNome() == nomeTeste);
    CHECK(itemTeste.getValor() == valorTeste);
    CHECK(itemTeste.getEfeito() == efeitoTeste);
    CHECK(itemTeste.getAlvo() == alvoTeste);
    CHECK(itemTeste.getTipo() == tipoTeste);
}

TEST_CASE("Teste 02: Testando a funcao calcularImpacto em Item"){
    Item itemTeste("Pocao", true, 10, Efeito("Regeneracao", 10, 2), true);
    int teste_impacto = itemTeste.calcularImpacto();
    
    //Como o _tipo do item eh true, ou seja cura (podemos mudar isso dps), a logica tem que retornar positivo
    CHECK(teste_impacto == 10);
}

TEST_CASE("Teste 03: Testando a funcao mostrarDescricao em Item"){
    Item itemTeste("Pocao", true, 10, Efeito("Regeneracao", 10, 2), true);
    
    itemTeste.mostrarDescricao();
    // NAO POSSUI TESTE, FUNCAO VOID QUE IMPRIME E EXECUTA ACOES SEM RETORNO.
}