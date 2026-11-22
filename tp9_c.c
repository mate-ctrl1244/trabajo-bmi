// Repositorio: PEGAR_AQUI_LA_URL_DE_TU_REPOSITORIO
#include <stdio.h>
#include <stdlib.h>

#define TAM_NOMBRE_ESTUDIANTE 80
#define TAM_NOMBRE_MATERIA 80

typedef struct {
  char nombre[TAM_NOMBRE_MATERIA];
  int cantidad_parciales;
  int *parcial;
  float promedio;
} materia_t;

struct estudiante {
  int legajo;
  char nombre[TAM_NOMBRE_ESTUDIANTE];
  int cantidad_materias;
  materia_t *materia;
};

struct estudiante cargar_estudiante(void);
void imprimir_estudiante(struct estudiante);
materia_t* reservar_materias(int);
void liberar_materias(materia_t*);
int* reservar_parciales(int);
void liberar_parciales(int*);
void cargar_materia(materia_t*);
void cargar_parciales(materia_t*);
void calcular_promedio(materia_t*);

int main(void){
  struct estudiante est1;

  est1 = cargar_estudiante();
  for (int i = 0; i < est1.cantidad_materias; i++)
    cargar_materia(est1.materia+i);

  imprimir_estudiante(est1);

  for (int i = 0; i < est1.cantidad_materias; i++)
    liberar_parciales((est1.materia+i)->parcial);
  liberar_materias(est1.materia);

  return 0;
}

struct estudiante cargar_estudiante(void) {
  struct estudiante e;

  printf("Ingrese legajo del estudiante: ");
  scanf("%d", &e.legajo);

  printf("Ingrese nombre del estudiante: ");
  scanf(" %79[^\n]", e.nombre);

  printf("¿Cuántas materias va a cargar? ");
  scanf("%d", &e.cantidad_materias);
  while (e.cantidad_materias < 1) {
    printf("Debe cargar al menos una materia. ¿Cuántas materias va a cargar? ");
    scanf("%d", &e.cantidad_materias);
  }
  e.materia = reservar_materias(e.cantidad_materias);

  return e;
}

void imprimir_estudiante(struct estudiante e) {
  printf("%10d", e.legajo);
  printf(" %s", e.nombre);

  printf("\n");
  for (int i = 0; i < e.cantidad_materias; i++) {
    materia_t *m = e.materia+i;
    printf("%s:", m->nombre);
    for (int j = 0; j < m->cantidad_parciales; j++)
      printf("%5d", *(m->parcial+j));
    printf("  Promedio: %.2f\n", m->promedio);
  }
}

void cargar_materia(materia_t *p) {
  printf("Ingrese el nombre de la materia: ");
  scanf(" %79[^\n]", p->nombre);
  printf("¿Cuántos parciales tiene %s? ", p->nombre);
  scanf("%d", &p->cantidad_parciales);

  p->parcial = reservar_parciales(p->cantidad_parciales);

  cargar_parciales(p);
}

void cargar_parciales(materia_t *p) {
  for (int i = 0; i < p->cantidad_parciales; i++) {
    printf("Ingrese calificación del %d° parcial: ", i + 1);
    scanf("%d", p->parcial+i);
    while (*(p->parcial+i) < 1 || *(p->parcial+i) > 10) {
      printf("Calificación inválida. Ingrese una nota entre 1 y 10: ");
      scanf("%d", p->parcial+i);
    }
  }
  calcular_promedio(p);
}

void calcular_promedio(materia_t *p) {
  int suma = 0;

  for (int i = 0; i < p->cantidad_parciales; i++)
    suma += *(p->parcial+i);

  if (p->cantidad_parciales > 0)
    p->promedio = (float)suma / p->cantidad_parciales;
  else
    p->promedio = 0;
}

materia_t* reservar_materias(int n) {
  materia_t *p = NULL;

  p = malloc(n * sizeof(materia_t));
  if (p == NULL) {
    printf("No se pudo reservar memoria. Fin del programa.\n");
    exit(1);
  }

  return p;
}

int* reservar_parciales(int n) {
  int *p = NULL;

  p = malloc(n * sizeof(int));
  if (p == NULL) {
    printf("No se pudo reservar memoria. Fin del programa.\n");
    exit(1);
  }

  return p;
}

void liberar_parciales(int *p) {
  if (p != NULL)
    free(p);
}

void liberar_materias(materia_t *p) {
  if (p != NULL)
    free(p);
}
