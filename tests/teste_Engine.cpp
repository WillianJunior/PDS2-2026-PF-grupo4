#include "doctest.h"
#include "Engine.hpp"
#include "Utils.hpp"
#include <sstream>
#include <iostream>

TEST_CASE("ENGINE - Teste 01: Verifica encerramento via Menu") {
    // Ativa as flags estáticas para garantir comportamento determinístico e sem delays
    Engine::modoTeste = true; 
    Utils::modoTeste = true;

    Engine jogo;

    // entrada do usuario
    std::stringstream simulacaoEntrada("2\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());

    // redirecionamento do buffer
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());

    jogo.iniciar();
    
    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);

    std::string saida = bufferSaida.str();
    
    CHECK(saida.find("1 - New Game") != std::string::npos);
    CHECK(saida.find("2 - Out") != std::string::npos);
    
    CHECK(saida.find("Encerrando o sistema. Até a próxima compilação!") != std::string::npos);
}