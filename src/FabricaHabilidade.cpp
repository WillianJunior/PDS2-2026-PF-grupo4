#include "FabricaInimigo.hpp"
#include "FabricaHabilidade.hpp"
#include "Inimigo.hpp"
#include "Habilidade.hpp"
#include "Efeito.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>

namespace FabricaHabilidade{

    Habilidade criarHabilidade(std::string nomeDaHabilidade){
        std::string habilidades = "data/Habilidades.txt";
        std::ifstream arquivo(habilidades);
        Efeito vazio("vazio", 0, 0);

        if(!arquivo.is_open()){
            std::cerr << "Arquivo " << habilidades << " nao encontrado\n";
            return Habilidade("Habilidade Erro", false, 0, false, Efeito("Nenhum", 0, 0));
        }

        std::string habilidade;
        while(std::getline(arquivo, habilidade)){
            std::stringstream corte(habilidade);
            std::string nomeHab, tipoHab, valorHab, alvoHab, efeitoHab;

            std::getline(corte, nomeHab, ';');

            if(nomeHab == nomeDaHabilidade){
                std::getline(corte, tipoHab, ';');
                bool tipo = std::stoi(tipoHab);
                std::getline(corte, valorHab, ';');
                int valor = std::stoi(valorHab);
                std::getline(corte, alvoHab, ';');
                bool alvo = std::stoi(alvoHab);
                std::getline(corte, efeitoHab, ';');
                Efeito efeito = vazio.criarEfeito(efeitoHab);

                arquivo.close();

                return Habilidade(nomeHab, tipo, valor, alvo, efeito);
            }
        }
        arquivo.close();
        return Habilidade("Nao Encontrada", false, 0, false, Efeito("Nenhum", 0, 0));
    }
}