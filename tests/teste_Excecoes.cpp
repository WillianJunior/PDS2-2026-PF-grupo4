#include "doctest.h"
#include "Excecoes.hpp"
#include <string>

TEST_CASE("Teste 01: Verificando lancamento e mensagem de IndiceInvalidoException") {
    // Verifica se a excecao pode ser capturada por ela mesma e pela classe mãe (RPGException)
    CHECK_THROWS_AS(throw IndiceInvalidoException(), IndiceInvalidoException);
    CHECK_THROWS_AS(throw IndiceInvalidoException(), RPGException);
    CHECK_THROWS_AS(throw IndiceInvalidoException(), std::exception);

    // Captura manualmente para testar a execucao da funcao .what()
    try {
        throw IndiceInvalidoException();
    } catch (const std::exception& e) {
        CHECK(std::string(e.what()) == "Erro: Indice nao existe no inventario.");
    }
}

TEST_CASE("Teste 02: Verificando lancamento e mensagem de EntradaInvalidaException") {
    CHECK_THROWS_AS(throw EntradaInvalidaException(), EntradaInvalidaException);
    CHECK_THROWS_AS(throw EntradaInvalidaException(), RPGException);

    try {
        throw EntradaInvalidaException();
    } catch (const std::exception& e) {
        CHECK(std::string(e.what()) == "Erro: Entrada invalida");
    }
}

TEST_CASE("Teste 03: Verificando a classe base RPGException") {
    try {
        throw RPGException("Mensagem de erro teste");
    } catch (const RPGException& e) {
        CHECK(std::string(e.what()) == "Mensagem de erro teste");
    }
}