#include "SalaEscolha.hpp"
#include <limits>

SalaEscolha::SalaEscolha(std::string nome, std::string historia) 
    : SalaBase(nome), _historia(historia) {}

std::string SalaEscolha::getNome() const {
    return this->_nome;
}
// adiciona uma opcao no vetores de opcoes que aquela salaescolha possui
void SalaEscolha::adicionarOpcao(std::string descricao, std::function<void(Personagem*)> consequencia){
    _opcoes.push_back({descricao, consequencia});
}

// imprime na tela a sala
void SalaEscolha::mostrarSala(){
    std::cout << "\n========================================" << std::endl;
    std::cout << "          " << this->_nome << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << _historia << std::endl;
}

// comeca a executar as açoes da sala
int SalaEscolha::executarSala(Personagem* personagem){
    std::cout <<"Sala de Escolhas" << std::endl;
    // imprime as opçoes do vetor _opcoes
    mostrarOpcoes();
    // age sob o personagem executando a consequencia
    executarEvento(personagem);
    return 3; //proxima sala exemplo 3 sala de combate
}

void SalaEscolha::mostrarOpcoes(){
    std::cout << "\nO que voce deseja escolher?" << std::endl;
    // imprime as opcoes da sala
    for (size_t i = 0; i < _opcoes.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << _opcoes[i].descricao << std::endl;
    }
    std::cout << "Sua escolha: ";
}
void SalaEscolha::executarEvento(Personagem* personagem) {
    int escolha;
    bool escolhaValida = false;
    // verificacao se a escolha faz sentido 
    // duas verificações: cin.fail -> se user digitou realmente um int
    // ou se ele digitou um numero que é uma escolha viável (exemplo: digitou 4 e so tinha 3 opcoes)

    while (!escolhaValida) {
        std::cin >> escolha;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            escolha = 0;
            std::cout << "Essa escolha não existe! Escolha uma opção: " << std::endl;
            continue; 
            }
        if (escolha > 0 && escolha <= _opcoes.size()) {
            std::cout << "\nVoce fez sua escolha!" << std::endl;
            _opcoes[escolha - 1].consequencia(personagem); 
            escolhaValida = true;
        } else {
            std::cout << "Opcao invalida, tente outra vez: ";
        }
    }
    }

void SalaEscolha::encerrarSala(){
}
