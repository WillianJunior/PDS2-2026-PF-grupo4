#include "Personagem.hpp"

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
    std::cout << "\n>>> Voce descobriu uma nova habilidade!! <<<\n";
    std::cout << "[" << habilidade.getNome() << "] | Usos: " << habilidade.getCooldown() << "\n";
    std::cout << "    >" << habilidade.mostrarDescricao() << "\n";
    std::cout << "------------------------------------------------\n";

    if(this->_inventarioHabilidade.getTamanho() < limite){
        this->_inventarioHabilidade.novaAcao(habilidade);
        std::cout << "Voce aprendeu a habilidade [" << habilidade.getNome() << "]!\n";
    }
    else{
        std::cout << "\nSua mente esta sobrecarregada e nao consegue aprender [" << habilidade.getNome() << "].\n";
        std::cout << "Deseja esquecer uma habilidade para aprender a nova?\n";

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

    std::cout << "\n>>> Voce achou um novo item!! <<<\n";
    std::cout << "[" << item.getNome() << "] | Usos: " << item.getUsosRestantes() << "\n";
    std::cout << "    >" << item.mostrarDescricao() << "\n";
    std::cout << "------------------------------------------------\n";

    if (this->_inventario.getTamanho() < limiteItens) {
        this->_inventario.novaAcao(item);
        std::cout << "Voce guardou o item [" << item.getNome() << "] na mochila!\n";
    } else {
        std::cout << "\nSua mochila esta chei e nao tem espaco para [" << item.getNome() << "].\n";
        std::cout << "Deseja descartar um item para pegar o novo?\n";
        
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