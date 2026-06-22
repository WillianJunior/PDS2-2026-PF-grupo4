#include "FabricaSE.hpp"
#include "Utils.hpp"
#include "FabricaHabilidade.hpp"
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
                p->alterarVida(30);
                Utils::coutDigitado() << "Voce curtiu a noite e a madrugada como se não houvesse um amanhã.\n";
                Utils::coutDigitado() << "No fim da festa, subiu na moto e no caminho até a casa pensou sobre o codigo.\n";
                Utils::coutDigitado() << "Voce percebe que se nao tivesse relaxado, nao conseguiria continuar codando.\n";
                Utils::coutDigitado() << "Feliz de ter se divertido, voce deita em sua cama, dorme e um novo dia se inicia.\n";
                Utils::coutDigitado() << "MAYCON GANHOU +20 DE VIDA!\n";
            });
            Natora.adicionarOpcao("Nao ir para o natora", [](Personagem *p){
                p->alterarVida(-30);
                Utils::coutDigitado() << "Voce negou a saída naquele dia, voce sabia que precisava codar.\n";
                Utils::coutDigitado() << "Subindo na moto e indo para a casa, voce sentiu o FOMO lhe consumir.\n";
                Utils::coutDigitado() << "Chateado por não ter descansado a cabeça e por não ter relaxado, você sente a dor do FOMO.\n";
                Utils::coutDigitado() << "o Fear of Missing Out retira 30 de vida de Maycon.\n";
            });
            salas.push_back(Natora);

            Utils::Animacao animacaonewtonEspirito;
            animacaonewtonEspirito.tempoFrame = 850;
            animacaonewtonEspirito.textoInicial.push_back("Passado um tempo, voce estava cansado de tanto codar.");
            animacaonewtonEspirito.textoInicial.push_back("No fundo, voce sabia que deveria descansar um pouco.");
            animacaonewtonEspirito.textoInicial.push_back("Deitou-se no sofa imundo do Gremio e olhando para cima, comecou a pensar.");
            animacaonewtonEspirito.textoInicial.push_back("Quando de repente, voce percebe uma figura entrando na sala e se assusta.");
            animacaonewtonEspirito.frames.push_back(R"(       
                          O      
                         /|\_    
                    ____/_|___________
                   |        |        |
                   |________|________|
                  /                  \
            )");
            animacaonewtonEspirito.frames.push_back(R"(   
                       O                     ______
                      /|\_                  |      |
                 ____/_|_____________       |      |
                |         |         |       |    o |
                |_________|_________|       |      |
               /                     \      |______|
            )");
            animacaonewtonEspirito.frames.push_back(R"(   
                       O                     ______
                      /|\_                  |      |
                 ____/_|_____________       |      |
                |         |         |       |    o |
                |_________|_________|       |      |
               /                     \      |______|
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                 "ISAAC NEWTON? VOCE MESMO?"
                       O                   
                      /|\_                   
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                     \      
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
    
                       O                   
                      /|\_                    "F = m . a"
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                     \      
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                        "O que ta fazendo aqui?"
                       O                   
                      /|\_                   
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                     \      
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                    
                       O                   
                      /|\_              "Vim te visitar, Maycon."
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                     \      
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                        "Porque?"
                       O                   
                      /|\_            "Voce precisa da minha ajuda."
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                     \      
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                        "Como?"
                       O                   
                      /|\_              "Com os meus conhecimentos."
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                     \      
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                "O que devo fazer?"
                       O                   
                      /|\_                    "Aperte a minha mão."
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                     \      
            )");

            SalaEscolha newtonEspirito("Encontro com a genialidade", animacaonewtonEspirito);
            Natora.adicionarOpcao("Apertar a mao de Isaac Newton", [](Personagem *p){
                Habilidade habilidade = FabricaHabilidade::criarHabilidade("Raio Gravitacional");
                Utils::coutDigitado() << "Voce se levanta para apertar a mao do grandioso Isaac Newton.\n";
                Utils::coutDigitado() << "Quanto mais voce se aproxima, mais voce percebe a aura de sua inteligencia.\n";
                Utils::coutDigitado() << "Apenas de tocar, apenas tocar aquela mao... te deu uma sensacao, como se tivesse aprendido algo novo.\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "Voce acorda e seus olhos se abrem, tudo foi um sonho, mas o conhecimento ficou.\n";
                Utils::coutDigitado() << "Maycon aprendeu Raio Gravitacional.\n";
                
            });
            Natora.adicionarOpcao("Ignorar o dom da sabedoria", [](Personagem *p){
                Habilidade habilidade = FabricaHabilidade::criarHabilidade("Raio Mayconiano");
                p->getInventarioHabilidade().novaAcao(habilidade);
                Utils::coutDigitado() << "Voce se recusa a apertar a mao do grandioso Isaac Newton.\n";
                Utils::coutDigitado() << "Lembrou-se de tudo que Gerald Weber lhe ensinou e percebeu que, na verdade...\n";
                Utils::coutDigitado() << "Isaac Newton era mediocre.\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "Voce acorda e seus olhos se abrem, tudo foi um sonho, mas sua autoconfianca ficou.\n";
                Utils::coutDigitado() << "Maycon aprendeu Raio Mayconiano.\n";
            });
            salas.push_back(newtonEspirito);
        
        Utils::Animacao animacaoFernandoPessoa;
        animacaoFernandoPessoa.tempoFrame = 40;
        animacaoFernandoPessoa.frames.push_back(R"( 
                   O                           v
                  /|\_                  ^           -
                 /_|__                        v
                |_____|                 -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                            -
                  /|\_                   -           v
                 /_|__                         -
                |_____|                  ^
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                             ^
                  /|\_                    v           -
                 /_|__                          ^
                |_____|                   -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                              -
                  /|\_                     -           ^
                 /_|__                           -
                |_____|                    v
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                               v
                  /|\_                      ^           -
                 /_|__                            v
                |_____|                     -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                -
                  /|\_                       -           v
                 /_|__                              -
                |_____|                      ^
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                 ^
                  /|\_                        v           -
                 /_|__                              ^
                |_____|                       -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                  -
                  /|\_                         -           ^
                 /_|__                                -
                |_____|                        v
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                   v
                  /|\_                          ^           -
                 /_|__                                v
                |_____|                         -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                    -
                  /|\_                           -           v
                 /_|__                                  -
                |_____|                          ^
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                     ^
                  /|\_                            v           -
                 /_|__                                  ^
                |_____|                           -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                      -
                  /|\_                             -           ^
                 /_|__                                   -
                |_____|                            v
            )");
            
        SalaEscolha FernandoPessoa("Poesia em vida", animacaoFernandoPessoa);
        
            salas.push_back(FernandoPessoa);
            int numeroEscolhido = rand() % 3;
            return salas[numeroEscolhido];
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
