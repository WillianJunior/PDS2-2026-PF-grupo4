#ifndef ITEM_H
#define ITEM_H

#include "Acao.hpp"

/**
 * @brief Representa um item no jogo.
 * * Herda da classe Acao e define as características específicas de um item consumível ou utilizável (como dano, cura ou efeitos).
 */
class Item : public Acao {
    public:
    /**
     * @brief Construtor padrão do Item.
     * * Inicializa o item definindo seu nome, tipo de alvo, valor e efeito.
     * @param nome O nome do item.
     * @param alvo Define quem será o alvo do item (ex: true para o próprio personagem, false para o inimigo).
     * @param valor O valor numérico do efeito do item (ex: quantidade de cura ou de dano).
     * @param efeito O efeito de status que o item aplica ao ser usado.
     */
        Item(std::string nome, bool alvo, int valor, Efeito efeito);

    /**
     * @brief Destrutor do objeto Item.
     * * Garante a limpeza adequada da memória quando o item for destruído.
     */
        ~Item();
};

#endif