#include "../../inc/update.h"
#include "../../inc/cuyanito.h"

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