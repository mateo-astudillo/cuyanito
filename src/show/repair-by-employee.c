#include "../../inc/cuyanito.h"
#include "../../inc/show.h"

int show_by_employee(REPAIR_LIST *rl){ // repair list
  int em_code = 0;
  printf("Código de empleado: ");
  scanf("%d", &em_code);
  
  struct stat stat_r;
  int quantity_em = 0;
  if (stat(REPAIR_PATH, &stat_r) == -1) {
    perror("Stat");
    return -1;
  }
  quantity_em = stat_r.st_size / sizeof(REPAIR);

  REPAIR repair;
  FILE *rf = fopen(REPAIR_PATH, "rb"); // repair file

  for(int i = 0; i < quantity_em; i++) {
    fread(&repair, sizeof(REPAIR), 1, rf);
    if (repair.employee_code == em_code) {
      print_repair(repair);      
    }
  }
  
  fclose(rf);
  return 0;
}
