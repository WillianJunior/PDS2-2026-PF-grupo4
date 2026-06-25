#ifndef FABRICAHABILIDADE_HPP
#define FABRICAHABILIDADE_HPP
#include "Inimigo.hpp"
#include <string>
#include <memory>

namespace FabricaHabilidade{
    /**
     * @brief Cria a habilidade que realmente será utilizada no jogo baseado no txt das habilidades
     * @param nomeDaHabilidade O nome da habilidade que deve ser criada
     */
        Habilidade criarHabilidade(std::string nomeDaHabilidade);
}

#endif