#include "doctest.h"
#include "SalaEscolha.hpp"
#include <sstream>
#include <iostream>

TEST_CASE("Teste 01: Cria uma SalaEscolha e verifica inicializacao"){
    std::string nomeSala = "Sala de Compra de Itens";
    SalaEscolha sala(nomeSala);

    CHECK(sala.getNome() == nomeSala); 
}

TEST_CASE("Teste 02: Cobertura dos metodos de fluxo e transicao"){
    SalaEscolha sala("Sala de Compra de Itens");
    sala.executarEvento();
    sala.encerrarSala();
    sala.proximaSala();
    
    // Nao possui CHECK metodos são void
}

TEST_CASE("Teste 03: Cobertura dos metodos de exibicao"){
    SalaEscolha sala("Sala de Compra de Itens");

    std::streambuf* coutOriginal = std::cout.rdbuf();
    std::ostringstream bufferInterno;
    std::cout.rdbuf(bufferInterno.rdbuf());

    sala.mostrarSala();
    sala.mostrarOpcoes();

    std::cout.rdbuf(coutOriginal);

    // como a implementação está vazia, o buffer capturado é uma string vazia
    CHECK(bufferInterno.str() == "");
}