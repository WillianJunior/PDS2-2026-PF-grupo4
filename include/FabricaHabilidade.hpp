#ifndef FABRICAHABILIDADE_HPP
#define FABRICAHABILIDADE_HPP
#include "Inimigo.hpp"
#include <string>
#include <memory>

namespace FabricaHabilidade{
    Habilidade criarHabilidade(std::string nomeDaHabilidade);
}

#endif