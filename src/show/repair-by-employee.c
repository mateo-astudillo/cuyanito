#include "../../inc/cuyanito.h"
#include "../../inc/show.h"
#include "../../inc/insert.h"

int show_by_employee(REPAIR_LIST *rl){ // repair list
  REPAIR repair;
  int em_code = 0;
  int quantity_em = 0;

  quantity_em = quantity_of( EMPLOYEES_PATH, sizeof(EMPLOYEE) );
  em_code = get_int(1, quantity_em, "Código de empleado");
  
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
