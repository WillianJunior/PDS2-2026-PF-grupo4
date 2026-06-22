#ifndef SAVEMANAGER_HPP
#define SAVEMANAGER_HPP

#include "Personagem.hpp"
#include <memory>

class SaveManager {
    public:
        static void salvar(int contadorSalas, Personagem& personagem);
        static std::unique_ptr<Personagem> carregar(int& contadorSalas);
        static bool existeSave();
};

#endif