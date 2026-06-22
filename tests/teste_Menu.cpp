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
    std::stringstream simulacaoEntrada("2\n\n"); 
    std::streambuf* cinBufferAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());

    // salva o buffer original do std::cin e redireciona pra simulação
    std::stringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf()); 

    // executa a funçãobb deve retornar nullptr
    std::unique_ptr<Personagem> personagemRetornado = menuTeste.executarMenuInicial(false);
    
    CHECK(personagemRetornado == nullptr);

    // restaura o buffer original do std::cin // PLUS: do cout também
    std::cin.rdbuf(cinBufferAntigo);
    std::cout.rdbuf(coutAntigo);
}

TEST_CASE("TESTE DE MENU FUNCAO executarMenuInicial - Escolha de Personagem") {
    Menu menuTeste;

    // Simula duas entradas
    // iniciar Novo Jogo e depois 1 escolher a classe
    std::stringstream simulacaoEntrada("1\n1\n\n\n"); 
    std::streambuf* cinBufferAntigo = std::cin.rdbuf(simulacaoEntrada.rdbuf());

    std::stringstream bufferSaida; // as coisas que iam aparecer na tela param de aparecer pra permitir o teste fluir
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());

    std::unique_ptr<Personagem> personagemRetornado = menuTeste.executarMenuInicial(false);

    std::cin.rdbuf(cinBufferAntigo);
    std::cout.rdbuf(coutAntigo);
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