//
// Created by User on 3/18/2021.
//

#include "../Vector/DynamicArray.h"
#include "../Domain/TrenchCoat.h"
#include <functional>
#ifndef LAB4_REPO_H
#define LAB4_REPO_H

#endif //LAB4_REPO_H
#pragma once

class TrenchCoatRepository
{
private:
    DynamicArray<TrenchCoat>* RepositoryStorage;
    DynamicArray<TrenchCoat>* UserStorage;
    int current_position = 0;
    int TotalPrice = 0;
    //DynamicArray<TrenchCoat>* UserStorage;
public:
    // Constructor
    TrenchCoatRepository();

    // Destructor
    ~TrenchCoatRepository();

    // Setters
    void AddCoat(TrenchCoat* SomeTrenchCoat);
    void DeleteCoat( string TrenchCoatId);
    void UpdateCoat(string TrenchCoatId, TrenchCoat* NewTrenchCoat);
    void SaveToUser(string Id);
    void SaleCart();

    // Getters
    int GetTotalPrice();
    TrenchCoat* Search(string TrenchCoatId);
    TrenchCoat* SearchUser(string TrenchCoatId);
    DynamicArray<TrenchCoat>* Filter(function<bool(TrenchCoat*)> = [](TrenchCoat*) {return true; }); // Initial declaration using a lambda function
    DynamicArray<TrenchCoat>* GetUserList();


};