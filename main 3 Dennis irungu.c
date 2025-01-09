#include <stdio.h>

int main()
{
    float fahr, celcius;
    float start, end, increment;

    printf("32(Fahrenheit): ");
    scanf("%f", &start);

    printf("100(Fahrenheit): ");
    scanf("%f", &end);

    printf("Increment: ");
    scanf("%f", &increment);

    printf("\nFahrenheit to Celsius conversion table\n");
    printf("=====================================\n");
    printf("Fahrenheit\tCelsius\n");
    printf("-------------------------------------\n");

    for (fahr = start; fahr <= end; fahr += increment)
    {
        celcius = (fahr - 32) * 5.0 / 9.0;
        printf("%.2f\t\t%.2f\n", fahr, celcius);
    }

    return 0;
}
