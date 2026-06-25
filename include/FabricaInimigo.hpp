#ifndef FABRICAINIMIGO_HPP
#define FABRICAINIMIGO_HPP
#include "Inimigo.hpp"
#include <string>
#include <memory>

namespace FabricaInimigo{
    /**
     * @brief Cria inimigo que realmente sera utilizado no jogo baseado no conteudo dos txts
     * @param nomePersonagem O nome do personagem para saber de quem é o inimigo
     * @param nomeDaHabilidade O andar do inimigo que será criado
     */
    std::unique_ptr<Inimigo> criarInimigo(std::string nomePersonagem, int andar);
}

#endif