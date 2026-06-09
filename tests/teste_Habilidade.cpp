#include "doctest.h"
#include "Habilidade.hpp"
#include <sstream>

TEST_CASE("Teste 01: Testando a inicializacao e atributos de Habilidade"){
    Habilidade habilidade_teste("habilidade_teste", false, 30, false, Efeito("Sem_efeito", 0, 0));
    
    CHECK(habilidade_teste.getNome() == "habilidade_teste");
    CHECK(habilidade_teste.getTipo() == false);
    CHECK(habilidade_teste.getValor() == 30);
    CHECK(habilidade_teste.getAlvo() == false);
}

TEST_CASE("Teste 02: Testando a funcao calcularImpacto em Habilidade"){
    Habilidade habilidade_teste("Bola de Fogo", false, 50, true, Efeito("Queimadura", 5, 2));
    int teste_impacto = habilidade_teste.calcularImpacto(); 
    
    //Como o _tipo da habilidade eh false, ou seja, dano (podemos mudar isso), a logica tem que retornar o valor negativo
    CHECK(teste_impacto == -50); 
}

TEST_CASE("Teste 03: Testando a funcao mostrarDescricao em Habilidade (Cobertura)"){
    Habilidade habilidade_teste("Bola de Fogo", false, 50, true, Efeito("Queimadura", 5, 2));
    
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
    std::istringstream inputSimulado("\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(inputSimulado.rdbuf());
    habilidade_teste.mostrarDescricao(); 
    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);
}