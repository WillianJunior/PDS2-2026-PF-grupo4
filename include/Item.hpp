#ifndef ITEM_H
#define ITEM_H
#include "Acao.hpp"

/**
 * @brief Representa um item no jogo.
 * * Herda da classe Acao e define as características específicas de um item consumível ou utilizável (como dano, cura ou efeitos).
 */
class Item : public Acao {
    private:
    /** @brief Inteiro que armazena usos restantes. */
        int _usosRestantes;
    public:
    /**
     * @brief Construtor padrão do Item.
     * * Inicializa o item definindo seu nome, tipo de alvo, valor e efeito.
     * @param nome O nome do item.
     * @param alvo Define quem será o alvo do item (ex: true para o próprio personagem, false para o inimigo).
     * @param tipo Define se é um item que altera vida ou aplica efeito (ex: true aplica efeito, false não aplica efeito).
     * @param valor O valor numérico do efeito do item (ex: quantidade de cura ou de dano).
     * @param efeito O efeito de status que o item aplica ao ser usado.
     */
        Item(std::string nome, bool tipo, int valor, Efeito efeito, bool alvo, int usos);

    /** @brief Se os usos restantes for maior que 0, ele o diminui */
        void atualizarUsos();

    /**
     * @brief Retorna o valor de usos restantes do item
     * * Getter para retornar o valor de usos restantes do item
     * @return Retorna uma número inteiro que corresponde ao valor de usos restantes do item
     */
        int getUsosRestantes();

    /**
     * @brief Compara dois itens
     * * Compara todos os parâmetros de dois itens para ver se sao iguais
     * @return Retorna true se sao iguais e false se sao diferentes
     */
        bool operator==(const Item& outro) const;

    /**
     * @brief Destrutor do objeto Item.
     * * Garante a limpeza adequada da memória quando o item for destruído.
     */
        ~Item();
};

#endif