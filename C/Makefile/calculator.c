#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("%.5f\n" , (float) get_int("x: ") / get_int("y: ")); // aks for a integer x and y and then divides , returns 5 decimal numbers
}