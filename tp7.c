
#include <stdio.h>

#define TAM 5

// Repositorio: https://github.com/mate-ctrl1244/trabajo-bmi

int main() {
    int codigo[TAM];
    float precio[TAM];
    int mayor = 0, menor = 0;
    int i;

    printf("Ingrese %d productos, se solicitara el codigo y precio:\n", TAM);

    for (i = 0; i < TAM; i++) {
        do {
            printf("Ingrese el codigo de barras (1-999999999): ");
            scanf("%d", &codigo[i]);

            if (codigo[i] < 1 || codigo[i] > 999999999) {
                printf("Error. El codigo de barras debe estar entre 1 y 999999999\n");
            }
        } while (codigo[i] < 1 || codigo[i] > 999999999);

        do {
            printf("Ingrese el precio: ");
            scanf("%f", &precio[i]);

            if (precio[i] < 0) {
                printf("Error. El precio no puede ser negativo.\n");
            }
        } while (precio[i] < 0);
    }

    mayor = 0;
    menor = 0;

    printf("\nCodigo       Precio\n");

    for (i = 0; i < TAM; i++) {
        printf("%9d %12.2f\n", codigo[i], precio[i]);

        if (precio[i] > precio[mayor]) {
            mayor = i;
        }

        if (precio[i] < precio[menor]) {
            menor = i;
        }
    }

    printf("\nMas caro: [%d] %.2f\n", codigo[mayor], precio[mayor]);
    printf("Mas barato: [%d] %.2f\n", codigo[menor], precio[menor]);

    return 0;
}
