#pragma once

#include "cuyanito.h"

int show_data();
int show_repairs(REPAIR_LIST *);
void print_repair(REPAIR);

int quantity_of(char *, int);

int show_by_employee(REPAIR_LIST *); 
int show_by_business(REPAIR_LIST *);
// int show_by_date(REPAIR_LIST *);
