#ifndef Ui_h
#define Ui_h

#include <stdio.h>
#include <stdlib.h>
#include "../service/Service.h"

typedef struct {
    EstateService* serv;
} UI;

UI create_UI(EstateService* serv);

void add_ui(UI* ui);

void delete_ui(UI* ui);

void update_ui(UI* ui);

void print_estates(UI* ui);

void print_menu();
//void destroy(UI* ui);

void run(UI* ui);

#endif /* Ui_h */