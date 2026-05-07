#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "InventarioHabilidade.hpp"
#include <iostream>
#include <vector>

//classe responsavel por preparar o terreno para as outras entidades:
//personagem e ininimgo
class Entidade{
    protected:
    //atributos que toda entidade tem:
        int _vida;
        std::string _nome;
        InventarioHabilidade _habilidades;
    public:

        Entidade(int vida, std::string nome, InventarioHabilidade habilidades);

        //essa funcao vai pegar uma habilidade e usar o efeito dela que estara descrito na habilidade especifica selecionada,
        //isso acontece no momento que o jogador decide atacar e ele escolhe qual habilidade ele vai usar
        virtual int escolherHabilidade(Habilidade& habilidade) = 0;

        //recebe um valor inteiro que foi passado pela funcao escolherHabilidade, e fazer a alteraçao descrita na habilidade, seja cura ou dano
        virtual void alterarVida(int valor) = 0;
        
        virtual ~Entidade();
};


#endif 

