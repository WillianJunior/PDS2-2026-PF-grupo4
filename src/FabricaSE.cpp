#include "FabricaSE.hpp"
#include "Utils.hpp"
#include "FabricaHabilidade.hpp"
#include "Item.hpp"
#include "FabricaItem.hpp"
#include <vector>
#include <random>

namespace FabricaSE {

    SalaEscolha criarSalas(std::string nome, int idEscolha) {
        std::vector<SalaEscolha> salas;
        Utils::Animacao animacao;
        
        if (nome == "Maycon") {
            Utils::Animacao animacaoNatora;
            animacaoNatora.tempoFrame = 750;
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
            
            SalaEscolha Natora("Natora", animacaoNatora, 0);
            
            Natora.adicionarOpcao("Ir para o natora", [](Personagem *p){
                p->alterarVida(50);
                Utils::coutDigitado() << "Voce curtiu a noite e a madrugada como se não houvesse um amanhã.\n";
                Utils::coutDigitado() << "No fim da festa, subiu na moto e no caminho até a casa pensou sobre o codigo.\n";
                Utils::coutDigitado() << "Voce percebe que se nao tivesse relaxado, nao conseguiria continuar codando.\n";
                Utils::coutDigitado() << "Feliz de ter se divertido, voce deita em sua cama, dorme e um novo dia se inicia.\n";
                Utils::coutDigitado() << "MAYCON GANHOU +50 DE VIDA!\n";
                Utils::esperar(5000);
            });
            
            Natora.adicionarOpcao("Nao ir para o natora", [](Personagem *p){
                p->alterarVida(-10);
                Utils::coutDigitado() << "Voce negou a saída naquele dia, voce sabia que precisava codar.\n";
                Utils::coutDigitado() << "Subindo na moto e indo para a casa, voce sentiu o FOMO lhe consumir.\n";
                Utils::coutDigitado() << "Chateado por não ter descansado a cabeça e por não ter relaxado, você sente a dor do FOMO.\n";
                Utils::coutDigitado() << "O Fear of Missing Out retira 10 de vida de Maycon.\n";
                Utils::esperar(5000);
            });
            
            salas.push_back(Natora);

            Utils::Animacao animacaonewtonEspirito;
            animacaonewtonEspirito.tempoFrame = 2400;
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
                       O                    ______
                      /|\_                  |      |
                 ____/_|_____________       |      |
                |         |         |       |    o |
                |_________|_________|       |      |
               /                    \       |______|
            )");
            animacaonewtonEspirito.frames.push_back(R"(   
                       O                    ______
                      /|\_                  |      |
                 ____/_|_____________       |      |
                |         |         |       |    o |
                |_________|_________|       |      |
               /                    \       |______|
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                 "ISAAC NEWTON? VOCE MESMO?"
                       O                   
                      /|\_                   
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
    
                       O                   
                      /|\_                    "F = m . a"
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                        "O que ta fazendo aqui?"
                       O                   
                      /|\_                   
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                    
                       O                   
                      /|\_              "Vim te visitar, Maycon."
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                        "Porque?"
                       O                   
                      /|\_            
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 

                       O                   
                      /|\_            "Voce precisa da minha ajuda."
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                        "Como?"
                       O                   
                      /|\_              
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 

                       O                   
                      /|\_            "Com os meus conhecimentos"
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
                "O que devo fazer?"
                       O                   
                      /|\_                   
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");
            animacaonewtonEspirito.frames.push_back(R"( 
    
                       O                   
                      /|\_            "Aperte a minha mão"
                 ____/_|_____________           O
                |         |         |         / | \
                |_________|_________|          / \
               /                    \       
            )");

            SalaEscolha newtonEspirito("Encontro com a genialidade", animacaonewtonEspirito, 1);
            
            newtonEspirito.adicionarOpcao("Apertar a mao de Isaac Newton", [](Personagem *p){
                Utils::coutDigitado() << "Voce se levanta para apertar a mao do grandioso Isaac Newton.\n";
                Utils::coutDigitado() << "Quanto mais voce se aproxima, mais voce percebe a aura de sua inteligencia.\n";
                Utils::coutDigitado() << "Apenas de tocar, apenas tocar aquela mao... te deu uma sensacao, como se tivesse aprendido algo novo.\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "Voce acorda e seus olhos se abrem, tudo foi um sonho, mas o conhecimento ficou.\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Raio Gravitacional"));
            });
            
            newtonEspirito.adicionarOpcao("Ignorar o dom da sabedoria", [](Personagem *p){
                Utils::coutDigitado() << "Voce se recusa a apertar a mao do grandioso Isaac Newton.\n";
                Utils::coutDigitado() << "Lembrou-se de tudo que Gerald Weber lhe ensinou e percebeu que, na verdade...\n";
                Utils::coutDigitado() << "Isaac Newton era mediocre.\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "Voce acorda e seus olhos se abrem, tudo foi um sonho, mas a autoconfianca ficou.\n";
                Utils::coutDigitado() << "Se vendo como um inventor melhor do que o cientista Isaac Newton, Maycon aprende e CRIA algo novo.\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Raio Mayconiano"));
            });
            
            salas.push_back(newtonEspirito);
        
