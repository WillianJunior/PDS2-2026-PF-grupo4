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

TEST_CASE("SALAESCOLHA - executarSala") {
    SalaEscolha sala("Sala de Escolha", "Evento aleatório.");
    Personagem heroi = criarPersonagemParaEscolha();

    // Redirecionamento para ocultar o cout do terminal durante os testes
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());

    // TESTE da execução passando o ponteiro do personagem sem chamar proximaSala
    int resultado = sala.executarSala(&heroi);

    std::cout.rdbuf(coutAntigo);

    // verifica se a sala retornou um ID de rota válido (maior que 0)
    CHECK(resultado > 0); 
}