#include "doctest.h"
#include "Efeito.hpp"
#include <sstream>

TEST_CASE("Teste 01: Cria um efeito"){
    std::string nomeTeste = "Veneno";
    int valorTeste = 10;
    int duracaoTeste = 5;

    Efeito efeito(nomeTeste, valorTeste, duracaoTeste);

    CHECK(efeito.getNome() == "Veneno");
    CHECK(efeito.getValor() == 10);
    CHECK(efeito.getDuracao() == 5);
}

TEST_CASE("Teste 02: Verifica alteracao da duracao"){
    Efeito efeito("Veneno", 10, 5);
    efeito.atualizarDuracao();

    CHECK(efeito.getDuracao() == 4);
    CHECK(efeito.isEncerrado() == false);
}

TEST_CASE("Teste 03: Verifica se foi encerrado"){
    Efeito efeito("Veneno", 10, 1);
    efeito.atualizarDuracao();

    CHECK(efeito.isEncerrado() == true);
}

TEST_CASE("Teste 04: Cobertura da funcao mostrarEfeito"){
    Efeito efeito("Veneno", 10, 1);
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
    std::istringstream inputSimulado("\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(inputSimulado.rdbuf());

    efeito.mostrarEfeito();

    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);

    //Nao possui CHECK, apenas para cobertura do código
}