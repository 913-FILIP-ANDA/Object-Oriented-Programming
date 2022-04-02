

#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

DynamicArray* createArray(int capacity)
{
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));

    //checking if the space was allocated
    if(arr == NULL)
        return NULL;

    arr->capacity = capacity;
    arr->length = 0;

    // allocating space for elements
    arr->elems = (TElement*)malloc(capacity * sizeof(TElement));
    if(arr->elems == NULL)
        return NULL;

    return arr;
}

DynamicArray * create_copy(DynamicArray* darr)
{
    DynamicArray * copy_darr = (DynamicArray*)malloc(sizeof(DynamicArray));

    if(darr == NULL)
        return NULL;

    copy_darr->capacity = darr->capacity;
    copy_darr->length = darr->length;

    copy_darr->elems = (TElement*)malloc(darr->capacity * sizeof(TElement));
    for(int i=0; i<copy_darr->length; i++)
        copy_darr->elems[i] = darr->elems[i];

    return copy_darr;
}

void destroy(DynamicArray* arr)
{
    if(arr==NULL)
        return;

    // free the space allocated for the planets
    free(arr->elems);
    arr->elems = NULL;

    // free the space allocated for the dynamic array
    free(arr);
    arr = NULL;
}

int resize_bigger(DynamicArray* arr)
{
    if(arr == NULL)
        return -1;

    arr->capacity = arr->capacity * 2;
    TElement* new_arr = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));

    if(new_arr == NULL)
        return -1;

    arr->elems = new_arr;
    return 0;

}

int resize_smaller(DynamicArray* arr)
{
    if(arr == NULL)
        return -1;

    arr->capacity = arr->capacity / 2;

    TElement* new_arr = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));

    if(new_arr == NULL)
        return -1;

    arr->elems = new_arr;
    return 0;
}

void add(DynamicArray* arr, TElement el)
{
    if(arr == NULL)
        return;
    if(arr->elems==NULL)
        return;

    // checking if we need to resize_bigger the array
    if(arr->length == arr->capacity)
        resize_bigger(arr);
    arr->elems[arr->length] = el;
    arr->length++;
}

void update(DynamicArray* arr, int position, TElement el)
{
    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;
    if (position<0 || position > arr->length)
        return;
    arr->elems[position] = el;
}

void delete(DynamicArray* arr, int position)
{
    if(arr == NULL)
        return;
    if(arr->elems == NULL)
        return;
    if(position < 0 || position > arr->length)
        return;
    for(int i=position; i<arr->length; i++)
        arr->elems[i] = arr->elems[i+1];
    arr->length -= 1;

    if(arr->length < arr->capacity / 2)
        resize_smaller(arr);

}

int len(DynamicArray* arr)
{
    if (arr == NULL)
        return -1;

    return arr->length;
}

TElement find_elem_on_pos(DynamicArray* arr, int pos)
{

    return arr->elems[pos];
}


