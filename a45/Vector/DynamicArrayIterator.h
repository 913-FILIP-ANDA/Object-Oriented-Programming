
#pragma once
#include "../AppException.h"
#include "DynamicArray.h"
template <class StorageElement>
class DynamicArrayIterator
{
private:
    DynamicArray<StorageElement>* IteratingArray;
    int Position;
public:
    // Constructor
    DynamicArrayIterator(DynamicArray<StorageElement>* SomeDynamicArray);

    // Move on to the next element of the list, or to the beginning
    void Next();

    // Get the current element
    StorageElement* GetCurrentElement();
};

// Constructor
template <typename StorageElement>
DynamicArrayIterator<StorageElement>::DynamicArrayIterator(DynamicArray<StorageElement>* SomeDynamicArray)
{
    IteratingArray = SomeDynamicArray;
    Position = 0;
}

// Move on to the next element of the list, or to the beginning
template <typename StorageElement>
void DynamicArrayIterator<StorageElement>::Next()
{
    Position++;
    if (Position >= IteratingArray->GetCount())
        Position = 0;
}

// Get the current element
template <typename StorageElement>
StorageElement* DynamicArrayIterator<StorageElement>::GetCurrentElement()
{
    if (IteratingArray->GetCount() == 0)
        return NULL;
    return (*IteratingArray)[Position];
}