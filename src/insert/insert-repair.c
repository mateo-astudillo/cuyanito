#include "../../inc/cuyanito.h"
#include "../../inc/insert.h"

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

int get_data_repair(REPAIR *r) {
  char text_temp[LENGTH_TMP];
  int tmp = 0;

  // Device
  printf("Dispositivo:\n");
  printf("1 - PC\n");
  printf("2 - Notebook\n");
  printf("3 - Celular\n");
  scanf("%s", text_temp);
  tmp = atoi(text_temp);
  if ( tmp > 0 && tmp < 4 ) {
    r->device = tmp;
  }

  // Employee code
  printf("Insert employee code\n");
  scanf("%s", text_temp);
  tmp = atoi(text_temp);
  if ( tmp ) {
    r->employee_code = tmp;
  }
  return 0;
}
