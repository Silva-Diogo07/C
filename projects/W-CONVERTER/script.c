 #include <stdio.h>

int main()

{
    int choice = 0;
    float pounds = 0.0f;
    float kilograms = 0.0f;

    printf("Weight Conversion Calculator\n");

    printf("\n");
    printf("Choose an option:\n");

    printf("\n");
    printf("1. Kilograms to pounds\n");
    printf("2. Pounds to kilograms\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter how many kilograms do you want to convert: ");
        scanf("%f", &kilograms);

        pounds = kilograms * 2.20462;
        printf("%.2f kilograms is %.2f pounds\n", kilograms, pounds);
        return 0;
    }
    printf("Enter how many pounds do you want to convert: ");
    scanf("%f", &pounds);

    kilograms = pounds / 2.20462;
    printf("%.2f pounds is %.2f kilograms\n", pounds, kilograms);

    return 0;
}