#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "InventarioHabilidade.hpp"
#include <iostream>
#include <vector>

//classe responsavel por preparar o terreno para as outras entidades:
//personagem e ininimgo
/** 
 * @brief Classe abstrata para representar as entidades
 * * Na hierarqueia é a mãe de Personagem e Inimigo.
 * * Criará métodos virtuais que serão sobrescritos pelas classes mais complexas.
*/

class Entidade{
    protected:
    /**
     * @brief Atributos de vida, nome e habilidades
     * * Vida atributo medidor de saúde da entidade, chegar a 0 gera morte
     * * Nome nome da entidade
     * * Habilidades lista de habilidades que a entidade possui
     */
        int _vida;
        std::string _nome;
        InventarioHabilidade _inventarioHabilidade;
    public: 
    /**
     * @brief Construtor padrão de entidade 
     * Aloca vida, nome e habilidades de entidade
     * @param vida Quantidade de vida que a entidade possui
     * @param nome Nome da entidade
     * @param habilidades Inventário de habilidades da entidade
     */
        Entidade(int vida, std::string nome, InventarioHabilidade inventarioHabilidade);

    /**
     * @brief Função virtual de escolher habilidade
     * * Será sobrescrita pelas classes concretas 
     * * Responsável por verificar a posição da habilidade no vetor _habilidades em inventarioHabilidade
     * * Executa a ação dessa habilidade para checar se é cura, dano ou mudança de estado
     * @param posicaoHabilidade índice (posição) da Habilidade no vetor _habilidades em inventaroHabilidade
     * @return inteiro que diz qual o dano, cura ou mudança de estado.
     */

        virtual int escolherHabilidade(int posicaoHabilidade) = 0;

    /**
     * @brief Função virtual de alterar a vida
     * * Responsável por alterar a vida da própria entidade
     * * Altera o valor de _vida
     * @param valor Em quanto a vida vai mudar [negativo ou positivo]
     */
        virtual void alterarVida(int valor) = 0;
    
    /** 
     * @brief Função virtual de verificar se está vivo
     * * Responsável por verificar se a vida do personagem esta maior ou igual que 0
     * @return false or true
    */
        virtual bool isMorto() = 0;
    
    /**
     * @brief Função virtual destrutora da Entidade
     * * Destrói a entidade que foi criada anteriormente
     * * É virtual para evitar vazamento de memória para que a entidade concreta consiga deletar tudo
     */
        virtual ~Entidade();
};


#endif 

