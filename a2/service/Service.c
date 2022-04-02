#include "Service.h"

EstateService create_service(EstateRepository* repo)
{
    EstateService serv;
    serv.repo = repo;
    return serv;
}
/*
void destroy_service(EstateService* serv)
{
    destroy_repository(serv->repo);
    free(serv);
}

EstateRepository * get_repo(EstateService * serv)
{
    return serv->repo;
}
*/

int search_by_attributes(EstateService* serv,  char address[])
{/*
    status = validate_string(address);
    if(status == 0)
        return 0;
*/
    return repo_find_by_attributes(serv->repo, address);
}

int add_service(EstateService* serv, char type[], char address[], double surface, double price)
{/*
    int status = validate_string(type);
    if(status == 0)
        return 0;
    status = validate_string(address);
    if(status == 0)
        return 0;
    status = validate_int(surface);
    if(status == 0)
        return 0;
    status = validate_int(price);
    if(status == 0)
        return 0;*/
    Estate estate = create_estate(type,address,surface,price);

    int status = add_repository(serv->repo, estate);

    return status;
}

int delete_service(EstateService * serv, char * address)
{   int result;
    result = delete_repository(serv->repo, address);

    return result;
}

int update_service(EstateService * serv, int position, char address[], char new_type[], double new_surface, double new_price)
{   int result;
    Estate  new_estate = create_estate(new_type, address, new_surface, new_price);
    return update_repository(serv->repo,position, new_estate);
    //if (result != 0)
        //return 1;
    //return 0;
    //return result;
}

DynamicArray* get_array(EstateService* serv)
{
    return repo_get_array(serv->repo);
}

/*
EstateRepository * filter_address(EstateService * serv, char key[])
{
    EstateRepository* repo = create_repository();
    int i;
    for (i = 0; i < serv->repo->estates->length; i++)
        if (strstr(get_address(serv->repo->estates->elems[i]), key) != 0)
            add_repository(repo, serv->repo->estates->elems[i]);
    destroy_repository(repo);
    return repo;
}

EstateRepository* sort_repository(EstateService* serv, EstateRepository* repository)
{
    int i, j;
    Estate* aux;
    for (i = 0; i < repository->estates->length - 1; i++)
    {
        for (j = i + 1; j < repository->estates->length; j++)
        {
            if (get_price(repository->estates->elems[i]) > get_price(repository->estates->elems[j]))
            {
                aux = repository->estates->elems[j];
                repository->estates->elems[j] = repository->estates->elems[i];
                repository->estates->elems[i] = aux;
            }
        }
    }
    return repository;
}

EstateRepository * filter_surface(EstateService * serv, double surface, EstateRepository * repo)
{
    {
        EstateRepository* new_repo = create_repository();
        int i;
        for (i = 0; i < repo->estates->length; i++)
        {
            if (surface == get_surface(repo->estates->elems[i]))
                add_repository(new_repo, repo->estates->elems[i]);
        }
        return new_repo;
    }
}
*/