#ifndef Controller_h
#define Controller_h

#include <stdio.h>
#include <stdlib.h>
#include "../repository/Repository.h"

typedef struct {
    EstateRepository* repo;
}EstateService;

EstateService create_service(EstateRepository* repo);

//void destroy_service(EstateService* serv);
int add_service(EstateService* serv, char type[], char address[], double surface, double price);
int search_by_attributes(EstateService* serv,char address[]);

//EstateRepository* get_repo(EstateService* serv);

int delete_service(EstateService* serv, char address[]);
int update_service(EstateService* serv ,int position, char address[], char new_type[], double new_surface, double new_price);
DynamicArray* get_array(EstateService* serv);
//EstateRepository* filter_address(EstateService* serv, char key[]);
//EstateRepository* sort_repository(EstateService* serv, EstateRepository* repository);
//EstateRepository* filter_surface(EstateService* serv, double surface, EstateRepository* repo);


#endif /* Service_h */