#include "../inc/cuyanito.h"
#include "../inc/menu.h" 

int menu(){
  int option = 0;
  char text_tmp[LENGTH_TMP];
  char *options[] = {
    "1 Ingresar reparaciones",
    "2 Buscar una reparación segun el tipo de dispositivo",
    "3 Buscar la reparacion con mayor precio final",
    "4 Mostrar las reparaciones realizadas por un empleado especifico",
    "5 Mostrar las reparaciones correspondientes a una sola empresa",
    "6 Mostrar las reparaciones realizadas en una fecha",
    "7 Almacenar todas las reparaciones",
    "8 Salir del programa",
    "9 Ver empleados y empresas",
    "10 ver reparaciones",
  };
  int size_options = sizeof(options) / sizeof(char*);
  for (int i = 0; i < size_options; i++) {
    printf(" %s\n", options[i]);
    usleep(50000);
  }
  printf(" > ");
  scanf("%s", text_tmp);
  option = atoi(text_tmp);
  return option;
}

