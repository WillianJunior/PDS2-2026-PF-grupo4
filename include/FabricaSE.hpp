#ifndef FABRICA_SALAS_HPP
#define FABRICA_SALAS_HPP

#include "SalaEscolha.hpp"

namespace FabricaSE {
    /**
     * @brief Cria sala escolha baseado no personagem
     * @param nome O nome do personagem para saber quais são as salas dele
     * @param idEscolha Qual é a escolha
     */
    SalaEscolha criarSalas(std::string nome, int idEscolha = -1);
}

#endif