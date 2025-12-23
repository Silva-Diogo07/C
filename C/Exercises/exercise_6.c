#include <stdio.h>

int main(void)
{
    // Array de strings (char*) que contém as 3 perguntas
    char *perguntas[3] = {
        "1) Qual é a capital de Portugal?\n a) Porto\n b) Lisboa\n c) Faro\n",
        "2) Quanto é 2 + 2?\n a) 3\n b) 4\n c) 5\n",
        "3) Qual linguagem estamos a usar?\n a) Python\n b) Java\n c) C\n"
    };

    // Array que guarda as respostas corretas para cada pergunta
    // perguntas[0] → resposta 'b'
    // perguntas[1] → resposta 'b'
    // perguntas[2] → resposta 'c'
    char respostas_corretas[3] = {'b', 'b', 'c'};

    char resposta;   // Variável para guardar a resposta do utilizador
    int pontos = 0;  // Contador de pontos (começa em 0)

    // Loop que percorre as 3 perguntas
    for (int i = 0; i < 3; i++)
    {
        // Mostra a pergunta atual
        printf("%s", perguntas[i]);

        // Pede a resposta ao utilizador
        printf("Resposta: ");

        // Lê um caractere (a, b ou c)
        // O espaço antes do %c ignora o ENTER anterior
        scanf(" %c", &resposta);

        // Verifica se a resposta do utilizador é igual à correta
        if (resposta == respostas_corretas[i])
        {
            pontos++;  // Se acertar, soma 1 ponto
            printf("Correto!\n\n");
        }
        else
        {
            printf("Errado!\n\n");
        }
    }

    // Mostra o resultado final
    printf("Pontuação final: %d / 3\n", pontos);

    return 0;  // Indica que o programa terminou corretamente
}
