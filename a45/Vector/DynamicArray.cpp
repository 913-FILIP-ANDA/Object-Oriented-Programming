/*
#include "DynamicArray.h"
#include "AppException.h"

#define INITIAL_CAPACITY 50
#define EMPTY_LIST_COUNT 0
#define FIRST_INDEX 0

// Constructor
template <typename StorageElement>
DynamicArray<StorageElement>::DynamicArray()
{
	Capacity = INITIAL_CAPACITY;
	Count = EMPTY_LIST_COUNT;
	Storage = new StorageElement*[Capacity];
}

// Destructor
template <typename StorageElement>
DynamicArray<StorageElement>::~DynamicArray()
{
	for (int i = FIRST_INDEX; i < Count; i++)
		delete Storage[i];
	delete Storage;
}

// Add an element at the end of the list
template <typename StorageElement>
void DynamicArray<StorageElement>::Push(StorageElement* SomeElement)
{
	Storage[Count++] = SomeElement;
	if (Count == Capacity)
		Grow();
}

// Pop the element from the end of the list (return and remove)
template <typename StorageElement>
StorageElement* DynamicArray<StorageElement>::Pop()
{
	StorageElement* PoppedElement = Storage[Count - 1];
	Storage[--Count] = NULL;
	if (Count == Capacity / 2)
		Shrink();
	return PoppedElement;
}

// Accessing the Storage
template <typename StorageElement>
StorageElement*& DynamicArray<StorageElement>::operator[](int Index)
{
	if (Index < FIRST_INDEX || Index >= Count)
		throw AppException("Index out of bounds!");
	return Storage[Index];
}

// Count getter
template <typename StorageElement>
int DynamicArray<StorageElement>::GetCount()
{
	return Count;
}

// Dynamic Array storage management functions
template <typename StorageElement>
void DynamicArray<StorageElement>::Grow()
{
	Capacity *= 2;
	StorageElement** NewStorage = new StorageElement* [Capacity];
	for (int i = FIRST_INDEX; i < Count; i++)
		NewStorage[i] = Storage[i];
	delete Storage;
	Storage = NewStorage;
}

template <typename StorageElement>
void DynamicArray<StorageElement>::Shrink()
{
	if (Count > Capacity / 2)
		throw AppException("Cannot shrink array! Too many elements");
	Capacity /= 2;
	StorageElement** NewStorage = new StorageElement * [Capacity];
	for (int i = FIRST_INDEX; i < Count; i++)
		NewStorage[i] = Storage[i];
	delete Storage;
	Storage = NewStorage;
}*/