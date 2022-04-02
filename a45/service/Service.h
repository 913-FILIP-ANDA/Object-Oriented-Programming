//
// Created by User on 3/18/2021.
//

#include "../Repository/Repo.h"
#include "../Vector/DynamicArrayIterator.h"
#ifndef LAB4_SERVICE_H
#define LAB4_SERVICE_H

#endif //LAB4_SERVICE_H

#pragma once

class Service
{
private:
    TrenchCoatRepository* TrenchCoatCollection;
    DynamicArrayIterator<TrenchCoat>* ActiveIterator;
public:
    Service();
    ~Service();

    // The commands
    void AddCommand(const string&, string,string, int, int, string);
    void DeleteCommand(string);
    void UpdateCommand(string, string,string ,int, int, string);
    DynamicArray<TrenchCoat>* ListCommand();
    TrenchCoat* ListBySizeCommand(string Size);
    TrenchCoat* ListAllCommand();
    TrenchCoat* NextCommand();
    void Save(string ExistingTrenchCoatId);
    DynamicArray<TrenchCoat>* MyListCommand();
    void SaleCart();


    int GetTotalPrice();
    void Inputs();
};