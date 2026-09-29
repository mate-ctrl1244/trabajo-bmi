#include <stdio.h>

int main() {

    float peso, altura, bmi;

    printf("Ingrese el peso en kg: ");
    scanf("%f", &peso);

    printf("\nIngrese la altura en metros: ");
    scanf("%f", &altura);

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
    return 0;
}