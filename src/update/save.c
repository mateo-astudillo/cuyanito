#include "../../inc/cuyanito.h"
#include "../../inc/update.h"

int save(REPAIR_LIST *rl){
  FILE *fl = fopen(REPAIR_PATH, "wb");
  if (fl == NULL) {
    fclose(fl);
    return 1;
  }
  
  while (rl != NULL) {
    fwrite(&rl->repair, sizeof(REPAIR), 1, fl);
    rl = rl->next;
  }

  fclose(fl);
  return 0;
}

int free_list(REPAIR_LIST **repair_list) {
  REPAIR_LIST *repair = *repair_list;
  REPAIR_LIST *delete = NULL;
  
  while (repair != NULL) {
    delete = repair;
    repair = repair->next;
    free(delete);
  }
  
  *repair_list = NULL;

  return 0;
}
