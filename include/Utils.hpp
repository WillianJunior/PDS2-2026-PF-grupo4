#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <vector>

namespace Utils {
    void coutTempo(std::string texto, int milisegundos = 55);
    void limparTela(); // essa vai ser usada para mudança de sala e vai limpar tudo
    void limparTelaAnima(); // essa vai fazer o cursor voltar pra linha 1 e vai gerar uma especie de "animação"
    void esperar(int milissegundos); // pra esperar né caba nao é de ferro
    extern bool modoTeste;

    struct Animacao {
        std::vector<std::string> textoInicial;
        std::vector<std::string> frames;
        std::vector<std::string> textoFinal;
        int tempoFrame = 200;
    };

    class coutDigitado {
    private:
        std::ostringstream buffer;
        int _tempo;
    public:
        coutDigitado(int tempo = 55) : _tempo(tempo) {}
        template <typename T>
        coutDigitado& operator<<(const T& valor) {
            buffer << valor;
            return *this;
        }
        ~coutDigitado() {
            coutTempo(buffer.str(), _tempo);
        }
    };

}

#endif