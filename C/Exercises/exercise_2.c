// README - Exercise made to practise loops + values acumulation

#include <stdio.h>

// Função que recebe a quantidade de números e retorna a soma
int somaNumeros(int quantidade) {
    int soma = 0;
    int num;

    for (int i = 0; i < quantidade; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &num);
        soma += num;
    }

    return soma;
}

int main(void) {
    // Parte 1: soma de 5 números
    printf("Digite 5 números:\n");
    int soma5 = somaNumeros(5);
    printf("A soma dos 5 números é: %d\n", soma5);

    // Parte 2: soma de N números
    int n;
    printf("Quantos números deseja inserir agora?\n");
    scanf("%d", &n);

    int somaN = somaNumeros(n);
    printf("A soma dos %d números é: %d\n", n, somaN);

    return 0;
}
