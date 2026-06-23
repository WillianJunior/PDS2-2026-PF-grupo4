#include "SalaCombate.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <random>
#include <algorithm>
#include "Excecoes.hpp"
#include "Utils.hpp"
#include "FabricaInimigo.hpp"

SalaCombate::SalaCombate(std::string nome, std::string historia, std::string textoVitoria, std::string textoDerrota, std::string nomePersonagem, int andar)
    : SalaBase(nome), _historia(historia), _inimigo(alocarInimigo(nomePersonagem, andar)), _textoVitoria(textoVitoria), _textoDerrota(textoDerrota), _idInimigo(andar) {
}

int SalaCombate::getId() {
    return _idInimigo;
}
      
void SalaCombate::mostrarSala(){
    Utils::coutDigitado(50) << _historia << "\n";

    std::vector<std::string> animacaoBatalha = {
        R"(
               O
              /|\
             / | |
              / \
             /   \
        )",
        R"(
               O
              /| \
             / |  \
              / \
             /   \
        )",
        R"(
               O
              /| \
             / | 
              / \
             /   \
        )",
        R"(
               O
              /|--
             / | 
              / \
             /   \
        )",
        R"(
               O
              /|---->  "Ele quer me impedir de codar!"
             / | 
              / \
             /   \
        )"
    };

    for (size_t i = 0; i < animacaoBatalha.size(); ++i) {
        Utils::limparTela();
        std::cout << "\n========================================\n";
        std::cout << "          " << this->_nome << "\n";
        std::cout << "========================================\n\n";
        
        std::cout << animacaoBatalha[i] << "\n";

        if (i == animacaoBatalha.size() - 1) {
            Utils::esperar(1500); 
        } else {
            Utils::esperar(300);
        }
    }
    std::cout << "\n";
    Utils::esperar(2000); 
    Utils::limparTela();
}

