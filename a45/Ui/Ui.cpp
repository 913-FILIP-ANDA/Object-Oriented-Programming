//
// Created by User on 3/18/2021.
//

#include "Ui.h"
#include "../AppException.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define FOREVER 1

UI::UI()
{
    Controller = new Service;
}

//void UI:: Inputs()


// Display menus

void UI::DisplayModeAHelp()
{
    cout << "\n";
    cout << "-- Help Menu --" << "\n";
    cout << "add [Id], [Size], [Colour],[Price], [Quantity], [Photograph]" << "\n";
    cout << "delete [Id]" << "\n";
    cout << "update [Id], [New Size], [New Colour], [New Price], [New Quantity], [New Photograph]" << "\n";
    cout << "list" << "\n";
    cout << "exit" << "\n";
    cout << "\n";
}

// Below are some helpful functions for numbers represented as strings
bool UI::StringIsFloat(string AnyString)
{
    int DotCount = 0;
    for (int i = 0; i < AnyString.length(); i++)
        if (AnyString[i] == '.')
            DotCount++;
        else if (AnyString[i] < '0' || AnyString[i] > '9')
            return false;
    if (DotCount <= 1)
        return true;
    else return false;
}



bool UI::StringIsInt(string AnyString)
{
    for (int i = 0; i < AnyString.length(); i++)
        if (AnyString[i] < '0' || AnyString[i] > '9')
            return false;
    return true;
}

int UI::StringToInt(string AnyString)
{
    if (StringIsInt(AnyString) == false)
        throw AppException("Invalid parameter!");
    int Number = 0;
    for (int i = 0; i < AnyString.length(); i++)
        Number = Number * 10 + AnyString[i] - '0';
    return Number;
}

// Turn parameters to their right type
// And then execute the command
void UI::AddCommandPreparation(string NewId, string NewSize, string NewColour, string NewPrice, string NewQuantity, string NewPhotograph)
{
    // Validations...
    if (StringIsInt(NewPrice) == false || StringIsInt(NewQuantity) == false)
        throw AppException("Invalid parameter!");
    int NewPriceAsInt = StringToInt(NewPrice);
    int NewQuantityAsInt = StringToInt(NewQuantity);
    Controller->AddCommand(NewId, NewSize,NewColour,  NewPriceAsInt, NewQuantityAsInt,  NewPhotograph);
}

// Turn parameters to their right type
// And then execute the command
void UI::UpdateCommandPreparation(string OldId, string NewSize, string NewColour, string NewPrice, string NewQuantity, string NewPhotograph)
{
    // Validations...
    if (StringIsInt(NewPrice) == false || StringIsInt(NewQuantity) == false)
        throw AppException("Invalid parameter!");
    int NewPriceAsInt = StringToInt(NewPrice);
    int NewQuantityAsInt = StringToInt(NewQuantity);
    Controller->UpdateCommand( OldId, NewSize,NewColour,  NewPriceAsInt, NewQuantityAsInt,  NewPhotograph);}

// Generate a string representation of an organic fragment
string UI::StringifyTrenchCoat(TrenchCoat* SomeTrenchCoat)
{
    stringstream StringStream;
    StringStream << "Id: " << SomeTrenchCoat->GetId() << " | Size: " << SomeTrenchCoat->GetSize() << " | Colour: " << SomeTrenchCoat->GetColour() << " | Price: " << SomeTrenchCoat->GetPrice();
    StringStream << " | Quantity: " << SomeTrenchCoat->GetQuantity() << " | Photograph: " << SomeTrenchCoat->GetPhotograph();
    return StringStream.str();
}


void UI::ListBySizeCommandPreparation(string Size)
{
    TrenchCoat* FirstTrenchCoat = Controller->ListBySizeCommand(Size);
    if (FirstTrenchCoat == NULL)
        throw AppException("There are no organic fragments with that size!");
    LargeDisplay(FirstTrenchCoat);
}

void UI::ListAllCommand()
{
    TrenchCoat* FirstTrenchCoat = Controller->ListAllCommand();
    if (FirstTrenchCoat == NULL)
        throw AppException("There are no organic fragments with that size!");
    LargeDisplay(FirstTrenchCoat);
}

void UI::NextCommand()
{
    TrenchCoat* FirstTrenchCoat= Controller->NextCommand();
    if (FirstTrenchCoat == NULL)
        throw AppException("There are no organic fragments with that size!");
    LargeDisplay(FirstTrenchCoat);
}

void UI::SaveCommand(string Id)
{
    Controller->Save(Id);
}

void UI::LargeDisplay(TrenchCoat* SomeTrenchCoat)
{
    stringstream StringStream;
    StringStream << " Id: " << SomeTrenchCoat->GetId() << " \n Size: " << SomeTrenchCoat->GetSize() << " \n Colour: " << SomeTrenchCoat->GetColour() << "\n Price: "<< SomeTrenchCoat->GetPrice();
    StringStream << " \n Quantity: " << SomeTrenchCoat->GetQuantity() << " \n Photograph: " << SomeTrenchCoat->GetPhotograph() << "\n";
    cout << StringStream.str();
}

