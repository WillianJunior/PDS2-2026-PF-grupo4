#include "doctest.h"
#include "InventarioHabilidade.hpp"
#include "Habilidade.hpp"
#include "Efeito.hpp"
#include <sstream>

TEST_CASE("Teste 01: Adiciona uma habilidade ao inventario e o exibe"){
    Efeito efeitoTeste = Efeito("EfeitoTeste", 15, 3);
    Habilidade habilidadeTeste = Habilidade("HabilidadeTeste", false, 15, false, efeitoTeste, 0);

    InventarioHabilidade inventarioHabilidade;

    inventarioHabilidade.novaAcao(habilidadeTeste);

    std::streambuf* coutOriginal = std::cout.rdbuf();

    std::ostringstream bufferInterno;

    std::cout.rdbuf(bufferInterno.rdbuf());

    inventarioHabilidade.mostrarInventario();
    
    std::cout.rdbuf(coutOriginal);

    CHECK(bufferInterno.str() == "1. HabilidadeTeste\n");
}

TEST_CASE("Teste 02: Realiza a troca de uma habilidade por outra e exibe o inventario"){
    Efeito efeito1 = Efeito("Efeito1", 4, 1);
    Efeito efeito2 = Efeito("Efeito2", 3, 2);
    Efeito efeito3 = Efeito("Efeito3", 2, 3);
    Efeito efeito4 = Efeito("Efeito4", 1, 4);
    Habilidade habilidade1 = Habilidade("Habilidade1", true, 4, true, efeito1, 0);
    Habilidade habilidade2 = Habilidade("Habilidade2", true, 3, false, efeito2, 0);
    Habilidade habilidade3 = Habilidade("Habilidade3", false, 2, true, efeito3, 0);
    Habilidade habilidade4 = Habilidade("Habilidade4", false, 1, false, efeito4, 0);

    InventarioHabilidade inventarioHabilidade;

    inventarioHabilidade.novaAcao(habilidade1);
    inventarioHabilidade.novaAcao(habilidade2);
    inventarioHabilidade.novaAcao(habilidade3);

    inventarioHabilidade.trocarAcao(1, habilidade4);

    std::streambuf* coutOriginal = std::cout.rdbuf();

    std::ostringstream bufferInterno;

    std::cout.rdbuf(bufferInterno.rdbuf());

    inventarioHabilidade.mostrarInventario();
    
    std::cout.rdbuf(coutOriginal);

    CHECK(bufferInterno.str() == "1. Habilidade1\n2. Habilidade4\n3. Habilidade3\n");
}

TEST_CASE("Teste 03: Adiciona uma habilidade ao inventario e veirifca o tamanho dele"){
    Efeito efeitoTeste = Efeito("EfeitoTeste", 15, 3);
    Habilidade habilidadeTeste = Habilidade("HabilidadeTeste", false, 15, false, efeitoTeste, 0);

    InventarioHabilidade inventarioHabilidade;

    inventarioHabilidade.novaAcao(habilidadeTeste);

    CHECK(inventarioHabilidade.getTamanho() == 1);
}

TEST_CASE("Teste 04: Cria um inventario de habilidades de teste e busca uma habilidade especifica pela posicao"){
    Efeito efeito1 = Efeito("Efeito1", 4, 1);
    Efeito efeito2 = Efeito("Efeito2", 3, 2);
    Habilidade habilidade1 = Habilidade("Habilidade1", true, 4, true, efeito1, 0);
    Habilidade habilidade2 = Habilidade("Habilidade2", true, 3, false, efeito2, 0);

    InventarioHabilidade inventarioHabilidade;

    inventarioHabilidade.novaAcao(habilidade1);
    inventarioHabilidade.novaAcao(habilidade2);

    CHECK(inventarioHabilidade.getHabilidade(1) == habilidade2);
}

TEST_CASE("Teste 05: Cria dois inventarios de habilidades iguais e verifica se sao iguais, faz o mesmo para dois inventarios diferentes"){
    Efeito efeito1 = Efeito("Efeito1", 4, 1);
    Efeito efeito2 = Efeito("Efeito2", 3, 2);
    Efeito efeito3 = Efeito("Efeito3", 2, 3);
    Efeito efeito4 = Efeito("Efeito4", 1, 4);
    Habilidade habilidade1 = Habilidade("Habilidade1", true, 4, true, efeito1, 0);
    Habilidade habilidade2 = Habilidade("Habilidade2", true, 3, false, efeito2, 0);
    Habilidade habilidade3 = Habilidade("Habilidade3", false, 2, true, efeito3, 0);
    Habilidade habilidade4 = Habilidade("Habilidade4", false, 1, false, efeito4, 0);

    InventarioHabilidade inventarioHabilidade1;
    InventarioHabilidade inventarioHabilidade2;
    InventarioHabilidade inventarioHabilidade3;
    InventarioHabilidade inventarioHabilidade4;

    inventarioHabilidade1.novaAcao(habilidade1);
    inventarioHabilidade1.novaAcao(habilidade2);
    inventarioHabilidade2.novaAcao(habilidade1);
    inventarioHabilidade2.novaAcao(habilidade2);
    inventarioHabilidade3.novaAcao(habilidade3);
    inventarioHabilidade4.novaAcao(habilidade4);

    CHECK(inventarioHabilidade1 == inventarioHabilidade2);
    CHECK(inventarioHabilidade3 != inventarioHabilidade4);
}

TEST_CASE("Teste 06: Cria um inventario de habilidades de teste, remove uma acao e verifica se foi removida exibindo o inventario"){
    Efeito efeito1 = Efeito("Efeito1", 4, 1);
    Efeito efeito2 = Efeito("Efeito2", 3, 2);
    Efeito efeito3 = Efeito("Efeito3", 2, 3);
    Habilidade habilidade1 = Habilidade("Habilidade1", true, 4, true, efeito1, 0);
    Habilidade habilidade2 = Habilidade("Habilidade2", true, 3, false, efeito2, 0);
    Habilidade habilidade3 = Habilidade("Habilidade3", false, 2, true, efeito3, 0);

    InventarioHabilidade inventarioHabilidade;

    inventarioHabilidade.novaAcao(habilidade1);
    inventarioHabilidade.novaAcao(habilidade2);
    inventarioHabilidade.novaAcao(habilidade3);

    inventarioHabilidade.descartarAcao(1);

    std::streambuf* coutOriginal = std::cout.rdbuf();

    std::ostringstream bufferInterno;

    std::cout.rdbuf(bufferInterno.rdbuf());

    inventarioHabilidade.mostrarInventario();
    
    std::cout.rdbuf(coutOriginal);

    CHECK(bufferInterno.str() == "1. Habilidade1\n2. Habilidade3\n");
}