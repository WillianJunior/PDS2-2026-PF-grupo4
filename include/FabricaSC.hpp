#ifndef FABRICASC_HPP
#define FABRICASC_HPP
#include "SalaCombate.hpp"
#include <string>
#include <memory>

namespace FabricaSC {
    std::unique_ptr<SalaCombate> criarSalas(std::string nome, int idInimigo);
}

#endif