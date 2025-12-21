#include <stdio.h> 
#include <string.h> 

int main(void)
{
    char name[100];   
    int age;  

    printf("What's your name?\n");

    // Lê uma linha inteira
    // - Guarda no array 'name'
    // - Lê no máximo sizeof(name) caracteres
    fgets(name, sizeof(name), stdin);

    // Remove o '\n' (ENTER) que o fgets guarda no final da string
    // strcspn encontra a posição do primeiro '\n'
    // Substituímos por '\0' (fim da string)
    name[strcspn(name, "\n")] = '\0';

    printf("How old are you?\n");
    scanf("%d", &age);

    printf("Hello, %s, you are %d years old.\n", name, age);

    return 0;
}
