#ifndef ACAO_H
#define ACAO_H

#include "Efeito.hpp"
#include <iostream>
#include <string>

/**
 * @brief Classe base para representar qualquer ação do jogo (como Habilidades ou Itens).
 * * Define os atributos e métodos comuns que todas as ações podem realizar, 
 * como causar dano, curar ou aplicar efeitos de status.
 */
class Acao {
    protected:
    /** @brief Nome da ação. */
        std::string _nome;
        
    /** @brief Define o tipo da ação (ex: true para cura, false para dano). */
        bool _tipo;
        
    /** @brief Valor numérico base da ação (quantidade de dano ou cura). */
        int _valor;
        
    /** @brief O efeito de status que a ação pode aplicar. */
        Efeito _efeito;
        
    /** @brief Define o alvo da ação (ex: true para si mesmo, false para o oponente). */
        bool _alvo;

    public:
    /**
     * @brief Construtor padrão da classe Acao.
     * * Inicializa os atributos básicos que toda ação deve ter.
     * @param nome O nome da ação.
     * @param tipo O tipo da ação (se é de dano ou de cura).
     * @param valor O valor numérico gerado pela ação.
     * @param efeito O efeito de status atrelado a esta ação.
     * @param alvo Quem será afetado pela ação.
     */
        Acao(std::string nome, bool tipo, int valor, Efeito efeito, bool alvo);
        
    /**
     * @brief Calcula ou aplica a alteração de vida baseada na ação.
     * @param alvo O alvo que receberá a alteração de vida.
     * @param valor A quantidade de vida a ser alterada.
     * @return Retorna um valor inteiro representando o resultado final da alteração.
     */
        virtual int alterarVida(bool alvo, int valor);

    /**
     * @brief Aplica o efeito de status no alvo determinado.
     * @param alvo O alvo que sofrerá o efeito.
     * @param efeito O efeito a ser aplicado.
     * @return Retorna um valor inteiro representando o sucesso ou a magnitude da aplicação.
     */
        virtual int aplicarEfeito(bool alvo, Efeito efeito);

    /**
     * @brief Exibe os detalhes da ação (informações da habilidade ou do item).
     */
        virtual void mostrarHabilidade();

    /**
     * @brief Retorna o nome da ação.
     * @return Uma string contendo o nome da habilidade ou item.
     */
        std::string getNome();

    /**
     * @brief Retorna o tipo da ação.
     * @return true se for de um tipo específico (ex: cura), false para outro (ex: dano).
     */
        bool getTipo();

    /**
     * @brief Retorna o valor numérico da ação.
     * @return Inteiro representando a magnitude (quantidade de dano, cura, etc).
     */
        int getValor();

    /**
     * @brief Retorna o alvo da ação.
     * @return true se o alvo for o próprio lançador, false se for o oponente.
     */
        bool getAlvo();

    /**
     * @brief Retorna o efeito atrelado à ação.
     * @return Objeto da classe Efeito associado a esta ação.
     */
        Efeito getEfeito();
        
    /**
     * @brief Destrutor virtual da classe Acao.
     * * Essencial para permitir que as classes filhas (Habilidade, Item) liberem sua memória corretamente.
     */
        virtual ~Acao();
};

#endif