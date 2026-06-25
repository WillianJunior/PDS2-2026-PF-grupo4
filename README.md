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
O projeto foi arquitetado sob os pilares fundamentais da **Programação Orientada a Objetos (POO)** e faz uso intensivo de padrões de projeto clássicos para garantir baixo acoplamento, alta coesão e facilidade de manutenção e expansão:

### 1. Pilares de POO Aplicados
- **Herança e Polimorfismo de Entidades:** A classe abstrata `Entidade` define o contrato base (vida, nome, recebimento de dano/efeitos). Dela derivam `Personagem` (que adiciona inventários e mecânicas de recarga) e `Inimigo` (que implementa a mecânica de combate por aleatoriedade com alguns filtros).
- **Herança e Polimorfismo de Salas:** O game loop manipula ponteiros genéricos para a classe abstrata `SalaBase`. As especializações `SalaCombate` e `SalaEscolha` sobrescrevem os métodos virtuais `mostrarSala()` e `executarSala()`, permitindo que a engine transicione entre diferentes modos de jogo sem conhecer os detalhes internos de cada sala.
- **Encapsulamento e Templates:** O gerenciamento de ações é construído através de um template genérico de classe base (`Inventario<T>`), que encapsula vetores seguros da STL. As classes `InventarioHabilidade` e `InventarioItem` especializam esse comportamento para lidar com regras exclusivas de *cooldowns* e consumo de quantidade, respectivamente.

### 2. Padrões de Projeto (*Design Patterns*)
- **Factory Method (Instanciação Dinâmica Desacoplada):**  
  A criação de objetos complexos é totalmente delegada a classes fábricas estáticas especializadas:
  - `FabricaSC` e `FabricaSE`: Montam e entregam instâncias prontas de `SalaCombate` e `SalaEscolha`, já injetando descrições narrativas, artes ASCII e opções de interatividade baseadas em IDs.
  - `FabricaInimigo`, `FabricaHabilidade` e `FabricaItem`: Centralizam atributos, falas de batalha e multiplicadores de impacto.
- **State Machine / Game Loop (Máquina de Estados Orquestrada):**  
  A classe `Engine` atua como o orquestrador principal. Ela pré-carrega a sequência da run em um vetor polimórfico (`std::vector<std::unique_ptr<SalaBase>>`). Durante o ciclo de jogo, a sala atual assume o controle de fluxo atuando como um estado autônomo e, ao finalizar, devolve o controle para a engine avançar o ID da sala.
- **Command / Callback Pattern (Eventos Narrativos):**  
  Na `SalaEscolha`, as opções selecionáveis encapsulam suas consequências através do wrapper `std::function<void(Personagem*)>`. Isso permite injetar lambdas e comportamentos arbitrários em tempo de instanciação na fábrica, evitando a criação de infinitas sub-classes para cada evento específico.
- **RAII e Gestão de Recursos Utilitários:**  
  A classe `Utils` manipula chamadas de sistema POSIX (`termios` e `fcntl`) para desligar o eco do terminal e permitir leituras assíncronas não-bloqueantes durante animações de digitação. O paradigma RAII garante que as flags do terminal do usuário sejam rigorosamente restauradas ao estado original ao fim da execução.
- **Persistência Centralizada:**  
  A classe `SaveManager` garante o salvamento em disco (`save.txt`), passando parâmetros como os da sala e o estado de vida e inventários do personagem, permitindo resgatar o progresso exato da sessão.


### 3. Gestão de Memória Moderna
O projeto **não utiliza gerenciamento manual de memória**. A posse dos objetos de salas e entidades é gerida estritamente por smart pointers de escopo único (**`std::unique_ptr`**) com transferências explícitas de propriedade via `std::move`. Isso anula riscos de vazamentos de memória (*memory leaks*) e ponteiros pendentes (*dangling pointers*).

## Estrutura de Diretórios
O repositório segue uma organização modular:
├── src/        # Código-fonte (.cpp) com a implementação interna das mecânicas
├── include/    # Contratos e cabeçalhos (.hpp)
├── data/       # Arquivos de texto (.txt) contendo artes ASCII e status de entidades
├── design/     # Documentação de modelagem
├── tests/      # Casos de teste unitário automatizados
├── build/      # Diretório temporário gerado para armazenar relatórios de teste
├── html/       # Documentação técnica gerada automaticamente pelo Doxygen (formato Web)
├── latex/      # Documentação técnica gerada automaticamente pelo Doxygen (formato LaTeX)
├── Doxyfile    # Arquivo de configuração de geração de documentação do Doxygen
├── Makefile    # Automação de compilação, execução e testes
└── README.md   # Documentação principal do projeto

