#include <stdio.h>

int main()
{
    int days_of_week = 0;
    printf("Choose a number for a day of the week (1-7): ");
    scanf("%d", &days_of_week);

    switch (days_of_week)
    {
        case 1:
            printf("It is Monday\n");
            break;

        case 2:
            printf("It is Tuesday\n");
            break;

        case 3:
            printf("It is Wednesday\n");
            break;

        case 4:
            printf("It is Thursday\n");
            break;

        case 5:
            printf("It is Friday\n");
            break;

        case 6:
            printf("It is Saturday\n");
            break;

        case 7:
            printf("It is Sunday\n");
            break;

        default:
            printf("Input not valid. Please choose a number from 1-7: ");
            break;
    }
    
    return 0;
}