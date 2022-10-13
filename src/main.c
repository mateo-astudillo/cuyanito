#include "../inc/cuyanito.h"
#include "../inc/menu.h"
#include "../inc/insert.h"
#include "../inc/update.h"
#include "../inc/show.h"
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  REPAIR_LIST *repair_list = NULL;
  int option = 0;
  while (option != 8) {
    option = menu();
    switch (option) {
    case 1:
      insert_repair(&repair_list);
      break;
    case 2:
      // search_type();
      break;
    case 3:
      // search_price();
      break;
    case 4:
      // show_employee();
      break;
    case 5:
      // show_busisness();
      break;
    case 6:
      // show_date();
      break;
    case 7:
      // save();
      break;
    case 8:
      free_list(&repair_list);
      printf("Adiós\n");
      break;
    case 9:
      show_data(); // dev
      break;
    case 10:
      show_repairs(repair_list); // dev
      break;
    default:
      printf("Opción incorrecta\n");
      break;
    }
  }
  return 0;
}
