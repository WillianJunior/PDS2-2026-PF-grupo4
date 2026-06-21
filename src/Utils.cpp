#include "Utils.hpp"
#include <iostream>
#include <thread>
#include <chrono>

namespace Utils {

    void coutTempo(std::string texto, int milisegundos){
        for(char letra : texto) {
            std::cout << letra << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
        }
    }
    void limparTela(){
        system("clear"); 
    }

    void limparTelaAnima(){
        std::cout << "\033[1;1H"; // comando que so volta o cursor pra linha 1 e permite "animar"
    }
    void esperar(int milissegundos){
        std::this_thread::sleep_for(std::chrono::milliseconds(milissegundos));
    }
}