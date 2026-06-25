#include "doctest.h"
#include "Item.hpp"
#include "Efeito.hpp"
#include <string>
#include <sstream>
// nome alvo valor efeito

TEST_CASE("Teste 01: Testando construcao de item e getters"){
    std::string nomeTeste = "Farinha de mandioca";
    bool alvoTeste = true;
    bool tipoTeste = true;
    int valorTeste = 50;
    Efeito efeitoTeste = Efeito("Envenenado", 10, 3);
    Item itemTeste(nomeTeste, tipoTeste, valorTeste, efeitoTeste, alvoTeste, 1);

    CHECK(itemTeste.getNome() == nomeTeste);
    CHECK(itemTeste.getValor() == valorTeste);
    CHECK(itemTeste.getEfeito() == efeitoTeste);
    CHECK(itemTeste.getAlvo() == alvoTeste);
    CHECK(itemTeste.getTipo() == tipoTeste);
}

TEST_CASE("Teste 02: Testando a funcao calcularImpacto em Item"){
    Item itemTeste("Pocao", true, 10, Efeito("Regeneracao", 10, 2), true, 1);
    int teste_impacto = itemTeste.calcularImpacto();
    
    //Como o _tipo do item eh true, ou seja cura (podemos mudar isso dps), a logica tem que retornar positivo
    CHECK(teste_impacto == 10);
}

TEST_CASE("Teste 03: Testando a funcao mostrarDescricao em Item"){
    Item itemTeste("Pocao", true, 10, Efeito("Regeneracao", 10, 2), true, 1);
    
    itemTeste.mostrarDescricao();
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
    std::istringstream inputSimulado("\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(inputSimulado.rdbuf());

    itemTeste.mostrarDescricao(); 

    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);
}
