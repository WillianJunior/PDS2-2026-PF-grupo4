#include "FabricaSE.hpp"
#include "Utils.hpp"
#include <vector>
#include <random>

namespace FabricaSE {

    SalaEscolha criarSalas(std::string nome) {
        std::vector<SalaEscolha> salas;

        if (nome == "Maycon") {
            SalaEscolha sala1("Sala do Maycon", "Historia aqui.");
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Maycon", "Historia aqui.");
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Maycon", "Historia aqui.");
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];
        } 
        else if (nome == "Vaz") {
            SalaEscolha sala1("Sala do Vaz", "Historia aqui.");
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Vaz", "Historia aqui.");
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Vaz", "Historia aqui.");
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];

        } 
        else if (nome == "Isaque") {
            SalaEscolha sala1("Sala do Isaque", "Historia aqui.");
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Isaque", "Historia aqui.");
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Isaque", "Historia aqui.");
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];
        } 
        else if (nome == "Nicole") {
            SalaEscolha sala1("Sala do Nicole", "Historia aqui.");
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Nicole", "Historia aqui.");
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Nicole", "Historia aqui.");
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];
        } 
        else if (nome == "Marcos") {
            SalaEscolha sala1("Sala do Marcos", "Historia aqui.");
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Marcos", "Historia aqui.");
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Marcos", "Historia aqui.");
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];
        } 
        else {
            SalaEscolha salaSegFault("Seg Fault", "Fault");
            return salaSegFault; // tem q ser uma sala de segmentationfault, de erro
        }
    }
}
