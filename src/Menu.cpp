#include "Menu.hpp"
#include "InventarioHabilidade.hpp"
#include "InventarioItem.hpp"
#include <utility>

Menu::Menu(){
    //recursos de interface
}
Menu::~Menu(){
}

std::unique_ptr<Personagem> Menu::executarMenuInicial() {
    int opcao = 0;
    std::cout << "=============================================" << std::endl;
    std::cout << "===================ENREDO====================" << std::endl;
    std::cout << "1 - New Game" << std::endl;
    std::cout << "2 - OUT" << std::endl;
    std::cout << "Escolha uma opcao: ";
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
    std::cout << "==============Historia================" << std::endl;
    std::cout << "==============Personagens=============" << std::endl;
    std::cin >> classeEscolhida;

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
    // +++++IMPLEMENTAR CONDIÇÕES PARA AS OUTRAS CLASSES

    return std::unique_ptr<Personagem>(new Personagem(vidaInicial, habilidadesIniciais, nomePersonagem, itensIniciais));

}
