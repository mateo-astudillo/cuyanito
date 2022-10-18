#include "../../inc/cuyanito.h"
#include "../../inc/show.h"
#include <sys/stat.h>

int quantity_of(char *file, int size_struct) {
  struct stat stat_em;
  int quantity = 0;

  if ( stat(file, &stat_em) == -1 ) {
    perror("Stat");
    return -1;
  }
  quantity = stat_em.st_size / size_struct;
  
  // FILE *f = fopen(file, "rb");
  // fclose(f);

  return quantity;
}

int show_data(){
  FILE *fl;
  EMPLOYEE *em = malloc(sizeof(EMPLOYEE));
  BUSINESS *bs = malloc(sizeof(BUSINESS));
  int quantity_em = 11; 
  int quantity_bs = 10;

  quantity_em = quantity_of( EMPLOYEES_PATH, sizeof(EMPLOYEE) );
  fl = fopen(EMPLOYEES_PATH, "rb");
  // fseek(fl, 0, SEEK_SET);
  for (int i = 0; i < quantity_em; i++) {
    fread(em, sizeof(EMPLOYEE), 1, fl);
    printf(" %d\n %s\n %s\n %s\n %s\n\n", em->code, em->dni, em->cuil, em->name, em->surname);
  }
  fclose(fl);

  quantity_bs = quantity_of( BUSINESS_PATH, sizeof(BUSINESS) );
  FILE *f = fopen(BUSINESS_PATH, "rb");
  // fseek(fl, 0, SEEK_SET);
  for (int i = 0; i < quantity_bs; i++) {
    fread(bs, sizeof(BUSINESS), 1, f);
    printf(" %d\n %s\n %s\n\n", bs->code, bs->cuit, bs->name);
  }
  fclose(f);

  printf("%d qua em\n", quantity_em);
  printf("%d qua em\n", quantity_bs);

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
  REPAIR r;
  int quantity_r = 0;

  FILE *fl = fopen(REPAIR_PATH, "a");
  fclose(fl);

  quantity_r = quantity_of( REPAIR_PATH, sizeof(REPAIR) );
  fl = fopen(REPAIR_PATH, "rb");
  if (fl == NULL) {
    fclose(fl);
    return -1;
  }

  printf("Reparaciones guardadas\n\n");
  for (int i = 0; i < quantity_r; i++) {
    fread(&r, sizeof(REPAIR), 1, fl);
    print_repair(r);
  }
  fclose(fl);

  printf("\nReparaciones sin guardar\n\n");
  while ( rl->next != NULL) {
    rl = rl->next;
  }
  while ( rl != NULL ) {
    print_repair(rl->repair);
    rl = rl->prev;
  }

  return 0;
}
