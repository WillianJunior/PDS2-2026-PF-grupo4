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
            animacaoNatora.tempoFrame = 450;
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
            });
            Natora.adicionarOpcao("Nao ir para o natora", [](Personagem *p){
                p->alterarVida(-10);
                Utils::coutDigitado() << "Voce negou a saída naquele dia, voce sabia que precisava codar.\n";
                Utils::coutDigitado() << "Subindo na moto e indo para a casa, voce sentiu o FOMO lhe consumir.\n";
                Utils::coutDigitado() << "Chateado por não ter descansado a cabeça e por não ter relaxado, você sente a dor do FOMO.\n";
                Utils::coutDigitado() << "o Fear of Missing Out retira 10 de vida de Maycon.\n";
            });
            salas.push_back(Natora);

            Utils::Animacao animacaonewtonEspirito;
            animacaonewtonEspirito.tempoFrame = 1200;
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

            SalaEscolha newtonEspirito("Encontro com a genialidade", animacaonewtonEspirito, 1);
            newtonEspirito.adicionarOpcao("Apertar a mao de Isaac Newton", [](Personagem *p){
                Habilidade habilidade = FabricaHabilidade::criarHabilidade("Raio Gravitacional");
                Utils::coutDigitado() << "Voce se levanta para apertar a mao do grandioso Isaac Newton.\n";
                Utils::coutDigitado() << "Quanto mais voce se aproxima, mais voce percebe a aura de sua inteligencia.\n";
                Utils::coutDigitado() << "Apenas de tocar, apenas tocar aquela mao... te deu uma sensacao, como se tivesse aprendido algo novo.\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "Voce acorda e seus olhos se abrem, tudo foi um sonho, mas o conhecimento ficou.\n";
                Utils::coutDigitado() << "Maycon aprendeu Raio Gravitacional.\n";
                
            });
            newtonEspirito.adicionarOpcao("Ignorar o dom da sabedoria", [](Personagem *p){
                Habilidade habilidade = FabricaHabilidade::criarHabilidade("Raio Mayconiano");
                p->getInventarioHabilidade().novaAcao(habilidade);
                Utils::coutDigitado() << "Voce se recusa a apertar a mao do grandioso Isaac Newton.\n";
                Utils::coutDigitado() << "Lembrou-se de tudo que Gerald Weber lhe ensinou e percebeu que, na verdade...\n";
                Utils::coutDigitado() << "Isaac Newton era mediocre.\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "...\n";
                Utils::coutDigitado() << "Voce acorda e seus olhos se abrem, tudo foi um sonho, mas a autoconfianca ficou.\n";
                Utils::coutDigitado() << "Se vendo como um inventor melhor do que o cientista Isaac Newton, Maycon aprende e CRIA algo novo.\n";
                Utils::coutDigitado() << "Maycon aprendeu Raio Mayconiano.\n";
            });
            salas.push_back(newtonEspirito);
        
        Utils::Animacao animacaoFernandoPessoa;
            animacaoFernandoPessoa.textoInicial.push_back("O mundo computacional o deixa ansioso, sendo a natureza uma fuga do estresse para o heroi.");
            animacaoFernandoPessoa.textoInicial.push_back("Maycon senta-se em um banco e observa os passaros partirem migrando em bando.");
            animacaoFernandoPessoa.textoInicial.push_back("Nao seria a natureza uma imagem-espelho de toda criacao?");
            animacaoFernandoPessoa.textoInicial.push_back("A natureza copia a humanidade ou a humanidade copia a natureza?");
            animacaoFernandoPessoa.textoInicial.push_back("Ao ver aquele bando, Maycon se sentiu inspirado, e antes de voltar a codar, queria escrever uma poesia.");
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
            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                       v
                  /|\_                              ^           -
                 /_|__                                    v
                |_____|                             -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                        -
                  /|\_                               -           v
                 /_|__                                     -
                |_____|                              ^
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                         ^
                  /|\_                                v           -
                 /_|__                                      ^
                |_____|                               -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                          -
                  /|\_                                 -           ^
                 /_|__                                       -
                |_____|                                v
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                           v
                  /|\_                                  ^          
                 /_|__                                        v
                |_____|                                 -
            )");

            animacaoFernandoPessoa.frames.push_back(R"( 
                   O                                            
                  /|\_                                   -         
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
            
        SalaEscolha FernandoPessoa("Poesia em vida", animacaoFernandoPessoa, 2);
        FernandoPessoa.adicionarOpcao("Escrever sobre a arte de codar", [](Personagem *p){
        Item itens = FabricaItem::criarItem("Bencao de Linus Torvald");
        p->getInventarioItem().novaAcao(itens);
        Utils::coutDigitado() << "\"...Outrora eu era deste escopo, e hoje regresso estrangeiro,\n";
        Utils::coutDigitado() << "Forasteiro da logica que leio, obsoleto de mim.\n";
        Utils::coutDigitado() << "Ja vi todos os bugs, ainda os que nunca criei, nem os que nunca resolverei.\n";
        Utils::coutDigitado() << "Eu reinei no sistema que nunca rodei...\"\n";
        });

        FernandoPessoa.adicionarOpcao("Escrever sobre o observar e viver", [](Personagem *p){
        Item itens = FabricaItem::criarItem("Bencao da Salvia");
        Utils::coutDigitado() << "\"...Outrora eu era a acao, e hoje regresso espectador,\n";
        Utils::coutDigitado() << "Amante do que vejo e ouco, pleno de mim.\n";
        Utils::coutDigitado() << "Contemplo tudo, ainda o que nunca vi, nem o que nunca verei.\n";
        Utils::coutDigitado() << "Eu reinei no que apenas observei...\"\n";
        p->getInventarioItem().novaAcao(itens);
        });

            salas.push_back(FernandoPessoa);
            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < salas.size()) {
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

        formulaIncidente.adicionarOpcao("Codar a Fabrica de Salas", [](Personagem *p){
            Habilidade hab = FabricaHabilidade::criarHabilidade("Doxygengaboom");
            p->getInventarioHabilidade().novaAcao(hab);
            
            Utils::coutDigitado() << "Nesse dia, voce decidiu ir codar e estudar.\n";
            Utils::coutDigitado() << "Vendo o que o William pedia, voce estudou os doxygen.\n";
            Utils::coutDigitado() << "Voce percebeu que estava ficando bom naquilo...\n";
            Utils::coutDigitado() << "Vaz aprendeu o Doxygengaboom!\n";
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
            Habilidade hab = FabricaHabilidade::criarHabilidade("Maldade Humana");
            p->getInventarioHabilidade().novaAcao(hab);
            
            Utils::coutDigitado() << "Voce percebeu que nao ia dar tempo e utilizou de metodos impuros.\n";
            Utils::coutDigitado() << "Voce se sentiu mal por isso, e isso te consumiu por dentro...\n";
            Utils::coutDigitado() << "Mas voce aprendeu a maldade...\n";
            Utils::coutDigitado() << "Vaz perdeu 10 de vida!\n";
            Utils::coutDigitado() << "Vaz aprendeu a habilidade Maldade Humana!\n";
        });

        checkpointAtrasado.adicionarOpcao("Codar no VSCODE", [](Personagem *p){
            p->alterarVida(20);
            Habilidade hab = FabricaHabilidade::criarHabilidade("Poder da Amizade");
            p->getInventarioHabilidade().novaAcao(hab);
            
            Utils::coutDigitado() << "Nao ficou da melhor forma, mas voce percebeu...\n";
            Utils::coutDigitado() << "Que voce tem o apoio do seu grupo!\n";
            Utils::coutDigitado() << "Voce os avisou e eles o apoiaram na parte que faltava.\n";
            Utils::coutDigitado() << "A amizade e o laco que os une.\n";
            Utils::coutDigitado() << "Vaz recuperou 20 de vida!\n";
            Utils::coutDigitado() << "Vaz aprendeu a habilidade Poder da Amizade!\n";
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
            Item item = FabricaItem::criarItem("Energetico");
            p->getInventarioItem().novaAcao(item);
            
            Utils::coutDigitado() << "Ouvindo uma Katy Perry voce nao poderia se sentir melhor.\n";
            Utils::coutDigitado() << "A energia te fez lembrar ate de algo que guardava!\n";
            Utils::coutDigitado() << "Abrindo o porta-luvas pode ver um...\n";
            Utils::coutDigitado() << "Um energetico!\n";
            Utils::coutDigitado() << "Vaz ganhou o item Energetico.\n";
        });

        spotify.adicionarOpcao("Escutar Crina Negra - Canarios do Reino", [](Personagem *p){
            Habilidade hab = FabricaHabilidade::criarHabilidade("Passinho do Forro");
            p->getInventarioHabilidade().novaAcao(hab);
            
            Utils::coutDigitado() << "Ouvindo o grupo Ferrugem, Vaz lembrou de seu amigo Marcos.\n";
            Utils::coutDigitado() << "Conseguiu lembrar como Marcos dancava forro bem!\n";
            Utils::coutDigitado() << "Ao som da musica e das memorias de Marcos, Vaz captou a energia do forro.\n";
            Utils::coutDigitado() << "Vaz aprendeu o Passinho do Forro!\n";
        });

        spotify.adicionarOpcao("Escutar Razoes e Emocoes - NX Zero", [](Personagem *p){
            p->alterarVida(-15);
            Utils::coutDigitado() << "Vaz ouviu Razoes e Emocoes e aquela musica...\n";
            Utils::coutDigitado() << "Aquela musica mexeu com ele.\n";
            Utils::coutDigitado() << "Enquanto ouvia, sofreu com os vocais do Di e a letra sofrida...\n";
            Utils::coutDigitado() << "Por mais que seja um bom rock, Vaz ficou melancolico.\n";
            Utils::coutDigitado() << "Vaz perdeu 15 de vida!\n";
        });

        salas.push_back(spotify);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }

        } 
        else if (nome == "Isaque") {
<<<<<<< HEAD
            SalaEscolha sala1("Sala do Isaque", animacao);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Isaque", animacao);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Isaque", animacao);
