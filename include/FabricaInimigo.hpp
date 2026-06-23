#ifndef FABRICAINIMIGO_HPP
#define FABRICAINIMIGO_HPP
#include "Inimigo.hpp"
#include <string>
#include <memory>

namespace FabricaInimigo{
    std::unique_ptr<Inimigo> criarInimigo(std::string nomePersonagem, int andar);
}

#endif