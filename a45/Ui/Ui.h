//
// Created by User on 3/18/2021.
//

#include <string>
#include "../service/Service.h"
#include "../Domain/TrenchCoat.h"

#ifndef LAB4_UI_H
#define LAB4_UI_H

#endif //LAB4_UI_H

#pragma once

using namespace std;
class UI
{
private:
    Service* Controller;

    // Display menus
    void DisplayModeAHelp();


    // Below are some helpful functions for numbers represented as strings
    bool StringIsFloat(string AnyString);

    bool StringIsInt(string AnyString);
    int StringToInt(string AnyString);

    // Turn parameters to their right type
    // And then execute the command
    void AddCommandPreparation(string NewId, string NewSize,string NewColour, string NewPrice, string NewQuantity, string NewPhotograph);

    // Turn parameters to their right type
    // And then execute the command
    void UpdateCommandPreparation(string OldTrenchCoatId, string NewSize, string NewColour, string NewPrice, string NewQuantity, string NewPhotograph);

    // Generate a string representation of an organic fragment
    string StringifyTrenchCoat(TrenchCoat* SomeTrenchCoat);
    void DisplayList(DynamicArray<TrenchCoat>* SomeArrayTrenchCoats);
    void SeeCart(DynamicArray<TrenchCoat>* SomeArrayTrenchCoats);
    void ListBySizeCommandPreparation(string Size);
    void LargeDisplay(TrenchCoat* SomeTrenchCoat);
    void ListAllCommand();
    void NextCommand();
    void SaveCommand(string Id);


public:
    UI();

    // Handling the Mode selection menu
    void Start();
};