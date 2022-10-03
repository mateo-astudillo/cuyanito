#include <stdio.h>
#include <inc/menu.h>

int menu(){
  unsigned short int opt = 0;
  unsigned short int exit = 0;
  printf("1 Ingresar reparaciones\n");
  printf("2 Buscar una reparacion segun el tipo de dispositivo\n");
  printf("3 Buscar la reparacion con mayor precio final\n");
  printf("4 Mostrar las reparaciones realizadas por un empleado especifico\n");
  printf("5 Mostrar las reparaciones correspondientes a una sola empresa\n");
  printf("6 Mostrar las reparaciones realizadas en una fecha \n");
  printf("7 Almacenar todas las reparaciones\n");
  printf("8 Salir del programa\n");
  scanf("%hu", &opt);
  while (!exit) {
    switch (opt) {
      case 8:
        exit = 1;
        break;
      case 1:
        //insert();
        break;
      case 2:
        //searh_type();
        break;
      case 3:
        //searh_price();
        break;
      case 4:
        //show_employed();
        break;
      case 5:
        //show_busisness();
        break;
      case 6:
        //show_date();
        break;
      case 7:
        //update();
        break;
      default:
        printf("Option incorrect\n");
        break;
    }
  }
  return 0;
}

