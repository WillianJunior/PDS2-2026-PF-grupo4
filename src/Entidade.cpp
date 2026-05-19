#include "Entidade.hpp"

Entidade::Entidade(int vida, std::string nome, InventarioHabilidade inventarioHabilidade)
    : _vida(vida), _nome(nome), _inventarioHabilidade(inventarioHabilidade){}

Entidade::~Entidade(){}