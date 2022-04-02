#include "Estate.h"
#include <string.h>
#include <stdio.h>
Estate create_estate(char type[], char address[], double surface, double price)
{
    //Estate* estate = (Estate*) malloc(sizeof(Estate));
    //estate -> type = (char*) malloc(sizeof(char)*strlen(type) + 1);
    //estate->address = (char*) malloc(sizeof(char)*strlen(address) + 1);
    Estate estate;
    strcpy(estate.type, type);
    strcpy(estate.address, address);

    estate.surface = surface;
    estate.price = price;

    return estate;
}
/*
void destroy_estate(Estate * estate)
{
    //free(estate->address);
    //free(estate->type);
    free(estate);
}

Estate * copy_estate(Estate * estate)
{
    Estate* new_estate = create_estate(estate->type, estate->address, estate->surface, estate->price);
    return new_estate;
}
*/
char * get_type(Estate * estate)
{
    return estate->type;

}

char * get_address(Estate * estate)
{
    return estate->address;
}

double get_surface(Estate * estate)
{
    return estate->surface;
}

double get_price(Estate * estate)
{
    return estate->price;
}

void to_string(Estate estate, char str[])
{
    sprintf(str, "%s | %s | %.2lf. | %.2lf.",  estate.type,  estate.address,  estate.surface, estate.price);

}