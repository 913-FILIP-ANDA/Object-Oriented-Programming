//
// Created by User on 3/18/2021.
//

//#include "../Domain/TrenchCoat.h"

#include "TrenchCoat.h"

// Create a trench coat
TrenchCoat::TrenchCoat(std::string NewId, std::string NewSize, std::string NewColour ,int NewPrice, int NewQuantity, std::string NewPhotograph)
{

    this ->Id = NewId;
    this->Size =NewSize;
    this ->Colour = NewColour;
    this ->Price = NewPrice;
    this ->Quantity = NewQuantity;
    this ->Photograph =NewPhotograph;
}
// Constructor to create a copy from an existing trench coat
TrenchCoat::TrenchCoat(TrenchCoat* SomeTrenchCoat)
{
    this ->Id = SomeTrenchCoat-> GetId();
    this->Size =SomeTrenchCoat->GetSize();
    this ->Colour =SomeTrenchCoat->GetColour();
    this ->Price = SomeTrenchCoat->GetPrice();
    this ->Quantity = SomeTrenchCoat->GetQuantity();
    this ->Photograph =SomeTrenchCoat->GetPhotograph();
}
// Getters
string TrenchCoat::GetId()
{
    return this->Id;
}
string TrenchCoat::GetSize()
{
    return this-> Size;
}
string TrenchCoat::GetColour()
{
    return this->Colour;
}
int TrenchCoat::GetPrice() const
{
    return this-> Price;
}
int TrenchCoat::GetQuantity() const
{
    return this-> Quantity;
}
string TrenchCoat::GetPhotograph()
{
    return this->Photograph;
}

// Setters
void TrenchCoat::SetSize(string NewSize)
{
    this-> Size = string(NewSize);
}
void TrenchCoat::SetColour(string NewColour)
{
    this->Colour = string(NewColour);
}
void TrenchCoat::SetPrice(int NewPrice)
{
    this->Price = NewPrice;
}
void TrenchCoat::SetQuantity(int NewQuantity)
{
    this->Quantity = NewQuantity;
}
void TrenchCoat::SetPhotograph(string NewPhotograph)
{
    this->Photograph = string(NewPhotograph);
}