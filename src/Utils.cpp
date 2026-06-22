#include "Utils.hpp"
#include <iostream>
#include <thread>
#include <chrono>

namespace Utils {
    bool modoTeste = false;

    void coutTempo(std::string texto, int milisegundos){
        for(char letra : texto) {
            std::cout << letra << std::flush;
            if(!modoTeste) {
                std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
            }
        }
    }
    void limparTela() {
        system("clear"); 
    }
    void esperar(int milissegundos){
        if(!modoTeste) {
            std::this_thread::sleep_for(std::chrono::milliseconds(milissegundos));
        }
    }
}