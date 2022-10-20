#include "../inc/cuyanito.h"
#include "../inc/menu.h"
#include "../inc/insert.h"
#include "../inc/update.h"
#include "../inc/show.h"

static void safe_exit(REPAIR_LIST **rl, int *o) {
  if ( *rl == NULL)
    return;

  int option = 0;
  char *messages[] = {
    "Está seguro que desea salir?",
    "Tiene reparaciones sin guardar",
    "1 - Guardar y salir",
    "2 - Solo guardar",
    "3 - Salir sin guardar"
  };
  for (int i = 0; i < 5; i++) {
    printf(" %s\n", messages[i]);
  }
  option = get_int(1, 3, "");
  switch (option) {
    case 1:
      save(*rl);
      printf("\n Adiós\n");
    case 2:
      save(*rl);
      *o = 11;
      break;
    case 3:
      break;
    default:
      break;
  }
  free_list(rl);
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
      show_by_business(repair_list);
      break;
    case 6:
      // show_by_date(repair_list);
      break;
    case 7:
      save(repair_list);
      free_list(&repair_list);
      break;
    case 8:
      safe_exit(&repair_list, &option);
      break;
    case 9:
      show_data(); // dev
      break;
    case 10:
      show_repairs(repair_list); // dev
      break;
    case 11:
      break;
    default:
      printf("Opción incorrecta\n");
      break;
    }
    printf("\n");
  }
  return 0;
}
