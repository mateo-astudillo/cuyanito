#include "../../inc/cuyanito.h"
#include "../../inc/insert.h"

static int get_int(){
  char text_tmp[LENGTH_TMP];
  int num = 0;
  scanf("%s", text_tmp);
  num = atoi(text_tmp);
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
  while (num < 1 || num > 3) {
    printf("Dispositivo:\n");
    printf("1 - PC\n");
    printf("2 - Notebook\n");
    printf("3 - Celular\n");
    num = get_int();
  }
  r->device = num ;

  // Employee code
  num = 0;
  while (num < 1 || num > 11) {
    printf("Código de empleado\n");
    num = get_int();
  }
  r->employee_code = num ;

  // Date
  do {
    num = 0;
    printf("Fecha\n");
    while (num < 1 || num > 31) {
      printf("Día 1-31\n");
      num = get_int();
    }
    day = num;
    num = 0;
    while (num < 1 || num > 12) {
      printf("Mes 1-12\n");
      num = get_int();
    }
    month = num;
    num = 0;
    while (num < 1900 || num > 2022) {
      printf("Año 1900-2022\n");
      num = get_int();
    }
    year = num;
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

