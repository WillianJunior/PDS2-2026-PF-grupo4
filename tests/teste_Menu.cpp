#include "doctest.h"
#include "Menu.hpp"
#include "Personagem.hpp"
#include <sstream>
#include <iostream>
#include <memory>

TEST_CASE("TESTE DE CONSTRUCAO DO MENU") {
    // Garante que o construtor padrão não lança exceções inesperadas
    REQUIRE_NOTHROW(Menu());
}

TEST_CASE("TESTE DE MENU FUNCAO executarMenuInicial") {
    Menu menuTeste;

    // Simulação de entrada de dados
    std::stringstream simulacaoEntrada;
    simulacaoEntrada << "2\n";

    // salva o buffer original do std::cin e redireciona pra simulação
    std::streambuf* cinBufferAntigo = std::cin.rdbuf();
    std::cin.rdbuf(simulacaoEntrada.rdbuf());

    // executa a funçãobb deve retornar nullptr
    std::unique_ptr<Personagem> personagemRetornado = menuTeste.executarMenuInicial();
    
    CHECK(personagemRetornado == nullptr);

    // restaura o buffer original do std::cin
    std::cin.rdbuf(cinBufferAntigo);
}

TEST_CASE("TESTE DE MENU FUNCAO executarMenuInicial - Escolha de Personagem") {
    Menu menuTeste;

    // Simula duas entradas
    // iniciar Novo Jogo e depois 1 escolher a classe
    std::stringstream simulacaoEntrada;
    simulacaoEntrada << "1\n1\n";

    std::streambuf* cinBufferAntigo = std::cin.rdbuf();
    std::cin.rdbuf(simulacaoEntrada.rdbuf());

    std::unique_ptr<Personagem> personagemRetornado = menuTeste.executarMenuInicial();

    // REQUIRE garante que o ponteiro não é nulo antes de tentar acessar seus métodos
    REQUIRE(personagemRetornado != nullptr); 
    
    // Verifica se os dados da Classe 1 foram injetados corretamente
    CHECK(personagemRetornado->getNome() == "Maycon");
    CHECK(personagemRetornado->getVida() == 120);
    
    // Opcional: Verificar se o inventário não está vazio
    CHECK(personagemRetornado->getInventarioItem().getTamanho() > 0);

    // 3. Restauração do std::cin
    std::cin.rdbuf(cinBufferAntigo);
}