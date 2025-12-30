#include <stdio.h>
#include <string.h>

typedef struct
{
    char *name;
    char *number;
} person;


int main(void)
{
    person people[3];
    
    people[0].name = "Michael";
    people[0].number = "+351 910 329 102";

    people[1].name = "Tone";
    people[1].number = "+351 961 491 103";

    people[2].name = "Ana";
    people[2].number = "+351 910 329 102";

    char name[100]; 

    printf("Name: ");
    scanf("%99s", name);

    for (int i = 0; i < 3; i++)
    {   
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found.\nNumber : %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}