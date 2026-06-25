#include "doctest.h"
#include "InventarioItem.hpp"
#include "Item.hpp"
#include "Efeito.hpp"
#include <sstream>

TEST_CASE("Teste 01: Adiciona um item ao inventario e o exibe"){
    Efeito efeitoTeste = Efeito("EfeitoTeste", 15, 3);
    Item itemTeste = Item("ItemTeste", false, 15, efeitoTeste, false, 1);

    InventarioItem inventarioItem;

    inventarioItem.novaAcao(itemTeste);

    std::streambuf* coutOriginal = std::cout.rdbuf();

    std::ostringstream bufferInterno;

    std::cout.rdbuf(bufferInterno.rdbuf());

    inventarioItem.mostrarInventario();
    
    std::cout.rdbuf(coutOriginal);

    CHECK(bufferInterno.str().find("ItemTeste") != std::string::npos);
}

TEST_CASE("Teste 02: Realiza a troca de um item por outro e exibe o inventario"){
    Efeito efeito1 = Efeito("Efeito1", 4, 1);
    Efeito efeito2 = Efeito("Efeito2", 3, 2);
    Efeito efeito3 = Efeito("Efeito3", 2, 3);
    Efeito efeito4 = Efeito("Efeito4", 1, 4);
    Item item1 = Item("Item1", true, 4, efeito1, true, 1);
    Item item2 = Item("Item2", true, 3, efeito2, false, 1);
    Item item3 = Item("Item3", false, 2, efeito3, true, 1);
    Item item4 = Item("Item4", false, 1, efeito4, false, 1);

    InventarioItem inventarioItem;

    inventarioItem.novaAcao(item1);
    inventarioItem.novaAcao(item2);
    inventarioItem.novaAcao(item3);

    inventarioItem.trocarAcao(1, item4);

    std::streambuf* coutOriginal = std::cout.rdbuf();

    std::ostringstream bufferInterno;

    std::cout.rdbuf(bufferInterno.rdbuf());

    inventarioItem.mostrarInventario();
    
    std::cout.rdbuf(coutOriginal);

    CHECK(bufferInterno.str().find("Item1") != std::string::npos);
    CHECK(bufferInterno.str().find("Item4") != std::string::npos);
    CHECK(bufferInterno.str().find("Item3") != std::string::npos);
}

TEST_CASE("Teste 03: Adiciona um item ao inventario e veirifca o tamanho dele"){
    Efeito efeitoTeste = Efeito("EfeitoTeste", 15, 3);
    Item itemTeste = Item("ItemTeste", false, 15, efeitoTeste, false, 1);

    InventarioItem inventarioItem;

    inventarioItem.novaAcao(itemTeste);

    CHECK(inventarioItem.getTamanho() == 1);
}

TEST_CASE("Teste 04: Cria um inventario de itens de teste e busca um item especifico pela posicao"){
    Efeito efeito1 = Efeito("Efeito1", 4, 1);
    Efeito efeito2 = Efeito("Efeito2", 3, 2);
    Item item1 = Item("Item1", true, 4, efeito1, true, 1);
    Item item2 = Item("Item2", true, 3, efeito2, false, 1);

    InventarioItem inventarioItem;

    inventarioItem.novaAcao(item1);
    inventarioItem.novaAcao(item2);

    CHECK(inventarioItem.getItem(1) == item2);
}

TEST_CASE("Teste 05: Cria dois inventarios de itens iguais e verifica se sao iguais, faz o mesmo para dois inventarios diferentes"){
    Efeito efeito1 = Efeito("Efeito1", 4, 1);
    Efeito efeito2 = Efeito("Efeito2", 3, 2);
    Efeito efeito3 = Efeito("Efeito3", 2, 3);
    Efeito efeito4 = Efeito("Efeito4", 1, 4);
    Item item1 = Item("Item1", true, 4, efeito1, true, 1);
    Item item2 = Item("Item2", true, 3, efeito2, false, 1);
    Item item3 = Item("Item3", false, 2, efeito3, true, 1);
    Item item4 = Item("Item4", false, 1, efeito4, false, 1);

    InventarioItem inventarioItem1;
    InventarioItem inventarioItem2;
    InventarioItem inventarioItem3;
    InventarioItem inventarioItem4;

    inventarioItem1.novaAcao(item1);
    inventarioItem1.novaAcao(item2);
    inventarioItem2.novaAcao(item1);
    inventarioItem2.novaAcao(item2);
    inventarioItem3.novaAcao(item3);
    inventarioItem4.novaAcao(item4);

    CHECK(inventarioItem1 == inventarioItem2);
    CHECK(inventarioItem3 != inventarioItem4);
}

TEST_CASE("Teste 06: Cria um inventario de itens de teste, remove uma acao e verifica se foi removida exibindo o inventario"){
    Efeito efeito1 = Efeito("Efeito1", 4, 1);
    Efeito efeito2 = Efeito("Efeito2", 3, 2);
    Efeito efeito3 = Efeito("Efeito3", 2, 3);
    Item item1 = Item("Item1", true, 4, efeito1, true, 1);
    Item item2 = Item("Item2", true, 3, efeito2, false, 1);
    Item item3 = Item("Item3", false, 2, efeito3, true, 1);

    InventarioItem inventarioItem;

    inventarioItem.novaAcao(item1);
    inventarioItem.novaAcao(item2);
    inventarioItem.novaAcao(item3);

    inventarioItem.descartarAcao(1);

    std::streambuf* coutOriginal = std::cout.rdbuf();

    std::ostringstream bufferInterno;

    std::cout.rdbuf(bufferInterno.rdbuf());

    inventarioItem.mostrarInventario();
    
    std::cout.rdbuf(coutOriginal);

    CHECK(bufferInterno.str().find("Item1") != std::string::npos);
    CHECK(bufferInterno.str().find("Item3") != std::string::npos);
}