#include "FabricaSC.hpp"
#include "Inimigo.hpp"
#include "Habilidade.hpp"
#include "Efeito.hpp"
#include <vector>
#include <cstdlib>

namespace FabricaSC {
    std::unique_ptr<SalaCombate> criarSalas(std::string nome, int andar) {
        std::vector<std::unique_ptr<SalaCombate>> salas;
        std::string tituloAndar = "Andar " + std::to_string(andar);

        if (nome == "Maycon") {
            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", nome, andar)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", nome, andar)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", nome, andar)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", nome, andar)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", nome, andar)));

            

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Vaz") {
            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", nome)));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Isaque") {
            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", nome)));


            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", nome)));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Nicole") {
            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", nome)));

           
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", nome)));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Marcos") {
            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", nome)));

            
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", nome)));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else {
            std::string historia = "CRITICAL ERROR: Memória violada. O Guardião do Ponteiro Nulo desperta!";
            
            return std::unique_ptr<SalaCombate>(new SalaCombate("SALA SEGFAULT", historia, nome));
        }
    }
}