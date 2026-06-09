#include "SalaCombate.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

SalaCombate::SalaCombate(std::string nome, std::string historia) 
    : SalaBase(nome), _historia(historia) {
    this->alocarInimigo();
}

void SalaCombate::mostrarSala(){
    std::cout << "\n========================================" << std::endl;
    std::cout << "          " << this->_nome << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << _historia << std::endl;
}

int SalaCombate::executarSala(Personagem* personagem){
    bool turnoDoJogador = true;
    int opcao = 0;

    std::cout << "\n| BATALHA INICIADA: " << personagem->getNome() << " VS " << _inimigo->getNome() << "|" << std::endl;
    
    while (!personagem->isMorto() && !_inimigo->isMorto()) {
        
        if (turnoDoJogador) {
            std::cout << "\n=== SUA VEZ ===" << std::endl;
            std::cout << "Seu HP: " << personagem->getVida() << " | HP do " << _inimigo->getNome() << ": " << _inimigo->getVida() << std::endl;
            
            std::cout << "1 - Usar Habilidade" << std::endl;
            std::cout << "2 - Usar Item" << std::endl;
            std::cout << "Escolha sua acao: ";
            std::cin >> opcao;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERRO Entrada invalida. Digite um numero." << std::endl;
                continue; 
            }

            if (opcao == 1) {
                personagem->getInventarioHabilidade().mostrarInventario();
                std::cout << "Escolha a habilidade: ";
                int numeroHabilidade;
                std::cin >> numeroHabilidade;

                try {
                    //int dano = personagem->escolherHabilidade(numeroHabilidade);
                    Habilidade habEscolhida = personagem->escolherHabilidade(numeroHabilidade);
                    int dano = habEscolhida.getValor();
                    if (dano > 0) {
                        _inimigo->alterarVida(-dano);
                        std::cout << "> " << _inimigo->getNome() << " sofreu " << dano << " de dano!" << std::endl;
                    }
                } catch (const std::exception& e) {
                    std::cout << "FALHA" << e.what() << std::endl;
                    continue; 
                }

            } else if (opcao == 2) {
                personagem->getInventarioItem().mostrarInventario();
                std::cout << "Escolha o item: ";
                int numeroItem;
                std::cin >> numeroItem;

                try {
                    personagem->escolherItem(numeroItem);
                } catch (const std::exception& e) {
                    std::cout << "FALHA " << e.what() << std::endl;
                    continue;
                }

            } else {
                std::cout << "Opcao inexistente." << std::endl;
                continue;
            }

        } else {
            std::cout << "\n=== VEZ DO INIMIGO ===" << std::endl;
            
            //IA interna no inimigo para escolher habilidade
            //int danoInimigo = _inimigo->escolherHabilidade(0); 
            Habilidade habInimigo = _inimigo->escolherHabilidade(0);
            int danoInimigo = habInimigo.getValor();
            personagem->alterarVida(-danoInimigo);
            
            std::cout << "> " << _inimigo->getNome() << " atacou e causou " << danoInimigo << " de dano!" << std::endl;
        }
        turnoDoJogador = !turnoDoJogador;
    }

    if (personagem->isMorto()) {
        std::cout << "\n[DERROTA] Suas forcas se esgotaram..." << std::endl;
        return 0; //encerra na engine
    } else {
        std::cout << "\n[VITORIA] O " << _inimigo->getNome() << " foi derrotado!" << std::endl;
        return 2; //ID da proxima sala
    }
}

void SalaCombate::alocarInimigo() {
    InventarioHabilidade habsInimigo;
    Efeito semEfeito("Nenhum", 0, 0);
    Habilidade ataqueInimigo("Syntax Error", false, 15, false, semEfeito);
    habsInimigo.novaAcao(ataqueInimigo);
    std::string nomeInimigo = "Bug Desconhecido";
    if (this->_nome.find("Segmentation Fault") != std::string::npos) {
        nomeInimigo = "SegFault Guardiao";
    }
    //assumingo inimigo uniqueptr
    _inimigo.reset(new Inimigo(80, habsInimigo, nomeInimigo, false));
}

void SalaCombate::encerrarSala() {
    std::cout << "A poeira do combate baixa. A porta a frente se abre." << std::endl;
}
