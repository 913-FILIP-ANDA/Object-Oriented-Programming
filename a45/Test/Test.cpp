//
// Created by User on 3/20/2021.
//

#include "Test.h"


#include "assert.h"
#include "../service/Service.h"
#include "../AppException.h"

// Add
void AddCommand_DuplicateInput_ThrowException()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->AddCommand("id", "a","black", 133, 2, "b");
        Controller->AddCommand("id", "a","black", 133, 2, "b");
        AssertionResult = false;
    }
    catch (AppException)
    {
        AssertionResult = true;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}

void AddCommand_ValidInput_CorrectAddition()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->AddCommand("id", "a","black", 133, 2, "b");
        AssertionResult = (*Controller->ListCommand())[0]->GetId() == "id";
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}

void AddCommand_MassiveValidInput_CorrectResize()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        for (int i = 0; i < 120; i++)
        {
            char a[2] = "a";
            a[0] = i;
            Controller->AddCommand(string(a), "a","black", 133, 2, "b");
        }
        AssertionResult = Controller->ListCommand()->GetCount() == 120;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
}

// Save (Add)
void SaveCommand_ValidInput_CorrectSave()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->AddCommand("id", "a","white", 1, 2, "b");
        Controller->Save("id");
        AssertionResult = (*Controller->MyListCommand())[0]->GetId() == "id";
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}

void SaveCommand_BadInput_ThrowException()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->Save("id");
        AssertionResult = false;
    }
    catch (AppException)
    {
        AssertionResult = true;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}

// Delete
void DeleteCommand_BadInput_ThrowException()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->DeleteCommand("id");
        AssertionResult = false;
    }
    catch (AppException)
    {
        AssertionResult = true;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}

void DeleteCommand_ValidInput_CorrectRemoval()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->AddCommand("id", "a","black", 133, 2, "b");
        Controller->DeleteCommand("id");
        AssertionResult = Controller->ListCommand()->GetCount() == 0;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}

// Update
void UpdateCommand_BadInput_ThrowException()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->UpdateCommand("id1", "b","white", 24, 1, "a");
        AssertionResult = false;
    }
    catch (AppException)
    {
        AssertionResult = true;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}

void DeleteCommand_ValidInput_CorrectRemovalFromSaved()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->AddCommand("id", "a", "black",133, 2, "b");
        Controller->Save("id");
        Controller->DeleteCommand("id");
        AssertionResult = Controller->MyListCommand()->GetCount() == 0;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}


void UpdateCommand_ValidInput_CorrectUpdate()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        Controller->AddCommand("id", "a","black", 133, 2, "b");
        Controller->UpdateCommand("id", "b","white", 133, 2, "c");
        TrenchCoat* Stored = (*Controller->ListCommand())[0];
        AssertionResult = Stored->GetSize() == "b" && Stored->GetColour() == "white"&&Stored->GetPrice()==133 && Stored->GetPhotograph() == "c" && Stored->GetQuantity() == 2;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
    assert(AssertionResult);
}

void FilterCommand_MassiveValidInput_CorrectExecution()
{
    Service* Controller = new Service;
    bool AssertionResult;
    try {
        for (int i = 0; i < 120; i++)
        {
            char a[2] = "a";
            a[0] = i;
            Controller->AddCommand(string(a),"cew" ,"a", 1, 2, "b");
        }
        DynamicArray<TrenchCoat>* StoredList = Controller->ListCommand();
        TrenchCoat* SomeTrenchCoat;
        for (int i = 0; i < 120; i++)
        {
            char a[2] = "a";
            a[0] = i;
            SomeTrenchCoat= (*StoredList)[i];
            if (SomeTrenchCoat->GetId() != a)
                throw "Error";
        }
        AssertionResult = StoredList->GetCount() == 120;
    }
    catch (...)
    {
        AssertionResult = false;
    }
    delete Controller;
}

void RunTests()
{
    AddCommand_ValidInput_CorrectAddition();
    AddCommand_DuplicateInput_ThrowException();
    AddCommand_MassiveValidInput_CorrectResize();
    SaveCommand_BadInput_ThrowException();
    SaveCommand_ValidInput_CorrectSave();
    DeleteCommand_BadInput_ThrowException();
    DeleteCommand_ValidInput_CorrectRemoval();
    DeleteCommand_ValidInput_CorrectRemovalFromSaved();
    UpdateCommand_BadInput_ThrowException();
    UpdateCommand_ValidInput_CorrectUpdate();
    FilterCommand_MassiveValidInput_CorrectExecution();
}
