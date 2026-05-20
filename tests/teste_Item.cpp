#include "doctest.h"
#include "Item.hpp"
#include "Efeito.hpp"
#include <string>
// nome alvo valor efeito

TEST_CASE("TESTE DE CONSTRUCAO DE ITEM + GETTER (FARINHA DE MANDIOCA)"){
    std::string nomeTeste = "Farinha de mandioca";
    bool alvoTeste = true;
    bool tipoTeste = true;
    int valorTeste = 50;
    Efeito efeitoTeste = Efeito("Envenenado", 10, 3);
    Item itemTeste(nomeTeste, tipoTeste, valorTeste, efeitoTeste, alvoTeste);

    CHECK(itemTeste.getNome() == nomeTeste);
    CHECK(itemTeste.getValor() == valorTeste);
    CHECK(itemTeste.getEfeito() == efeitoTeste);
    CHECK(itemTeste.getAlvo() == alvoTeste);
    CHECK(itemTeste.getTipo() == tipoTeste);
}

TEST_CASE("TESTE DE ITEM FUNCAO alterarVida"){
    Item itemTeste("nomeTeste", true, 10, Efeito("Envenenado", 10, 2), true);
    int teste = itemTeste.alterarVida(itemTeste.getAlvo(), itemTeste.getValor());
    CHECK(teste == 0);
}

TEST_CASE("TESTE DE ITEM FUNCAO aplicarEfeito"){
    Item itemTeste("nomeTeste", true, 10, Efeito("Envenenado", 10, 2), true);
    int teste = itemTeste.aplicarEfeito(itemTeste.getAlvo(), itemTeste.getEfeito());
    CHECK(teste == 0);
}

TEST_CASE("TESTE DE ITEM FUNCAO mostrarHabilidade"){
    Item itemTeste("nomeTeste", true, 10, Efeito("Envenenado", 10, 2), true);
    itemTeste.mostrarHabilidade();
    // NÃO POSSUI TESTE, FUNÇÃO VOID QUE IMPRIME E EXECUTA AÇÕES SEM RETORNO.
}


