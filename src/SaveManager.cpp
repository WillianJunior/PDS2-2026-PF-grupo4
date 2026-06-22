#include "SaveManager.hpp"
#include "InventarioHabilidade.hpp"
#include "InventarioItem.hpp"
#include "Habilidade.hpp"
#include "Item.hpp"
#include "Efeito.hpp"
#include <fstream>
#include <string>
#include <memory>

bool SaveManager::existeSave() {
    std::ifstream arquivo("save.txt");
    return arquivo.good();
}

void SaveManager::salvar(int contadorSalas, Personagem& personagem) {
    std::ofstream arquivo("save.txt");
    // Sala atual
    arquivo << contadorSalas << "\n";
    // Dados básicos do personagem
    arquivo << personagem.getNome() << "\n";
    arquivo << personagem.getVida() << "\n";
    arquivo << personagem.getVidaMaxima() << "\n";
    // Habilidades
    InventarioHabilidade inventarioHabilidade = personagem.getInventarioHabilidade();
    arquivo << inventarioHabilidade.getTamanho() << "\n";
    for (int i = 0; i < inventarioHabilidade.getTamanho(); i++) {
        Habilidade habilidade = inventarioHabilidade.getHabilidade(i);
        arquivo << habilidade.getNome() << "\n";
        arquivo << habilidade.getTipo() << "\n";
        arquivo << habilidade.getValor() << "\n";
        arquivo << habilidade.getAlvo() << "\n";
        arquivo << habilidade.getEfeito().getNome() << "\n";
        arquivo << habilidade.getEfeito().getValor() << "\n";
        arquivo << habilidade.getEfeito().getDuracao() << "\n";
    }
    // Itens
    InventarioItem inventarioItem = personagem.getInventarioItem();
    arquivo << inventarioItem.getTamanho() << "\n";
    for (int i = 0; i < inventarioItem.getTamanho(); i++) {
        Item item = inventarioItem.getItem(i);
        arquivo << item.getNome() << "\n";
        arquivo << item.getTipo() << "\n";
        arquivo << item.getValor() << "\n";
        arquivo << item.getAlvo() << "\n";
        arquivo << item.getEfeito().getNome() << "\n";
        arquivo << item.getEfeito().getValor() << "\n";
        arquivo << item.getEfeito().getDuracao() << "\n";
    }
}

std::unique_ptr<Personagem> SaveManager::carregar(int& contadorSalas) {
    std::ifstream arquivo("save.txt");
    if (!arquivo.is_open()) return nullptr;
    // Sala atual
    arquivo >> contadorSalas;
    arquivo.ignore(); // descarta o '\n' que sobrou
    // Dados básicos
    std::string nome;
    int vida, vidaMaxima;
    std::getline(arquivo, nome);
    arquivo >> vida >> vidaMaxima;
    // Habilidades
    int qtdHabilidades;
    arquivo >> qtdHabilidades;
    arquivo.ignore();
    InventarioHabilidade inventarioHabilidade;
    for (int i = 0; i < qtdHabilidades; i++) {
        std::string nomeHabilidade, nomeEfeito;
        bool tipo, alvo;
        int valor, valorEfeito, duracaoEfeito;
        std::getline(arquivo, nomeHabilidade);
        arquivo >> tipo >> valor >> alvo;
        arquivo.ignore();
        std::getline(arquivo, nomeEfeito);
        arquivo >> valorEfeito >> duracaoEfeito;
        arquivo.ignore();
        Efeito efeito(nomeEfeito, valorEfeito, duracaoEfeito);
        Habilidade habilidade(nomeHabilidade, tipo, valor, alvo, efeito);
        inventarioHabilidade.novaAcao(habilidade);
    }
    // Itens
    int qtdItens;
    arquivo >> qtdItens;
    arquivo.ignore();
    InventarioItem inventarioItem;
    for (int i = 0; i < qtdItens; i++) {
        std::string nomeItem, nomeEfeito;
        bool tipo, alvo;
        int valor, valorEfeito, duracaoEfeito;
        std::getline(arquivo, nomeItem);
        arquivo >> tipo >> valor >> alvo;
        arquivo.ignore();
        std::getline(arquivo, nomeEfeito);
        arquivo >> valorEfeito >> duracaoEfeito;
        arquivo.ignore();
        Efeito efeito(nomeEfeito, valorEfeito, duracaoEfeito);
        Item item(nomeItem, tipo, valor, efeito, alvo);
        inventarioItem.novaAcao(item);
    }
    auto personagemCarregado = std::unique_ptr<Personagem>(new Personagem(vidaMaxima, inventarioHabilidade, nome, inventarioItem));
    personagemCarregado->alterarVida(vida - vidaMaxima);
    return personagemCarregado;
}