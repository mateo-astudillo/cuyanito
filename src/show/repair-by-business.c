#include "../../inc/cuyanito.h"
#include "../../inc/show.h"
#include "../../inc/insert.h"

int show_by_business(REPAIR_LIST *rl) { // repair list
  REPAIR repair;
  int bs_code = 0;
  int quantity_bs = 0;
  int quantity_r = 0;

  quantity_bs = quantity_of( BUSINESS_PATH, sizeof(BUSINESS) );
  bs_code = get_int(1, quantity_bs, "Código de empresa");
  
  quantity_r = quantity_of( REPAIR_PATH, sizeof(REPAIR) );
  FILE *rf = fopen(REPAIR_PATH, "rb"); // repair file

  for(int i = 0; i < quantity_r; i++) {
    fread(&repair, sizeof(REPAIR), 1, rf);
    if (repair.business_code == bs_code) {
      print_repair(repair);      
    }
  }
  
  fclose(rf);
  return 0;
}
