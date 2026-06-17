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
}