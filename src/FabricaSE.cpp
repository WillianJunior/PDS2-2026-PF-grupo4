#include "FabricaSE.hpp"
#include "Utils.hpp"
#include <vector>
#include <random>

namespace FabricaSE {

    SalaEscolha criarSalas(std::string nome) {
        std::vector<SalaEscolha> salas;
        Utils::Animacao animacao;
        if (nome == "Maycon") {
            Utils::Animacao animacaoNatora;
            animacaoNatora.textoInicial.push_back("Ah, Mathias. Sei não...");
            animacaoNatora.textoInicial.push_back("- Vamo, Maycon! Cê precisa relaxar um pouco, mano.");
            animacaoNatora.textoInicial.push_back("Mas ainda falta implementar um monte de coisa.");
            animacaoNatora.textoInicial.push_back("- Uma mente cansada não produz nada!");
            animacaoNatora.textoInicial.push_back("Ce ta certo, mas sei la...");
            animacaoNatora.frames.push_back(R"(

     .------.
    /        \
   |       ¬  |
   |          > IR PRO NA TORA?
   |       __ |
    \        /
     '------'
            )");
            animacaoNatora.frames.push_back(R"(

                              .------.
                             /        \
                           | O        |
   NAO IR PRO NATORA?     <         /
                         | __       |
                         \        /
                         '------'
            )");
            SalaEscolha Natora("Natora", animacaoNatora);
            Natora.adicionarOpcao("Ir para o natora", [](Personagem *p){
                p->alterarVida(20);
                Utils::coutDigitado() << "Tuts tuts tuts\n";
            });
            Natora.adicionarOpcao("Nao ir para o natora", [](Personagem *p){
                p->alterarVida(20);
                Utils::coutDigitado() << "Tuts tuts tuts\n";
            });
            salas.push_back(Natora);
            // SalaEscolha sala2("Sala do Maycon", animacao);
            // salas.push_back(sala2);
            // SalaEscolha sala3("Sala do Maycon", animacao);
            // salas.push_back(sala3);
            // int numeroEscolhido = rand() % 3;
            return salas[0];
        } 
        else if (nome == "Vaz") {
            SalaEscolha sala1("Sala do Vaz", animacao);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Vaz", animacao);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Vaz", animacao);
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];

        } 
        else if (nome == "Isaque") {
            SalaEscolha sala1("Sala do Isaque", animacao);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Isaque", animacao);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Isaque", animacao);
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];
        } 
        else if (nome == "Nicole") {
            SalaEscolha sala1("Sala do Nicole", animacao);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Nicole", animacao);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Nicole", animacao);
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];
        } 
        else if (nome == "Marcos") {
            SalaEscolha sala1("Sala do Marcos", animacao);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Marcos", animacao);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Marcos", animacao);
            salas.push_back(sala3);

            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];
        } 
        else {
            SalaEscolha salaSegFault("Seg Fault", animacao);
            return salaSegFault; // tem q ser uma sala de segmentationfault, de erro
        }
    }
}
