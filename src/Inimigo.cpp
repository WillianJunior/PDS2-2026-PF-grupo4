#include "Inimigo.hpp"
#include "Utils.hpp"

Inimigo::Inimigo(int vida, InventarioHabilidade habilidade, std::string nome)
    : Entidade(vida, nome, habilidade), _vidaMaxima(vida){}

Habilidade& Inimigo::escolherHabilidade(int posicaoHabilidade){
    Habilidade& habilidade = this->_inventarioHabilidade.getHabilidade(posicaoHabilidade);
    habilidade.mostrarDescricao();
    return habilidade;
}

void Inimigo::alterarVida(int valor){
    this->_vida += valor;
    if(this->_vida > this->_vidaMaxima){
        this->_vida = this->_vidaMaxima;
    }
}

bool Inimigo::isMorto(){
    return this->_vida <= 0;
}

void Inimigo::combateInimigo(Personagem& personagem) {
    // atualiza os cooldowns de todas as habilidades
    this->getInventarioHabilidade().atualizarCooldowns();
    // aplica todos os efeitos no inimigo
    this->processarEfeitosAtivos();
    if(this->isMorto()) return;

    std::vector<int> opcoesValidas;
    int numHabilidades = this->getInventarioHabilidade().getTamanho();
    for(int i = 0; i < numHabilidades; i++) {
        Habilidade& hab = this->getInventarioHabilidade().getHabilidade(i);
        
        if(hab.getCooldownAtual() == 0) {
            if(hab.getAlvo() == true) { 
                if(this->getVida() < 0.5 * this->_vidaMaxima) {
                    opcoesValidas.push_back(i);
                }
            } else { 
                opcoesValidas.push_back(i);
            }
        }
    }

    /// proteção contra Loop Infinito (se não tem o que usar, passa o turno)
    if(opcoesValidas.empty()) {
        Utils::coutDigitado(350) << "...\n[";
        Utils::esperar(350);
        std::cout << "> " << this->getNome() << " está exausto e não conseguiu fazer nada neste turno!" << std::endl;
        return;
    }

    int indexSorteado = rand() % opcoesValidas.size();
    int posicaoEscolhida = opcoesValidas[indexSorteado];
    
    Habilidade& habInimigo = this->escolherHabilidade(posicaoEscolhida);

    if(habInimigo.getAlvo()) {
        int vidaPersonagemAntesDaCura = this->getVida();
        int impacto = habInimigo.calcularImpacto();
        habInimigo.iniciarCooldown(); 
        
        this->alterarVida(impacto);
        this->receberEfeito(habInimigo.getEfeito());
        
        int vidaRealmenteRecuperada = this->getVida() - vidaPersonagemAntesDaCura;
        std::cout << "> " << this->getNome() << " recuperou " << vidaRealmenteRecuperada << " de vida!" << std::endl;
    } else {
        int impacto = habInimigo.calcularImpacto();
        habInimigo.iniciarCooldown(); 
        personagem.alterarVida(impacto);
        personagem.receberEfeito(habInimigo.getEfeito());
        
        Utils::coutDigitado(350) << "...\n[";
        Utils::esperar(350);
        std::cout << "> " << this->getNome() << " atacou e causou " << std::abs(impacto) << " de dano!" << std::endl;
    }
}

Inimigo::~Inimigo(){}