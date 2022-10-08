#pragma once

#define EMPLOYED_PATH "/home/mateo/Projects/C/Proyecto/data/empleados.dat"
#define BUSINESS_PATH "/home/mateo/Projects/C/Proyecto/data/empleados.dat"

#define LENGTH_PARSE 16

typedef struct {
  int code;
  char dni[9];
  char cuil[15];
  char name[40];
  char surname[40];
} EMPLOYEE;

typedef struct {
  int code;
  char cuit[15];
  char name[40];
} BUSINESS;

typedef struct {
  int device; // 1 PC - 2 Notebook - 3 smartphone
  int employee_code;
  char date[11];
  float hardware_cost;
  float software_cost;
  char business[100];
  int business_code;
  float price;
} REPAIR;

typedef struct REPAIR_LIST{
  REPAIR repair;
  struct REPAIR_LIST *next;
  struct REPAIR_LIST *prev;
} REPAIR_LIST;
