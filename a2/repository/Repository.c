#include "Repository.h"

EstateRepository create_repository()
{
    //EstateRepository repo = (EstateRepository*)malloc(sizeof(EstateRepository));
    EstateRepository repo;
    repo.estates = createArray(100);
    return repo;
}

int repo_find_by_attributes(EstateRepository * repo,char address[])
{
    for(int i=0; i<len(repo->estates); i++)
    {
        if(strcmp(repo->estates->elems[i].address, address)==0)
            // element is already in the list
            return i;
    }

    // element has not been found
    return -1;
}

int add_repository(EstateRepository* repo, Estate estate)

{
    int position = repo_find_by_attributes(repo,  get_address(&estate));
    if ( position == -1) {
        add(repo->estates, estate);
    }
    else {
        update(repo->estates, position, estate);
    }
    return 1;
}

int delete_repository(EstateRepository* repo, char address[])
{
    int position = repo_find_by_attributes(repo,address);
    if ( position == -1)
        return 0;
    else{
        delete(repo->estates, position);
        return 1;
    }
}

int update_repository(EstateRepository* repo,int position, Estate new_estate)
{
    update(repo->estates, position, new_estate);
    return 1;
}
/*
void destroy_repository(EstateRepository* repo)
{
    deallocate_array(repo->estates);
    free(repo);
}
 */

DynamicArray* repo_get_array(EstateRepository * repo)
{
    return repo->estates;
}

int repo_len(EstateRepository * repo)
{
    return repo->estates->length;
}
