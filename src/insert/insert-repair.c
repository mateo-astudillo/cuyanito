#include "../../inc/cuyanito.h"
#include "../../inc/insert.h"

static int get_int(int min, int max){
  char text_tmp[LENGTH_TMP];
  int num = 0;
  while (num < min || num > max) {
    scanf("%s", text_tmp);
    num = atoi(text_tmp);
  }
  return num;
}

static float get_float(){
  char text_tmp[LENGTH_TMP];
  int num = 0;
  scanf("%s", text_tmp);
  num = atof(text_tmp);
  return num;
}

static int get_data_repair(REPAIR *r) {
  int num = 0;
  float num_f = 0;
  int day, month, year;

  // Device
  printf("Dispositivo:\n");
  printf("1 - PC\n");
  printf("2 - Notebook\n");
  printf("3 - Celular\n");
  r->device = get_int(1, 3);

  // Employee code
  printf("Código de empleado\n");
  r-> employee_code = get_int(1, 11);

  // Date
  do {
    printf("Fecha\n");
    printf("Día 1-31\n");
    day = get_int(1, 31);
    printf("Mes 1-12\n");
    month = get_int(1, 12);
    printf("Año 1-22\n");
    year = get_int(1, 22);
    year += 2000;
    num = sprintf(r->date, "%d/%d/%d\n", day, month, year);
  } while ( !num );

  return 0;
}

int insert_repair(REPAIR_LIST **list) {
  REPAIR_LIST *aux = *list;
  REPAIR_LIST *new = malloc(sizeof(REPAIR_LIST));
  if (new == NULL) {
    return 1;
  }
  if (aux == NULL) {
    *list = new;
    new->prev = NULL;
  } else {
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = new;
    new->prev = aux;
  }
  new->next = NULL;
  get_data_repair(&new->repair);
  return 0;
}