## Compilação e Execução
O projeto conta com um Makefile configurado para automatizar os processos de build no Linux. 

Para compilar o código fonte e gerar o binário executável, execute na raiz do projeto:
make

Isso criará o arquivo binário rpg_game na pasta raiz. Para iniciá-lo manualmente em seguida, basta rodar:
./rpg_game

Para compilar e executar o jogo em seguida:
make run

Para limpar os arquivos objetos .o gerados durante a compilação:
make clean

A cobertura de testes (cálculo de dano, limite de vida, uso de inventário e lançamento de exceções) foi implementada. Para executar a suíte de testes:
make test

## Como Jogar
We Can't Code This Game é um RPG por turnos no qual você assume o papel de um estudante universitário lutando contra metáforas de bugs, bloqueios criativos e prazos apertados para conseguir entregar o trabalho final de PDS II, além de outras situações adversas.

1. Início e Seleção de Personagem
Ao executar o jogo, você terá acesso ao Menu Principal:

    • New Game: Inicia uma nova jornada. Você deverá escolher seu desenvolvedor/herói digitando um número de 1 a 5:
        [1] Maycon (O Lutador Alquimista): 120 HP | Habilidade inicial: Investida | Item inicial: Xeque-Mate
        [2] Vaz (O Mestre dos Ares): 100 HP | Habilidades iniciais: Contar uma Piada e Forças Aéreas
        [3] Nicole (A Exterminadora de Coca-Cola): 120 HP | Habilidade: Arremessar um Livro | Item: Coca-Cola
        [4] Marcos (O Hipnotizador do Forró): 120 HP | Habilidade: Passinho do Forró | Item: Água Benta
        [5] Isaque (O Invocador de Aliados): 120 HP | Habilidades: Aviãozinho de Papel e Chamar a Ex

    • Load Game: Carrega automaticamente seu último progresso salvo (disponível caso exista um jogo salvo no arquivo save.txt).
    
    • Out: Encerra o jogo.

• Dica: Acelerar Diálogos:
O jogo exibe os diálogos com um efeito animado de digitação. Ao jogar as primeiras vezes é interessante acompanhar os diálogos com calma para entender melhor a história, mas, após entender a história, se você quiser acelerar a velocidade do texto em 10x, basta pressionar a tecla Espaço durante as falas.

2. Progredindo pelas Salas
A sua campanha consiste em sobreviver a uma sequência gerada aleatoriamente de 8 salas (5 Salas de Combate e 3 Salas de Escolha), finalizando na batalha contra o Boss e na entrega final do código:

    • Salas de Combate (Batalhas por Turnos)
        Nos embates, os turnos alternam entre Sua Vez e a Vez do Inimigo. A cada rodada do jogador, os tempos de recarga (cooldowns) das suas habilidades diminuem e efeitos de status são calculados.
        Digite o número correspondente à ação desejada:
            [ 1 ] - Usar Habilidade: Lista as habilidades disponíveis do seu personagem. Algumas causam dano ao inimigo, enquanto outras curam sua vida. Após o uso, a habilidade entra em cooldown por algumas rodadas.
            [ 2 ] - Usar Item: Abre seu inventário consumível. Itens possuem efeitos imediatos de cura, buffs ou dano direto e são gastos ao serem utilizados.
            (Em ambos os menus, você pode digitar 0 para cancelar e voltar à escolha de ação).
            Ao derrotar um inimigo, seu personagem descansa, recupera 30 pontos de vida, limpa penalidades de status e recebe recompensas antes de prosseguir.

    • Salas de Escolha (Eventos Interativos)
        Entre combates, você entrará em salas de eventos com decisões narrativas ou trocas de inventário. Serão exibidas opções numeradas [1], [2], etc. Leia a situação e digite o número da sua escolha para receber buffs, itens especiais ou possíveis penalidades em sua vida e atributos.

3. Sistema de Salvamento (Save Automático)
O motor do jogo possui um sistema de save:

    Salvo ao Concluir Salas: Ao finalizar qualquer sala (seja de combate ou escolha), seu progresso, vida, inventário, histórico de salas percorridas, etc são salvos automaticamente em um arquivo save.txt.
    Pausa de Campanha: Após o salvamento automático de conclusão de sala, o jogo perguntará se você deseja:
    [ 1 ] - Seguir para a próxima sala
    [ 2 ] - Sair (Fecha com segurança; você poderá continuar exatamente de onde parou usando a opção Load Game no menu inicial posteriormente).
    Morte Permanente (Permadeath): Caso sua vida chegue a 0 (Game Over) ou você conclua a história final do jogo com vitória, o arquivo save.txt é excluído automaticamente para que uma nova história comece limpa.