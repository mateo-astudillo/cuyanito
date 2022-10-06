#pragma once

#define EMPLOYED_PATH "/home/mateo/Projects/C/Proyecto/data/empleados.dat"
#define BUSINESS_PATH "/home/mateo/Projects/C/Proyecto/data/empleados.dat"

typedef struct {
  int code;
  char dni[9];
  char cuil[15];
  char name[40];
  char surname[40];
} employee;

typedef struct {
  int code;
  char cuit[15];
  char name[40];
} business;

typedef struct {
  int device; // 1 PC - 2 Notebook - 3 smartphone
  int employee_code;
  char date[11];
  float hardware_cost;
  float software_cost;
  char business[100];
  int business_code;
  float price;
} data;

