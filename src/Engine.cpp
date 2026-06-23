#include "Engine.hpp"
#include "Menu.hpp"
#include "SalaCombate.hpp"
#include "SalaEscolha.hpp"
#include "Utils.hpp"
#include "FabricaSE.hpp"
#include "FabricaSC.hpp"
#include "SaveManager.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

bool Engine::modoTeste = false;

Engine::Engine() : _personagem(nullptr) {
    srand(time(NULL));
    // reservado para carregar configurações gerais
    // leitura de arquivos de save.
}

//cria a sequencia aleatoria de salas que tera na run atual, 5 combates e 3 escolhas, finalizando em um boss
void Engine::prepararSalas(std::string nome){
    int qtdCombate = 0;
    int qtdEscolha = 0;

    //// a logica de escolha dos inimigos aleatorios fica aqui, ela seleciona um numero aleatorio e manda pra fabrica que criar com o numero
    //// correspondente
    std::vector<int> idsInimigos = {1, 2, 3, 4, 5};
    std::random_shuffle(idsInimigos.begin(), idsInimigos.end());

    //// aqui alterei o loop pra 8 interações, 5 combates e 3 escolhas, se tiver boss final em conjunto teria que mudar
    for(int i = 0; i < 8; i++){
        int sala = rand() % 2;
       
        if((sala == 1 && qtdEscolha < 3) || qtdCombate == 5){
            std::unique_ptr<SalaBase> salaEscolhida(new SalaEscolha(FabricaSE::criarSalas(nome)));
            
            for (int j = 0; j < (int)_salasDoJogo.size(); j++) {
                if(_salasDoJogo[j]->getNome() == salaEscolhida->getNome()) {
                    salaEscolhida.reset(new SalaEscolha(FabricaSE::criarSalas(nome)));
                    j = -1; 
                }
            }
            _salasDoJogo.push_back(std::move(salaEscolhida));
            qtdEscolha++;
        }
        else {
            // Entrega o id da sala aleatorio ao inves do sequencial
            int idSorteado = idsInimigos[qtdCombate];
            _salasDoJogo.push_back(FabricaSC::criarSalas(nome, idSorteado));
            qtdCombate++;
        }
    }
}

void Engine::iniciar(){
    Menu menuPrincipal;
    int salaID = 0;
    bool existeSave = false;

    if(!Engine::modoTeste) {
        existeSave = SaveManager::existeSave();
    }
    _personagem = menuPrincipal.executarMenuInicial(existeSave);

    if (!_personagem) {
        std::cout << "Inicialização abortada. Encerrando o sistema." << std::endl;
        return;
    }

    if(_personagem->getNome() == "PersonagemSalvo")
    {
        _personagem = SaveManager::carregar(salaID, _salasDoJogo);
        if (!_personagem) {
            std::cerr << "Erro ao carregar o save. Arquivo corrompido ou inacessível.\n";
            return;
        }
        std::cout << "Jogo carregado! Continuando na sala " << salaID + 1 << "...\n";
    } else {
        this->prepararSalas(_personagem->getNome());
    }

    // loop principal - maquina de estados
    while (salaID < 8 && !_personagem->isMorto()) {
        std::unique_ptr<SalaBase> salaAtual = fabricarProximaSala(salaID);
        if (!salaAtual) {
            std::cerr << "ERRO DE ROTEAMENTO - Ponteiro nulo retornado para a sala ID: " << salaID << std::endl;
            break;
        }
        salaAtual->mostrarSala();
        
        // A sala assume o controle até sua lógica interna terminar, 
        // alterando os estados do personagem passado por raw pointer (.get()).
        if(salaAtual->executarSala(*_personagem.get()) == 0){
            std::cout << "\nGAME OVER" << std::endl;
            // apaga save em game over
            std::remove("save.txt");
            break;
        } else {
            salaID++;
            // salva após cada sala
            SaveManager::salvar(salaID, *_personagem, _salasDoJogo);
        }
        salaAtual->encerrarSala();
        
        // O escopo do while garante que salaAtual seja destruída 
    }

    // Finalização e encerramento da gistória
    if (!_personagem->isMorto()) {
        std::cout << "\nHISTORIA FINAL DO JOGO" << std::endl;
        // apaga save na vitória
        std::remove("save.txt");
    }
    
}

std::unique_ptr<SalaBase> Engine::fabricarProximaSala(int idSala) {
    // AS salas são inseridas aqui
     return std::move(_salasDoJogo[idSala]);
}