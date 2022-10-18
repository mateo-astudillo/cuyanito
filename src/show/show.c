#include "../../inc/cuyanito.h"
#include "../../inc/show.h"

int quantity_of(char *file, int size_struct) {
  struct stat stat_em;
  int quantity = 0;
  if ( stat(file, &stat_em) == -1 ) {
    perror("Stat");
    return -1;
  }
  quantity = stat_em.st_size / size_struct;

  return quantity;
}


int show_data(){
  EMPLOYEE em;
  BUSINESS bs; 
  int quantity_em = 0; 
  int quantity_bs = 0;

  quantity_em = quantity_of(EMPLOYEES_PATH, sizeof(EMPLOYEE));
  FILE *fl = fopen(EMPLOYEES_PATH, "rb");
  for (int i = 0; i < quantity_em; i++) {
    fread(&em, sizeof(EMPLOYEE), 1, fl);
    printf(" %d\n %s\n %s\n %s\n %s\n\n", em.code, em.dni, em.cuil, em.name, em.surname);
  }
  fclose(fl);

  // Business
  quantity_bs = quantity_of(BUSINESS_PATH, sizeof(BUSINESS));
  fl = fopen(BUSINESS_PATH, "rb");
  for (int i=0; i < quantity_bs; i++) {
    fread(&bs, sizeof(BUSINESS), 1, fl);
    printf(" %d\n %s\n %s\n\n", bs.code, bs.cuit, bs.name);
  }
  fclose(fl);

  return 0;
}

void print_repair(REPAIR r){
  switch (r.device) {
    case 1:
      printf("Dispositivo: PC\n");
      break;
    case 2:
      printf("Dispositivo: Notebook\n");
      break;
    case 3:
      printf("Dispositivo: Celular\n");
      break;
  }
  printf("Código de empleado: %d\n", r.employee_code);
  printf("Fecha: %s\n", r.date);
}


int show_repairs(REPAIR_LIST *rl){
  FILE *fl = fopen(REPAIR_PATH, "a");
  fclose(fl);

  struct stat stat_r;
  int quantity_r = 0;
  if (stat(REPAIR_PATH, &stat_r) == -1) {
    perror("Stat");
    return -1;
  }
  quantity_r = stat_r.st_size / sizeof(REPAIR);

  fl = fopen(REPAIR_PATH, "rb");
  if (fl == NULL) {
    fclose(fl);
    return -1;
  }

  REPAIR *r = malloc(sizeof(REPAIR));
  printf("Reparaciones guardadas\n\n");
  for (int i = 0; i < quantity_r; i++) {
    fread(r, sizeof(REPAIR), 1, fl);
    print_repair(*r);
  }
  fclose(fl);
  free(r);

  printf("\nReparaciones sin guardar\n\n");
  while (rl != NULL) {
    print_repair(rl->repair);
    rl = rl->next;
  }

  return 0;
}
