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
    Habilidade ataque("Golpe Limpo", false, poderDeAtaque, false, semEfeito, 0);
    invHab.novaAcao(ataque);
  
    InventarioItem invItem; 
    // Adiciona um item de cura no indice 0
    Item pocao_de_cura_vazia("Pocao Teste", true, 0, semEfeito, true);
    invItem.novaAcao(pocao_de_cura_vazia);
    
    return Personagem(vidaInicial, invHab, "Estudante Tester", invItem);
}

// --- CASOS DE TESTE ---

TEST_CASE("SALACOMBATE - Inicializacao e Getters") {
    InventarioHabilidade inventarioHabilidadeTeste;
    std::unique_ptr<Inimigo> inimigoTeste(new Inimigo(100, inventarioHabilidadeTeste, "Inimigo Teste"));

    SalaCombate sala("Sala do Segmentation Fault", "Um ponteiro nulo bloqueia o caminho.", "Você venceu!", "Você perdeu", "Vaz", 1);
    CHECK(sala.getNome() == "Sala do Segmentation Fault");
}

TEST_CASE("SALACOMBATE - mostrarSala (Redirecionamento de cout)") {
    InventarioHabilidade inventarioHabilidadeTeste;
    std::unique_ptr<Inimigo> inimigoTeste(new Inimigo(100, inventarioHabilidadeTeste, "Inimigo Teste"));

    SalaCombate sala("Sala Teste", "Enredo especifico do teste.", "Você venceu!", "Você perdeu", "Vaz", 1);
    
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
    InventarioHabilidade inventarioHabilidadeTeste;
    std::unique_ptr<Inimigo> inimigoTeste(new Inimigo(100, inventarioHabilidadeTeste, "Inimigo Teste"));

    SalaCombate sala("Sala do Boss", "O chefe apareceu!", "Você venceu!", "Você perdeu", "Vaz", 1);
    
    // O inimigo alocado internamente tem 80 de HP. 
    // Criamos um personagem com 100 de ataque para matá-lo em 1 hit.
    Personagem heroi = criarPersonagemParaTeste(100, 100);

    // Simula a entrada do usuário: 
    // "1" (Abre o menu de habilidades) -> "0" (Escolhe a habilidade do índice 0)
    std::stringstream simulacaoEntrada("1\n1\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());
    
    // Oculta os textos do combate redirecionando o cout para o vazio
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());

    // Executa a lógica (deve dar One-Hit Kill no inimigo)
    int resultado = -1;
    try {
        resultado = sala.executarSala(heroi);
    } catch (...) {
        // Se der algum erro (como EntradaInvalida), cai aqui
        // Isso evita que a função aborte antes de restaurar o cout/cin
    }
    // Restauração obrigatória dos fluxos
    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);

    CHECK(resultado == 1);
    CHECK(heroi.isMorto() == false);
}

TEST_CASE("SALACOMBATE - executarSala: Derrota do Jogador") {
    InventarioHabilidade inventarioHabilidadeTeste;
    std::unique_ptr<Inimigo> inimigoTeste(new Inimigo(100, inventarioHabilidadeTeste, "Inimigo Teste"));

    SalaCombate sala("Sala Implacavel", "O inimigo ataca primeiro!", "Você venceu!", "Você perdeu", "Vaz", 1);
    
    // Personagem com 1 de vida. Qualquer ataque do inimigo o matará.
    Personagem heroi = criarPersonagemParaTeste(1, 0);
    
    //CORRIGI APENAS PARA RODAS SEM TRAVAR
    // Simula uma escolha inválida: "9". (NAO TEM ESSA ESCOLHA INVALIDA, TROQUEI POR 2\n0\n) 
    // Isso emite um aviso e passa o turno para o inimigo, que ataca e mata o herói.
    std::stringstream simulacaoEntrada("2\n1\n");
    std::streambuf* cinAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());
    
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());

    int resultado = -1;
    try {
        resultado = sala.executarSala(heroi);
    } catch (...) {
        // Se der algum erro (como EntradaInvalida), cai aqui
        // Isso evita que a função aborte antes de restaurar o cout/cin
    }
    // Restauração obrigatória dos fluxos
    std::cin.rdbuf(cinAntigo);
    std::cout.rdbuf(coutAntigo);

    CHECK(resultado == 0);
    CHECK(heroi.isMorto() == true);
}