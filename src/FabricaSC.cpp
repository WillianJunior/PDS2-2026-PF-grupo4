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
            
            std::string introProcastinacao = 
                "Você se depara com um inimigo silencioso, que consome toda sua vontade de codar.\n"
                "O inimigo sussurra: 'Não se preocupe, tem muito tempo ainda para terminar...\n"
                "Vou eliminar toda sua motivação pela raiz, você não vai levantar mais da cama.'\n"
                "A Procrastinação começa a atacar!";
            std::string vitProcastinacao = "Você venceu a procrastinação e agora tem ânimo suficiente para enfrentar os próximos desafios!";
            std::string derProcastinacao = "Você perdeu para a procrastinação, não consegue mais agir, está fraco e desanimado.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introProcastinacao, vitProcastinacao, derProcastinacao, nome, andar)));

            std::string introBug = 
                "Em meio a uma sessão produtiva alucinante você encontrou um inimigo perverso.\n"
                "Um bug invisível, indecifrável, inencontrável.\n"
                "Ele se esconde em meio ao código e te impede de prosseguir causando falhas generalizadas.";
            std::string vitBug = "Você venceu o bug sinistro e agora pode continuar codando tranquilamente.";
            std::string derBug = "Você foi vencido pelo bug, todo o seu sistema foi corroído e não pode mais continuar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introBug, vitBug, derBug, nome, andar)));

            std::string introGripe = 
                "Sua imunidade está baixíssima, e você foi atacado pelo pior inimigo que alguem pode enfrentar.\n"
                "A gripe de homem tenta te derrubar e te destruir. Se você deixar, ela pode te deixar acamado por dias.";
            std::string vitGripe = "Você venceu a gripe e pode continuar a programar.";
            std::string derGripe = "Não!! A gripe de homem te pegou, você está morto.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introGripe, vitGripe, derGripe, nome, andar)));

            std::string introAlcool = 
                "Parece que você andou exagerando nas bebidinhas, você se depara com a iminência do alcoolismo.\n"
                "Se ele te vencer é possível que você não consiga terminar o jogo pois terá que ir para a reabilitação.";
            std::string vitAlcool = "Você venceu o vício e está a limpo.";
            std::string derAlcool = "Você perdeu para o vício, e irá direto pra clínica de reabilitação.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introAlcool, vitAlcool, derAlcool, nome, andar)));

            std::string introSauron = 
                "O terror da Terra Média ressurgiu de Mordor apenas para te impedir de continuar a programar o jogo.\n"
                "Sauron veio para te destruir só para não ver o jogo ficar pronto.";
            std::string vitSauron = "Você derrotou Sauron e agora pode continuar o jogo.";
            std::string derSauron = "Você foi derrotado e Sauron te transformou em um Orc maligno que não sabe um if else.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introSauron, vitSauron, derSauron, nome, andar)));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Marcos") {
            
            std::string introCabrita = 
                "Você foi mais uma vez para Esmeraldas, você sabia que se fosse poderia não terminar o jogo, pois lá se encontra seu inimigo terrível.\n"
                "A cabrita de Esmeraldas pode te dar uma cabeçada tão forte que é possível que você nunca mais consiga digitar uma linha de código.";
            std::string vitCabrita = "Você venceu a cabrita e pode voltar pra BH pra codar.";
            std::string derCabrita = "Você perdeu e terá que ficar em Esmeraldas para sempre.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introCabrita, vitCabrita, derCabrita, nome, andar)));

            std::string introEspirito = 
                "Você foi interceptado por um espírito obsessor que começa a influenciar seus pensamentos para que você pare imediatamente de programar o jogo.\n"
                "Você terá que usar todas as suas forças para impedir a subjugação do espírito pois ele irá te dominar completamente.";
            std::string vitEspirito = "Você venceu o espírito e mandou ele para o umbral.";
            std::string derEspirito = "Você perdeu e o espírito tomou conta do seu pensamento, você não pode mais codar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introEspirito, vitEspirito, derEspirito, nome, andar)));

            std::string introCLT = 
                "Um dos inimigos mais perversos acaba de cruzar o seu caminho.\n"
                "A carteira de trabalho fará você trabalhar como escravo por um mísero salário.\n"
                "Como você irá programar se vai sobrar apenas 4 horas para dormir?";
            std::string vitCLT = "Você venceu a carteira de trabalho, está livre agora para codar.";
            std::string derCLT = "Você perdeu, foi promovido a escala 6x1 presencial com 2 horas de trânsito pra chegar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introCLT, vitCLT, derCLT, nome, andar)));

            std::string introHearthstone = 
                "Parece um jogo inocente mas pode ser muito perverso.\n"
                "Quando Hearthstone cruza seu caminho é melhor vencê-lo, pois ficará preso no vortex do jogo e não conseguirá sair mais.";
            std::string vitHearthstone = "Você venceu e consegue fechar o jogo e continuar programando.";
            std::string derHearthstone = "Você foi derrotado, agora ficará preso para sempre em 'só mais uma partidinha'.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introHearthstone, vitHearthstone, derHearthstone, nome, andar)));
            
            std::string introPossuido = 
                "Você foi surpreendido pelo seu grande amigo Isaque, mas agora ele está possuído, não consegue parar de contar historias sobre suas ex namoradas.\n"
                "É melhor derrotá-lo pois ele não irá te deixar em paz nunca.";
            std::string vitPossuido = "Você venceu Isaque, conseguiu desmaiá-lo para poder codar em paz.";
            std::string derPossuido = "Você foi derrotado, ele não vai te deixar concentrar nunca mais.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introPossuido, vitPossuido, derPossuido, nome, andar)));


            int num = rand() % salas.size();
            return std::move(salas[num]);
        }

        else if (nome == "Isaque") {

            std::string introReels = 
                "O seu inimigo mortal acaba de cruzar seu caminho.\n"
                "Munido de dopamina barata e scroll infinito, o maldito Reels não vai te deixar terminar o jogo.\n"
                "Derrote-o e mande todos os vídeos de sabonete sendo cortados para o inferno de onde eles vieram.";
            std::string vitReels = "Você derrotou o Reels, agora pode ter sua atenção de volta para programar.";
            std::string derReels = "Nãoo, você foi vencido, está completamente preso e não pode mais sair do scroll infinito.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introReels, vitReels, derReels, nome, andar)));

            std::string introPolicia = 
                "Você estava andando de forma muito suspeita, agora precisa derrotar a polícia para poder continuar programando.\n"
                "Se não derrotá-lo ele vai te incriminar e encher sua mochila de DVDs piratas.";
            std::string vitPolicia = "Você venceu a polícia, pode seguir sua vida e terminar o jogo.";
            std::string derPolicia = "Foi derrotado, a polícia te incriminou e você puxou 30 anos de cadeia.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introPolicia, vitPolicia, derPolicia, nome, andar)));

            std::string introFome = 
                "Você se deparou com seu inimigo mortal, a fome te impede de fazer qualquer coisa, ela não deixa você pensar em mais nada.\n"
                "É completamente impossível programar com fome!!!";
            std::string vitFome = "Você venceu a fome, pode seguir programando em paz.";
            std::string derFome = "Você foi vencido pela fome eterna, não há comida no mundo que tape esse buraco no estômago.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introFome, vitFome, derFome, nome, andar)));

            std::string introTunTun = 
                "Um dos piores inimigos existentes cruza seu caminho, ele está totalmente tomado de crueldade e sadismo.\n"
                "Tung Tung Sahur quer te destruir completamente.";
            std::string vitTunTun = "Você venceu Tung Tung Sahur e está livre para continuar codando.";
            std::string derTunTun = "Você perdeu, Tung Tung Sahur roubou sua alma.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introTunTun, vitTunTun, derTunTun, nome, andar)));

            std::string introKick = 
                "Você foi surpreendido por um inimigo cruel, com todas suas manobras de skate radicais ele pode sugar sua alma até você não poder codar mais.\n"
                "Kick Buttowski vai te obrigar a realizar uma manobra mortal, derrote-o.";
            std::string vitKick = "Você venceu, conseguiu passar pela sua crueldade.";
            std::string derKick = "Você perdeu, não conseguirá mais codar sem sua alma.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introKick, vitKick, derKick, nome, andar)));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 
        else if (nome == "Vaz") {
            
            std::string introTempo = 
                "Um inimigo cruel cruza seu caminho, o tempo. Ele comprime suas 24 horas do dia para você não conseguir cumprir todas as suas tarefas e te impede de programar o jogo.";
            std::string vitTempo = "Você venceu o tempo e agora tem tempo de sobra para programar.";
            std::string derTempo = "Você foi derrotado e agora não consegue mais achar tempo para programar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introTempo, vitTempo, derTempo, nome, andar)));

            std::string introFormula = 
                "Você foi surpreendido pelo carro do Fórmula, ele vai dar tantos defeitos que você jamais conseguirá prosseguir e continuar a programar.\n"
                "Derrote ele para conseguir continuar programando.";
            std::string vitFormula = "Você venceu o carro do Fórmula e agora ele pode seguir sozinho pra competição.";
            std::string derFormula = "Você perdeu para o carro do Fórmula e ele está com milhares de problemas.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introFormula, vitFormula, derFormula, nome, andar)));

            std::string introMissel = 
                "Você estava em um voo rotineiro quando foi surpreendido por um míssel antiaéreo. Se ele te pegar é possível que você nunca mais volte a codar.";
            std::string vitMissel = "Você derrotou o míssil, pousou em segurança e pode voltar a programar.";
            std::string derMissel = "Você perdeu para o terrível míssil e agora não consegue mais codar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introMissel, vitMissel, derMissel, nome, andar)));

            std::string introErroCompilacao = 
                "Você se depara com o temível erro de compilação indescritível, você não sabe onde começa a procurar.\n"
                "Se ele te derrotar pode nunca mais compilar nenhum código.";
            std::string vitErroCompilacao = "Você venceu o erro de compilação, agora pode continuar programando em paz.";
            std::string derErroCompilacao = "Você foi derrotado, seu código não compila mais e você não pode continuar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introErroCompilacao, vitErroCompilacao, derErroCompilacao, nome, andar)));

            std::string introCalculo = 
                "Um inimigo cruel cruza seu caminho, uma prova que parece impossível de resolver e que pode simplesmente te destruir por completo.\n"
                "Supere a prova de Cálculo 2 para poder continuar programando.";
            std::string vitCalculo = "Você superou a prova de Cálculo 2 e pode usar todo seu raciocínio para programar agora.";
            std::string derCalculo = "Nãoo!! Você foi derrotado e agora está com 5 matérias travadas, você não vai conseguir terminar o jogo.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introCalculo, vitCalculo, derCalculo, nome, andar)));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        } 

        else if (nome == "Nicole") {
            
            std::string introCpp = 
                "Você foi surpreendida por seu cruel inimigo, a linguagem de programação de alto nível e propósito geral C++.\n"
                "Com todas as suas alocações de memória e ponto-e-vírgulas, se você não derrotá-la nunca poderá terminar o jogo.";
            std::string vitCpp = "Você venceu o C++, agora que o domina pode seguir programando.";
            std::string derCpp = "Você foi derrotada, nunca poderá terminar o jogo.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introCpp, vitCpp, derCpp, nome, andar)));

            std::string introGit = 
                "Seu arco-inimigo está diante de você, o Git com suas branchs e merges infinitas apenas para causar confusão mental e te impedir de fazer um commit.\n"
                "Derrote para conseguir programar.";
            std::string vitGit = "Você venceu o Git e agora pode programar tranquila.";
            std::string derGit = "Você perdeu e não consegue salvar seus códigos, nunca conseguirá terminar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introGit, vitGit, derGit, nome, andar)));

            std::string introVscode = 
                "Você se depara com um inimigo cruel, o VSCode está fazendo de tudo para impedir você de compilar o seu código.\n"
                "Elimine-o se quiser conseguir terminar.";
            std::string vitVscode = "Você venceu e agora pode programar.";
            std::string derVscode = "Você foi derrotada e no bloco de notas você não consegue programar porque não tem cores nas letras.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introVscode, vitVscode, derVscode, nome, andar)));

            std::string introLivro = 
                "Surge na sua frente um novo e fascinante livro, você não consegue segurar, precisa lê-lo inteiro imediatamente.\n"
                "Se não conseguir derrotar não vai ter tempo de terminar o jogo.";
            std::string vitLivro = "Você venceu, agora pode continuar programando.";
            std::string derLivro = "Você perdeu, ficou presa na leitura e não pode continuar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introLivro, vitLivro, derLivro, nome, andar)));

            std::string introCarro = 
                "Um inimigo terrível se aproxima, um carro manual. Você não sabe como dirigi-lo e ele nunca irá sair da sua frente.\n"
                "Como você irá programar agora?";
            std::string vitCarro = "Você derrotou o carro e pode continuar programando.";
            std::string derCarro = "Você perdeu, ficou presa na embreagem e não pode mais programar.";
            salas.push_back(std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, introCarro, vitCarro, derCarro, nome, andar)));

            int num = rand() % salas.size();
            return std::move(salas[num]);
        }
        
        
        else {
            std::string historia = "CRITICAL ERROR: Memória violada. O Guardião do Ponteiro Nulo desperta!";
            std::string vit = "Sistema recuperado com sucesso.";
            std::string der = "Segmentation Fault (core dumped).";
            
            return std::unique_ptr<SalaCombate>(new SalaCombate("SALA SEGFAULT", historia, vit, der, nome, andar));
        }
    }
}