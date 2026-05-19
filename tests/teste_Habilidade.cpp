#include "doctest.h"
#include "Habilidade.hpp"

// Os TEST_CASEs serão escritos aqui
TEST_CASE("Testando a inicializacao e atributos de Habilidade"){
    std::string nome_teste = "habilidade_teste";
    bool tipo_teste = false;
    int valor_teste = 30;
    bool alvo_teste = false;
    Efeito efeito_teste("Sem_efeito", 0, 0);
    Acao acaoTeste(nome_teste, true, 30, efeito_teste, alvo_teste);
    Habilidade habilidade_teste(nome_teste, tipo_teste, valor_teste, alvo_teste, efeito_teste);
    CHECK(acaoTeste.getNome() == nome_teste);
    CHECK(habilidade_teste.getNome() == nome_teste);
    CHECK(habilidade_teste.getTipo() == tipo_teste);
    CHECK(habilidade_teste.getValor() == valor_teste);
    CHECK(habilidade_teste.getAlvo() == alvo_teste);
}