#ifndef EXCECOES_HPP
#define EXCECOES_HPP

#include <exception>
#include <string>

/**
 * @brief Classe base de todas as execeções
 */
class RPGException : public std::exception {
protected:
    std::string _mensagem;
public:
    explicit RPGException(const std::string& msg) : _mensagem(msg) {}
    virtual const char* what() const noexcept override {
        return _mensagem.c_str();
    }
};

/**
 * @brief Lançada quando o jogador tenta acessar um indice fora dos limites
 */
class IndiceInvalidoException : public RPGException {
public:
    IndiceInvalidoException() : RPGException("Erro: Indice nao existe no inventario.") {}
};

/**
 * @brief Lançada quando ocorre uma falha na leitura da entrada
 */
class EntradaInvalidaException : public RPGException {
public:
    EntradaInvalidaException() : RPGException("Erro: Entrada invalida") {}
};

#endif