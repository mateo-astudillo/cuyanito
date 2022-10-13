#include "../../inc/show.h"
#include "../../inc/cuyanito.h"
#include <stdio.h>
#include <stdlib.h>

#define FILEPATH "/home/mateo/Projects/C/Cuyanito/data/empleados.dat"
#define FILEPATH2 "/home/mateo/Projects/C/Cuyanito/data/empresas.dat"

int show(){
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
