#include "doctest.h"
#include "Menu.hpp"

// Os TEST_CASEs serão escritos aqui
TEST_CASE("TESTE DE CONSTRUCAO DO MENU") {
    Menu menuTeste;
    CHECK(true); 
}

TEST_CASE("TESTE DE MENU FUNCAO iniciarJogo") {
    Menu menuTeste;
    menuTeste.iniciarJogo();
    // NÃO POSSUI TESTE, FUNÇÃO VOID QUE IMPRIME E EXECUTA AÇÕES SEM RETORNO
}

TEST_CASE("TESTE DE MENU FUNCAO escolherPersonagemInicial") {
    Menu menuTeste;
    menuTeste.escolherPersonagemInicial();
    // NÃO POSSUI TESTE, FUNÇÃO VOID QUE IMPRIME E EXECUTA AÇÕES SEM RETORNO
}