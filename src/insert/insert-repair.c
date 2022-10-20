#include "../../inc/cuyanito.h"
#include "../../inc/insert.h"

int get_int(int min, int max, char *text){
  char text_tmp[LENGTH_TMP];
  int num = 0;
  while (num < min || num > max) {
    printf(" %s\n (%d - %d)\n > ", text, min, max);
    scanf("%s", text_tmp);
    num = atoi(text_tmp);
  }
  return num;
}

char *get_date() {
  char *date = malloc(11);
  int day, month, year, ok;
  do {
    printf(" Fecha\n");
    day = get_int(1, 31, "Día");
    month = get_int(1, 12, "Mes");
    year = get_int(1, 22, "Año");
    year += 2000;
    ok = sprintf(date, "%d/%d/%d\n", day, month, year);
  } while ( !ok );
  return date;
}

static int get_data_repair(REPAIR *r) {
  int day, month, year, ok;

  r->device = get_int(1, 3, "Dispositivo\n 1 - PC\n 2 - Notebook\n 3 - Celular");
  r->employee_code = get_int(1, 11, "Código de empleado");
  do {
    printf(" Fecha\n");
    day = get_int(1, 31, "Día");
    month = get_int(1, 12, "Mes");
    year = get_int(1, 22, "Año");
    year += 2000;
    ok = sprintf(r->date, "%d/%d/%d\n", day, month, year);
  } while ( !ok );

  return 0;
}

int insert_repair(REPAIR_LIST **list) {
  REPAIR_LIST *l = *list;
  REPAIR_LIST *new = malloc(sizeof(REPAIR_LIST));

  if ( new == NULL ) {
    return -1;
  }

  new->prev = NULL;
  new->next = l;
  if ( l != NULL )
    l->prev = new;
  *list = new;

  get_data_repair(&new->repair);

  return 0;
}
/*
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
*/
