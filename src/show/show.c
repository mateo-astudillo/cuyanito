#include "../../inc/cuyanito.h"
#include "../../inc/show.h"

// Devs functions

#define FILEPATH "/home/mateo/Projects/C/Cuyanito/data/empleados.dat"
#define FILEPATH2 "/home/mateo/Projects/C/Cuyanito/data/empresas.dat"

int show_data(){
  FILE *fl = fopen(FILEPATH, "rb");
  EMPLOYEE *em = malloc(sizeof(EMPLOYEE));

  for (int i=0; i<11; i++) {
    fread(em, sizeof(EMPLOYEE), 1, fl);
    printf(" %d\n %s\n %s\n %s\n %s\n\n", em->code, em->dni, em->cuil, em->name, em->surname);
  }

  fclose(fl);
  free(em);

  fl = fopen(FILEPATH2, "rb");
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
  while (rl != NULL) {
    switch (rl->repair.device) {
      case 1:
        printf("Device: PC\n");
        break;
      case 2:
        printf("Device: Notebook\n");
        break;
      case 3:
        printf("Device: Smartphone\n");
        break;
    }
    printf("Employee code: %d\n", rl->repair.employee_code);
    rl = rl->next;
  }
  return 0;
}
