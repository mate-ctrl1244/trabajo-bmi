#include <stdio.h>

int main() {

    float peso, altura, bmi;

    do {
        printf("Ingrese el peso en kg: ");
        scanf("%f", &peso);

        if (peso < 0) {
            printf("Error: el peso debe ser mayor que cero.\n");
        }

    } while (peso < 0);

    do {
        printf("\nIngrese la altura en metros: ");
        scanf("%f", &altura);

        if (altura <= 0) {
            printf("Error: la altura debe ser mayor que cero.\n");
        }

    } while (altura <= 0);

    bmi = peso / (altura * altura);

    printf("\nSu índice de masa corporal es: %.2f\n\n", bmi);

    printf("    Indice    | Condicion\n");
    printf("--------------------------\n");
    printf("    <18.5     | Bajo peso\n");
    printf(" 18.5 a 24.9  | Normal\n");
    printf(" 25.0 a 29.9  | Sobrepeso\n");
    printf("     >=30     | Obesidad\n");

    if (bmi < 18.5) {
        printf("\nUsted se encuentra en la condición: Bajo peso\n");
    }
    else if (bmi < 25) {
        printf("\nUsted se encuentra en la condición: Normal\n");
    }
    else if (bmi < 30) {
        printf("\nUsted se encuentra en la condición: Sobrepeso\n");
    }
    else {
        printf("\nUsted se encuentra en la condición: Obesidad\n");
    }

    // Repositorio: https://github.com/mate-ctrl1244/trabajo-bmi

    return 0;
}