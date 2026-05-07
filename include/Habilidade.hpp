#ifndef HABILIDADE_H
#define HABILIDADE_H

#include "Acao.hpp"

/**
 * @brief Representa uma habilidade no jogo.
 * * Herda da classe Acao e define as características específicas de uma habilidade, como dano, cura ou efeitos.
 */
class Habilidade : public Acao {
    public:
    /**
     * @brief Construtor da habilidade que herda de Acao
     * * Constrói nome, alvo, valor, efeito
     * @param nome Nome da habilidade
     * @param tipo Se a habilidade é de alterar vida [personagem ou do inimigo], ou causar efeito
     * @param valor Qual o valor que a habilidade retorna [dano, cura]
     * @param alvo Em quem a habilidade será usada
     * @param efeito Qual efeito ela causa no personagem ou em si
     */
        Habilidade(std::string nome, bool tipo, int valor, bool alvo, Efeito efeito);

    /** 
     * @brief Destrutor do objeto habilidade
     * Garante que não vaze memória de habilidades.
    */
        ~Habilidade();

};

#endif