            Utils::Animacao animacaoFernandoPessoa;
            animacaoFernandoPessoa.textoInicial.push_back("O mundo computacional o deixa ansioso, sendo a natureza uma fuga do estresse para o heroi.");
            animacaoFernandoPessoa.textoInicial.push_back("Maycon senta-se em um banco e observa os passaros partirem migrando em bando.");
            animacaoFernandoPessoa.textoInicial.push_back("Nao seria a natureza uma imagem-espelho de toda criacao?");
            animacaoFernandoPessoa.textoInicial.push_back("A natureza copia a humanidade ou a humanidade copia a natureza?");
            animacaoFernandoPessoa.textoInicial.push_back("Ao ver aquele bando, Maycon se sentiu inspirado, e antes de voltar a codar, queria escrever uma poesia.");
            animacaoFernandoPessoa.tempoFrame = 150;
            
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
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                       v
                  /|\_                              ^           -
                 /_|__                                    v
                |_____|                             -
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_                               -         
                 /_|__                                         -
                |_____|                                  ^
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_                                    v        
                 /_|__                                          ^
                |_____|                                   -
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_                                     -       
                 /_|__                                           
                |_____|                                    v
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_                                           
                 /_|__                                           
                |_____|                                     -
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_   "Um grande programador sabe muito mais alem de codar..."                                          
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_   "Um grande programador sabe muito mais alem de codar..."                                            
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_    "Um grande programador sabe muito mais alem de codar..."                                             
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_   "Um grande programador sabe muito mais alem de codar..."                                              
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_   "Um grande programador sabe muito mais alem de codar..."                                          
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_   "Um grande programador sabe muito mais alem de codar..."                                            
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_    "Um grande programador sabe muito mais alem de codar..."                                             
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_   "Um grande programador sabe muito mais alem de codar..."                                              
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_   "Um grande programador sabe muito mais alem de codar..."                                          
                 /_|__                                           
                |_____|                                      
            )");
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        
                  /|\_   "Um grande programador sabe muito mais alem de codar..."                                            
                 /_|__                                           
                |_____|                                      
            )");
            
            SalaEscolha FernandoPessoa("Poesia em vida", animacaoFernandoPessoa, 2);
            
            FernandoPessoa.adicionarOpcao("Escrever sobre a arte de codar", [](Personagem *p){
                Utils::coutDigitado() << "\"...Outrora eu era deste escopo, e hoje regresso estrangeiro,\n";
                Utils::coutDigitado() << "Forasteiro da logica que leio, obsoleto de mim.\n";
                Utils::coutDigitado() << "Ja vi todos os bugs, ainda os que nunca criei, nem os que nunca resolverei.\n";
                Utils::coutDigitado() << "Eu reinei no sistema que nunca rodei...\"\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Bencao de Linus"));
                Utils::esperar(5000);
            });

            FernandoPessoa.adicionarOpcao("Escrever sobre o observar e viver", [](Personagem *p){
                Utils::coutDigitado() << "\"...Outrora eu era a acao, e hoje regresso espectador,\n";
                Utils::coutDigitado() << "Amante do que vejo e ouco, pleno de mim.\n";
                Utils::coutDigitado() << "Contemplo tudo, ainda o que nunca vi, nem o que nunca verei.\n";
                Utils::coutDigitado() << "Eu reinei no que apenas observei...\"\n";
                
                p->receberItem(FabricaItem::criarItem("Bencao da Salvia"));
                Utils::esperar(5000);
            });

            salas.push_back(FernandoPessoa);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < (int)salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }
        } 
        else if (nome == "Vaz") {
            Utils::Animacao animacaoFormula;
            animacaoFormula.textoInicial.push_back("O dia tem sido cansativo, e voce sabe que precisa abrir o codigo do grande jogo.");
            animacaoFormula.textoInicial.push_back("Entretanto, um evento inesperado acontece e... voce se depara com uma escolha.");
            animacaoFormula.tempoFrame = 2550;
            
            animacaoFormula.frames.push_back(R"( 
                                                          "Ei Vaz, precisamos de voce!"
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");
            animacaoFormula.frames.push_back(R"( 
         "Precisam de mim onde?"
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");
            animacaoFormula.frames.push_back(R"( 
                                                          "No Formula, uai!"
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");
            animacaoFormula.frames.push_back(R"( 
         "Mas..."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");
            animacaoFormula.frames.push_back(R"( 
                                                          "O que, cara?"
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");
            animacaoFormula.frames.push_back(R"( 
         "Eu preciso codar o projeto."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");
            animacaoFormula.frames.push_back(R"( 
                                                          "Deixa disso! Precisamos de voce."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");
            animacaoFormula.frames.push_back(R"( 
         "Mas eles precisam de mim..."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            SalaEscolha formulaIncidente("Formula Incidente", animacaoFormula, 0);
            
            formulaIncidente.adicionarOpcao("Ir para o Formula", [](Personagem *p){
                Utils::coutDigitado() << "Nesse dia, voce decidiu ir para o Formula.\n";
                Utils::coutDigitado() << "Como voce passou suas horas dedicando-se a equipe,\n";
                Utils::coutDigitado() << "Voce nao desenvolveu nenhuma habilidade...\n";
            });

            formulaIncidente.adicionarOpcao("Completar o Doxygen", [](Personagem *p){
                Utils::coutDigitado() << "Nesse dia, voce decidiu ir codar e estudar.\n";
                Utils::coutDigitado() << "Vendo o que o William pedia, voce estudou os doxygen.\n";
                Utils::coutDigitado() << "Voce percebeu que estava ficando bom naquilo...\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Doxygengaboom"));
            });
            
            salas.push_back(formulaIncidente);
            
            Utils::Animacao animacaoCheckpoint;
            animacaoCheckpoint.textoInicial.push_back("Nesse dia, voce estava no onibus, com a sensacao de que havia esquecido de algo.");
            animacaoCheckpoint.textoInicial.push_back("De repente, voce se lembrou e percebeu que estava em apuros.");
            animacaoCheckpoint.textoInicial.push_back("A C6 estava se aproximando, e o time contava com voce para completar a parte designada.");
            animacaoCheckpoint.textoInicial.push_back("Voce abre o celular para codar e sabe que falta pouco tempo...");
            animacaoCheckpoint.tempoFrame = 5000;

            animacaoCheckpoint.frames.push_back(R"( 
             .-----------.
             |  23:59    |
             |           |
             | [VSCode]  |
             |           |
             | [Gemini]  |
             |           |
             |     O     |
             '-----------'
            )");

            SalaEscolha checkpointAtrasado("Checkpoint Atrasado", animacaoCheckpoint, 1);

            checkpointAtrasado.adicionarOpcao("Codar com o Gemini", [](Personagem *p){
                p->alterarVida(-10);
                
                Utils::coutDigitado() << "Voce percebeu que nao ia dar tempo e utilizou de metodos impuros.\n";
                Utils::coutDigitado() << "Voce se sentiu mal por isso, e isso te consumiu por dentro...\n";
                Utils::coutDigitado() << "Mas voce aprendeu a maldade...\n";
                Utils::coutDigitado() << "Vaz perdeu 10 de vida!\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Maldade Humana"));
            });

            checkpointAtrasado.adicionarOpcao("Codar no VSCODE", [](Personagem *p){
                p->alterarVida(20);
                
                Utils::coutDigitado() << "Nao ficou da melhor forma, mas voce percebeu...\n";
                Utils::coutDigitado() << "Que voce tem o apoio do seu grupo!\n";
                Utils::coutDigitado() << "Voce os avisou e eles o apoiaram na parte que faltava.\n";
                Utils::coutDigitado() << "A amizade e o laco que os une.\n";
                Utils::coutDigitado() << "Vaz recuperou 20 de vida!\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Poder da Amizade"));
            });

            salas.push_back(checkpointAtrasado);
            
            Utils::Animacao animacaoSpotify;
            animacaoSpotify.textoInicial.push_back("Voce voltava para casa em seu carro,");
            animacaoSpotify.textoInicial.push_back("decidindo o que ia ouvir ate chegar.");
            animacaoSpotify.textoInicial.push_back("Pensou, pensou e refletiu sobre todas as possibilidades...");
            animacaoSpotify.textoInicial.push_back("O que voce poderia ouvir?");
            animacaoSpotify.tempoFrame = 850;
            
            std::string frame1 = R"( 
             .-----------.
             |  Spotify  |
             | CBJR      |
             | Ceu Azul  |
             | ==O------ |
             | [|< > |>] |
             |     O     |
             '-----------'
            )";

            std::string frame2 = R"( 
             .-----------.
             |  Spotify  |
             | OneRepuic |
             | Counting S|
             | ===O----- |
             | [|< > |>] |
             |     O     |
             '-----------'
            )";

            std::string frame3 = R"( 
             .-----------.
             |  Spotify  |
             | Katy Perry|
             | Fireworks |
             | =====O--- |
             | [|< > |>] |
             |     O     |
             '-----------'
            )";

            std::string frame4 = R"( 
             .-----------.
             |  Spotify  |
             | Can do Rei|
             | Crina Negr|
             | =======O- |
             | [|< > |>] |
             |     O     |
             '-----------'
            )";

            std::string frame5 = R"( 
             .-----------.
             |  Spotify  |
             | NX Zero   |
             | Razoes    |
             | ========O |
             | [|< > |>] |
             |     O     |
             '-----------'
            )";
            
            for (int i = 0; i < 2; i++) {
                animacaoSpotify.frames.push_back(frame1);
                animacaoSpotify.frames.push_back(frame2);
                animacaoSpotify.frames.push_back(frame3);
                animacaoSpotify.frames.push_back(frame4);
                animacaoSpotify.frames.push_back(frame5);
            }

            SalaEscolha spotify("Spotify", animacaoSpotify, 2);

            spotify.adicionarOpcao("Escutar Ceu Azul - Charlie Brown Jr", [](Personagem *p){
                p->alterarVida(30);
                Utils::coutDigitado() << "Voce ouviu as musicas do chorao e se sentiu restaurado pela energia do skate.\n";
                Utils::coutDigitado() << "Vaz recebeu 30 de vida!\n";
            });

            spotify.adicionarOpcao("Escutar Counting Stars - OneRepublic", [](Personagem *p){
                p->alterarVida(40);
                Utils::coutDigitado() << "Ouvir Counting Stars foi insano.\n";
                Utils::coutDigitado() << "Pouco a pouco acelerou o carro e se sentia em um filme.\n";
                Utils::coutDigitado() << "Talvez nunca esteve tao inspirado.\n";
                Utils::coutDigitado() << "Vaz se sente vivo! Vaz recebeu 40 de vida!\n";
            });

            spotify.adicionarOpcao("Escutar Katy Perry - Fireworks", [](Personagem *p){
                Utils::coutDigitado() << "Ouvindo uma Katy Perry voce nao poderia se sentir melhor.\n";
                Utils::coutDigitado() << "A energia te fez lembrar ate de algo que guardava!\n";
                Utils::coutDigitado() << "Abrindo o porta-luvas pode ver um...\n";
                
                p->receberItem(FabricaItem::criarItem("Energetico"));
            });

            spotify.adicionarOpcao("Escutar Crina Negra - Canarios do Reino", [](Personagem *p){
                Utils::coutDigitado() << "Ouvindo Crina Negra, Vaz lembrou de seu amigo Marcos.\n";
                Utils::coutDigitado() << "Conseguiu lembrar como Marcos dancava forro bem!\n";
                Utils::coutDigitado() << "Ao som da musica e das memorias de Marcos, Vaz captou a energia do forro.\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Passinho do Forro"));
            });

            spotify.adicionarOpcao("Escutar Razoes e Emocoes - NX Zero", [](Personagem *p){
                p->alterarVida(-15);
                Utils::coutDigitado() << "Vaz ouviu Razoes e Emocoes e aquela musica...\n";
                Utils::coutDigitado() << "Aquela musica mexeu com ele.\n";
                Utils::coutDigitado() << "Enquanto ouvia, sofreu com os vocais do Di e a letra melancolica...\n";
                Utils::coutDigitado() << "Por mais que seja um bom rock, Vaz ficou melancolico.\n";
                Utils::coutDigitado() << "Vaz perdeu 15 de vida!\n";
            });

            salas.push_back(spotify);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < (int)salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }

        } 
        else if (nome == "Isaque") {
            Utils::Animacao animacaoAbstinencia;
            animacaoAbstinencia.textoInicial.push_back("Isaque encarava o computador pensando como e o que iria codar.");
            animacaoAbstinencia.textoInicial.push_back("Diante do tamanho do trabalho, sabia que precisava fazer o maximo o quanto antes.");
            animacaoAbstinencia.textoInicial.push_back("Com o VSCode de um lado, e a droga do outro, Isaque nao sabia por qual optar.");
            animacaoAbstinencia.textoInicial.push_back("Isaque...");
            animacaoAbstinencia.textoInicial.push_back("... Um viciado.");
            animacaoAbstinencia.textoInicial.push_back("Um viciado em League of Legends!");
            animacaoAbstinencia.textoInicial.push_back("E essa era sua droga.");
            animacaoAbstinencia.textoInicial.push_back("Dias que ele nao jogava e a abstinencia comecava a apertar. O que ele deveria fazer?");
            animacaoAbstinencia.tempoFrame = 500;

            animacaoAbstinencia.frames.push_back(R"( 
        [VSCode]                 [LOL]
                   (<_<)

            )");
            animacaoAbstinencia.frames.push_back(R"( 
        [VSCode]                 [LOL]
                   (>_>)

            )");
            animacaoAbstinencia.frames.push_back(R"( 
        [VSCode]                 [LOL]
                   (<_<)

            )");
            animacaoAbstinencia.frames.push_back(R"( 
        [VSCode]                 [LOL]
                   (>_>)

            )");
            animacaoAbstinencia.frames.push_back(R"( 
        [VSCode]                 [LOL]
                   (<_<)

            )");
            animacaoAbstinencia.frames.push_back(R"( 
        [VSCode]                 [LOL]
                   (>_>)

            )");

            SalaEscolha abstinenciaDroga("Abstinencia de uma Droga", animacaoAbstinencia, 0);

            abstinenciaDroga.adicionarOpcao("Suprir a abstinencia e jogar LOL", [](Personagem *p){
                Utils::coutDigitado() << "Sabendo do seu vicio, Isaque nao aguentou.\n";
                Utils::coutDigitado() << "Abriu o LOL e mesmo que precisasse codar,\n";
                Utils::coutDigitado() << "Jogou ate 3 da manha, atrapalhando seu sono...\n";
                Utils::coutDigitado() << "No outro dia, acordou destruido mas contente,\n";
                Utils::coutDigitado() << "Porque poucas coisas poderiam deixa-lo feliz...\n";
                Utils::coutDigitado() << "Como o LOL.\n";
                Utils::coutDigitado() << "Isaque perdeu 20 de vida por dormir mal!\n";
                Utils::coutDigitado() << "Isaque ganhou 20 de vida por jogar feliz!\n";
            });

            abstinenciaDroga.adicionarOpcao("Abrir o VSCode e cumprir com os deveres", [](Personagem *p){
                p->alterarVida(20);

                Utils::coutDigitado() << "O dom da Responsabilidade tocou em seu coracao,\n";
                Utils::coutDigitado() << "Pois por mais que seu vicio estivesse logo ali,\n";
                Utils::coutDigitado() << "Ele decidiu abrir o VSCode e codar por horas.\n";
                Utils::coutDigitado() << "Adiantou o trabalho e, no outro dia,\n";
                Utils::coutDigitado() << "Participou dos LOLZEIROS ANONIMOS para desabafar.\n";
                Utils::coutDigitado() << "Encontrou la um amigo, chamado Daniel.\n";
                Utils::coutDigitado() << "Conversou por horas com ele e, no fim,\n";
                Utils::coutDigitado() << "Daniel lhe deu um presente para ajudar a livrar-se do vicio.\n";
                
                p->receberItem(FabricaItem::criarItem("Ritalina"));
            });

            abstinenciaDroga.adicionarOpcao("Jogar o computador para fora da janela", [](Personagem *p){
                Utils::coutDigitado() << "Cansado de tudo, voce nao aguentou.\n";
                Utils::coutDigitado() << "Viu como unica opcao arremessar seu computador para fora da janela.\n";
                Utils::coutDigitado() << "Viu ele voar como se fosse um passaro,\n";
                Utils::coutDigitado() << "Ate se espatifar no chao.\n";
                Utils::coutDigitado() << "Nessa decisao imprudente, Isaque percebeu que ainda precisava codar.\n";
                Utils::coutDigitado() << "Lembrou-se das aulas de Henrique em PDS1, pegou um caderno e disse:\n";
                Utils::coutDigitado() << "\"Eu sei o que fazer.\"\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Papelada de Codigos"));
            });

            salas.push_back(abstinenciaDroga);
            
            Utils::Animacao animacaoChuva;
            animacaoChuva.textoInicial.push_back("Nessa semana, voce queria codar bastante.");
            animacaoChuva.textoInicial.push_back("Chegou em casa e, mesmo vendo o ceu nublado, decidiu ir para a UFMG.");
            animacaoChuva.textoInicial.push_back("Triste escolha foi essa que Isaque fez.");
            animacaoChuva.textoInicial.push_back("No destino ate a UFMG, percebeu as nuvens se escurecerem ate o momento em que...");
            animacaoChuva.textoInicial.push_back("Comecou a chover.");
            animacaoChuva.textoInicial.push_back("Voce ficou debaixo de uma marquise, esperando a chuva passar.");
            animacaoChuva.textoInicial.push_back("O problema e: voce avistou um gatinho, pobre coitado, na chuva...");
            animacaoChuva.textoInicial.push_back("Voce vai deixar o gatinho pobre e coitado na chuva?");
            animacaoChuva.tempoFrame = 150;

            std::string frameChuvaA = R"( 
           _________        /   /   /   /
           |   O   |          /   /   /
           |  /|\  |        /   /   /   /
           |  / \  |          /   /   /
            )";

            std::string frameChuvaB = R"( 
           _________          /   /   /
           |   O   |        /   /   /   /
           |  /|\  |          /   /   /
           |  / \  |        /   /   /   /
            )";

            for (int i = 0; i < 60; i++) {
                animacaoChuva.frames.push_back(frameChuvaA);
                animacaoChuva.frames.push_back(frameChuvaB);
            }

            SalaEscolha salaDaChuva("Chuva, muita chuva", animacaoChuva, 1);

            salaDaChuva.adicionarOpcao("Resgatar o gatinho pobre coitado", [](Personagem *p){
                p->alterarVida(-15);

                Utils::coutDigitado() << "Seu coracao nao poderia ignorar um gatinho pobre coitado todo perdido na chuva.\n";
                Utils::coutDigitado() << "Isaque se levanta e parte para ajudar o pobre gatito.\n";
                Utils::coutDigitado() << "Voce se molha e corre ate o gato, pegando-o pelos bracos e voltando para a marquise.\n";
                Utils::coutDigitado() << "O gato, assustado, quase foge de voce e volta para a chuva,\n";
                Utils::coutDigitado() << "Mas logo fica agradecido pelo seu ato heroico.\n";
                Utils::coutDigitado() << "Passa a esfregar a cabeca em voce e relaxar.\n";
                Utils::coutDigitado() << "Voce sente que acordara gripado amanha...\n";
                Utils::coutDigitado() << "Isaque ganhou um novo amigo!\n";
                Utils::coutDigitado() << "Isaque perdeu 15 de vida!\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Arranhada do Gatinho"));
            });

            salaDaChuva.adicionarOpcao("Sentar e ignorar o gato burro", [](Personagem *p){
                Utils::coutDigitado() << "O egoismo consumiu o fundo da sua alma.\n";
                Utils::coutDigitado() << "Poucos humanos foram e seriam tao crueis quanto voce foi.\n";
                Utils::coutDigitado() << "O gato saiu do seu campo de visao, mas nunca saiu do campo da sua alma.\n";
                Utils::coutDigitado() << "Por dentro voce se sente um anjo caido.\n";
                Utils::coutDigitado() << "A chuva parou.\n";
                Utils::coutDigitado() << "Mas a dor continuou.\n";
                Utils::coutDigitado() << "Voce volta para casa e dorme.\n";
                Utils::coutDigitado() << "Em seus sonhos, um arcanjo te visita.\n";
                Utils::coutDigitado() << "Voce se sente acuado e envergonhado dos seus atos.\n";
                Utils::coutDigitado() << "O arcanjo diz: \"Derrame.\"\n";
                Utils::coutDigitado() << "E seu corpo se derrama no chao.\n";
                Utils::coutDigitado() << "Ao acordar, a culpa se dissolveu, e voce talvez entenda como fazer os inimigos se derramarem diante de ti.\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Derrame do Arcanjo"));
            });
            salas.push_back(salaDaChuva);

            Utils::Animacao animacaoAraujo;
            animacaoAraujo.textoInicial.push_back("\"Quer saber! Depois eu codo. Preciso de alguma merda.\"");
            animacaoAraujo.textoInicial.push_back("Isaque nao queria saber mais de VSCode, precisava ir para uma Araujo e achar o que comer.");
            animacaoAraujo.textoInicial.push_back("O problema e...");
            animacaoAraujo.textoInicial.push_back("No caminho ate a Araujo...");
            animacaoAraujo.textoInicial.push_back("Nesse caminho tortuoso...");
            animacaoAraujo.textoInicial.push_back("Assombrado...");
            animacaoAraujo.textoInicial.push_back("Onde a maldade e tudo de ruim pode acontecer...");
            animacaoAraujo.textoInicial.push_back("...");
            animacaoAraujo.textoInicial.push_back("Nada acontece.");
            animacaoAraujo.textoInicial.push_back("Voce chega na Araujo e precisa decidir o que comer!");
            animacaoAraujo.tempoFrame = 2000;

            std::string framePringles = R"( 
                 ___ 
                |   |
                |PRI|
                |NGL|
                |ES |
                |___|
            )";

            std::string frameDoritos = R"( 
                 /^\ 
                /DOR\ 
               /ITOS \ 
              /_______\ 
            )";

            for (int i = 0; i < 4; i++) {
                animacaoAraujo.frames.push_back(framePringles);
                animacaoAraujo.frames.push_back(frameDoritos);
            }

            SalaEscolha araujo("Drogaria Araujo", animacaoAraujo, 2);
            
            araujo.adicionarOpcao("Pringles", [](Personagem *p){
                Utils::coutDigitado() << "Voce opta pelo pacote de Pringles.\n";
                Utils::coutDigitado() << "Apesar da formula ter mudado e nao ser tao bom quanto antes,\n";
                Utils::coutDigitado() << "Uma Pringles ainda continua caindo muito bem!\n";
                Utils::coutDigitado() << "Isaque se chateia por fomentar o capitalismo, mas esta feliz com sua Pringles.\n";
                
                p->receberItem(FabricaItem::criarItem("Pringles"));
            });

            araujo.adicionarOpcao("Doritos", [](Personagem *p){
                Utils::coutDigitado() << "Voce opta pelo pacote de Doritos.\n";
                Utils::coutDigitado() << "Apesar da formula ter mudado e nao ser tao bom quanto antes,\n";
                Utils::coutDigitado() << "Um Doritos ainda continua caindo muito bem!\n";
                Utils::coutDigitado() << "Isaque se chateia por fomentar o capitalismo, mas esta feliz com seu Doritos.\n";
                
                p->receberItem(FabricaItem::criarItem("Doritos"));
            });
            salas.push_back(araujo);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < (int)salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }
        } 
        else if (nome == "Nicole") {
            Utils::Animacao animacaoLivro;
            animacaoLivro.textoInicial.push_back("Nicole sabia da grande missao que seria codar esse grande codigo.");
            animacaoLivro.textoInicial.push_back("Derrotar todos aqueles inimigos seria uma dificuldade e tanto, ela precisaria de tempo.");
            animacaoLivro.textoInicial.push_back("Mas... Onde ela arrumaria tempo?");
            animacaoLivro.tempoFrame = 4000;

            animacaoLivro.frames.push_back(R"( 
         "Eu vou ter que sair do clube do livro."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            animacaoLivro.frames.push_back(R"( 
                                                  "O que? Como assim?"
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            animacaoLivro.frames.push_back(R"( 
         "Eu estou numa grande aventura agora."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            animacaoLivro.frames.push_back(R"( 
                                                  "Maior do que o nosso clube?"
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            animacaoLivro.frames.push_back(R"( 
         "E... E. Talvez."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            animacaoLivro.frames.push_back(R"( 
                                                  "Ok, ta bom."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            animacaoLivro.frames.push_back(R"( 
         "Nao fica assim."
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            animacaoLivro.frames.push_back(R"( 
                                                  "A sua escolha e essa? Abandonar o clube do livro?"
                   O                                     O
                  /|\                                   /|\
                  / \                                   / \
            )");

            SalaEscolha clubeLivro("Clube do Livro", animacaoLivro, 0);

            clubeLivro.adicionarOpcao("Abandonar o clube do livro", [](Personagem *p){
                Utils::coutDigitado() << "Voce sabe quais sao as prioridades na sua vida.\n";
                Utils::coutDigitado() << "O time precisa de voce e, por mais que tenha construido tanto nesse clube...\n";
                Utils::coutDigitado() << "O momento de partir chegou.\n";
                Utils::coutDigitado() << "Abracando os membros do grupo, se despediu de cada um.\n";
                Utils::coutDigitado() << "Por ultimo, Joao Fonseca, membro honorario do clube, disse que tinha um ultimo presente.\n";
                Utils::coutDigitado() << "Um presente que a ajudasse na sua missao.\n";
                
                p->receberItem(FabricaItem::criarItem("Livro Macico"));
            });

            clubeLivro.adicionarOpcao("Manter o clube do livro", [](Personagem *p){
                p->alterarVida(25);

                Utils::coutDigitado() << "Por mais que voce tenha uma grande missao pela frente,\n";
                Utils::coutDigitado() << "Se abster das felicidades da sua vida nao deve ser o melhor caminho.\n";
                Utils::coutDigitado() << "A vida nao e apenas trabalho.\n";
                Utils::coutDigitado() << "A vida nao e apenas aventura.\n";
                Utils::coutDigitado() << "A vida tambem e fazer o que gostamos.\n";
                Utils::coutDigitado() << "Se mantendo no clube do livro sua saude mental agradecera.\n";
                Utils::coutDigitado() << "Vendo seu esforco em ficar, Sinner, membro honorario do clube do livro, lhe deu um presente.\n";
                Utils::coutDigitado() << "Nicole ganhou 25 de vida!\n";
                
                p->receberItem(FabricaItem::criarItem("Maca"));
            });
            salas.push_back(clubeLivro);

            Utils::Animacao animacaoCansaco;
            animacaoCansaco.textoInicial.push_back("O dia estava chato, estava tenebroso para Nicole.");
            animacaoCansaco.textoInicial.push_back("Havia muitas provas naquela semana e ja havia a grande missao de William para cumprir.");
            animacaoCansaco.textoInicial.push_back("Exausta, ela precisava colocar aquilo para fora.");
            animacaoCansaco.tempoFrame = 4000;

            animacaoCansaco.frames.push_back(R"( 
             "Maycon: Ta cansada, Nicole?"
               O      O      O      O      O
              /|\    /|\    /|\    /|\    /|\
              / \    / \    / \    / \    / \
            )");

            animacaoCansaco.frames.push_back(R"( 
                     "Marcos: O que ta acontecendo?"
               O      O      O      O      O
              /|\    /|\    /|\    /|\    /|\
              / \    / \    / \    / \    / \
            )");

            animacaoCansaco.frames.push_back(R"( 
                            "Isaque: Ta tudo de boa?"
               O      O      O      O      O
              /|\    /|\    /|\    /|\    /|\
              / \    / \    / \    / \    / \
            )");

            animacaoCansaco.frames.push_back(R"( 
                                   "Vaz: O que foi, Nicole?"
               O      O      O      O      O
              /|\    /|\    /|\    /|\    /|\
              / \    / \    / \    / \    / \
            )");

            animacaoCansaco.frames.push_back(R"( 
                                          "..."
               O      O      O      O      O
              /|\    /|\    /|\    /|\    /|\
              / \    / \    / \    / \    / \
            )");

            SalaEscolha diaCansativo("Dia Cansativo", animacaoCansaco, 1);

            diaCansativo.adicionarOpcao("Falar sobre o dia", [](Personagem *p){
                Utils::coutDigitado() << "As vezes o cansaco so pode ser lidado de forma externa.\n";
                Utils::coutDigitado() << "Nao querendo armazenar tudo aquilo, Nicole optou por falar.\n";
                Utils::coutDigitado() << "Falou sobre as provas, sobre as aulas, sobre o VSCode.\n";
                Utils::coutDigitado() << "\"Que dia chato!\"\n";
                Utils::coutDigitado() << "E por fim, estava feliz por ter falado sobre tudo.\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Reclamar"));
            });

            diaCansativo.adicionarOpcao("Nao falar sobre o dia", [](Personagem *p){
                p->alterarVida(20);
                Utils::coutDigitado() << "De certa forma, voce nao queria ficar reclamando.\n";
                Utils::coutDigitado() << "Preferiu mostrar que na verdade estava tudo correndo bem.\n";
                Utils::coutDigitado() << "E de tanto pensar que estava correndo bem, passou a correr bem!\n";
                Utils::coutDigitado() << "O otimismo, nesse dia, fez bem para voce.\n";
                Utils::coutDigitado() << "E o dia que estava cansativo ficou um pouco mais tranquilo.\n";
                Utils::coutDigitado() << "Nicole ganhou 20 de vida!\n";
            });

            salas.push_back(diaCansativo);

            Utils::Animacao animacaoBalao;
            animacaoBalao.textoInicial.push_back("A parte de criar os Itens... criar as Habilidades... isso tem dado trabalho demais para Nicole.");
            animacaoBalao.textoInicial.push_back("Alem dos desafios e batalhas que vem enfrentando para codar e concluir a grande missao de William.");
            animacaoBalao.textoInicial.push_back("O seu ultimo desafio foi lidar com a implementacao de funcoes em Salas de Combate.");
            animacaoBalao.textoInicial.push_back("Buscou formas e formas de resolver, mas nao conseguiu!");
            animacaoBalao.textoInicial.push_back("Ate que... se lembrou de um professor, um mestre de sua antiga escola Balao Vermelho.");
            animacaoBalao.textoInicial.push_back("O professor Frota, especialista em design de jogos e modelacao de hierarquias.");
            animacaoBalao.tempoFrame = 120;

            std::string frameAnda1 = R"( 
                                                                         / \
                                                                        / BV\
                                                                       |_____|
             O                                                         |     |
            /|\                                                        |     |
            / \                                                        |     |
            )";

            std::string frameAnda2 = R"( 
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                   O                                                   |     |
                  /|\                                                  |     |
                  / \                                                  |     |
            )";

            std::string frameChegada = R"( 
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                             |     |
                        /|\                                            |     |
                        / \                                            |     |
            )";

            std::string frameFrotaAparece = R"( 
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala1 = R"( 
                                                    "O que esta fazendo aqui?"
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala2 = R"( 
                   "Mestre, eu voltei."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala3 = R"( 
                                                               "..."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala4 = R"( 
                  "Preciso da sua ajuda."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala5 = R"( 
                                                  "Voce fugiu do Balao Vermelho."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala6 = R"( 
                  "Eu precisava partir."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala7 = R"( 
             "Por favor, eu preciso de ajuda!"
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala8 = R"( 
                                                              "Diga."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala9 = R"( 
   "Como posso implementar a fabricacao da Sala de Escolhas?"
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala10 = R"( 
                                                        "Ah... eu sei bem."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala11 = R"( 
                         "Como!?"
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala12 = R"( 
                                         "Um mestre nao te da a resposta, mas o caminho."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala13 = R"( 
                    "E qual o caminho?"
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala14 = R"( 
                                                    "O que voce acha melhor..."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala15 = R"( 
                                      "Criar classes separadas e montar a fabrica depois..."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala16 = R"( 
                                              "Ou implementar tudo em um so arquivo?"
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala17 = R"( 
                    "Eu... eu nao sei!"
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            std::string fala18 = R"( 
                                               "E tudo que posso te dizer, Nicole."
                                                                         / \
                                                                        / BV\
                                                                       |_____|
                         O                                   O         |     |
                        /|\                                 /|\        |     |
                        / \                                 / \        |     |
            )";

            for(int i = 0; i < 7; i++) {
                animacaoBalao.frames.push_back(frameAnda1);
                animacaoBalao.frames.push_back(frameAnda2);
                animacaoBalao.frames.push_back(frameChegada);
            }

            for(int i = 0; i < 10; i++) animacaoBalao.frames.push_back(frameChegada);
            for(int i = 0; i < 7; i++) animacaoBalao.frames.push_back(frameFrotaAparece);

            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala1);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala2);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala3);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala4);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala5);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala6);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala3); 
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala7);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala8);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala9);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala10);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala11);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala12);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala13);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala14);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala15);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala16);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala17);
            for(int i = 0; i < 30; i++) animacaoBalao.frames.push_back(fala18);

            SalaEscolha balaoVermelho("Balao Vermelho", animacaoBalao, 2);

            balaoVermelho.adicionarOpcao("Criar classes separadas", [](Personagem *p){
                Utils::coutDigitado() << "Indo embora do Balao Vermelho voce pensou sobre tudo isso que o Mestre lhe disse.\n";
                Utils::coutDigitado() << "Lembrou tambem das instrucoes do Grande William, e o quanto ele falava sobre hierarquia.\n";
                Utils::coutDigitado() << "Com todo esse conhecimento, tomou por decisao criar classes separadas, e isso fez o codigo ser coeso, mas nao acoplado!\n";
                Utils::coutDigitado() << "Os riscos de erro agora diminuem e, se existirem, voce sabe aonde buscar.\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Plasma Hierarquico"));
            });

            balaoVermelho.adicionarOpcao("Tudo em apenas um arquivo", [](Personagem *p){
                Utils::coutDigitado() << "Refletiu sobre tudo que aprendeu ate aqui e tomou por decisao fazer tudo em apenas um arquivo.\n";
                Utils::coutDigitado() << "Sabia que as instrucoes nao eram exatamente essas, mas pensou:\n";
                Utils::coutDigitado() << "Apenas quem se arrisca merece viver o extraordinario.\n";
                Utils::coutDigitado() << "Eu nao tenho medo de nada!\n";
                Utils::coutDigitado() << "Os riscos de erro aumentaram, mas definitivamente seu codigo e algo unico.\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Codigos Macarronados"));
            });
            salas.push_back(balaoVermelho);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < (int)salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }
        } 
        else if (nome == "Marcos") {
            Utils::Animacao animacaoCentro;
            animacaoCentro.textoInicial.push_back("Vivendo e sabendo de toda essa grande missao, percebeu que nao precisava so saber codar.");
            animacaoCentro.textoInicial.push_back("Marcos entendeu que seus chakras precisavam estar alinhados.");
            animacaoCentro.textoInicial.push_back("Sua espiritualidade deve estar alinhada!");
            animacaoCentro.textoInicial.push_back("...");
            animacaoCentro.textoInicial.push_back("Voce decide ir ao Centro Espirita e, chegando la, uma conversa interna entre voce e seu espiritual comeca, com a intervencao de dois espiritos.");
            animacaoCentro.textoInicial.push_back("O da esquerda, dizia sobre a persistencia.");
            animacaoCentro.textoInicial.push_back("O da direita, dizia sobre a calmaria.");
            animacaoCentro.tempoFrame = 300;

            std::string frameEspirito1 = R"( 
            o        _--_
                    ( - -)
                    | __ |       o
                     \__/
            )";

            std::string frameEspirito2 = R"( 
                     _--_
            o       ( - -)       o
                    | __ |
                     \__/
            )";

            std::string frameEspirito3 = R"( 
                     _--_        o
                    ( - -)
            o       | __ |
                     \__/
            )";

            std::string frameEspirito4 = R"( 
                     _--_
            o       ( - -)       o
                    | __ |
                     \__/
            )";

            for (int i = 0; i < 2; i++) {
                animacaoCentro.frames.push_back(frameEspirito1);
                animacaoCentro.frames.push_back(frameEspirito2);
                animacaoCentro.frames.push_back(frameEspirito3);
                animacaoCentro.frames.push_back(frameEspirito4);
            }

            SalaEscolha centroEspirita("Centro Espirita", animacaoCentro, 0);

            centroEspirita.adicionarOpcao("Ouvir o espirito da esquerda", [](Personagem *p){
                Utils::coutDigitado() << "O espirito da esquerda lhe manda de volta para casa.\n";
                Utils::coutDigitado() << "Voce deve codar e concluir sua missao o quanto antes.\n";
                Utils::coutDigitado() << "Mesmo que se canse, mesmo que doa,\n";
                Utils::coutDigitado() << "Mesmo que voce queira desistir.\n";
                Utils::coutDigitado() << "Lembre-se, William nao desistiu.\n";
                Utils::coutDigitado() << "Alan Turing nao desistiu.\n";
                Utils::coutDigitado() << "Dizia para voltar para casa e codar como nunca.\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Duro na Queda"));
            });

            centroEspirita.adicionarOpcao("Ouvir o espirito da direita", [](Personagem *p){
                Utils::coutDigitado() << "O espirito da direita lhe diz para se acalmar.\n";
                Utils::coutDigitado() << "Uma missao bem concluida e uma missao que a aventura lhe ensinou algo.\n";
                Utils::coutDigitado() << "Do que adianta o fim do codigo\n";
                Utils::coutDigitado() << "Se voce nao se lembrar como implementa?\n";
                Utils::coutDigitado() << "A aventura conta mais do que o fim...\n";
                Utils::coutDigitado() << "Depois de conversar com os espiritos, Marcos abriu os olhos e levantou-se para ir.\n";
                Utils::coutDigitado() << "Na saida, uma boa alma lhe disse:\n";
                Utils::coutDigitado() << "\"Sempre que precisar conversar com os espiritos, use esse colar.\"\n";
                
                p->receberItem(FabricaItem::criarItem("Colar dos Espiritos"));
            });
            salas.push_back(centroEspirita);

            Utils::Animacao animacaoMorfismos;
            animacaoMorfismos.textoInicial.push_back("Marcos se viu com um problema na sua vida...");
            animacaoMorfismos.textoInicial.push_back("Ja havia codado bastante e decidiu sair para descansar.");
            animacaoMorfismos.textoInicial.push_back("Chamou no seu WhatsApp 3 pessoas para sair, o problema era...");
            animacaoMorfismos.textoInicial.push_back("As 3 se chamam Maria.");
            animacaoMorfismos.textoInicial.push_back("Quando se encontraram, sempre que Marcos dizia \"Maria\", as tres olhavam!");
            animacaoMorfismos.tempoFrame = 2500;

            animacaoMorfismos.frames.push_back(R"( 
          "Maria!"
             O               O   O   O
            /|\             /|\ /|\ /|\
            / \             / \ / \ / \
            )");

            animacaoMorfismos.frames.push_back(R"( 
                        "Oi!" "Oi!" "Oi!"
             O               O   O   O
            /|\             /|\ /|\ /|\
            / \             / \ / \ / \
            )");

            animacaoMorfismos.frames.push_back(R"( 
          "Voce nao, a outra Maria!"
             O               O   O   O
            /|\             /|\ /|\ /|\
            / \             / \ / \ / \
            )");

            animacaoMorfismos.frames.push_back(R"( 
                        "Eu?" "Eu?" "Eu?"
             O               O   O   O
            /|\             /|\ /|\ /|\
            / \             / \ / \ / \
            )");

            animacaoMorfismos.frames.push_back(R"( 
          "Como eu vou resolver isso?!"
             O               O   O   O
            /|\             /|\ /|\ /|\
            / \             / \ / \ / \
            )");

            SalaEscolha variosMorfismos("Varios Morfismos", animacaoMorfismos, 1);

            variosMorfismos.adicionarOpcao("Mudar o nome de cada Maria", [](Personagem *p){
                Utils::coutDigitado() << "Como nao e possivel chamar uma Maria so pelo nome Maria, Marcos cansou.\n";
                Utils::coutDigitado() << "Olhou para cada uma e foi dizendo:\n";
                Utils::coutDigitado() << "\"Voce e Maria Lucia, Voce e Maria Fernanda e Voce e Maria Beatriz, ok?\"\n";
                Utils::coutDigitado() << "E, dessa maneira, conseguiu encontrar a melhor forma de conseguir chamar as marias.\n";
                Utils::coutDigitado() << "Isso e o verdadeiro Overload!\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Overload Marianico"));
            });

            variosMorfismos.adicionarOpcao("Dar uma funcao para cada Maria", [](Personagem *p){
                Utils::coutDigitado() << "Marcos olhou para cada uma e percebeu que elas tem caracteristicas que as distinguem.\n";
                Utils::coutDigitado() << "Disse para cada Maria que elas continuam Marias, mas uma e a Maria Engracada, outra e a Maria Chata e a outra e a Maria Linda!\n";
                Utils::coutDigitado() << "Assim, Marcos conseguiu entender como, mesmo com o mesmo nome, pode cumprir funcoes diferentes.\n";
                Utils::coutDigitado() << "Isso e o verdadeiro Override!\n";
                
                p->receberHabilidade(FabricaHabilidade::criarHabilidade("Override Impiedoso"));
            });

            salas.push_back(variosMorfismos);

            Utils::Animacao animacaoFafich;
            animacaoFafich.textoInicial.push_back("Hoje voce acordou determinado para codar bastante.");
            animacaoFafich.textoInicial.push_back("Se aprontou rapidamente e partiu para a UFMG.");
            animacaoFafich.textoInicial.push_back("No caminho ate o coworking, voce tinha dois caminhos para ir:");
            animacaoFafich.textoInicial.push_back("Um caminho mais rapido, passando pela FAFICH e o CAD 1,");
            animacaoFafich.textoInicial.push_back("E um caminho mais longo, dando a volta na Praca de Servicos e indo direto a Engenharia.");
            animacaoFafich.tempoFrame = 8000;

            animacaoFafich.frames.push_back(R"( 
                     [FAFICH]
                    / 
             O     /
            /|\   <
            / \    \
                    \
                     [PRACA DE SERVICOS]
            )");

            SalaEscolha fafich("FAFICH", animacaoFafich, 2);

            fafich.adicionarOpcao("Passar pela FAFICH", [](Personagem *p){
                p->alterarVida(-30);

                Utils::coutDigitado() << "Ah... uma escolha plausivel.\n";
                Utils::coutDigitado() << "Tao cansado e precisando codar tanto, que escolheu o caminho mais rapido.\n";
                Utils::coutDigitado() << "Bom, o cliche das historias se repete...\n";
                Utils::coutDigitado() << "Nem sempre o caminho mais facil e o melhor.\n";
                Utils::coutDigitado() << "Ratos mutantes saem dos bueiros e comecam a roer suas pernas.\n";
                Utils::coutDigitado() << "Voce ate consegue se livrar dos ratos mutantes,\n";
                Utils::coutDigitado() << "Mas das paredes escorria um liquido viscoso que era toxico.\n";
                Utils::coutDigitado() << "As partes do seu corpo que acabaram encostando nas paredes tiveram queimaduras de nivel 3.\n";
                Utils::coutDigitado() << "Passando da FAFICH, voce chega a engenharia.\n";
                Utils::coutDigitado() << "Mas a que custo...\n";
                Utils::coutDigitado() << "Marcos perdeu 30 de vida!\n";
            });

            fafich.adicionarOpcao("Passar pela Praca de Servicos", [](Personagem *p){
                p->alterarVida(30);

                Utils::coutDigitado() << "Que escolha sabia!\n";
                Utils::coutDigitado() << "Nao sabemos os perigos que a FAFICH pode esconder.\n";
                Utils::coutDigitado() << "O melhor caminho as vezes e o mais demorado.\n";
                Utils::coutDigitado() << "Voce chega revigorado para codar e esta mais contente do que nunca no coworking!\n";
                Utils::coutDigitado() << "Marcos ganhou 30 de vida!\n";
            });

            salas.push_back(fafich);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < (int)salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }
        } 
        throw std::invalid_argument("Erro: Nome de personagem invalido na Fabrica de Salas!");
    }
}