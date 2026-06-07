#include "Engine.hpp"
#include "Menu.hpp"
#include "SalaCombate.hpp"
#include "SalaEscolha.hpp"
#include <iostream>

Engine::Engine() : _personagem(nullptr) {
    // reservado para carregar configurações gerais
    // leitura de arquivos de save.
}

void Engine::iniciar() {
    Menu menuPrincipal;
    
    _personagem = menuPrincipal.executarMenuInicial();

    // Verificação de segurança caso o jogador tenha fechado o jogo no menu
    if (!_personagem) {
        std::cout << "Inicialização abortada. Encerrando o sistema." << std::endl;
        return;
    }

    // 2. Loop Principal (Máquina de Estados)
    int idProximaSala = 1; // ID do primeiro nó

 /*   while (idProximaSala != 0 && !_personagem->isMorto()) {
        
        std::unique_ptr<SalaBase> salaAtual = fabricarProximaSala(idProximaSala);
        
        // Tratamento de falha de roteamento
        if (!salaAtual) {
            std::cerr << "[ERRO DE ROTEAMENTO] Ponteiro nulo retornado para a sala ID: " << idProximaSala << std::endl;
            break; 
        }

        salaAtual->mostrarSala();
        
        // A sala assume o controle até sua lógica interna terminar, 
        // alterando os estados do personagem passado por raw pointer (.get()).
        idProximaSala = salaAtual->executarSala(_personagem.get()); 
        
        salaAtual->encerrarSala();
        
        // O escopo do while garante que salaAtual seja destruída 
    }

    // 3. Finalização e Encerramento da História
    if (_personagem->isMorto()) {
        std::cout << "\nHistoria Final" << std::endl;
    } else {
        std::cout << "\nEncerramento" << std::endl;
    }
}*/

/*std::unique_ptr<SalaBase> Engine::fabricarProximaSala(int idSala) {
    // O isolamento das dependências concretas ocorre aqui.
    // Qualquer nova sala criada no futuro exigirá alteração apenas neste escopo fechado.
    switch (idSala) {
        case 1:
            // Combate inicial
            return std::unique_ptr<SalaBase>(new SalaCombate("Sala do Segmentation Fault"));
        case 2:
            // Sala Escolha
            return std::unique_ptr<SalaBase>(new SalaEscolha("Reunião de Alinhamento (Refeitório)"));
        case 3:
            // Sala 3
            return std::unique_ptr<SalaBase>(new SalaCombate("Sala do Memory Leak"));
        case 4:
            // Boss final
            return std::unique_ptr<SalaBase>(new SalaCombate("Defesa do Projeto - Avaliador Implacável"));
        default:
            return nullptr; // 0 encerra o loop
    }
}*/