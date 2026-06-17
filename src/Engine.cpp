#include "Engine.hpp"
#include "Menu.hpp"
#include "SalaCombate.hpp"
#include "SalaEscolha.hpp"
#include "Utils.hpp"
#include "FabricaSE.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

Engine::Engine() : _personagem(nullptr) {
    srand(time(NULL));
    // reservado para carregar configurações gerais
    // leitura de arquivos de save.
}

//cria a sequencia aleatoria de salas que tera na run atual, podendo ir de 6 combates e 1 escolha, até 4 combates e 3 escolhas, finalizando em um boss
void Engine::prepararSalas(std::string nome){
    int qtdCombate = 0;
    int qtdEscolha = 0;

    for(int i = 0; i < 7; i++){
        std::string titulo = "Andar " + std::to_string(i + 1);
        int sala = rand() % 2;
        if(sala == 1 && qtdEscolha < 3){
            std::unique_ptr<SalaBase> salaEscolhida(new SalaEscolha(FabricaSE::criarSalas(nome)));
            for (size_t i = 0; i < _salasDoJogo.size(); i++)
            {
                if(_salasDoJogo[i]->getNome() == salaEscolhida->getNome())
                {
                    std::unique_ptr<SalaBase> salaEscolhida(new SalaEscolha(FabricaSE::criarSalas(nome)));
                    i = 0;
                }
            }
            
            _salasDoJogo.push_back(std::move(salaEscolhida));
            qtdEscolha++;
        }
        else{
            _salasDoJogo.push_back(std::unique_ptr<SalaBase>(new SalaCombate(titulo, "Sala de combate " + std::to_string(i + 1))));
        }
    }
    _salasDoJogo.push_back(std::unique_ptr<SalaBase>(new SalaCombate("SALA DO CHEFE", "boss final personalizado")));
}

void Engine::iniciar(){
    Menu menuPrincipal;
    _personagem = menuPrincipal.executarMenuInicial();

    if (!_personagem) {
        std::cout << "Inicialização abortada. Encerrando o sistema." << std::endl;
        return;
    }

    //geraçao das salas
    this->prepararSalas(_personagem->getNome());

    // loop principal - maquina de estados
    int contadorSalas = 0;
    
    while (contadorSalas < 8 && !_personagem->isMorto()) {
        
        std::unique_ptr<SalaBase> salaAtual = fabricarProximaSala(contadorSalas);
        
        if (!salaAtual) {
            std::cerr << "ERRO DE ROTEAMENTO - Ponteiro nulo retornado para a sala ID: " << contadorSalas << std::endl;
            break; 
        }

        salaAtual->mostrarSala();
        
        // A sala assume o controle até sua lógica interna terminar, 
        // alterando os estados do personagem passado por raw pointer (.get()).
        if(salaAtual->executarSala(_personagem.get()) == 0){
            std::cout << "\nGAME OVER" << std::endl;
            break;
        } else{
            contadorSalas++;
        }
        
        
        salaAtual->encerrarSala();
        
        // O escopo do while garante que salaAtual seja destruída 
    }

    // Finalização e encerramento da gistória
    if (!_personagem->isMorto()) {
        std::cout << "\nHISTORIA FINAL DO JOGO" << std::endl;
    }
    
}

std::unique_ptr<SalaBase> Engine::fabricarProximaSala(int idSala) {
    // AS salas são inseridas aqui
     return std::move(_salasDoJogo[idSala]);
}