void UI::DisplayList(DynamicArray<TrenchCoat>* SomeArrayOfTrenchCoats)
{
    int Count = SomeArrayOfTrenchCoats->GetCount();
    for (int i = 0; i < Count; i++)
        cout << StringifyTrenchCoat((*SomeArrayOfTrenchCoats)[i]) << "\n";
    delete SomeArrayOfTrenchCoats;
}


void UI::SeeCart(DynamicArray<TrenchCoat>* SomeArrayOfTrenchCoats) {
    //DV::DynamicVector<TrenchCoat::Coat> coat_list = this->serv.get_cart();
    int Count = SomeArrayOfTrenchCoats->GetCount();
    for(int pos=0; pos<Count; pos++)
        cout << StringifyTrenchCoat((*SomeArrayOfTrenchCoats)[pos]) << "\n";
    cout<<"\nTotal cart: ";
    cout<<this->Controller->GetTotalPrice()<<" RON"<<endl;
    cout<<"Finish command?(Yes/No)";
    string option;
    cin>>option;
    while(option != "Yes" && option != "No") {
        cout << "Invalid input. Try again: ";
        cin >> option;
    }
    if(option == "Yes"){
        cout<<"Thanks for buying from us! Enjoy your new coat!";
        this->Controller->SaleCart();
        return;
    }
    else
        return;

}


void UI::Start() {
    Controller->Inputs();
    char InputString[1000];
    int Mode = -1;
    string Command;
    while (FOREVER) {
        try {
            cout << "> ";
            cin.getline(InputString, 995);
            stringstream Input;
            Input << InputString;
            Input >> Command;
            if (Command == "exit") {
                break;
            } else if (Command == "mode") {
                string InputMode;
                Input >> InputMode;
                if (InputMode == "")
                    throw AppException("Not enough parameters.");
                if (InputMode == "a" || InputMode == "A")
                    Mode = 1;
                else if (InputMode == "b" || InputMode == "B") {
                    //ListAllCommand();
                    Mode = 2;
                } else cout << "Cannot switch to that mode!" << "\n";
            } else if (Mode == 1) {
                if (Command == "help") {
                    DisplayModeAHelp();
                } else if (Command == "add") {
                    string Id, Size, Colour, Price, Quantity, Photograph;
                    Input>> Id >> Size >>Colour >> Price >> Quantity >> Photograph;
                    if (Id == "" || Size == "" || Colour == "" || Price == "" ||  Quantity == "" || Photograph == "")
                        throw AppException("Not enough parameters.");
                    if (Id.back() == ',')
                        Id.pop_back();
                    if (Size.back() == ',')
                        Size.pop_back();
                    if (Colour.back() == ',')
                        Colour.pop_back();
                    if (Price.back() == ',')
                        Price.pop_back();
                    if (Quantity.back() == ',')
                        Quantity.pop_back();
                    if (Photograph.back() == ',')
                        Photograph.pop_back();
                    AddCommandPreparation(Id, Size, Colour,Price, Quantity, Photograph);
                } else if (Command == "delete") {
                    string Id;
                    Input >> Id;
                    if (Id == "")
                        throw AppException("Not enough parameters.");
                    Controller->DeleteCommand(Id);
                } else if (Command == "update") {
                    string Id, Size, Colour, Price, Quantity, Photograph;
                    Input >> Id >> Size >> Colour>>Price >> Quantity >> Photograph;
                    if (Id == "" || Size == "" || Colour == "" || Price == "" ||  Quantity == "" || Photograph == "")
                        throw AppException("Not enough parameters.");
                    if (Id.back() == ',')
                        Id.pop_back();
                    if (Size.back() == ',')
                        Size.pop_back();
                    if (Colour.back() == ',')
                        Colour.pop_back();
                    if (Price.back() == ',')
                        Price.pop_back();
                    if (Quantity.back() == ',')
                        Quantity.pop_back();
                    if (Photograph.back() == ',')
                        Photograph.pop_back();
                    UpdateCommandPreparation(Id, Size, Colour, Price, Quantity, Photograph);
                } else if (Command == "list") {
                    DisplayList(Controller->ListCommand());
                } else {
                    cout << "Command not found!" << "\n";
                }
            } else if (Mode == 2){


                if (Command == "list") {
                    char P = Input.peek();
                    if (P == -1) {
                        ListAllCommand();
                    } else {
                        string Size;
                        Input >> Size;
                        //if (Size == "")
                            //throw AppException("Not enough parameters.");
                        //P = Input.peek();
                        //if (Size.back() == ','){
                            //Size.pop_back();
                            ListBySizeCommandPreparation(Size);
                        }
                    }
                 else if (Command == "next") {
                    NextCommand();
                } else if (Command == "mylist") {
                    DisplayList(Controller->MyListCommand());
                } else if (Command == "save") {
                    string Id;
                    Input >> Id;
                    if (Id == "")
                        throw AppException("Not enough parameters.");
                    SaveCommand(Id);
                    //NextCommand();
                    cout<< this->Controller->GetTotalPrice()<< "RON" <<endl;
                }else if(Command=="finish"){
                    SeeCart(Controller->MyListCommand());
                }
                else {
                    //cin.ignore(1000, '\n');
                    cout << "Command not found!" << "\n";
                }

            }
            else {
                cout << "Command not found!" << "\n";
            }
        }
        catch (AppException &error) {
            cout << error.what() << "\n";
        }
    }
    delete Controller;
}