#include "Engine.hpp"
#include "Menu.hpp"
#include "SalaCombate.hpp"
#include "SalaEscolha.hpp"
#include "Utils.hpp"
#include <iostream>

Engine::Engine() : _personagem(nullptr) {
    // reservado para carregar configurações gerais
    // leitura de arquivos de save.
}

void Engine::iniciar() {
    Menu menuPrincipal;
    _personagem = menuPrincipal.executarMenuInicial();

    if (!_personagem) {
        std::cout << "Inicialização abortada. Encerrando o sistema." << std::endl;
        return;
    }

    // loop principal - maquina de estados
    int idProximaSala = 1;

   while (idProximaSala != 0 && !_personagem->isMorto()) {
        
        std::unique_ptr<SalaBase> salaAtual = fabricarProximaSala(idProximaSala);
        
        if (!salaAtual) {
            std::cerr << "ERRO DE ROTEAMENTO - Ponteiro nulo retornado para a sala ID: " << idProximaSala << std::endl;
            break; 
        }

        salaAtual->mostrarSala();
        
        // A sala assume o controle até sua lógica interna terminar, 
        // alterando os estados do personagem passado por raw pointer (.get()).
        idProximaSala = salaAtual->executarSala(_personagem.get()); 
        
        salaAtual->encerrarSala();
        
        // O escopo do while garante que salaAtual seja destruída 
    }

    // Finalização e encerramento da gistória
    if (_personagem->isMorto()) {
        std::cout << "\nHistoria Final" << std::endl;
    } else {
        std::cout << "\nEncerramento" << std::endl;
    }
}

std::unique_ptr<SalaBase> Engine::fabricarProximaSala(int idSala) {
    // AS salas são inseridas aqui
    switch (idSala) {
        case 1:
            return std::unique_ptr<SalaBase>(new SalaCombate("COMBATE 1", "Historia 1"));
        case 2:
            return std::unique_ptr<SalaBase>(new SalaEscolha("SALA ESCOLHA 2", "Historia 2"));
        case 3:
            return std::unique_ptr<SalaBase>(new SalaCombate("COMBATE 3", "Historia 3"));
        case 4:
            return std::unique_ptr<SalaBase>(new SalaCombate("COMBATE FINAL", "Historia 4"));
        default:
            return nullptr; // 0 encerra o loop
    }
}