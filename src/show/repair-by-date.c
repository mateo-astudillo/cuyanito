#include "../../inc/cuyanito.h"
#include "../../inc/show.h"
#include "../../inc/insert.h"

int show_by_date(REPAIR_LIST *rl) { // repair list
  REPAIR repair;
  int bs_code = 0;
  int quantity_r = 0;
  char date[11];
  char *text_tmp;

  quantity_r = quantity_of( REPAIR_PATH, sizeof(REPAIR) );
  FILE *rf = fopen(REPAIR_PATH, "rb"); // repair file


  text_tmp = get_date();
  strcpy( date, text_tmp );
  free(text_tmp);

  for(int i = 0; i < quantity_r; i++) {
    fread(&repair, sizeof(REPAIR), 1, rf);
    if ( !strcmp(date, repair.date) ) {
      print_repair(repair);      
    }
  }
  
  fclose(rf);
  return 0;
}
