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

namespace FabricaInimigo{
    std::unique_ptr<Inimigo> criarInimigo(std::string nomePersonagem){
        //abrir arquivo txt dos inimigos dependendo do personagem
        std::string inimigos = "data/Inimigos_" + nomePersonagem + ".txt";
        std::ifstream arquivo(inimigos);

        //se der erro e o arquivo n existir
        if(!arquivo.is_open()){
            std::cerr << "Arquivo" << inimigos << "não encontrado, gerando inimigo genérico:";

            Efeito semEfeito("Vazio", 0, 0);
            Habilidade semHab("Vazio", false, 0, false, semEfeito);
            InventarioHabilidade semInv;
            semInv.novaAcao(semHab);

            
            return std::unique_ptr<Inimigo>(new Inimigo(80, semInv, "sem arquivo"));

        }
        //linha
        std::string inimigo;
        while(std::getline(arquivo, inimigo)){
            //para partir a linha atual
            std::stringstream corte(inimigo);
            std::string pedaco;

            //vai pegar a primeira parte ate o primeiro ';' para ver o andar
            std::getline(corte, pedaco, ';');
            int ordem = std::stoi(pedaco);

            if(ordem == contador){
                //dados do inimigo:
                std::string nomeInimigo;
                std::getline(corte, nomeInimigo, ';');

                std::getline(corte, pedaco, ';');
                int vidaInimigo = std::stoi(pedaco);

                //lista de habilidades separadas 
                std::string listaHabilidades;
                std::getline(corte, listaHabilidades, ';');

                InventarioHabilidade inventarioInimigo;
                std::stringstream cortesDeHabilidades(listaHabilidades);
                std::string nomeHab;

                while(std::getline(cortesDeHabilidades, nomeHab, ',')){
                    Habilidade habilidade = FabricaHabilidade::criarHabilidade(nomeHab);
                    inventarioInimigo.novaAcao(habilidade);
                }

                
                arquivo.close();
                contador++; 
                
                return std::unique_ptr<Inimigo>(new Inimigo(vidaInimigo, inventarioInimigo, nomeInimigo));
            }
        }
        arquivo.close();
        Efeito semEfeito("Vazio", 0, 0);
        Habilidade semHab("Vazio", false, 0, false, semEfeito);
        InventarioHabilidade semInv;
        semInv.novaAcao(semHab);
        return std::unique_ptr<Inimigo>(new Inimigo(80, semInv, "Inimigo nao encontrado"));
    }
}