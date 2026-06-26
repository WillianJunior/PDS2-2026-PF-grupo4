#include "FabricaSC.hpp"
#include "Inimigo.hpp"
#include "Habilidade.hpp"
#include "Efeito.hpp"
#include <vector>
#include <cstdlib>

namespace FabricaSC {
    std::unique_ptr<SalaCombate> criarSalas(std::string nome, int idInimigo) {
        std::string tituloAndar = "Combate";

if (nome == "Maycon") {
            if (idInimigo == 1) { 
                std::string intro = "Você se depara com um inimigo silencioso, que consome toda sua vontade de codar.\nO inimigo sussurra: 'Não se preocupe, tem muito tempo ainda para terminar...'\nJogar um ClashRoyale não vai te matar\nA Procrastinação começa a atacar!";
                std::string vit = "Você venceu a procrastinação e agora tem ânimo suficiente para enfrentar os próximos desafios!";
                std::string der = "Você perdeu para a procrastinação, não consegue mais agir, está fraco e desanimado.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            } 
            else if (idInimigo == 2) { 
                std::string intro = "Em meio a uma sessão produtiva alucinante você encontrou um inimigo perverso.\nUm bug invisível, indecifrável, inencontrável.\nEle se esconde em meio ao código e te impede de prosseguir causando falhas generalizadas.";
                std::string vit = "Você venceu o bug sinistro e agora pode continuar codando tranquilamente.";
                std::string der = "Você foi vencido pelo bug, todo o seu sistema foi corroído e não pode mais continuar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 3) { 
                std::string intro = "Sua imunidade está baixíssima, e você foi atacado pelo pior inimigo que alguem pode enfrentar.\nA gripe de homem tenta te derrubar e te destruir. Se você deixar ela pode te deixar acamado por dias.";
                std::string vit = "Você venceu a gripe e pode continuar a programar.";
                std::string der = "Não!! A gripe de homem te pegou, você está morto.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 4) { 
                std::string intro = "Parece que você andou exagerando nas bebidinhas, você se depara com a iminência do alcoolismo.\nSe ele te vencer é possível que você não consiga terminar o jogo pois tera que ir para a reabilitação.";
                std::string vit = "Você venceu o vicio e está a limpo.";
                std::string der = "Você perdeu para o vicio, e irá direto pra clinica de reabilitação.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 5) { 
                std::string intro = "O terror da terramedia ressurgiu de mordor apenas para te impedir de continuar a programar o jogo.\nSauron veio para te destruir só para não ver o jogo ficar pronto.";
                std::string vit = "Você derrotou Sauron e agora pode continuar o jogo.";
                std::string der = "Você foi derrotado e Sauron te transformou em um Orc maligno que não sabe um if else.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
        }

 else if (nome == "Marcos") {
            if (idInimigo == 1) {
                std::string intro = "Você foi mais uma vez para Esmeraldas, você sabia que se fosse poderia não terminar o jogo pois lá se encontra seu inimigo terrível.\nA cabrita de Esmeraldas pode te dar uma cabeçada tão forte que é possível que você nunca mais consiga digitar uma linha de código.";
                std::string vit = "Voce venceu a cabrita e pode voltar pra BH pra codar.";
                std::string der = "Voce perdeu e terá que ficar em Esmeraldas para sempre.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            } 
            else if (idInimigo == 2) {
                std::string intro = "Você foi interceptado por um espirito obsessor que começa a influenciar seus pensamentos para que você pare imediatamente de programar o jogo.\nVocê terá que usar todas as suas forças para impedir a subjugação do espirito pois ele irá te dominar completamente.";
                std::string vit = "Você venceu o espirito e mandou ele para o umbral.";
                std::string der = "Você perdeu e o espirito tomou conta do seu pensamento, você não pode mais codar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 3) {
                std::string intro = "Um dos inimigos mais perversos acaba de cruzar o seu caminho.\nA carteira de trabalho fará você trabalhar como escravo por um mísero salário.\nComo você irá programar se vai sobrar apenas 4 horas para dormir?";
                std::string vit = "Você venceu a carteira de trabalho, está livre agora para codar.";
                std::string der = "Você perdeu, foi promovido a escala 6X1 presencial com 2 horas de trânsito pra chegar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 4) {
                std::string intro = "Parece um jogo inocente mas pode ser muito perverso.\nQuando Hearthstone cruza seu caminho é melhor vencê-lo pois ficará preso no vortex do jogo e não conseguirá sair mais.";
                std::string vit = "Você venceu e consegue fechar o jogo e continuar programando.";
                std::string der = "Você foi derrotado, agora ficará preso para sempre em 'só mais uma partidinha'.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 5) {
                std::string intro = "Você foi surpreendido pelo seu grande amigo Isaque, mas agora ele está possuído, não consegue parar de contar historias sobre suas ex namoradas.\nÉ melhor derrotá-lo pois ele não irá te deixar em paz nunca.";
                std::string vit = "Você venceu Isaque, conseguiu desmaiá-lo para poder codar em paz.";
                std::string der = "Você foi derrotado, ele não vai te deixar concentrar nunca mais.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
        }
        else if (nome == "Isaque") {
            if (idInimigo == 1) {
                std::string intro = "O seu inimigo mortal acaba de cruzar seu caminho.\nMunido de dopamina barata e scroll infinito, o maldito Reels não vai te deixar terminar o jogo.\nDerrote-o e mande todos os videos de sabonete sendo cortados para o inferno de onde eles vieram.";
                std::string vit = "Você derrotou o Reels, agora pode ter sua atenção de volta para programar.";
                std::string der = "Nãoo, você foi vencido, está completamente preso e não pode mais sair do Scroll infinito.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 2) {
                std::string intro = "Você estava andando de forma muito suspeita, agora precisa derrotar a policia para poder continuar programando.\nSe não derrotá-lo ele vai te incriminar e encher sua mochila de DVDs piratas.";
                std::string vit = "Você venceu a policia, pode seguir sua vida e terminar o jogo.";
                std::string der = "Foi derrotado, a policia te incriminou e você puxou 30 anos de cadeia.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 3) {
                std::string intro = "Você se deparou com seu inimigo mortal, a fome te impede de fazer qualquer coisa, ela não deixa você pensar em mais nada.\nÉ completamente impossível programar com fome!!!";
                std::string vit = "Você venceu a fome, pode seguir programando em paz.";
                std::string der = "Você foi vencido pela fome eterna, não há comida no mundo que tape esse buraco no estômago.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 4) {
                std::string intro = "Um dos piores inimigos existentes cruzam seu caminho, ele está totalmente tomado de crueldade e sadismo.\nTung Tung Sahur quer te destruir completamente.";
                std::string vit = "Você venceu Tung Tung Sahur esta livre para continuar codando.";
                std::string der = "Voce perdeu, Tung Tung Sahur roubou sua alma.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 5) {
                std::string intro = "Quando você menos esperava surge o inimigo a sua frente com seu skate maligno\nEnfrente Kick Butowski para continuar programando";
                std::string vit = "Você venceu Kick Butowski e não precisa praticar manobras mortais";
                std::string der = "Voce perdeu, Kick te obriga a praticar uma manobra mortal e você não pode mais codar";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
        }

        else if (nome == "Vaz") {
            if (idInimigo == 1) {
                std::string intro = "Um inimigo cruel cruza seu caminho: O Tempo.\nEle comprime suas 24 horas do dia para você não conseguir cumprir todas as suas tarefas e te impede de programar o jogo.";
                std::string vit = "Você venceu o tempo e agora tem tempo de sobra para programar.";
                std::string der = "Você foi derrotado e agora não consegue mais achar tempo para programar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            } 
            else if (idInimigo == 2) {
                std::string intro = "Você foi surpreendido pelo Carro do Fórmula.\nEle vai dar tantos defeitos que você jamais conseguirá prosseguir e continuar a programar. Derrote-o para conseguir continuar!";
                std::string vit = "Você venceu o carro do Fórmula e agora ele pode seguir sozinho pra competição.";
                std::string der = "Você perdeu para o carro do Fórmula e ele está com milhares de problemas.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 3) {
                std::string intro = "Você estava em um voo rotineiro quando foi surpreendido por um Míssil Antiaéreo.\nSe ele te pegar é possível que você nunca mais volte a codar.";
                std::string vit = "Você derrotou o míssil, pousou em segurança e pode voltar a programar.";
                std::string der = "Você perdeu para o terrível míssil e agora não consegue mais codar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 4) {
                std::string intro = "Você se depara com o temível Erro de Compilação Indecifrável.\nVocê não sabe onde começar a procurar, e se ele te derrotar pode nunca mais compilar nenhum código.";
                std::string vit = "Você venceu o erro de compilação! Agora pode continuar programando em paz.";
                std::string der = "Você foi derrotado, seu código não compila mais e você não pode continuar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 5) {
                std::string intro = "Um inimigo cruel cruza seu caminho, uma prova que parece impossível de resolver e que pode simplesmente te destruir por completo.\nSupere a Prova de Cálculo 2 para poder continuar programando.";
                std::string vit = "Você superou a prova de Cálculo 2 e pode usar todo seu raciocínio para programar agora.";
                std::string der = "Nãoo!! Você foi derrotado e agora está com 5 matérias travadas, você não vai conseguir terminar o jogo.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
        }
        else if (nome == "Nicole") {
            if (idInimigo == 1) {
                std::string intro = "Você foi surpreendida por seu cruel inimigo, a linguagem de programação de alto nível e propósito geral C++.\nCom todas as suas alocações de memória e ponto e vírgulas, se você não derrotá-la nunca poderá terminar o jogo.";
                std::string vit = "Você venceu o C++, agora que o domina pode seguir programando.";
                std::string der = "Você foi derrotada, nunca poderá terminar o jogo.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 2) {
                std::string intro = "Seu arco-inimigo está diante de você: o Git.\nCom suas branchs e merges infinitos apenas para causar confusão mental e te impedir de fazer um commit. Derrote-o para conseguir programar.";
                std::string vit = "Você venceu o Git e agora pode programar tranquila.";
                std::string der = "Você perdeu e não consegue salvar seus códigos, nunca conseguirá terminar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 3) {
                std::string intro = "Você se depara com um inimigo cruel, o VSCode.\nEle está fazendo de tudo para te impedir de compilar o seu código, elimine-o se quiser conseguir terminar.";
                std::string vit = "Você venceu e agora pode programar.";
                std::string der = "Você foi derrotada e no bloco de notas você não consegue programar porque não tem cores nas letras.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 4) {
                std::string intro = "Surge na sua frente um novo e fascinante livro, você não consegue segurar, precisa lê-lo inteiro imediatamente.\nSe não conseguir derrotá-lo não vai ter tempo de terminar o jogo.";
                std::string vit = "Você venceu a tentação, agora pode continuar programando.";
                std::string der = "Você perdeu, ficou presa na leitura e não pode continuar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
            else if (idInimigo == 5) {
                std::string intro = "Um inimigo terrível se aproxima: um Carro Manual.\nVocê não sabe como dirigi-lo e ele nunca irá sair da sua frente, como você irá programar agora?";
                std::string vit = "Você derrotou o carro e pode continuar programando.";
                std::string der = "Você perdeu, ficou presa na embreagem e não pode mais programar.";
                return std::unique_ptr<SalaCombate>(new SalaCombate(tituloAndar, intro, vit, der, nome, idInimigo));
            }
        }

        
        std::string intro = "CRITICAL ERROR: Memória violada. O Guardião do Ponteiro Nulo desperta!";
        return std::unique_ptr<SalaCombate>(new SalaCombate("SALA SEGFAULT", intro, "Memória restaurada.", "Core dumped.", nome, 1));
    }
}