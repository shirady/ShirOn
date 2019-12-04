#include "Address.h"
#include "user.h"
#include "Buyer.h"
#include "Interface.h"

//#include "Item.h"
//#include "Feedback.h"
//#include "Date.h"
//#include "Order.h"

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

int main()
{
    //menu();
	//cout << "Enter the details of the user\n"
	//	<< "User name: "
	//	<< "Password: "
	//	<< "Address (country, city, street, buildNo, apartmentNo, zipCode)" ;

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


	/*char country[Address::MAX_LEN_COUNTRY] = "Israel";
	char city[Address::MAX_LEN_CITY] = "Tel-Aviv";
	char street[Address::MAX_LEN_STREET] = "Tel-Hai";
	int buildNo = 2;
	int apartmentNo = 17;
	char zipCode[Address::MAX_LEN_ZIP_CODE] = "A744-559";

	char name[User::MAX_LEN_NAME] = "Shira";
	char password[User::MAX_LEN_PASSWORD] = "1234";

	Address address(country, city, street, buildNo, apartmentNo, zipCode);
	User user(name, password, address);*/

	char systemName[System::MAX_LEN_SYSTEM_NAME] = "Shiron";
	System system(systemName);
	Interface interface(system);
	interface.menu();
}

