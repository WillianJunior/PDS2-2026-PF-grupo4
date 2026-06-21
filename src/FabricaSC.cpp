#include "FabricaSC.hpp"
#include "Inimigo.hpp"
#include "Habilidade.hpp"
#include "Efeito.hpp"
#include <vector>
#include <cstdlib>

namespace FabricaSC {
    std::unique_ptr<SalaCombate> criarSalas(std::string nome, int andar) {
        std::vector<std::unique_ptr<SalaCombate>> salas;
        InventarioHabilidade habsInimigo;
        Efeito semEfeito("Nenhum", 0, 0);
        Habilidade ataquePadrao("Ataque Generico", false, 15, false, semEfeito);
        habsInimigo.novaAcao(ataquePadrao);
        std::string tituloAndar = "Andar " + std::to_string(andar);

        if (nome == "Maycon") {
            std::unique_ptr<Inimigo> ini1(new Inimigo(80, habsInimigo, "Inimigo 1", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", std::move(ini1))));

            std::unique_ptr<Inimigo> ini2(new Inimigo(80, habsInimigo, "Inimigo 2", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", std::move(ini2))));

            std::unique_ptr<Inimigo> ini3(new Inimigo(80, habsInimigo, "Inimigo 3", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", std::move(ini3))));

            std::unique_ptr<Inimigo> ini4(new Inimigo(80, habsInimigo, "Inimigo 4", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", std::move(ini4))));

            std::unique_ptr<Inimigo> ini5(new Inimigo(80, habsInimigo, "Inimigo 5", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", std::move(ini5))));

            std::unique_ptr<Inimigo> ini6(new Inimigo(80, habsInimigo, "Inimigo 6", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", std::move(ini6))));

            std::unique_ptr<Inimigo> ini7(new Inimigo(80, habsInimigo, "Inimigo 7", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", std::move(ini7))));

            std::unique_ptr<Inimigo> ini8(new Inimigo(80, habsInimigo, "Inimigo 8", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", std::move(ini8))));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Vaz") {
            std::unique_ptr<Inimigo> ini1(new Inimigo(80, habsInimigo, "Inimigo 1", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", std::move(ini1))));

            std::unique_ptr<Inimigo> ini2(new Inimigo(80, habsInimigo, "Inimigo 2", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", std::move(ini2))));

            std::unique_ptr<Inimigo> ini3(new Inimigo(80, habsInimigo, "Inimigo 3", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", std::move(ini3))));

            std::unique_ptr<Inimigo> ini4(new Inimigo(80, habsInimigo, "Inimigo 4", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", std::move(ini4))));

            std::unique_ptr<Inimigo> ini5(new Inimigo(80, habsInimigo, "Inimigo 5", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", std::move(ini5))));

            std::unique_ptr<Inimigo> ini6(new Inimigo(80, habsInimigo, "Inimigo 6", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", std::move(ini6))));

            std::unique_ptr<Inimigo> ini7(new Inimigo(80, habsInimigo, "Inimigo 7", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", std::move(ini7))));

            std::unique_ptr<Inimigo> ini8(new Inimigo(80, habsInimigo, "Inimigo 8", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", std::move(ini8))));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Isaque") {
            std::unique_ptr<Inimigo> ini1(new Inimigo(80, habsInimigo, "Inimigo 1", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", std::move(ini1))));

            std::unique_ptr<Inimigo> ini2(new Inimigo(80, habsInimigo, "Inimigo 2", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", std::move(ini2))));

            std::unique_ptr<Inimigo> ini3(new Inimigo(80, habsInimigo, "Inimigo 3", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", std::move(ini3))));

            std::unique_ptr<Inimigo> ini4(new Inimigo(80, habsInimigo, "Inimigo 4", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", std::move(ini4))));

            std::unique_ptr<Inimigo> ini5(new Inimigo(80, habsInimigo, "Inimigo 5", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", std::move(ini5))));

            std::unique_ptr<Inimigo> ini6(new Inimigo(80, habsInimigo, "Inimigo 6", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", std::move(ini6))));

            std::unique_ptr<Inimigo> ini7(new Inimigo(80, habsInimigo, "Inimigo 7", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", std::move(ini7))));

            std::unique_ptr<Inimigo> ini8(new Inimigo(80, habsInimigo, "Inimigo 8", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", std::move(ini8))));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Nicole") {
            std::unique_ptr<Inimigo> ini1(new Inimigo(80, habsInimigo, "Inimigo 1", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", std::move(ini1))));

            std::unique_ptr<Inimigo> ini2(new Inimigo(80, habsInimigo, "Inimigo 2", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", std::move(ini2))));

            std::unique_ptr<Inimigo> ini3(new Inimigo(80, habsInimigo, "Inimigo 3", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", std::move(ini3))));

            std::unique_ptr<Inimigo> ini4(new Inimigo(80, habsInimigo, "Inimigo 4", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", std::move(ini4))));

            std::unique_ptr<Inimigo> ini5(new Inimigo(80, habsInimigo, "Inimigo 5", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", std::move(ini5))));

            std::unique_ptr<Inimigo> ini6(new Inimigo(80, habsInimigo, "Inimigo 6", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", std::move(ini6))));

            std::unique_ptr<Inimigo> ini7(new Inimigo(80, habsInimigo, "Inimigo 7", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", std::move(ini7))));

            std::unique_ptr<Inimigo> ini8(new Inimigo(80, habsInimigo, "Inimigo 8", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", std::move(ini8))));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Marcos") {
            std::unique_ptr<Inimigo> ini1(new Inimigo(80, habsInimigo, "Inimigo 1", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 1 apareceu!", std::move(ini1))));

            std::unique_ptr<Inimigo> ini2(new Inimigo(80, habsInimigo, "Inimigo 2", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 2 apareceu!", std::move(ini2))));

            std::unique_ptr<Inimigo> ini3(new Inimigo(80, habsInimigo, "Inimigo 3", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 3 apareceu!", std::move(ini3))));

            std::unique_ptr<Inimigo> ini4(new Inimigo(80, habsInimigo, "Inimigo 4", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 4 apareceu!", std::move(ini4))));

            std::unique_ptr<Inimigo> ini5(new Inimigo(80, habsInimigo, "Inimigo 5", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 5 apareceu!", std::move(ini5))));

            std::unique_ptr<Inimigo> ini6(new Inimigo(80, habsInimigo, "Inimigo 6", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 6 apareceu!", std::move(ini6))));

            std::unique_ptr<Inimigo> ini7(new Inimigo(80, habsInimigo, "Inimigo 7", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 7 apareceu!", std::move(ini7))));

            std::unique_ptr<Inimigo> ini8(new Inimigo(80, habsInimigo, "Inimigo 8", false));
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, "Um Inimigo 8 apareceu!", std::move(ini8))));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else {
            std::string historia = "CRITICAL ERROR: Memória violada. O Guardião do Ponteiro Nulo desperta!";
            std::unique_ptr<Inimigo> inimigoChefao(new Inimigo(150, habsInimigo, "SegFault Guardiao", true));
            
            return std::unique_ptr<SalaCombate>(new SalaCombate("SALA SEGFAULT", historia, std::move(inimigoChefao)));
        }
    }
}