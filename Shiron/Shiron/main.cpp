#include "user.h"
#include "system.h"
#include "Item.h"
#include "Address.h"
#include "Feedback.h"
#include "Date.h"
#include "Buyer.h"
#include "Order.h"

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
void menu();

int main()
{
    menu();
}

void menu()
{
    bool exit=false;
    int option=0;
    int year, month, day;
    while(!exit)
    {
        cout << "Welcome to Shiron! The world advanced shopping platfrom online\n"
		<< "Choose your option:\n";
        cout << "(1) Add a buyer\n";
        cout << "(2) Add a seller\n";
        cout << "(3) Add an item to a seller\n";
        cout << "(4) Add a feedback to a seller\n";
        cout << "(5) Add an item to basket of a buyer\n";
        cout << "(6) Make an order for a buyer\n";
        cout << "(7) Pay for an order of a buyer\n";
        cout << "(8) Show details of all buyers\n";
        cout << "(9) Show details of all sellers\n";
        cout << "(10) Show details of all the products of a certain name\n";
        cout << "(11) Exit\n";
        cin >> option;
        switch(option) {
            case 1 : cout << "Enter the details of the buyer\n";
                     cout << "Name:\n";
                     cout << "Password:\n";
                     cout << "Address:\n";
                     break;
            case 2 : cout << "Enter the details of the seller\n";
                     cout << "name:\n";
                     cout << "Password:\n";
                     cout << "Address:\n";
                     break;
            case 3 :
                     cout << "Enter the seller name\n";
                     cout << "Enter the item name:\n";
                     cout << "Choose the item category:\n";
                     cout << "Enter the item price\n";
                     break;
            case 4 : cout << "Enter your id in the system:\n";
                     cout << "Enter the id of the seller that you want to give a feedback:\n";
                     cout << "Enter the feedback:\n";
                     cout << "Enter the year:\n";
                     cin >> year;
                     cout << "Enter the month:\n";
                     cin >> month;
                     cout << "Enter the day:\n";
                     cin >> day;
                Feedback("seller", "responder", "The product is great", year, month, day);
                     break;
            case 5 : cout << '5';
                     break;
            case 6 : cout << '6';
                     break;
            case 7 : cout << '7';
                     break;
            case 8 : cout << '8';
                     break;
            case 9 : cout << '9';
                     break;
            case 10 : cout << '10';
                     break;
            case 11 : cout << '11';
                     exit=true;
                     break;
        }
    }
}
