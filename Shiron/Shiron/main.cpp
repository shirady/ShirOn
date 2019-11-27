#include "Address.h"
#include "user.h"
#include "Buyer.h"
#include "system.h"

//#include "Item.h"
//#include "Feedback.h"
//#include "Date.h"
//#include "Order.h"

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
//void menu();

int main()
{
    //menu();
	//cout << "Enter the details of the user\n"
	//	<< "User name: "
	//	<< "Password: "
	//	<< "Address (country, city, street, buildNo, appartmentNo, zipCode)" ;

	//char country [Address::MAX_LEN_COUNTRY]= "Israel";
	//char city[Address::MAX_LEN_CITY] = "Tel Aviv";
	//char street[Address::MAX_LEN_STREET] = "Hashlom";
	//char zipCode[Address::MAX_LEN_ZIP_CODE] = "76543";
	//char name[User::MAX_LEN_NAME] = "Shira";
	//char password[User::MAX_LEN_PASSWORD] = "1234";

 //   User user(name, password, country, city, street, 10, 2, zipCode);

	//char name[User::MAX_LEN_NAME] = "Shira";
	//bool check = User::CheckWhiteSpace(name);

	//char country[Address::MAX_LEN_COUNTRY] = "$New";
	//bool check = Address::CheckCharacters(country);

	//char city[Address::MAX_LEN_CITY] = "!Tel-Aviv";
	//bool check = Address::CheckCharacters(city);

	//char street[Address::MAX_LEN_STREET] = "T3el-Hai";
	//bool check = Address::CheckCharacters(street);

	//char zipCode[Address::MAX_LEN_ZIP_CODE] = "A744-559";
	//bool check = Address::CheckCharacters(zipCode);


	char country[Address::MAX_LEN_COUNTRY] = "Israel";
	char city[Address::MAX_LEN_CITY] = "Tel-Aviv";
	char street[Address::MAX_LEN_STREET] = "Tel-Hai";
	int buildNo = 2;
	int appartmentNo = 17;
	char zipCode[Address::MAX_LEN_ZIP_CODE] = "A744-559";

	char name[User::MAX_LEN_NAME] = "Shira";
	char password[User::MAX_LEN_PASSWORD] = "1234";

	Address address(country, city, street, buildNo, appartmentNo, zipCode);
	User user(name, password, address);
}

//void menu()
//{
//    bool exit=false;
//    int option=0;
//    int year, month, day;
//    while(!exit)
//    {
//        cout << "Welcome to Shiron! The world advanced shopping platfrom online\n"
//		<< "Choose your option:\n"
//        << "(1) Add a buyer\n"
//        << "(2) Add a seller\n"
//        << "(3) Add an item to a seller\n"
//        << "(4) Add a feedback to a seller\n"
//        << "(5) Add an item to basket of a buyer\n"
//        << "(6) Make an order for a buyer\n"
//        << "(7) Pay for an order of a buyer\n"
//        << "(8) Show details of all buyers\n"
//        << "(9) Show details of all sellers\n"
//        << "(10) Show details of all the products of a certain name\n"
//        << "(11) Exit\n";
//        cin >> option;
//        switch(option) {
//            case 1 : cout << "Enter the details of the buyer\n";
//                     cout << "Name:\n";
//                     cout << "Password:\n";
//                     cout << "Address:\n";
//                     break;
//            case 2 : cout << "Enter the details of the seller\n";
//                     cout << "name:\n";
//                     cout << "Password:\n";
//                     cout << "Address:\n";
//                     break;
//            case 3 :
//                     cout << "Enter the seller name\n";
//                     cout << "Enter the item name:\n";
//                     cout << "Choose the item category:\n";
//                     cout << "Enter the item price\n";
//                     break;
//            case 4 : cout << "Enter your id in the system:\n";
//                     cout << "Enter the id of the seller that you want to give a feedback:\n";
//                     cout << "Enter the feedback:\n";
//                     cout << "Enter the year:\n";
//                     cin >> year;
//                     cout << "Enter the month:\n";
//                     cin >> month;
//                     cout << "Enter the day:\n";
//                     cin >> day;
//                     Feedback("seller", "responder", "The product is great", Date(year,month,day));
//                     break;
//            case 5 : cout << '5';
//                     break;
//            case 6 : cout << '6';
//                     break;
//            case 7 : cout << '7';
//                     break;
//            case 8 : cout << '8';
//                     break;
//            case 9 : cout << '9';
//                     break;
//            case 10 : cout << '10';
//                     break;
//            case 11 : cout << '11';
//                     exit=true;
//                     break;
//        }
//    }
//}
