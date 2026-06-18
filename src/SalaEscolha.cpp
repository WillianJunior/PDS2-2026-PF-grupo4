#include "SalaEscolha.hpp"
#include <limits>
#include <random>
#include "Utils.hpp"

SalaEscolha::SalaEscolha(std::string nome, std::string historia) 
    : SalaBase(nome), _historia(historia) {}

// adiciona uma opcao no vetores de opcoes que aquela salaescolha possui
void SalaEscolha::adicionarOpcao(std::string descricao, std::function<void(Personagem*)> consequencia){
    _opcoes.push_back({descricao, consequencia});
}

// imprime na tela a sala
void SalaEscolha::mostrarSala(){
    Utils::coutDigitado() << "\n========================================\n";
    Utils::coutDigitado() << "          " << this->_nome << "\n";
    Utils::coutDigitado() << "========================================\n";
    Utils::coutDigitado() << _historia << "\n";
}

// comeca a executar as açoes da sala
int SalaEscolha::executarSala(Personagem& personagem){
    std::cout <<"Sala de Escolhas" << std::endl;
    // imprime as opçoes do vetor _opcoes
    mostrarOpcoes();
    // age sob o personagem executando a consequencia
    executarEvento(personagem);
    if(!personagem.isMorto()) { 
    return 1; 
    } else {
    return 0; }
}

void SalaEscolha::mostrarOpcoes(){
    Utils::coutDigitado() << "\nO que voce deseja escolher?\n";
    // imprime as opcoes da sala
    for (size_t i = 0; i < _opcoes.size(); ++i) {
        Utils::coutDigitado() << "[" << i + 1 << "] " << _opcoes[i].descricao << "\n";
    }
    Utils::coutDigitado() << "Sua escolha: ";
}
void SalaEscolha::executarEvento(Personagem& personagem) {
    int escolha;
    bool escolhaValida = false;
    // verificacao se a escolha faz sentido 
    // duas verificações: cin.fail -> se user digitou realmente um int
    // ou se ele digitou um numero que é uma escolha viável (exemplo: digitou 4 e so tinha 3 opcoes)

    while (!escolhaValida) {
        std::cin >> escolha;
        //protecao contra loop infinito de eof
        if(std::cin.eof()){
            throw std::runtime_error("Fim inesperado da entrada (EOF). Faltou input no teste?");
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            escolha = 0;
            std::cout << "Essa escolha não existe! Escolha uma opção: " << std::endl;
            continue; 
            }
        if (escolha > 0 && escolha <= _opcoes.size()) {
            int numeroSorteado = rand() % 3 + 1;
            switch (numeroSorteado){
            case 1:
                Utils::coutTempo("Otima escolha...\n", 50);
                break;
            case 2:
                Utils::coutTempo("Isso definitivamente vai ajudar.\n", 50);
                break;
            case 3:
                Utils::coutTempo("Ada Lovelace amaria isso.\n", 50);
                break;
            }
            _opcoes[escolha - 1].consequencia(&personagem); 
            escolhaValida = true;
        } else {
            std::cout << "Opcao invalida, tente outra vez: ";
        }
    }
    }

void SalaEscolha::encerrarSala(){
    int numeroSorteado = rand() % 5 + 1;
    switch (numeroSorteado){
    case 1:
        Utils::coutTempo("O codigo precisa ser feito. A porta a frente se abre.\n", 50);
        break;
    case 2:
        Utils::coutTempo("A esperança de codar renasce. Um novo desafio surge a frente.\n", 50);
        break;
    case 3:
        Utils::coutTempo("Alan Turing nao pararia aqui. Uma porta se abre.\n", 50);
        break;
    case 4:
        Utils::coutTempo("O que o William pensaria de mim se eu desistisse? Mais uma porta se abre.\n", 50);
        break;
    case 5:
        Utils::coutTempo("Nenhuma IA vai me substituir, que venha a proxima porta.\n", 50);
        break;
    }
}
