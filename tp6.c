#include <stdio.h>

#define PI 3.14159265

float calcularAreaRectangulo(float longitud, float altura) {
    return longitud * altura;
}

float calcularPerimetroRectangulo(float longitud, float altura) {
    return 2 * (longitud + altura);
}

float calcularAreaCirculo(float radio) {
    return PI * radio * radio;
}

float calcularPerimetroCirculo(float radio) {
    return 2 * PI * radio;
}

void imprimirResultados(float area, float perimetro) {
    printf("El area es: %.2f\n", area);
    printf("El perimetro es: %.2f\n", perimetro);
}

int main() {
    int opcion;
    float longitud, altura, radio;
    float area, perimetro;

    do {
        printf("Ingrese la figura que desea calcular (1: rectangulo, 2: circulo): ");
        scanf("%d", &opcion);

        if (opcion != 1 && opcion != 2) {
            printf("Opcion invalida. Ingrese 1 o 2.\n");
        }

    } while (opcion != 1 && opcion != 2);

    if (opcion == 1) {
        printf("\nOpcion de rectangulo seleccionada\n");

        printf("Ingrese la longitud del rectangulo: ");
        scanf("%f", &longitud);

        printf("Ingrese la altura del rectangulo: ");
        scanf("%f", &altura);

        area = calcularAreaRectangulo(longitud, altura);
        perimetro = calcularPerimetroRectangulo(longitud, altura);

        printf("\nEl area del rectangulo es: %.2f\n", area);
        printf("El perimetro del rectangulo es: %.2f\n", perimetro);

    } else {
        printf("\nOpcion de circulo seleccionada\n");

        printf("Ingrese el radio del circulo: ");
        scanf("%f", &radio);

        area = calcularAreaCirculo(radio);
        perimetro = calcularPerimetroCirculo(radio);

        printf("\nEl area del circulo es: %.2f\n", area);
        printf("El perimetro del circulo es: %.2f\n", perimetro);
    }

    return 0;
}