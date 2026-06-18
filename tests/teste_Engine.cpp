#include "doctest.h"
#include "Engine.hpp"
#include <sstream>
#include <iostream>

TEST_CASE("ENGINE - Teste 01: Verifica encerramento via Menu") {
    Engine jogo;

    std::stringstream simulacaoEntrada("2\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());

    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());

    jogo.iniciar();
    
    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);

    std::string saida = bufferSaida.str();
    
    CHECK(saida.find("1 - New Game") != std::string::npos);
    CHECK(saida.find("2 - OUT") != std::string::npos);
    CHECK(saida.find("Inicialização abortada. Encerrando o sistema.") != std::string::npos);
}