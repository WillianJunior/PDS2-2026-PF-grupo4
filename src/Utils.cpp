#include "Utils.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

namespace Utils {
    bool modoTeste = false;

    void coutTempo(std::string texto, int milisegundos){
        bool pularTextoAtual = false;

        if(!modoTeste) {
            struct termios oldt, newt;
            
            // Desliga o terminal para ele não mostrar o que foi digitado
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);

            // Torna a leitura não bloqueante (não precisa ler algo obrigatoriamente para não travar o jogo)
            int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
            fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

            // Limpa o buffer de teclas antigas
            while(getchar() != EOF) {}

            for(char letra : texto) {
                std::cout << letra << std::flush;
                
                // Olha se a tecla espaço foi pressionada
                int ch = getchar();
                if (ch != EOF) {
                    if (ch == ' ') {
                        pularTextoAtual = true;
                    }
                }

                if (!pularTextoAtual) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
                } else {
                    // Deixa o texto 10x mais rápifo
                    std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos/10));
                }
            }

            // Limpa qualquer restos de teclas que foram digitadas enquanto o texto estava pulando rápido
            while(getchar() != EOF) {}

            // Volta o terminal ao normal
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            fcntl(STDIN_FILENO, F_SETFL, oldf);
            
        } else {
            // Se estiver no modo teste escreve tudo instantaneamente
            for(char letra : texto) {
                std::cout << letra << std::flush;
            }
        }
    }


    void limparTela() {
        system("clear"); 
    }

    void esperar(int milissegundos){
        if(!modoTeste) {
            struct termios oldt, newt;
            
            // Desliga o terminal para ele não mostrar o que foi digitado durante a espera
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);

            // Espera o tempo determinado
            std::this_thread::sleep_for(std::chrono::milliseconds(milissegundos));

            // Torna a leitura não bloqueante
            int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
            fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

            // Limpa o buffer de teclas que o usuário segurou (como o espaço)
            while(getchar() != EOF) {}

            // Volta o terminal ao normal
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            fcntl(STDIN_FILENO, F_SETFL, oldf);
        }
    }
}