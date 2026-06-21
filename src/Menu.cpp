#include "Menu.hpp"
#include "InventarioHabilidade.hpp"
#include "InventarioItem.hpp"
#include <utility>
#include "Utils.hpp"

Menu::Menu(){
    //recursos de interface
}

Menu::~Menu(){
}

std::unique_ptr<Personagem> Menu::executarMenuInicial() {
    int opcao = 0;
    std::string menu = R"(
    +-------------------------------------+
    |                                     |
    |       WE CANT CODE THIS GAME        |
    |                                     |
    +-------------------------------------+
    |                                     |
    |         > 1 - New Game              |
    |         > 2 - Out                   |
    |                                     |
    +-------------------------------------+
)";
    std::cout << menu;
    std::cin >> opcao;

    switch (opcao)
    {
    case 1:
        return this->escolherPersonagemInicial();
    case 2:
    default:
        return nullptr;
    }
}

std::unique_ptr<Personagem> Menu::escolherPersonagemInicial() {
    int classeEscolhida = 0;
    Utils::limparTela();
    Utils::esperar(150);

    // O Professor
    Utils::coutDigitado(75) << "Entao e isso meus alunos, o grande trabalho de voces para esse semestre e implementar um projeto de medio porte com C++.\n";
    Utils::coutDigitado(75) << "As instrucoes estarao no Moodle.\n\n";
    Utils::coutDigitado(250) << "Boa sorte. Voces vao precisar.\n\n";
    // alguma animaçao 
    Utils::esperar(400);
    // A Introdução
    Utils::coutDigitado(85) << "Desde o dia em que William trouxe a grande missao, 5 herois se dispuseram a concluir esse desafio. A jornada nao seria facil, nao seria simples e nao seria rapida, mas seria uma jornada e tanto.\n\n";

    // Herói 1: Maycon
    std::vector<std::string> animacaoMaycon = {
        R"(
          .------.
         /  o  o  \
        |    __    |
         \        /
          '------'
        )",
        R"(
          .------.
         /  >  <  \
        |    __    |
         \        /
          '------'
        )"
    };
    for (size_t i = 0; i < animacaoMaycon.size(); ++i) {
        Utils::limparTela();
        std::cout << animacaoMaycon[i] << "\n";
        if (i < animacaoMaycon.size() - 1) {
            Utils::esperar(400); 
        }
    }
    Utils::coutDigitado(75) << "O primeiro dos 5 herois seria Maycon, um bravo lutador alquimista. A historia nos conta que, certo dia, tentaram envenenar Maycon com 50 litros de veneno.\n";
    Utils::coutDigitado(75) << "Bastou um Xeque-Mate para que o nosso heroi resistisse a todo efeito daquele veneno.\n\n";

    // Herói 2: Vaz
    std::vector<std::string> animacaoVaz = {
        R"(
          .------.
         /  o  o  \
        |    __    |
         \        /
          '------'
        )",
        R"(
          .------.
         /  >  <  \
        |    __    |
         \        /
          '------'
        )"
    };
    for (size_t i = 0; i < animacaoVaz.size(); ++i) {
        Utils::limparTela();
        std::cout << animacaoVaz[i] << "\n";
        if (i < animacaoVaz.size() - 1) {
            Utils::esperar(400); 
        }
    }
    Utils::coutDigitado(75) << "O segundo desse esquadrao seria Vaz, conhecido por suas habilidades aereas e pelo seu grande senso de humor. Certo dia, havia um silencio pairando na sala, Vaz entao contou uma piada e, desde entao, fazem 50 anos que a sala nao para de rir.\n\n";

    // Heroína 3: Nicole
    std::vector<std::string> animacaoNicole = {
        R"(
          .------.
         /  o  o  \
        |    __    |
         \        /
          '------'
        )",
        R"(
          .------.
         /  >  <  \
        |    __    |
         \        /
          '------'
        )"
    };
    for (size_t i = 0; i < animacaoNicole.size(); ++i) {
        Utils::limparTela();
        std::cout << animacaoNicole[i] << "\n";
        if (i < animacaoNicole.size() - 1) {
            Utils::esperar(400); 
        }
    }
    Utils::coutDigitado(75) << "A terceira heroina se chama Nicole, a garota que ganhou o grande titulo de exterminar toda producao de Coca-Cola em BH e regiao. O governo decidia por politicas para diminuir o consumo de Coca-Cola a fim de melhorar a saude populacional; sabendo disso, Nicole bebeu todos os litros de Coca-Cola e garantiu a saude da vila Belo Horizonte pelos proximos 15 anos.\n\n";

    // Herói 4: Marcos
    std::vector<std::string> animacaoMarcos = {
        R"(
          .------.
         /  o  o  \
        |    __    |
         \        /
          '------'
        )",
        R"(
          .------.
         /  >  <  \
        |    __    |
         \        /
          '------'
        )"
    };
    for (size_t i = 0; i < animacaoMarcos.size(); ++i) {
        Utils::limparTela();
        std::cout << animacaoMarcos[i] << "\n";
        if (i < animacaoMarcos.size() - 1) {
            Utils::esperar(400); 
        }
    }
    Utils::coutDigitado(75) << "O quarto heroi, conhecido por Marcos, hipnotiza seus inimigos com seus bravos passos de forro. Uma vez, Marcos passou pela Praca de Servicos e dancou com uma garota. As lendas dizem que essa menina vaga pela UFMG ja fazem 20 anos em busca de encontrar alguem que fizesse-a dancar tao bem.\n\n";

    // Herói 5: Isaque
    std::vector<std::string> animacaoIsaque = {
        R"(
          .------.
         /  o  o  \
        |    __    |
         \        /
          '------'
        )",
        R"(
          .------.
         /  >  <  \
        |    __    |
         \        /
          '------'
        )"
    };
    for (size_t i = 0; i < animacaoIsaque.size(); ++i) {
        Utils::limparTela();
        std::cout << animacaoIsaque[i] << "\n";
        if (i < animacaoIsaque.size() - 1) {
            Utils::esperar(400); 
        }
    }
    Utils::coutDigitado(75) << "O quinto heroi chama-se Isaque, guerreiro que durante sua jornada acumulou aliados por onde passava. Em uma de suas aventuras, se encontrava em apuros mas nao se preocupou, pois em um grito sonoro e longinquo ele disse: \"MINHA EX, RETORNE!\", rapidamente ela exterminou quem o assolava.\n\n";

    Utils::coutDigitado() << "Com qual grande heroi voce ira seguir essa aventura?\n";
    Utils::coutDigitado(10) << "[1] Maycon - O Lutador Alquimista\n";
    Utils::coutDigitado(10) << "[2] Vaz    - O Mestre dos Ares\n";
    Utils::coutDigitado(10) << "[3] Nicole - A Exterminadora de Coca-Cola\n";
    Utils::coutDigitado(10) << "[4] Marcos - O Hipnotizador do Forro\n";
    Utils::coutDigitado(10) << "[5] Isaque - O Invocador de Aliados\n\n";
    
    bool escolhaValida = false;
    std::string entradaUsuario;

    while (!escolhaValida) {
        std::cin >> entradaUsuario;
        if (std::cin.eof()) {
            throw std::runtime_error("EOF: NAO TEM ESCOLHA\n");
        }
        try {
            classeEscolhida = std::stoi(entradaUsuario);
            if (classeEscolhida < 1 || classeEscolhida > 5) {
                Utils::coutDigitado() << "Escolha um dos herois de 1 a 5.\n";
                } else {
                escolhaValida = true;}
        } 
        catch (const std::invalid_argument& e) {
            Utils::coutDigitado() << "Escolha pelo numero, um heroi de 1 a 5.\n";} 
        catch (const std::out_of_range& e) {
            Utils::coutDigitado() << "Numero grande demais! Escolha um heroi de 1 a 5.\n";}
    }

    InventarioHabilidade habilidadesIniciais;
    InventarioItem itensIniciais;

    std::string nomePersonagem = "Maycon";
    int vidaInicial = 100;

    if (classeEscolhida == 1) {
        nomePersonagem = "Maycon";
        vidaInicial = 120;
        
        Efeito semEfeito("Nenhum", 0, 0);
        Habilidade ataqueBasico("Investida", false, 25, false, semEfeito);
        habilidadesIniciais.novaAcao(ataqueBasico);
        
        Item xequemate("Xeque-Mate", true, 40, semEfeito, true);
        itensIniciais.novaAcao(xequemate);
    }
    if (classeEscolhida == 2) {
        nomePersonagem = "Vaz";
        vidaInicial = 100;
        
        Efeito semEfeito("Nenhum", 0, 0);
        Habilidade ataqueBasico("Contar uma piada", false, 15, false, semEfeito); // colocar um efeito
        habilidadesIniciais.novaAcao(ataqueBasico);
        
        Habilidade ataqueEspecial("Forcas Aereas", false, 40, false, semEfeito);
        habilidadesIniciais.novaAcao(ataqueEspecial);
    }
    if (classeEscolhida == 3) {
        nomePersonagem = "Nicole";
        vidaInicial = 120;
        
        Efeito semEfeito("Nenhum", 0, 0);
        Habilidade ataqueBasico("Arremesar um Livro", false, 25, false, semEfeito);
        habilidadesIniciais.novaAcao(ataqueBasico);
        
        Item cocacola("Coca-cola", true, 40, semEfeito, true);
        itensIniciais.novaAcao(cocacola);
    }
    if (classeEscolhida == 4) {
        nomePersonagem = "Marcos";
        vidaInicial = 120;
        
        Efeito semEfeito("Nenhum", 0, 0);
        Habilidade ataqueBasico("Passinho do Forro", false, 15, false, semEfeito); // colocar um efeito
        habilidadesIniciais.novaAcao(ataqueBasico);
        
        Item aguabenta("Agua Benta", true, 40, semEfeito, true);
        itensIniciais.novaAcao(aguabenta);
    }
    if (classeEscolhida == 5) {
        nomePersonagem = "Isaque";
        vidaInicial = 120;
        
        Efeito semEfeito("Nenhum", 0, 0);
        Habilidade ataqueBasico("Aviaozinho de Papel", false, 25, false, semEfeito);
        habilidadesIniciais.novaAcao(ataqueBasico);
        
        Habilidade chamarEx("Chamar a Ex", false, 15, false, semEfeito); // colocar um efeito
        habilidadesIniciais.novaAcao(chamarEx);
    }
    

    return std::unique_ptr<Personagem>(new Personagem(vidaInicial, habilidadesIniciais, nomePersonagem, itensIniciais));

}
