#include <stdio.h>

int main() {

    int estudiantes;
    int calificacion;
    int mayor = 0;
    int menor = 100;
    int suma = 0;
    float promedio;

    do {
        printf("Ingrese la cantidad de estudiantes: ");
        scanf("%d", &estudiantes);

        if (estudiantes <= 0) {
            printf("Error: la cantidad de estudiantes debe ser positiva.\n");
        }

    } while (estudiantes <= 0);

    for (int i = 0; i < estudiantes; i++) {

        do {
            printf("Ingrese la calificacion del estudiante %d: ", i + 1);
            scanf("%d", &calificacion);

            if (calificacion < 0 || calificacion > 100) {
                printf("Error: la calificacion debe estar entre 0 y 100.\n");
            }

        } while (calificacion < 0 || calificacion > 100);

        suma += calificacion;

        if (calificacion > mayor) {
            mayor = calificacion;
        }

        if (calificacion < menor) {
            menor = calificacion;
        }
    }

    promedio = (float)suma / estudiantes;

    printf("\nPromedio: %.2f\n", promedio);
    printf("Calificacion mas alta: %d\n", mayor);
    printf("Calificacion mas baja: %d\n", menor);

    // Repositorio: https://github.com/mate-ctrl1244/trabajo-bmi

    return 0;
}