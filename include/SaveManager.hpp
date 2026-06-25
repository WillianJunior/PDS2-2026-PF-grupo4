#ifndef SAVEMANAGER_HPP
#define SAVEMANAGER_HPP

#include "Personagem.hpp"
#include "SalaBase.hpp"
#include <vector>
#include <memory>
#include <string> 

class SaveManager {
    public:
    /**
     * @brief Salva as informações da run.
     * @param contadorSalas Inteiro que indica em qual sala o jogador está.
     * @param personagem Personagem da run.
     * @param salas Vetor com as salas para, se a run for retomada, ter a mesma sequência.
     */
        static void salvar(int contadorSalas, Personagem& personagem, const std::vector<std::unique_ptr<SalaBase>>& salas);

    /**
     * @brief Carrega as informações salvas de uma run, permitindo que o jogador retome do mesmo ponto que havia parado.
     * @param contadorSalas Inteiro que indica em qual sala o jogador estava.
     * @param salas Vetor com as salas para retomar a run com a mesma sequência de salas.
     */
        static std::unique_ptr<Personagem> carregar(int& contadorSalas, std::vector<std::unique_ptr<SalaBase>>& salas);
        
    /**
     * @brief Verifica se existe um arquivo de save.
     * @return Retorna true se existir um save.
     */
        static bool existeSave();
};

#endif