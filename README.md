# PDS2-2026-PF-grupo4

| We Can't Code This Game - Motor de RPG |

## Integrantes:
•	Maycon Jonnatha Rezende Ferreira
•	Isaque Daniel Freire Martins
•	Marcos Paulo Rodrigues Vilaça
•	João vaz Rousset
•	Nicole Araujo Campos Szuster

## Descrição:

Este projeto consiste na implementação de um motor simplificado de RPG baseado em turnos. O sistema, que será inteiramente desenvolvido em C++, exige a modelagem de personagens, regras de combate e o gerenciamento de recursos. 

## Objetivos:

•	Desenvolver Motor RPG: Implementar um sistema com diferentes personagens, inimigos, combate por turnos, regras de dano, inventário e uso de itens e habilidades. 
•	Extensibilidade: Desenvolver o projeto de modo a ser possível adicionar facilmente novas salas de combates, inimigos e itens. 
•	Qualidade Técnica: Aplicar os conceitos de Programação Orientada a Objetos, incluindo encapsulamento, herança e polimorfismo. 
•	Qualidade de Software: Construir um sistema confiável, reutilizável e de fácil manutenção, com modularidade definida.

## Motivação e Enredo

A motivação para o tema deste projeto surgiu de um desafio real enfrentado pela nossa equipe: durante as discussões iniciais de brainstorming, nenhuma das ideias de temas e cenários propostos parecia agradar a todos os membros do grupo. Diante desse bloqueio criativo, decidimos transformar o nosso próprio processo de desenvolvimento no enredo central do jogo e nossas características pessoais na temática dos personagens e inimigos.
Assim nasceu a ideia de um "meta-jogo". A narrativa acompanha cinco estudantes que estão criando um jogo e enfrentam diversos empecilhos para conseguir terminá-lo. Cada membro do nosso grupo atua como uma "classe" de personagem selecionável no início da jornada. O jogador assume o papel de um desses estudantes e deve avançar por diversas salas de combate. Os inimigos enfrentados são, na verdade, metáforas para os desafios de desenvolvimento que tentam nos impedir de entregar o projeto final. Para auxiliar na progressão, o jogo também conta com salas interativas voltadas para a troca de itens especiais e gerenciamento de inventário, unindo nossa sátira criativa a todos os requisitos técnicos exigidos para o projeto do motor RPG.

## Arquitetura e Padrões de Projeto
State Pattern / Máquina de Estados: O fluxo principal (Game Loop) orquestra a transição entre Salas de Combate e Salas de Escolha de forma desacoplada.
Factory Method: Instanciação dinâmica de inimigos, itens e salas através de classes fábricas (FabricaSC, FabricaSE, etc.).
Gestão de Memória Utilização exclusiva de smart pointers (std::unique_ptr e std::shared_ptr) para mitigar vazamentos de memória.

## Estrutura de Diretórios
O repositório segue uma organização modular padrão:
├── src/        # Arquivos de implementação (.cpp)
├── include/    # Contratos e cabeçalhos (.hpp)
├── data/       # Arquivos de texto (.txt) contendo status, histórias e ASCII arts
├── tests/      # Casos de teste unitário
├── docs/       # Arquivos de configuração e saída do Doxygen
├── Makefile    # Automação de compilação
└── README.md   # Documentação principal

## Compilação e Execução
O projeto conta com um Makefile configurado para automatizar os processos de build no Linux. 

Para compilar o código fonte e gerar o binário executável, execute na raiz do projeto:
make

Para compilar e executar o jogo em seguida:
make run

Para limpar os arquivos objetos .o gerados durante a compilação:
make clean

A cobertura de testes (cálculo de dano, limite de vida, uso de inventário e lançamento de exceções) foi implementada. Para executar a suíte de testes:
make test


