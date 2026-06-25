#ifndef FABRICASC_HPP
#define FABRICASC_HPP
#include "SalaCombate.hpp"
#include <string>
#include <memory>

namespace FabricaSC {
    /**
     * @brief Cria sala de combate baseado no nome do personagem e no id do inimigo
     * @param nome O nome do personagem para saber quais são as possibilidades de sala para ele
     * @param idInimigo O id do inimigo para saber qual das salas possíveis será criada
     */
    std::unique_ptr<SalaCombate> criarSalas(std::string nome, int idInimigo);
}

#endif