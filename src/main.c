#include "../inc/cuyanito.h"
#include "../inc/menu.h"
#include "../inc/insert.h"

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
      // searh_type();
      break;
    case 3:
      // searh_price();
      break;
    case 4:
      // search_by_employee();
      break;
    case 5:
      // show_busisness();
      break;
    case 6:
      // show_date();
      break;
    case 7:
      // update();
      break;
    case 8:
      free_list(&repair_list);
      printf("Adiós\n");
      break;
    default:
      printf("Opción incorrecta\n");
      break;
    }
  }
  return 0;
}
