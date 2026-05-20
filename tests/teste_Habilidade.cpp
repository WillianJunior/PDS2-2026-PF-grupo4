#include "doctest.h"
#include "Habilidade.hpp"

TEST_CASE("Testando a inicializacao e atributos de Habilidade") {
    Habilidade habilidade_teste("habilidade_teste", false, 30, false, Efeito("Sem_efeito", 0, 0));
    
    CHECK(habilidade_teste.getNome() == "habilidade_teste");
    CHECK(habilidade_teste.getTipo() == false);
    CHECK(habilidade_teste.getValor() == 30);
    CHECK(habilidade_teste.getAlvo() == false);
}

TEST_CASE("Testando a funcao alterarVida em Habilidade") {
    Habilidade habilidade_teste("Bola de Fogo", false, 50, true, Efeito("Queimadura", 5, 2));
    int teste_vida = habilidade_teste.alterarVida(habilidade_teste.getAlvo(), habilidade_teste.getValor());
    
    CHECK(teste_vida == 0); 
}

TEST_CASE("Testando a funcao aplicarEfeito em Habilidade") {
    Habilidade habilidade_teste("Bola de Fogo", false, 50, true, Efeito("Queimadura", 5, 2));
    int teste_efeito = habilidade_teste.aplicarEfeito(habilidade_teste.getAlvo(), habilidade_teste.getEfeito());
    
    CHECK(teste_efeito == 0);
}

TEST_CASE("Testando a funcao mostrarHabilidade em Habilidade (Cobertura)") {
    Habilidade habilidade_teste("Bola de Fogo", false, 50, true, Efeito("Queimadura", 5, 2));
    habilidade_teste.mostrarHabilidade();
    //Nao possui CHECK, apenas para cobertura do código
}