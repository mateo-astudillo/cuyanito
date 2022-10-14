#include "../../inc/cuyanito.h"
#include "../../inc/show.h"
#include <stdio.h>

// Devs functions

int show_data(){
  FILE *fl = fopen(EMPLOYEE_PATH, "rb");

  EMPLOYEE *em = malloc(sizeof(EMPLOYEE));
  for (int i=0; i<11; i++) {
    fread(em, sizeof(EMPLOYEE), 1, fl);
    printf(" %d\n %s\n %s\n %s\n %s\n\n", em->code, em->dni, em->cuil, em->name, em->surname);
  }
  fclose(fl);
  free(em);

  fl = fopen(BUSINESS_PATH, "rb");
  BUSINESS *bs = malloc(sizeof(BUSINESS));
  for (int i=0; i<10; i++) {
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

  fl = fopen(REPAIR_PATH, "rb");
  if (fl == NULL) {
    fclose(fl);
    return 1;
  }

  REPAIR *r = malloc(sizeof(REPAIR));
  fread(r, sizeof(REPAIR), 1, fl);

  printf("Reparaciones guardadas\n");
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
  fclose(fl);
  free(r);

  printf("Reparaciones sin guardar\n");
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
