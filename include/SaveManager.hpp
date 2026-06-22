#ifndef SAVEMANAGER_HPP
#define SAVEMANAGER_HPP

#include "Personagem.hpp"
#include "SalaBase.hpp"
#include <vector>
#include <memory>
#include <string> 

class SaveManager {
    public:
        static void salvar(int contadorSalas, Personagem& personagem, const std::vector<std::unique_ptr<SalaBase>>& salas);
        static std::unique_ptr<Personagem> carregar(int& contadorSalas, std::vector<std::unique_ptr<SalaBase>>& salas);
        static bool existeSave();
};

#endif