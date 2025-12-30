#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Recebe um int
// Devolve o nome da escolha
const char* nome_escolha(int escolha)
{
    if (escolha == 0) return "Pedra";
    else if (escolha == 1) return "Papel";
    else if (escolha == 2) return "Tesoura";
    else return "Desconhecido";
}

int main(void)
{
    srand(time(NULL));

    int jogador; // escolha do jogador 
    int computador; // escolha aleatória
    int continuar = 1; // controla o loop do jogo

    while (continuar)
    {
        printf("\nEscolhe uma opção:\n");
        printf("0 - Pedra\n");
        printf("1 - Papel\n");
        printf("2 - Tesoura\n");
        printf("> ");
        scanf("%d", &jogador);

        if (jogador < 0 || jogador > 2)
        {
            printf("Escolha inválida!\n");
            continue;
        }

        computador = rand() % 3;

        // Converte o número para texto
        printf("Jogador escolheu: %s\n", nome_escolha(jogador));
        printf("Computador escolheu: %s\n", nome_escolha(computador));

        if (jogador == computador)
        {
            printf("Empate! Vamos jogar outra vez.\n");
            continue;
        }
        else if (
            (jogador == 0 && computador == 2) ||
            (jogador == 1 && computador == 0) ||
            (jogador == 2 && computador == 1)
        )
        {
            printf("Jogador venceu!\n");
        }
        else
        {
            printf("Computador venceu!\n");
        }

        printf("Queres continuar? (1 = sim, 0 = não): ");
        scanf("%d", &continuar);
    }

    printf("Jogo terminado.\n");
    return 0;
}
