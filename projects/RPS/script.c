#include <stdio.h>   // printf, scanf (entrada e saída)
#include <stdlib.h>  // rand, srand
#include <time.h>    // time (usado para aleatoriedade)

// ================= ENUM =================
// Criamos um novo tipo chamado Choice.
// Ele representa todas as opções possíveis do jogo.
//
// Internamente:
// ROCK     = 0
// PAPER    = 1
// SCISSORS = 2
typedef enum {
    ROCK,
    PAPER,
    SCISSORS
} Choice;

// ================= FUNÇÃO DE CONVERSÃO =================
// Recebe um valor do tipo Choice (ROCK, PAPER ou SCISSORS)
// e devolve uma string correspondente.
//
// const char* significa:
// "ponteiro para uma string constante (não pode ser alterada)"
const char* choiceToString(Choice choice) {

    // switch analisa o valor de 'choice'
    switch (choice) {

        // Se choice == ROCK (0)
        case ROCK:
            return "Rock";

        // Se choice == PAPER (1)
        case PAPER:
            return "Paper";

        // Se choice == SCISSORS (2)
        case SCISSORS:
            return "Scissors";

        // Caso algum valor inválido apareça
        default:
            return "Unknown";
    }
}

// ================= ESCOLHA DO COMPUTADOR =================
// Gera um número aleatório entre 0 e 2
// e converte esse número para o tipo Choice
Choice getComputerChoice(void) {
    return (Choice)(rand() % 3);
}

// ================= VERIFICAR VENCEDOR =================
// Recebe a escolha do jogador e do computador
// e retorna quem venceu
const char* checkWinner(Choice player, Choice computer) {

    // Se as escolhas forem iguais → empate
    if (player == computer) {
        return "Tie";
    }

    // Todas as situações em que o jogador ganha
    if (
        (player == ROCK     && computer == SCISSORS) ||
        (player == SCISSORS && computer == PAPER)    ||
        (player == PAPER    && computer == ROCK)
    ) {
        return "Player";
    }

    // Caso contrário, o computador vence
    return "Computer";
}

// ================= JOGAR UMA RODADA =================
// Mostra as escolhas e o resultado da rodada
void playRound(Choice player, Choice computer) {

    // Exibe as escolhas convertendo enum → string
    printf("Player: %s\n", choiceToString(player));
    printf("Computer: %s\n", choiceToString(computer));

    // Verifica quem ganhou
    const char* result = checkWinner(player, computer);

    // Decide a mensagem com base no resultado
    if (result[0] == 'T') {
        printf("It's a Tie!\n");
    } else if (result[0] == 'P') {
        printf("You Win!\n");
    } else {
        printf("You Lost!\n");
    }
}

// ================= FUNÇÃO PRINCIPAL =================
int main(void) {

    // Inicializa o gerador de números aleatórios
    // Sem isso, o rand() geraria sempre a mesma sequência
    srand((unsigned)time(NULL));

    int input;

    // Menu para o jogador
    printf("Choose an option:\n");
    printf("0 - Rock\n");
    printf("1 - Paper\n");
    printf("2 - Scissors\n");
    printf("> ");

    // Lê a escolha do jogador
    scanf("%d", &input);

    // Verifica se o valor é válido
    if (input < 0 || input > 2) {
        printf("Invalid choice!\n");
        return 1; // encerra o programa com erro
    }

    // Converte o número digitado para o tipo Choice
    Choice playerChoice = (Choice)input;

    // Gera a escolha aleatória do computador
    Choice computerChoice = getComputerChoice();

    // Executa uma rodada do jogo
    playRound(playerChoice, computerChoice);

    return 0; // fim do programa
}
