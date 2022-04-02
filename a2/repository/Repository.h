#ifndef Repository_h
#define Repository_h

#include <stdio.h>
#include <stdlib.h>

#include "../vector/DynamicArray.h"

typedef struct {
    DynamicArray *estates; //estates is a dynamic array with elements =estates of different types such as houses, apartments, villas, penthouses
} EstateRepository;

//This function creates a repository by allocating it memory
EstateRepository create_repository();

//This function destroys a repository by deallocating the memory already allocated
//void destroy_repository(EstateRepository* repo);
int repo_find_by_attributes(EstateRepository * repo, char address[]);
int add_repository(EstateRepository* repo, Estate estate);
//int get_repo_length(EstateRepository* repo);

int delete_repository(EstateRepository* repo, char address[]);
int update_repository(EstateRepository* repo, int position, Estate new_estate);
DynamicArray* repo_get_array(EstateRepository * repo);

int repo_len(EstateRepository * repo);
#endif /* Repository_h */