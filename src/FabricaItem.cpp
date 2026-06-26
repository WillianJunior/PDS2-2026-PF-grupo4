#include "FabricaItem.hpp"
#include "Item.hpp"
#include "Efeito.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

namespace FabricaItem{

    Item criarItem (std::string nomeItem){
        std::string itens = "data/Itens.txt";
        std::ifstream arquivo(itens);
        Efeito vazio("Nenhum", 0 ,0);

        if(!arquivo.is_open()){
            std::cerr << "Arquivo " << itens << " não encontrado\n";
            return Item("Item Erro", 0, 0, Efeito("Nenhum", 0, 0), 0, 1);
        }

        std::string item;
        while(std::getline(arquivo, item)){
            std::stringstream corte(item);
            std::string nomeIt, alvoIt, tipoIt, valorIt, efeitoIt, usosIt;

            std::getline(corte, nomeIt, ';');

            if(nomeIt == nomeItem){
                std::getline(corte, alvoIt, ';');
                bool alvo = std::stoi(alvoIt);
                std::getline(corte, tipoIt, ';');
                bool tipo = std::stoi(tipoIt);
                std::getline(corte, valorIt, ';');
                int valor = std::stoi(valorIt);
                std::getline(corte, efeitoIt, ';');
                Efeito efeito = vazio.criarEfeito(efeitoIt);
                std::getline(corte, usosIt, ';');
                int usos = std::stoi(usosIt);

                arquivo.close();

                return Item(nomeIt, tipo, valor, efeito, alvo, usos);
            }
        }
    
        arquivo.close();
        return Item("Nao encontrado", 0, 0, vazio, 0, 1);
    }
}
   