=======
            SalaEscolha sala1("Sala do Isaque 1", animacao, 0);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Isaque 2", animacao, 1);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Isaque 3", animacao, 2);
>>>>>>> f902e02f66fa6feef8a6bf1feccff0abbe37c00b
            salas.push_back(sala3);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }
        } 
        else if (nome == "Nicole") {
<<<<<<< HEAD
            SalaEscolha sala1("Sala do Nicole", animacao);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Nicole", animacao);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Nicole", animacao);
=======
            SalaEscolha sala1("Sala do Nicole 1", animacao, 0);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Nicole 2", animacao, 1);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Nicole 3", animacao, 2);
>>>>>>> f902e02f66fa6feef8a6bf1feccff0abbe37c00b
            salas.push_back(sala3);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }
        } 
        else if (nome == "Marcos") {
<<<<<<< HEAD
            SalaEscolha sala1("Sala do Marcos", animacao);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Marcos", animacao);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Marcos", animacao);
=======
            SalaEscolha sala1("Sala do Marcos 1", animacao, 0);
            // sala1.adicionarOpcao(descricao, consequencia);
            salas.push_back(sala1);
            SalaEscolha sala2("Sala do Marcos 2", animacao, 1);
            salas.push_back(sala2);
            SalaEscolha sala3("Sala do Marcos 3", animacao, 2);
>>>>>>> f902e02f66fa6feef8a6bf1feccff0abbe37c00b
            salas.push_back(sala3);

            if (idEscolha != -1 && idEscolha >= 0 && idEscolha < salas.size()) {
                return salas[idEscolha];
            } else {
                int numeroEscolhido = rand() % 3;
                return salas[numeroEscolhido];
            }
        } 
        else {
            SalaEscolha salaSegFault("Seg Fault", animacao);
            return salaSegFault; // tem q ser uma sala de segmentationfault, de erro
        }
    }
}
