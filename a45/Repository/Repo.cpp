//
// Created by User on 3/18/2021.
//


#include "../Repository/Repo.h"
#include "../Domain/TrenchCoat.h"


using namespace std;
#define FIRST_INDEX 0

TrenchCoatRepository::TrenchCoatRepository()
{
    this ->RepositoryStorage = new DynamicArray<TrenchCoat>;
    this ->UserStorage = new DynamicArray<TrenchCoat>;
}

TrenchCoatRepository::~TrenchCoatRepository()
{
    delete this ->RepositoryStorage;
    while (UserStorage->GetCount())
        UserStorage->Pop();
    delete UserStorage;
}

void TrenchCoatRepository::AddCoat(TrenchCoat* SomeTrenchCoat)
{
    this ->RepositoryStorage->Push(SomeTrenchCoat);
    this->TotalPrice += SomeTrenchCoat->GetPrice();

}

void TrenchCoatRepository::DeleteCoat(string TrenchCoatId)
{   int UserCount;
    UserCount = UserStorage->GetCount();
    for (int i = FIRST_INDEX; i < UserCount; i++)
        if ((*UserStorage)[i]->GetId() == TrenchCoatId)
        {
            for (int j = i; j < UserCount - 1; j++)
                (*UserStorage)[j] = (*UserStorage)[j + 1];
            (*UserStorage)[UserCount - 1] = NULL;
            break;
        }
    if (UserCount > 0)
        UserStorage->Pop();
    int Count = this ->RepositoryStorage->GetCount();
    for(int i = FIRST_INDEX; i< Count;i++)
        if ((*this ->RepositoryStorage)[i]->GetId() == TrenchCoatId)
        {
            delete (*this ->RepositoryStorage)[i];
            this ->TotalPrice -= (*this->RepositoryStorage)[i]->GetPrice();
            for (int j = i; j < Count - 1; j++)
                (*this ->RepositoryStorage)[j] = (*this ->RepositoryStorage)[j + 1];
            (*this ->RepositoryStorage)[Count - 1] = NULL;
            break;
        }
    this ->RepositoryStorage->Pop();

}

void TrenchCoatRepository::UpdateCoat(string TrenchCoatId, TrenchCoat* NewTrenchCoat)
{
    int Count = RepositoryStorage->GetCount();
    int UserCount = UserStorage->GetCount();
    for (int i = FIRST_INDEX; i < UserCount; i++)
        if ((*UserStorage)[i]->GetId() == TrenchCoatId)
            (*UserStorage)[i] = NewTrenchCoat;
    for (int i = FIRST_INDEX; i < Count; i++)
        if ((*RepositoryStorage)[i]->GetId() == TrenchCoatId)
        {
            delete (*RepositoryStorage)[i];
            (*RepositoryStorage)[i] = NewTrenchCoat;
        }
}
/*
void TrenchCoatRepository::Next() {
    if (this->RepositoryStorage->GetCount() == this->current_position + 1)
        this->current_position = 0;
    else
        this->current_position++;

    if (this->RepositoryStorage->GetCount() == 0)
        this->current_position = 0;
}

int TrenchCoatRepository::Get_total_price(){
    return this->TotalPrice;
}
*/
TrenchCoat* TrenchCoatRepository::Search(string TrenchCoatId)
{
    int Count = RepositoryStorage->GetCount();
    for (int i = FIRST_INDEX; i < Count; i++)
        if ((*RepositoryStorage)[i]->GetId() == TrenchCoatId)
            return (*RepositoryStorage)[i];
    return NULL;
}

TrenchCoat* TrenchCoatRepository::SearchUser(string TrenchCoatId)
{
    int Count = UserStorage->GetCount();
    for (int i = FIRST_INDEX; i < Count; i++)
        if ((*UserStorage)[i]->GetId() == TrenchCoatId)
            return (*UserStorage)[i];
    return NULL;
}


DynamicArray<TrenchCoat>* TrenchCoatRepository::Filter(function<bool(TrenchCoat*)>FilterFunction)
{
    int Count = RepositoryStorage->GetCount();
    DynamicArray<TrenchCoat>* FilteredList = new DynamicArray<TrenchCoat>;
    for (int i = FIRST_INDEX; i < Count; i++)
        if (FilterFunction((*RepositoryStorage)[i]) == true)
            FilteredList->Push(new TrenchCoat((*RepositoryStorage)[i]));
    return FilteredList;
}


DynamicArray<TrenchCoat>* TrenchCoatRepository::GetUserList()
{
    int Count = UserStorage->GetCount();
    DynamicArray<TrenchCoat>* FilteredList = new DynamicArray<TrenchCoat>;
    for (int i = FIRST_INDEX; i < Count; i++)
        FilteredList->Push(new TrenchCoat((*UserStorage)[i]));
    return FilteredList;
}

void TrenchCoatRepository::SaleCart(){
    int Count = UserStorage->GetCount();
    for (int i = FIRST_INDEX; i < Count; i++){
        int quantity=(*UserStorage)[i]->GetQuantity();
        if(quantity == 1)
            this->DeleteCoat((*UserStorage)[i]->GetId());
        else{
            (*UserStorage)[i]->SetQuantity(quantity-1);
            this->UpdateCoat((*UserStorage)[i]->GetId(),(*UserStorage)[i]);
        }
    }
}

int TrenchCoatRepository::GetTotalPrice()
{
    return this->TotalPrice;
}

void TrenchCoatRepository::SaveToUser(string Id)
{
    UserStorage->Push(Search(Id));
}

