//#include <inc/menu.h> // Final
#include "../inc/cuyanito.h" // Dev
#include "../inc/menu.h" // Dev

int menu(){
  int option = 0;
  char parse[MENU_PARSE];
  char *options[] = {
    "1 Ingresar reparaciones",
    "2 Buscar una reparación segun el tipo de dispositivo",
    "3 Buscar la reparacion con mayor precio final",
    "4 Mostrar las reparaciones realizadas por un empleado especifico",
    "5 Mostrar las reparaciones correspondientes a una sola empresa",
    "6 Mostrar las reparaciones realizadas en una fecha",
    "7 Almacenar todas las reparaciones",
    "8 Salir del programa",
  };
  for (int i = 0; i < 8; i++) {
    printf(" %s\n", options[i]);
    usleep(50000);
  }
  scanf("%s", parse);
  option = atoi(parse);
  return option;
}

