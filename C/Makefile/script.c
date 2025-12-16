#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array de opções global
const char* options[] = {"rock", "paper", "scissors"};

// retorna escolha aleatória
const char* getComputerChoice(void) {
    return options[rand() % 3]; // índice 0,1,2 direto
}

void checkWinner(int playerSelection , int computerSelection)
{
    if (playerSelection == computerSelection)
    {
        return "Tie";
    }
    else if (playerSelection == "rock" && computerSelection == "scissors" || playerSelection == "scissors" && computerSelection == "paper" || playerSelection == "paper" && computerSelection == "rock")
    {
        return "Player";
    } 
    else
    {
        return "Computer";
    }
}


int main(void) {
    // Inicializa o gerador de números aleatórios
    srand((unsigned)time(NULL));

    // Escolha do computador
    const char* choice = getComputerChoice();

    // Debug
    printf("Computer chose: %s\n", choice);

    return 0;
}

// TODO: playRound()