#include "doctest.h"
#include "SalaCombate.hpp"
#include "Personagem.hpp"
#include "Habilidade.hpp"
#include "Efeito.hpp"
#include <sstream>
#include <iostream>

// --- FUNÇÃO AUXILIAR (FIXTURE) ---
// Prepara um personagem genérico para ser injetado nos testes da sala
Personagem criarPersonagemParaTeste(int vidaInicial, int poderDeAtaque) {
    InventarioHabilidade invHab;
    Efeito semEfeito("Nenhum", 0, 0);
    
    // Adiciona uma habilidade de ataque no índice 0
    Habilidade ataque("Golpe Limpo", false, poderDeAtaque, false, semEfeito);
    invHab.novaAcao(ataque);

    InventarioItem invItem; // Inventário de itens vazio
    
    return Personagem(vidaInicial, invHab, "Estudante Tester", invItem);
}

// --- CASOS DE TESTE ---

TEST_CASE("SALACOMBATE - Inicializacao e Getters") {
    SalaCombate sala("Sala do Segmentation Fault", "Um ponteiro nulo bloqueia o caminho.");
    CHECK(sala.getNome() == "Sala do Segmentation Fault");
}

TEST_CASE("SALACOMBATE - mostrarSala (Redirecionamento de cout)") {
    SalaCombate sala("Sala Teste", "Enredo especifico do teste.");
    
    // 1. Redireciona o fluxo de saída para uma string local
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
    
    // 2. Executa o método
    sala.mostrarSala();
    
    // 3. Restaura o cout original (crítico para o doctest não quebrar)
    std::cout.rdbuf(coutAntigo);
    
    // 4. Validação
    std::string saida = bufferSaida.str();
    CHECK(saida.find("Sala Teste") != std::string::npos);
    CHECK(saida.find("Enredo especifico do teste.") != std::string::npos);
}

TEST_CASE("SALACOMBATE - executarSala: Vitoria do Jogador") {
    SalaCombate sala("Sala do Boss", "O chefe apareceu!");
    
    // O inimigo alocado internamente tem 80 de HP. 
    // Criamos um personagem com 100 de ataque para matá-lo em 1 hit.
    Personagem heroi = criarPersonagemParaTeste(100, 100);

    // Simula a entrada do usuário: 
    // "1" (Abre o menu de habilidades) -> "0" (Escolhe a habilidade do índice 0)
    std::stringstream simulacaoEntrada("1\n0\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());
    
    // Oculta os textos do combate redirecionando o cout para o vazio
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());

    // Executa a lógica (deve dar One-Hit Kill no inimigo)
    int resultado = sala.executarSala(&heroi);

    // Restauração obrigatória dos fluxos
    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);

    // Valida se o retorno foi 2 (código de vitória configurado no cpp)
    CHECK(resultado == 2);
    CHECK(heroi.isMorto() == false);
}

TEST_CASE("SALACOMBATE - executarSala: Derrota do Jogador") {
    SalaCombate sala("Sala Implacavel", "O inimigo ataca primeiro!");
    
    // Personagem com 1 de vida. Qualquer ataque do inimigo o matará.
    Personagem heroi = criarPersonagemParaTeste(1, 0);

    // Simula uma escolha inválida: "9". 
    // Isso emite um aviso e passa o turno para o inimigo, que ataca e mata o herói.
    std::stringstream simulacaoEntrada("9\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());
    
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());

    int resultado = sala.executarSala(&heroi);

    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);

    // Valida se o retorno foi 0 (código de falha crítica)
    CHECK(resultado == 0);
    CHECK(heroi.isMorto() == true);
}