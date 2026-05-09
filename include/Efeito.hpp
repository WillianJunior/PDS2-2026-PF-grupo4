#ifndef EFEITO_H
#define EFEITO_H

#include <iostream>
#include <string>

/**
 * @brief Representa um efeito de status contínuo no jogo.
 * * Responsável por gerenciar condições temporárias (como envenenamento, queimadura ou regeneração) que afetam uma entidade ao longo dos turnos.
 */
class Efeito{
    private:
    /** @brief Nome do efeito (ex: Queimadura, Veneno) */
        std::string _nome;
        
    /** @brief Valor numérico do impacto do efeito (quantidade de dano ou cura por turno) */
        int _valor;
        
    /** @brief Quantidade de turnos que o efeito permanecerá ativo */
        int _duracao;
        
    public:
    /**
     * @brief Construtor padrão de Efeito
     * * Inicializa o efeito definindo seu nome, valor de impacto e sua duração.
     * @param nome O nome do efeito
     * @param valor A quantidade de dano ou cura aplicada a cada turno
     * @param duracao Quantos turnos o efeito vai durar
     */
        Efeito(std::string nome, int valor, int duracao);

    /**
     * @brief Aplica o valor do efeito na entidade
     * * Responsável por executar a alteração de vida baseada no valor numérico durante o turno atual.
     */
        void aplicarEfeito();

    /**
     * @brief Atualiza o tempo de vida restante do efeito
     * * Diminui a duração do efeito toda vez que a rodada é concluída.
     */
        void atualizarDuracao();

    /**
     * @brief Detecta se o efeito chegou ao fim
     * * Checa a duração atual e essa deve chegar a 0 para encerrar o efeito.
     * @return Retorna true se estiver encerrado (duração <= 0), e false caso contrário.
     */
        bool isEncerrado();

    /**
     * @brief Destrutor do objeto Efeito
     * * Garante a limpeza adequada da memória quando o efeito for destruído.
     */
        ~Efeito();
};

#endif