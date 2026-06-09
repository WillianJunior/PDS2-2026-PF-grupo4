#include "doctest.h"
#include "SalaEscolha.hpp"
#include <sstream>
#include <iostream>

Personagem criarPersonagemParaEscolha() {
    InventarioHabilidade invHab;
    InventarioItem invItem;
    return Personagem(100, invHab, "Estudante Tester", invItem);
}

TEST_CASE("SALAESCOLHA - Inicializacao e Getters") {
    SalaEscolha sala("TROCA DE ITENS", "ESCOLHA ENTRE TIPOS DE CAFÉ");
    
    CHECK(sala.getNome() == "TROCA DE ITENS");
}

TEST_CASE("SALAESCOLHA - executarSala com input simulado") {
    SalaEscolha sala("Sala de Escolha", "Evento aleatorio.");
    Personagem personagem = criarPersonagemParaEscolha();
    bool consequencia = false; 
    // [&consequencia] é a variável que está sendo capturada para ser alterada dentro da função consequencia, recebendo
    // o parametro personagem* p para executar a ação
    sala.adicionarOpcao("Beber Cafe", [&consequencia](Personagem* p) {
        consequencia = true; 
    });
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
    std::istringstream inputSimulado("1\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(inputSimulado.rdbuf());
    int resultado = sala.executarSala(&personagem);
    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);

    CHECK(resultado == 3); // proxima sala
    CHECK(consequencia == true); // checa se eventos estão sendo confirmados no personagem
}

TEST_CASE("SALAESCOLHA - USUARIO BURRO DIGITOU ERRADO") {
    SalaEscolha sala("Teste Falha", "Texto");
    Personagem personagem = criarPersonagemParaEscolha();
    sala.adicionarOpcao("Unica Opcao", [](Personagem* p) {});
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
    std::istringstream inputSimulado("9\n1\n"); // --> testando o usuario digitando errado (nao tem 9 op) e depois certo
    std::streambuf* cinAntigo = std::cin.rdbuf(inputSimulado.rdbuf());

    int resultado = sala.executarSala(&personagem);

    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);
    CHECK(resultado == 3); 
}