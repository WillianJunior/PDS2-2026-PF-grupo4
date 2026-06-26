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
}

//cria a sequencia aleatoria de salas que tera na run atual, 5 combates e 3 escolhas, finalizando em um boss
void Engine::prepararSalas(std::string nome){
    int qtdCombate = 0;
    int qtdEscolha = 0;

    //// a logica de escolha dos inimigos aleatorios fica aqui, ela seleciona um numero aleatorio e manda pra fabrica que criar com o numero
    //correspondente
    std::vector<int> idsInimigos = {1, 2, 3, 4, 5};
    std::random_shuffle(idsInimigos.begin(), idsInimigos.end());

    //loop pra 8 interações, 5 combates e 3 escolhas, se tiver boss final em conjunto teria que mudar
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

    // Sala do boss
    _salasDoJogo.push_back(FabricaSC::criarSalas(nome, 6)); 
}

void Engine::iniciar(){
    bool rodando = true;

    while (rodando) {
        Menu menuPrincipal;
        int salaID = 0;
        bool existeSave = false;

        // Evita vazamento de memória
        _salasDoJogo.clear();
        _personagem.reset(); 

        if(!Engine::modoTeste) {
            existeSave = SaveManager::existeSave();
        }
        
        _personagem = menuPrincipal.executarMenuInicial(existeSave);

        // Condição de encerramento escolheu sair do menu inicial
        if (!_personagem) {
            std::cout << "Encerrando o sistema. Até a próxima compilação!" << std::endl;
            rodando = false;
            break; 
        }

        if(_personagem->getNome() == "PersonagemSalvo")
        {
            _personagem = SaveManager::carregar(salaID, _salasDoJogo);
            if (!_personagem) {
                std::cerr << "Erro ao carregar o save. Arquivo corrompido ou inacessível.\n";
                Utils::esperar(2000);
                continue; 
            }
            std::cout << "Jogo carregado! Continuando na sala " << salaID + 1 << "...\n";
        } else {
            this->prepararSalas(_personagem->getNome());
        }

        // maquina de estados
        while (salaID < 9 && !_personagem->isMorto()) {
            std::unique_ptr<SalaBase> salaAtual = fabricarProximaSala(salaID);
            if (!salaAtual) {
                std::cerr << "ERRO DE ROTEAMENTO - Ponteiro nulo retornado para a sala ID: " << salaID << std::endl;
                break;
            }
            salaAtual->mostrarSala();
            
            // A sala assume o controle até sua lógica interna terminar, 
            // alterando os estados do personagem passado por raw pointer (.get()).
            if(salaAtual->executarSala(*_personagem.get()) == 0){
                std::cout << "\n========================================\n";
                std::cout << "               GAME OVER                  \n";
                std::cout << "========================================\n";
                // apaga save em game over
                std::remove("save.txt");
                break; 
            } else {
                salaID++;
                // salva após cada sala
                SaveManager::salvar(salaID, *_personagem, _salasDoJogo);
            }
            salaAtual->encerrarSala();
            
            if(!_personagem->isMorto() && salaID < 9){
                int escolhaSaida = 0;
                while(true){
                    std::cout << "\n========================================================\n";
                    std::cout << "  SALA CONCLUIDA! O jogo foi salvo automaticamente.\n";
                    std::cout << "========================================================\n";
                    std::cout << "[ 1 ] - Seguir para a proxima sala\n";
                    std::cout << "[ 2 ] - Voltar ao Menu Principal\n";
                    std::cout << "Escolha: ";
                
                    std::cin >> escolhaSaida;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(10000, '\n'); // Limpa o "lixo" do buffer
                        std::cout << "Entrada invalida! Digite apenas o numero 1 ou 2.\n";
                        continue; 
                    }
                    if(escolhaSaida == 1){
                        break;
                    } 
                    else if(escolhaSaida == 2){
                        std::cout << "\nVoltando ao menu principal...\n";
                        break;
                    } 
                    else{
                        std::cout << "Opcao inexistente! Escolha 1 ou 2.\n";
                    }
                }
                // se escolheu 2, sai da engine da partida atual
                if (escolhaSaida == 2){
                    break; 
                }
            }
        } 

        if (_personagem && !_personagem->isMorto() && salaID >= 9){
            std::cout << "\n========================================\n";
            std::cout << "   VITÓRIA! O PROJETO FOI ENTREGUE!       \n";
            std::cout << "========================================\n";
            std::cout << "\nWilliam ficou muito contente em ver o projeto finalmente entregue\n Apesar de todos os desafios, batalhas arduas foi possivel entregar um codigo quase perfeito\n Mas as ameaças ainda estão presentes\n Se prepare pois os novos desafios serão ainda maiores " << std::endl;
            // apaga save na vitória
            std::remove("save.txt");
        }

        if (rodando) {
            Utils::esperar(4000); 
            Utils::limparTela();
        }

        
    } // Fim do Laço da Aplicação -- retorna ao Menu
}

std::unique_ptr<SalaBase> Engine::fabricarProximaSala(int idSala) {
    // AS salas são inseridas aqui
     return std::move(_salasDoJogo[idSala]);
}