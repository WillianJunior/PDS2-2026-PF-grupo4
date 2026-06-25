#ifndef HABILIDADE_H
#define HABILIDADE_H

#include "Acao.hpp"

/**
 * @brief Representa uma habilidade no jogo.
 * * Herda da classe Acao e define as características específicas de uma habilidade, como dano, cura ou efeitos.
 */
class Habilidade : public Acao {
    private:
    /** @brief Tempo de cooldown */
        int _cooldown;
    /** @brief Tempo de cooldownAtual */
        int _cooldownAtual;

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
        Habilidade(std::string nome, bool tipo, int valor, bool alvo, Efeito efeito, int cooldown);
    
    /**
     * @brief Compara duas habilidades
     * * Compara todos os parâmetros de duas habilidades para ver se sao iguais
     * @return Retorna true se sao iguais e false se sao diferentes
     */
        bool operator==(const Habilidade& outro) const;

    /**
     * @brief Retorna o valor de cooldown da habilidade
     * * Getter para retornar o valor de cooldown
     * @return Retorna uma número inteiro que corresponde ao valor do cooldown
     */
        int getCooldown();

    /**
     * @brief Retorna o valor de cooldown atual da habilidade
     * * Getter para retornar o valor de cooldown atual
     * @return Retorna uma número inteiro que corresponde ao valor do cooldown atual
     */
        int getCooldownAtual();

    /** @brief Atribui o cooldown ao cooldown atual */
        void iniciarCooldown();

    /** @brief Se o cooldown for maior que 0, ele o diminui */
        void atualizarCooldown();

    /** @brief Zera o cooldown */
        void zerarCooldown();

    /**
     * @brief Atribui um valor ao cooldown atual
     * @param valor O valor que será atribuído ao cooldown atual
     */
        void setCooldownAtual(int valor);

    /** 
     * @brief Destrutor do objeto habilidade
     * Garante que não vaze memória de habilidades.
    */
        ~Habilidade();

};

#endif