#include "doctest.h"
#include "FabricaSC.hpp"
#include "SalaCombate.hpp"
#include <string>
#include <sstream> 
#include <iostream>

TEST_CASE("Teste 01: Testando a geracao de salas de combate para todos os personagens e IDs") {
    std::string personagens[] = {"Maycon", "Vaz", "Isaque", "Nicole", "Marcos"};
    
    for (std::string nomePersonagem : personagens) {
        for (int id = 1; id <= 5; id++) {
            std::unique_ptr<SalaCombate> sala = FabricaSC::criarSalas(nomePersonagem, id);
            
            // Garante que o ponteiro inteligente gerado foi alocado na memoria com sucesso
            CHECK(sala != nullptr); 
            // O construtor padrao atribui "Combate" como o tituloAndar da sala criada
            CHECK(sala->getNome() == "Combate");
        }
    }
}

TEST_CASE("Teste 02: Testando o fallback de seguranca (Personagem ou ID invalido)") {
    // Ao passar um personagem inexistente ou um ID fora do limite, a fabrica retorna a sala "CRITICAL ERROR: Memória violada."
    std::ostringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
    std::streambuf* cerrAntigo = std::cerr.rdbuf(bufferSaida.rdbuf()); 

    std::unique_ptr<SalaCombate> salaInvalida = FabricaSC::criarSalas("PersonagemFantasma", 99);
    
    std::cout.rdbuf(coutAntigo);
    std::cerr.rdbuf(cerrAntigo);

    CHECK(salaInvalida != nullptr);

    CHECK(salaInvalida->getNome() == "SALA SEGFAULT"); 
}
