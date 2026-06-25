#include "doctest.h"
#include "FabricaSE.hpp"
#include "SalaEscolha.hpp"
#include "Personagem.hpp"
#include <string>
#include <sstream>

TEST_CASE("Teste 01: Testando a geracao de salas de escolha por id para todos os personagens") {
    std::string personagens[] = {"Maycon", "Vaz", "Isaque", "Nicole", "Marcos"};
    
    for (std::string nomePersonagem : personagens) {
        
        // Testa a criação das 3 salas de escolha específicas pelo id, para todos os personagens
        for (int id = 0; id < 3; id++) {
            SalaEscolha sala = FabricaSE::criarSalas(nomePersonagem, id);
            
            // Garante que a sala criada possui um nome
            CHECK(sala.getNome() != ""); 
        }
    }
}

TEST_CASE("Teste 02: Testando a geracao de salas de escolha aleatoria para todos os personagens") {
    std::string personagens[] = {"Maycon", "Vaz", "Isaque", "Nicole", "Marcos"};
    
    for (std::string nomePersonagem : personagens) {
        // Testa a criação de uma sala aleatória (sem passar um ID específico)
        SalaEscolha salaAleatoria = FabricaSE::criarSalas(nomePersonagem);
        CHECK(salaAleatoria.getNome() != "");
    }
}

TEST_CASE("Teste 03: Executando as consequencias das opcoes para cobrir os lambdas") {
    std::string personagens[] = {"Maycon", "Vaz", "Isaque", "Nicole", "Marcos"};
    Personagem personagemTeste(10, InventarioHabilidade(), "PersonagemTeste", InventarioItem());
    for (std::string nomePersonagem : personagens) {
        for (int id = 0; id < 3; id++) {
            for (int opcao = 1; opcao <= 5; opcao++) { 
                SalaEscolha sala = FabricaSE::criarSalas(nomePersonagem, id);
                if (sala.getNome() == "") continue; 
                // Coloca a variável opção na entrada e uma opção 1 de garantia caso não tenha opções suficientes para o indice da variavel opcao (aí vai alegar entrada invalida e vai pegar essa reserva)
                std::string entradaFalsa = std::to_string(opcao) + "\n1\n";
                
                std::istringstream simulacaoEntrada(entradaFalsa);
                std::streambuf* cinAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());

                std::ostringstream bufferSaida;
                std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
                
                sala.executarEvento(personagemTeste);
                sala.encerrarSala();

                std::cout.rdbuf(coutAntigo);
                std::cin.rdbuf(cinAntigo);
            }
        }
    }
}