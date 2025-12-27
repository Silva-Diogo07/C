#include <stdio.h>

int main(void)
{
    // Pergunta quantos números quer inserir
    int n;
    printf("Quantos números queres adicionar ao array? ");
    scanf("%d", &n);  // Lê o número e guarda em 'n'

    // Declara um array com espaço para 100 números
    int array[100];

    // Lê 'n' números e guarda no array
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Bubble sort para ordenar o array do menor para o maior
    for (int i = 0; i < n - 1; i++)          
    {
        for (int j = 0; j < n - 1; j++)      // Percorre os elementos
        {
            if (array[j] > array[j + 1])     // Se o elemento atual for maior que o seguinte
            {
                // Troca os elementos usando uma variável temporária
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    } 

    // Imprime o array ordenado
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

// TODO: Binary search