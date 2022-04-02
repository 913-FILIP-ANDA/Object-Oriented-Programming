
#ifndef OOP_REPO_H
#define OOP_REPO_H

#endif //OOP_REPO_H

#pragma once

#include "../domain/Estate.h"

typedef Estate TElement;

typedef struct {
    TElement* elems;
    int length;
    int capacity;
}DynamicArray;


/**
 * Function that creates a dynamic array with a given capacity.
 * @param capacity : integer
 * @return dynamic array
 */
DynamicArray* createArray(int capacity);


/**
 * Function that creates a copy to the dynamic array.
 * @param darr: dynamic array
 */
DynamicArray * create_copy(DynamicArray* darr);


/**
 * Function that deletes from memory a dynamic array.
 */
void destroy(DynamicArray* ar);


/**
 * Function used when adding an element to the array, in case there is no space left in the reserved memory.
 */
int resize_bigger(DynamicArray* arr);


/**
 * Function that adds an element in the dynamic array, saving it at the appropriate position in memory.
 * @param ar : dynamic array
 * @param el : of generic type TElement
 */
void add(DynamicArray* ar, TElement el);


/**
 * Function that changes an element on a given position with a new one.
 * @param position : integer
 * @param el : of generic type TElement
 */
void update(DynamicArray* ar, int position, TElement el);


/**
 * Function that deletes an element from the array, aka removes it from memory.
 * @param position: integer
 */

void delete(DynamicArray* ar, int position);


/**
 * Function that returnes the length of the dynamic array(the number of elements it curently has)
 * @return length: positive integer
 */
int len(DynamicArray* ar);


/**
 * Function that returns the element on a given position
 */
TElement find_elem_on_pos(DynamicArray* arr, int position);





