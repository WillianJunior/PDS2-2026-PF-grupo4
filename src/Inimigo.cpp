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
    double vidaBase = this->getVida();
    //atualiza os cooldowns de todas as habilidades
    this->getInventarioHabilidade().atualizarCooldowns();
    //aplica todos os efeitos no inimigo
    this->processarEfeitosAtivos();
    if(this->isMorto()) return;

    while(true){
        int numHabilidades = this->getInventarioHabilidade().getTamanho();
        int posicao = rand() % numHabilidades;
        
        Habilidade& habInimigo = this->escolherHabilidade(posicao);
        
        if(habInimigo.getCooldownAtual() > 0){
            continue; // Recarregando, repete o while para ele sortear outra
        }

        if(habInimigo.getAlvo()){
            if(this->getVida() < 0.5 * vidaBase){
                int impacto = habInimigo.calcularImpacto();
                habInimigo.iniciarCooldown(); // <--- Inicia o cooldown da cura!
                this->alterarVida(impacto);
                std::cout << "> " << this->getNome() << " recuperou " << std::abs(impacto) << " de vida!" << std::endl;
                break;
            }
            else{
                continue;
            }
        }
        else{
            int impacto = habInimigo.calcularImpacto();
            habInimigo.iniciarCooldown(); // <--- Inicia o cooldown do ataque!
            personagem.alterarVida(impacto);
            personagem.receberEfeito(habInimigo.getEfeito());
            Utils::coutDigitado(350) << "...\n[";
                Utils::esperar(350);
            std::cout << "> " << this->getNome() << " atacou e causou " << std::abs(impacto) << " de dano!" << std::endl;
            break;
        }
    }
}

Inimigo::~Inimigo(){}