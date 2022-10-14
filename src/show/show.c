#include "../../inc/cuyanito.h"
#include "../../inc/show.h"

// Devs functions

int show_data(){
  struct stat stat_em;
  int quantity_em = 0;
  if (stat(EMPLOYEE_PATH, &stat_em) == -1) {
    perror("Stat");
    return 1;
  }
  quantity_em = stat_em.st_size / sizeof(EMPLOYEE);

  FILE *fl = fopen(EMPLOYEE_PATH, "rb");

  EMPLOYEE *em = malloc(sizeof(EMPLOYEE));
  for (int i = 0; i < quantity_em; i++) {
    fread(em, sizeof(EMPLOYEE), 1, fl);
    printf(" %d\n %s\n %s\n %s\n %s\n\n", em->code, em->dni, em->cuil, em->name, em->surname);
  }
  fclose(fl);
  free(em);

  // Business
  struct stat stat_bs;
  int quantity_bs = 0;
  if (stat(BUSINESS_PATH, &stat_bs) == -1) {
    perror("Stat");
    return 1;
  }
  quantity_bs = stat_bs.st_size / sizeof(BUSINESS);

  fl = fopen(BUSINESS_PATH, "rb");
  BUSINESS *bs = malloc(sizeof(BUSINESS));
  for (int i=0; i < quantity_bs; i++) {
    fread(bs, sizeof(BUSINESS), 1, fl);
    printf(" %d\n %s\n %s\n\n", bs->code, bs->cuit, bs->name);
  }
  fclose(fl);
  free(bs);

  return 0;
}

int show_repairs(REPAIR_LIST *rl){
  FILE *fl = fopen(REPAIR_PATH, "a");
  fclose(fl);

  struct stat stat_r;
  int quantity_r = 0;
  if (stat(REPAIR_PATH, &stat_r) == -1) {
    perror("Stat");
    return 1;
  }
  quantity_r = stat_r.st_size / sizeof(REPAIR);

  fl = fopen(REPAIR_PATH, "rb");
  if (fl == NULL) {
    fclose(fl);
    return 1;
  }

  REPAIR *r = malloc(sizeof(REPAIR));
  printf("Reparaciones guardadas\n\n");
  for (int i = 0; i < quantity_r; i++) {
    fread(r, sizeof(REPAIR), 1, fl);
    switch (r->device) {
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
    printf("Código de empleado: %d\n", r->employee_code);
  }
  fclose(fl);
  free(r);

  printf("\nReparaciones sin guardar\n\n");
  while (rl != NULL) {
    switch (rl->repair.device) {
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
    printf("Código de empleado: %d\n", rl->repair.employee_code);
    rl = rl->next;
  }

  return 0;
}
