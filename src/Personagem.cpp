#include "Personagem.hpp"
#include "Utils.hpp"

Personagem::Personagem(int vida, InventarioHabilidade inventarioHabilidade, std::string nome, InventarioItem inventarioItem)
    : Entidade(vida, nome, inventarioHabilidade), _inventario(inventarioItem), _vidaMaxima(vida){}

Habilidade& Personagem::escolherHabilidade(int posicaoHabilidade){
    Habilidade& habilidade = this->_inventarioHabilidade.getHabilidade(posicaoHabilidade);
    return habilidade;
}

Item Personagem::escolherItem(int posicaoItem){
    Item& item = this->_inventario.getItem(posicaoItem);
    item.atualizarUsos();
    Item copia = item;
    if(item.getUsosRestantes() == 0){
        this->_inventario.descartarAcao(posicaoItem);
    }
    return copia;
}

void Personagem::receberHabilidade(Habilidade habilidade){
    int limite = 3;
    Utils::coutDigitado() << "\n>>> Voce descobriu uma nova habilidade!! <<<\n";
    Utils::coutDigitado() << "[" << habilidade.getNome() << "] | Cooldown: " << habilidade.getCooldown() << "\n";
    Utils::coutDigitado() << "  > " << habilidade.mostrarDescricao() << "\n";
    Utils::coutDigitado() << "------------------------------------------------\n";

    if(this->_inventarioHabilidade.getTamanho() < limite){
        this->_inventarioHabilidade.novaAcao(habilidade);
        Utils::coutDigitado() << "Voce aprendeu a habilidade [" << habilidade.getNome() << "]!\n";
    }
    else{
        Utils::coutDigitado() << "\nSua mente esta sobrecarregada e nao consegue aprender [" << habilidade.getNome() << "].\n";
        Utils::coutDigitado() << "Deseja esquecer uma habilidade para aprender a nova?\n";

        _inventarioHabilidade.mostrarInventario();
        std::cout << "Digite o numero da habilidade que deseja esquecer (0 para recusar a nova):\n";

        int escolha;
        std::cin >> escolha;

        if (escolha > 0 && escolha <= this->_inventarioHabilidade.getTamanho()) {
            std::cout << "\nVoce esqueceu [" << this->_inventarioHabilidade.getHabilidade(escolha - 1).getNome() 
                      << "] e aprendeu [" << habilidade.getNome() << "]!\n";
            this->_inventarioHabilidade.trocarAcao(escolha - 1, habilidade);
        } else {
            std::cout << "\nVoce ignorou a habilidade [" << habilidade.getNome() << "] e manteve sua mente focada.\n";
        }
    }
}

void Personagem::receberItem(Item item){
    int limiteItens = 3;

    Utils::coutDigitado() << "\n>>> Voce achou um novo item!! <<<\n";
    Utils::coutDigitado() << "[" << item.getNome() << "] | Usos: " << item.getUsosRestantes() << "\n";
    Utils::coutDigitado() << "  > " << item.mostrarDescricao() << "\n";
    Utils::coutDigitado() << "------------------------------------------------\n";

    if (this->_inventario.getTamanho() < limiteItens) {
        this->_inventario.novaAcao(item);
        Utils::coutDigitado() << "Voce guardou o item [" << item.getNome() << "] na mochila!\n";
    } else {
        Utils::coutDigitado() << "\nSua mochila esta cheia e nao tem espaco para [" << item.getNome() << "].\n";
        Utils::coutDigitado() << "Deseja descartar um item para pegar o novo?\n";
        
        this->_inventario.mostrarInventario();
        std::cout << "Digite o numero do item a ser descartado (0 para recusar o novo): ";
        
        int escolha;
        std::cin >> escolha;

        if (escolha > 0 && escolha <= this->_inventario.getTamanho()) {
            std::cout << "\nVoce jogou fora [" << this->_inventario.getItem(escolha - 1).getNome() 
                      << "] e pegou [" << item.getNome() << "]!\n";
            this->_inventario.trocarAcao(escolha - 1, item);
        } else {
            std::cout << "\nVoce ignorou o item [" << item.getNome() << "] e seguiu em frente.\n";
        }
    }
}

void Personagem::alterarVida(int valor){
    this->_vida += valor;
    if(this->_vida > this->_vidaMaxima){
        this->_vida = this->_vidaMaxima;
    }
}

bool Personagem::isMorto(){
    return this->_vida <= 0;
}

InventarioItem& Personagem::getInventarioItem(){
    return this->_inventario;
}

int Personagem::getVidaMaxima(){
    return this->_vidaMaxima;
}

Personagem::~Personagem(){}