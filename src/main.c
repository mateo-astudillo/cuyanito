#include "../inc/cuyanito.h"
#include "../inc/menu.h"
#include "../inc/insert.h"
#include "../inc/update.h"
#include "../inc/show.h"

static void safe_exit(REPAIR_LIST *rl) {
  if ( rl == NULL)
    return; 

  char option[LENGTH_TMP];
  char *messages[] = {
    "Está seguro que desea salir?",
    "Tiene reparaciones sin guardar",
    "Si - No (s - n)"
  };
  scanf("%s", option);
}

int main(int argc, char **argv) {
  REPAIR_LIST *repair_list = NULL;
  REPAIR_LIST *repair_list_saved = NULL;

  int option = 0;
  while (option != 8) {
    option = menu();
    system(CLEAR);
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
      show_by_employee(repair_list);
      break;
    case 5:
      show_by_busisness(repair_list);
      break;
    case 6:
      show_by_date(repair_list);
      break;
    case 7:
      safe_exit(repair_list)
      save(repair_list);
      free_list(&repair_list);
      break;
    case 8:
      free_list(&repair_list);
      printf("\n Adiós\n");
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
    printf("\n");
  }
  return 0;
}
