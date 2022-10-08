//#include <inc/menu.h> // Final
#include "../inc/menu.h" // Dev
#include "../inc/cuyanito.h" // Dev

int menu(int *opt){
  char parse[LENGTH_PARSE];
  printf("1 Ingresar reparaciones\n");
  printf("2 Buscar una reparacion segun el tipo de dispositivo\n");
  printf("3 Buscar la reparacion con mayor precio final\n");
  printf("4 Mostrar las reparaciones realizadas por un empleado especifico\n");
  printf("5 Mostrar las reparaciones correspondientes a una sola empresa\n");
  printf("6 Mostrar las reparaciones realizadas en una fecha \n");
  printf("7 Almacenar todas las reparaciones\n");
  printf("8 Salir del programa\n");
  scanf("%s", parse);
  *opt = atoi(parse);
  return 0;
}

