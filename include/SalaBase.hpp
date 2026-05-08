#ifndef SALABASE_H
#define SALABASE_H

#include <iostream>
#include <string>

/**
 * @brief Classe base abstrata que representa uma sala genérica.
 * * Define a interface padrão e os atributos básicos que todas as 
 * salas específicas devem herdar e implementar.
 */
class SalaBase {
    protected:
        /** * @brief Nome ou identificador da sala. 
         */
        std::string _nome;

        /**
         * @brief Construtor da classe SalaBase.
         * @param nome O nome que será atribuído à sala.
         */
        SalaBase(std::string nome);

    public:
        /**
         * @brief Encerra a execução ou o contexto da sala atual.
         * Método virtual puro que deve ser implementado pelas classes filhas.
         */
        virtual void encerrarSala() = 0;

        /**
         * @brief Realiza a transição ou o carregamento da próxima sala.
         * Método virtual puro que deve ser implementado pelas classes filhas.
         */
        virtual void proximaSala() = 0;

        /**
         * @brief Exibe as informações, o menu ou o conteúdo da sala na tela.
         * Método virtual puro que deve ser implementado pelas classes filhas.
         */
        virtual void mostrarSala() = 0;

        /**
         * @brief Destrutor virtual.
         * Garante que os recursos das classes derivadas sejam liberados corretamente.
         */
        virtual ~SalaBase();
};

#endif