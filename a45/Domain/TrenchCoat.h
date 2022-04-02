#pragma once
#include <string>
using namespace std;

class TrenchCoat
{
private:
    string Id;
    string Size;
    string Colour;
    int Price;
    int Quantity;
    string Photograph;
public:
    // Create an TrenchCoat
    TrenchCoat(string NewId, string NewSize, string NewColour, int NewPrice, int NewQuantity, string NewPhotograph);

    // Constructor to create a copy from an existing TrenchCoat
    TrenchCoat(TrenchCoat* SomeTrenchCoat);

    // Getters
    string GetId() ;
    string GetSize();
    string GetColour();
    int GetPrice() const;
    int GetQuantity() const;
    string GetPhotograph();

    // Setters
    void SetSize(string NewSize);
    void SetColour(string NewColour);
    void SetPrice(int NewPrice);
    void SetQuantity(int NewQuantity);
    void SetPhotograph(string NewPhotograph);

};