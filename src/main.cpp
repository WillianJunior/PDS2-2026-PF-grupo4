#include "Engine.hpp"
#include <iostream>
#include <exception>

int main() {
    try {
        Engine loopPrincipal;
        loopPrincipal.iniciar();
    } 
    catch (const std::exception& e) {
        std::cerr << "\n[CRITICAL RUNTIME ERROR] Exceção não tratada capturada na raiz: " << e.what() << std::endl;
        return 1;
    } 
    catch (...) {
        std::cerr << "\n[CRITICAL RUNTIME ERROR] Exceção de tipo desconhecido causou o encerramento da Engine." << std::endl;
        return 1;
    }
    

    return 0;
}