#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
//#include "Item.h"
#include "Buyer.h"
//class Seller;

class System
{
public:
	static const int MAX_LEN_SYSTEM_NAME = 20;
	static const unsigned int INITIAL_LOGICAL_SIZE = 0;
	static const unsigned int INITIAL_PHYSICAL_SIZE = 1;

private:
	char* m_systemName;
	Buyer** m_allBuyers;
	//Seller** m_allSellers;

	//an array of items for each category
	//Item** m_KidsItems;
	//Item** m_ElectrinicsItems;
	//Item** m_OfficeItems;
	//Item** m_ClothingItems;

	unsigned int m_logicSizeBuyers; //the number of buyers and buyers that sign in
	unsigned int m_PhysSizeBuyres; //the maximum number of buyers in the system
	//int m_CurrentSellers; //the number of sellers and buyers that sign in
	//int m_maxSellers; //the maximum number of sellers in the system

public:
	bool setSystemName(const char* systemName);
	bool setLogicSizeBuyers(unsigned int logicSizeBuyers);
	bool setPhysSizeBuyres(unsigned int physSizeBuyres);

	const char* getSystemName();
	Buyer** getAllBuyers(); //const?
	//Seller** getAllSellers(); //const?

	void reallocBuyers();

	System(char* systemName, unsigned int PhysSizeBuyres = INITIAL_PHYSICAL_SIZE); //c'tor
	~System(); //d'tor

	bool addBuyerToSystem(Buyer& buyer);
	//bool addSellerToSystem(Seller& seller);
	//void showAllBuyers() const;
	//void showAllSellers() const;
};

#endif //__SYSTEM_H