//
// Created by User on 3/18/2021.
//



#include "../service/Service.h"
#include "../Repository/Repo.h"
#include "../AppException.h"
#include "../Domain/TrenchCoat.h"


Service::Service()
{
    TrenchCoatCollection = new TrenchCoatRepository;
    ActiveIterator = NULL;
}

Service::~Service()
{
    delete TrenchCoatCollection;
    if (ActiveIterator != NULL)
        delete ActiveIterator;
}

void Service::AddCommand(const string& NewId, string NewSize,string NewColour, int NewPrice, int NewQuantity, string NewPhotograph)
{
    // Basic Validation
    if (TrenchCoatCollection->Search(NewId) != NULL)
        throw AppException("There already exists an trench coat with that Id.");
    TrenchCoat* NewTrenchCoat = new TrenchCoat(NewId, NewSize,NewColour,NewPrice, NewQuantity, NewPhotograph);
    TrenchCoatCollection->AddCoat(NewTrenchCoat);
}

void Service::DeleteCommand(string ExistingTrenchCoatId)
{
    if (TrenchCoatCollection->Search(ExistingTrenchCoatId) == NULL)
        throw AppException("There doesn't exists an trench coat with that Id.");
    TrenchCoatCollection->DeleteCoat(ExistingTrenchCoatId);
}

void Service::UpdateCommand(string OldTrenchCoatId, string NewSize,string NewColour,int NewPrice,int NewQuantity, string NewPhotograph)
{
    // Basic Validation
    if (TrenchCoatCollection->Search(OldTrenchCoatId) == NULL)
        throw AppException("There doesn't exists an trench coat with that Id.");
    TrenchCoat* NewTrenchCoat = new TrenchCoat(OldTrenchCoatId, NewSize, NewColour,NewPrice, NewQuantity, NewPhotograph);
    TrenchCoatCollection->UpdateCoat(OldTrenchCoatId, NewTrenchCoat);
}

DynamicArray<TrenchCoat>* Service::ListCommand()
{
    return TrenchCoatCollection->Filter();
}




TrenchCoat* Service::ListBySizeCommand(string Size)
{
    DynamicArray<TrenchCoat>* FilteredList = TrenchCoatCollection->Filter([&Size](TrenchCoat* SomeTrenchCoat) // using a lambda function as a parameter
            {
        if (SomeTrenchCoat->GetSize() == Size)
            return true;
        return false;
            });
    if (ActiveIterator != NULL)
        delete ActiveIterator;
    ActiveIterator = new DynamicArrayIterator<TrenchCoat>(FilteredList);
    return ActiveIterator->GetCurrentElement();
}

TrenchCoat* Service::ListAllCommand()
{
    DynamicArray<TrenchCoat>* FilteredList = TrenchCoatCollection->Filter();
    if (ActiveIterator != NULL)
        delete ActiveIterator;
    ActiveIterator = new DynamicArrayIterator<TrenchCoat>(FilteredList);
    return ActiveIterator->GetCurrentElement();
}

TrenchCoat* Service::NextCommand()
{
    ActiveIterator->Next();
    return ActiveIterator->GetCurrentElement();
}

void Service::Save(string ExistingTrenchCoatId)
{
    if (TrenchCoatCollection->Search(ExistingTrenchCoatId) == NULL)
        throw AppException("There doesn't exist an organic fragment with that Id.");
    if (TrenchCoatCollection->SearchUser(ExistingTrenchCoatId) != NULL)
        throw AppException("The user already has that organic fragment.");
    TrenchCoatCollection->SaveToUser(ExistingTrenchCoatId);
}

DynamicArray<TrenchCoat>* Service::MyListCommand()
{
    return TrenchCoatCollection->GetUserList();
}

int Service::GetTotalPrice()
{
    return TrenchCoatCollection->GetTotalPrice();
}

void Service::SaleCart(){
    return TrenchCoatCollection->SaleCart();
}
void Service ::Inputs()
{
    TrenchCoat* el1 = new TrenchCoat("1", "M","black",122, 1, "httpdedwc");
    TrenchCoatCollection->AddCoat(el1);
    TrenchCoat* el2 = new TrenchCoat("2", "L","black",100, 2, "httpdedwc");
    TrenchCoatCollection->AddCoat(el2);
    TrenchCoat* el3 = new TrenchCoat("3", "M","black",122, 1, "htgtttpdedwc");
    TrenchCoatCollection->AddCoat(el3);
    TrenchCoat* el4 = new TrenchCoat("4", "XL","red",10, 1, "httpdedwc");
    TrenchCoatCollection->AddCoat(el4);
    TrenchCoat* el5 = new TrenchCoat("5", "M","black",12, 1, "httpdedwc");
    TrenchCoatCollection->AddCoat(el5);
    TrenchCoat* el6 = new TrenchCoat("6", "S","black",50, 1, "httpdedwc");
    TrenchCoatCollection->AddCoat(el6);
    TrenchCoat* el7 = new TrenchCoat("7", "XS","white",162, 1, "httpdedwc");
    TrenchCoatCollection->AddCoat(el7);
    TrenchCoat* el8 = new TrenchCoat("8", "M","pink",352, 1, "httpdedwc");
    TrenchCoatCollection->AddCoat(el8);
    TrenchCoat* el9 = new TrenchCoat("9", "M","black",122, 1, "httpdedwc");
    TrenchCoatCollection->AddCoat(el9);
    TrenchCoat* el10 = new TrenchCoat("10", "M","black",122, 1, "httpdedwc");
    TrenchCoatCollection->AddCoat(el10);

}