int SalaCombate::executarSala(Personagem& personagem){
    bool turnoDoJogador = true;
    int opcao = 0;

    std::cout << "========================================================\n";
    std::cout << "   BATALHA INICIADA: " << personagem.getNome() << " VS " << _inimigo->getNome() << "\n";
    std::cout << "========================================================\n";

    double vidaBase = _inimigo->getVida();
    
    while (!personagem.isMorto() && !_inimigo->isMorto()) {
        
        if (turnoDoJogador) {
            std::cout << "\n=== SUA VEZ ===" << std::endl;
            //atualiza os cooldowns de todas as habilidades
            personagem.getInventarioHabilidade().atualizarCooldowns();
            //aplica todos os efeitos no personagem
            personagem.processarEfeitosAtivos(); 
            if(personagem.isMorto()) break;

            std::cout << "Seu HP: " << personagem.getVida() << " | HP do " << _inimigo->getNome() << ": " << _inimigo->getVida() << std::endl;
            
            std::cout << "1 - Usar Habilidade" << std::endl;
            std::cout << "2 - Usar Item" << std::endl;
            std::cout << "Escolha sua acao: ";
            std::cin >> opcao;
            Utils::esperar(150);

            //protecao contra loop infinito de eof
            if(std::cin.eof()){
               throw EntradaInvalidaException();
            }

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERRO Entrada invalida. Digite um numero." << std::endl;
                continue; 
            }

            if (opcao == 1) {
                personagem.getInventarioHabilidade().mostrarInventario();
                std::cout << "Escolha a habilidade: ";
                int numeroHabilidade;
                std::cin >> numeroHabilidade;

                //protecao contra loop infinito de eof
                if(std::cin.eof()){
                    throw EntradaInvalidaException();
                }                

                try {
                    //int dano = personagem->escolherHabilidade(numeroHabilidade);
                    Habilidade& habEscolhida = personagem.escolherHabilidade(numeroHabilidade - 1);
                    if(habEscolhida.getCooldownAtual() > 0){
                        Utils::coutDigitado() << "[!] Habilidade em cooldown! Escolha outra.\n";
                        continue; 
                    }
                    int impacto = habEscolhida.calcularImpacto();
                    habEscolhida.iniciarCooldown();
                    if (!habEscolhida.getAlvo()) { 
                        _inimigo->alterarVida(impacto);
                        //aplica efeito no inimigo caso habilidade tenha algum
                        _inimigo->receberEfeito(habEscolhida.getEfeito());
                        Utils::coutDigitado(350) << "...\n[";
                        Utils::esperar(350);
                        std::cout << "> " << _inimigo->getNome() << " sofreu " << std::abs(impacto) << " de dano!" << std::endl;
                    }
                    else{
                        personagem.alterarVida(impacto);
                        personagem.receberEfeito(habEscolhida.getEfeito());
                        Utils::coutDigitado(350) << "...";
                        Utils::esperar(350);
                        std::cout << "> " << personagem.getNome() << " recuperou " << std::abs(impacto) << " de vida!" << std::endl;
                    }
                } catch (const std::exception& e) {
                    std::cout << "\n[ERRO] " << e.what() << "\n" << std::endl;
                    continue; 
                }

            } else if (opcao == 2) {
                personagem.getInventarioItem().mostrarInventario();
                std::cout << "Escolha o item: ";
                int numeroItem;
                std::cin >> numeroItem;

                //protecao contra loop infinito de eof
                if(std::cin.eof()){
                    throw EntradaInvalidaException();
                }

                try {
                    Item itEscolhido = personagem.escolherItem(numeroItem - 1);
                    int impacto = itEscolhido.calcularImpacto();
                    if(!itEscolhido.getAlvo()){
                        _inimigo->alterarVida(impacto);
                        _inimigo->receberEfeito(itEscolhido.getEfeito());
                        Utils::coutDigitado(350) << "...\n[";
                        Utils::esperar(350);
                        std::cout << "> " << _inimigo->getNome() << " sofreu " << std::abs(impacto) << " de dano!" << std::endl;
                    }
                    else{
                        personagem.alterarVida(impacto);
                        personagem.receberEfeito(itEscolhido.getEfeito());
                        Utils::coutDigitado(350) << "...\n[";
                        Utils::esperar(350);
                        std::cout << "> " << personagem.getNome() << " recuperou " << std::abs(impacto) << " de vida!" << std::endl;
                    }
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
            //atualiza os cooldowns de todas as habilidades
            _inimigo->getInventarioHabilidade().atualizarCooldowns();
            //aplica todos os efeitos no inimigo
            _inimigo->processarEfeitosAtivos();
            if(_inimigo->isMorto()) break;

            while(true){
                int numHabilidades = _inimigo->getInventarioHabilidade().getTamanho();
                int posicao = rand() % numHabilidades;
                
                Habilidade& habInimigo = _inimigo->escolherHabilidade(posicao);
                
                if(habInimigo.getCooldownAtual() > 0){
                    continue; // Recarregando, repete o while para ele sortear outra
                }

                if(habInimigo.getAlvo()){
                    if(_inimigo->getVida() < 0.5 * vidaBase){
                        int impacto = habInimigo.calcularImpacto();
                        habInimigo.iniciarCooldown(); // <--- Inicia o cooldown da cura!
                        _inimigo->alterarVida(impacto);
                        std::cout << "> " << _inimigo->getNome() << " recuperou " << std::abs(impacto) << " de vida!" << std::endl;
                        break;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    int impacto = habInimigo.calcularImpacto();
                    habInimigo.iniciarCooldown(); // <--- Inicia o cooldown do ataque!
                    personagem.alterarVida(impacto);
                    personagem.receberEfeito(habInimigo.getEfeito());
                    Utils::coutDigitado(350) << "...\n[";
                        Utils::esperar(350);
                    std::cout << "> " << _inimigo->getNome() << " atacou e causou " << std::abs(impacto) << " de dano!" << std::endl;
                    break;
                }
            }
        }
        turnoDoJogador = !turnoDoJogador;
    }

    if (personagem.isMorto()) {
        Utils::coutDigitado(350) << "...\n[";
        Utils::esperar(350);

        std::cout << "\n[DERROTA] " << _textoDerrota << std::endl;
        return 0; //encerra na engine
    } else {
        Efeito semEfeito("Nenhum", 0, 0);
        Item item("Boné pra trás", 1, 10, semEfeito, 1, 1);
        personagem.getInventarioItem().novaAcao(item);
        Utils::coutDigitado(350) << "...\n[";
        Utils::esperar(350);
        std::cout << "\n[VITORIA] " << _textoVitoria << std::endl;
        std::cout << "Você recebeu o item: " << item.getNome() << std::endl;
        personagem.limparEfeitos();
        return 1; 
    }
}

std::unique_ptr<Inimigo> SalaCombate::alocarInimigo(std::string nomePersonagem, int andar) {
    return FabricaInimigo::criarInimigo(nomePersonagem, andar);
}

char SalaCombate::getTipo(){
    return 'C';
}

void SalaCombate::encerrarSala() {
    Utils::coutDigitado() << "A poeira do combate baixa. Voce precisa voltar a codar.\n";
    Utils::limparTela();
}
