//
// Created by User on 3/9/2021.
//

#ifndef Estate_h
#define Estate_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char type[100];
    char address[100];
    double surface;
    double price;
} Estate;

Estate create_estate(char type[], char address[], double surface, double price);

//void destroy_estate(Estate* estate);

//Estate* copy_estate(Estate* estate);

char* get_type(Estate* estate);

char* get_address(Estate* estate);

double get_surface(Estate* estate);

double get_price(Estate* estate);

void to_string(Estate estate, char str[]);

//Estate* copy_estate(Estate* estate);


#endif /* Estate_h */