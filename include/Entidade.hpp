#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "InventarioHabilidade.hpp"
#include "Efeito.hpp"
#include <iostream>
#include <vector>
#include "Utils.hpp"

/** * @brief Classe abstrata para representar as entidades
 * * Na hierarquia é a mãe de Personagem e Inimigo.
 * * Criará métodos virtuais que serão sobrescritos pelas classes mais complexas.
*/
class Entidade{
    protected:
    /** @brief Atributo medidor de saúde da entidade, chegar a 0 gera morte */
        int _vida;

    /** @brief Nome da entidade */
        std::string _nome;
        
    /** @brief Lista de habilidades que a entidade possui */
        InventarioHabilidade _inventarioHabilidade;

    /** @brief Lista de efeitos temporarios que estao agindo na entidade */
        std::vector<Efeito> _efeitosAtivos;

    public: 
    /**
     * @brief Construtor padrão de entidade 
     * Aloca vida, nome e habilidades de entidade
     * @param vida Quantidade de vida que a entidade possui
     * @param nome Nome da entidade
     * @param inventarioHabilidade Inventário de habilidades da entidade
     */
        Entidade(int vida, std::string nome, InventarioHabilidade inventarioHabilidade);

    /**
     * @brief Função virtual de escolher habilidade
     * * Será sobrescrita pelas classes concretas 
     * * Responsável por verificar a posição da habilidade no vetor e retorna-la
     * @param posicaoHabilidade índice (posição) da Habilidade no vetor _habilidades em inventaroHabilidade
     * @return Retorna a copia do objeto Habilidade.
     */
        virtual Habilidade& escolherHabilidade(int posicaoHabilidade) = 0;

    /**
     * @brief Função virtual de alterar a vida
     * * Responsável por alterar a vida da própria entidade
     * * Altera o valor de _vida
     * @param valor Em quanto a vida vai mudar [negativo ou positivo]
     */
        virtual void alterarVida(int valor) = 0;
    
    /** * @brief Função virtual de verificar se está vivo
     * * Responsável por verificar se a vida do personagem esta maior ou igual que 0
     * @return false or true
    */
        virtual bool isMorto() = 0;

    /**
     * @brief Adiciona um novo efeito na lista de efeitos ativos
     * @param novoEfeito O Efeito que vai afetar a entidade
     */
        void receberEfeito(Efeito novoEfeito);

    /**
     * @brief Itera sobre os efeitos ativos aplicando eles e diminuindo a duracao deles
     */
        void processarEfeitosAtivos();

    /**
     * @brief Limpa os efeitos
     */
        void limparEfeitos();

    /**
     * @brief Retorna a vida atual da entidade.
     */
        int getVida();

    /**
     * @brief Retorna o nome da entidade.
     */
        std::string getNome();

    /**
     * @brief Retorna o inventário de habilidades.
     */
        InventarioHabilidade& getInventarioHabilidade();
    
    /**
     * @brief Função virtual destrutora da Entidade
     * * Destrói a entidade que foi criada anteriormente
     * * É virtual para evitar vazamento de memória para que a entidade concreta consiga deletar tudo
     */
        virtual ~Entidade();
};

#endif