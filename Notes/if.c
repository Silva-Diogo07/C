#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    bool isAdult = false;

    // if (isAdult)
    // {
    //     printf("You are an adult\n");
    // }
    // else
    // {
    //     printf("You are NOT an adult\n");
    // }

    char name[50] = "";

    printf("Enter you name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    if(strlen(name) == 0)
    {
        printf("You did not enter your name");
    }
    else if (strlen(name) != 0 && isAdult)
    {
        printf("Hello %s you are an adult\n", name);
    }
    else
    {
        printf("Hello %s you are NOT an adult\n", name);
    }
}