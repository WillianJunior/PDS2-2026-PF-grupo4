#include "FabricaItem.hpp"
#include "Item.hpp"
#include "Efeito.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>

namespace FabricaItem{

    Item CriarItem (std::string nomeItem){
        std::string itens = "data/Itens.txt";
        std::ifstream arquivo(itens);
        Efeito vazio("vazio", 0 ,0);

        if(!arquivo.is_open()){
            std::cerr << "Arquivo " << itens << " não encontrado\n";
            return Item("Item Erro", 0, 0, Efeito("Nenhum", 0, 0), 0);
        }

        std::string item;
        while(std::getline(arquivo, item)){
            std::stringstream corte(item);
            std::string nomeIt, alvoIt, tipoIt, valorIt, efeitoIt;

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

                arquivo.close();

                return Item(nomeIt, tipo, valor, efeito, alvo);
            }
        }
    
        arquivo.close();
        return Item("Não encontrado", 0, 0, vazio, 0);
    }
}
   

