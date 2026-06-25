#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <vector>

/**
 * @brief Namespace contendo funções utilitárias de formatação de texto, tempo e interface.
 */
namespace Utils {
    /**
     * @brief Imprime um texto na tela caractere por caractere, gerando efeito de digitação.
     * @param texto O texto que será impresso.
     * @param milisegundos Tempo de espera em milissegundos entre cada caractere.
     */
    void coutTempo(std::string texto, int milisegundos = 55);

    /**
     * @brief Limpa completamente a tela do terminal.
     */
    void limparTela(); // essa vai ser usada para mudança de sala e vai limpar tudo

    /**
     * @brief Move o cursor de volta para a primeira linha do terminal para sobrescrever quadros de animação.
     */
    void limparTelaAnima(); // essa vai fazer o cursor voltar pra linha 1 e vai gerar uma especie de "animação"

    /**
     * @brief Pausa a execução do programa por um determinado tempo.
     * @param milissegundos Tempo de pausa em milissegundos.
     */
    void esperar(int milissegundos); // pra esperar né caba nao é de ferro

    /** @brief Define se está acontecendo os testes (quando true, desativa comportamentos que atrapaham os testes (ex: tempo de escrita)). */
    extern bool modoTeste;

    /**
    * @brief Estrutura que armazena os quadros e textos de uma animação em ASCII.
    */
    struct Animacao {
        /** @brief Linhas de texto exibidas antes da animação começar. */
        std::vector<std::string> textoInicial;

        /** @brief Vetor contendo os quadros (frames) da animação em sequência. */
        std::vector<std::string> frames;

        /** @brief Linhas de texto exibidas após o término da animação. */
        std::vector<std::string> textoFinal;

        /** @brief Duração de cada quadro da animação em milissegundos. */
        int tempoFrame = 200;
    };

    /**
     * @brief Classe utilitária que acumula o que deve ser imprimido e imprime com efeito de digitação ao ser destruída.
     */
    class coutDigitado {
        private:
        /** @brief Buffer interno que armazena o que deverá ser impresso. */
            std::ostringstream buffer;

        /** @brief Tempo de atraso entre cada caractere na impressão final. */
            int _tempo;
        public:
        /**
         * @brief Construtor da classe coutDigitado.
         * @param tempo Tempo em milissegundos por caractere (padrão: 75ms).
         */
            coutDigitado(int tempo = 75) : _tempo(tempo) {}

        /**
         * @brief Sobrecarga do operador de inserção para acumular dados no buffer.
         * @tparam T Tipo do dado a ser inserido.
         * @param valor O valor a ser adicionado ao buffer.
         * @return Referência para o próprio objeto coutDigitado.
         */
            template <typename T>
            coutDigitado& operator<<(const T& valor) {
                buffer << valor;
                return *this;
            }

        /**
         * @brief Destrutor que descarrega o conteúdo do buffer na tela chamando `coutTempo`.
         */
            ~coutDigitado() {
                coutTempo(buffer.str(), _tempo);
            }
    };

}

#endif