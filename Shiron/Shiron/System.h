#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Item.h"

class Buyer; 
class Seller;

class System
{
public:
	static const int MAX_LEN_SYSTEM_NAME = 20;

private:
	char* m_systemName;
	Buyer** m_allByers;
	Seller** m_allSellers;

	//an array of items for each category
	Item** m_KidsItems;
	Item** m_ElectrinicsItems;
	Item** m_OfficeItems;
	Item** m_ClothingItems;

	//The old use of the array
	int m_CurrentByers; //the number of buyers and buyers that sign in
	int m_CurrentSellers; //the number of sellers and buyers that sign in
	int m_maxBuyres; //the maximum number of buyers in the system
	int m_maxSellers; //the maximum number of sellers in the system

public:
	bool setSystemName(const char* systemName);
	//System(const System& other); //copy c'tor
	//bool setAllBuyers(const Buyer** allByres);
	//bool setAllsellers(const Seller** allSellers);

	const char* getSystemName();
	Buyer** getAllBuyers(); //const?
	Seller** getAllSellers(); //const?

	System(int maxBuyres, int maxSellers);
	System(System&& other); //move c'tor
	//~System(); //d'tor

	//bool addBuyerToSystem(Buyer& buyer);
	//bool addSellerToSystem(Seller& seller);
	//void showAllBuyers() const;
	//void showAllSellers() const;
};

#endif //__SYSTEM_H