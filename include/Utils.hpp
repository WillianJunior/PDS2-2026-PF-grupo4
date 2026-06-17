#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>

namespace Utils {
    void coutTempo(std::string texto, int milisegundos = 30);

    class coutDigitado {
    private:
        std::ostringstream buffer;
        int _tempo;
    public:
        coutDigitado(int tempo = 30) : _tempo(tempo) {}
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