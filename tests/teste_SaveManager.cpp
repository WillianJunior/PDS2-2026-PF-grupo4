#include "doctest.h"
#include "SaveManager.hpp"
#include "Personagem.hpp"
#include "Habilidade.hpp"
#include "Item.hpp"
#include "Efeito.hpp"
#include "SalaCombate.hpp"
#include "SalaEscolha.hpp"
#include "FabricaSC.hpp"
#include "FabricaSE.hpp"
#include <vector>
#include <memory>
#include <cstdio>

TEST_CASE("Teste 01: Testando se o existeSave detecta corretamente quando nao existe arquivo de save") {
    // Deleta o arquivo de save (se ele existir) para simular o primeiro acesso
    std::remove("save.txt");

    // Verifica se ele identifica corretamente que não existe save
    CHECK(SaveManager::existeSave() == false);
}

TEST_CASE("Teste 02: Tentar carregar o save, sem existir, e ver se não quebra o jogo") {
    std::remove("save.txt");

    int contador = 0;
    std::vector<std::unique_ptr<SalaBase>> salas;
    std::unique_ptr<Personagem> personagemTeste = SaveManager::carregar(contador, salas);
    
    CHECK(personagemTeste == nullptr);
}

TEST_CASE("Teste 03: Salvar e Carregar dados completos") {
    std::remove("save.txt"); // Garante ambiente limpo

    // Cria um personagem
    Personagem personagemTeste(100, InventarioHabilidade(), "Maycon", InventarioItem());

    std::ostringstream bufferSaida;
    std::streambuf* coutAntigo = std::cout.rdbuf(bufferSaida.rdbuf());
    
    // Adiciona uma habilidade
    Efeito efeitoTesteHabilidade("Efeito Teste Habilidade", 20, 2);
    Habilidade habilidadeTeste("Habilidade Teste", true, 20, true, efeitoTesteHabilidade, 3);
    personagemTeste.receberHabilidade(habilidadeTeste);

    // Adiciona um item
    Efeito efeitoTesteItem("Efeito Teste Item", 50, 1);
    Item itemTeste("Item Teste", true, 50, efeitoTesteItem, true, 2);
    personagemTeste.receberItem(itemTeste);

    std::cout.rdbuf(coutAntigo);

    // Prepara uma sequencia de Salas
    std::vector<std::unique_ptr<SalaBase>> salas;
    salas.push_back(FabricaSC::criarSalas("Maycon", 1));
    salas.push_back(std::unique_ptr<SalaBase>(new SalaEscolha(FabricaSE::criarSalas("Maycon", 1))));

    // Salva o jogo no andar = 5
    SaveManager::salvar(5, personagemTeste, salas);

    // Verifica se o arquivo de save foi criado com sucesso
    CHECK(SaveManager::existeSave() == true);

    // Carrega o jogo salvo em variaveis novas para checagem
    int contadorSalasCarregado = 0;
    std::vector<std::unique_ptr<SalaBase>> salasCarregadas;
    
    std::unique_ptr<Personagem> personagemTesteCarregado = SaveManager::carregar(contadorSalasCarregado, salasCarregadas);

    // Verifica as integridades estruturais
    REQUIRE(personagemTesteCarregado != nullptr);
    CHECK(contadorSalasCarregado == 5);
    CHECK(personagemTesteCarregado->getNome() == "Maycon");
    CHECK(personagemTesteCarregado->getVidaMaxima() == 100);
    
    // Verifica inventarios
    CHECK(personagemTesteCarregado->getInventarioHabilidade().getTamanho() == 1);
    CHECK(personagemTesteCarregado->getInventarioItem().getTamanho() == 1);
    
    // Verifica atributos internos salvos e carregados
    CHECK(personagemTesteCarregado->getInventarioHabilidade().getHabilidade(0).getNome() == "Habilidade Teste");
    CHECK(personagemTesteCarregado->getInventarioItem().getItem(0).getNome() == "Item Teste");

    // Verifica sala (o SaveManager preenche o vetor com "nullptrs" de acordo com o andar atual), se estavamos no andar 5, o jogo preenche 5 nulos, e depois insere as 2 salas salvas no vetor. Total = 7
    CHECK(salasCarregadas.size() == 7);
    
    // Limpa o arquivo de save
    std::remove("save.txt");
}