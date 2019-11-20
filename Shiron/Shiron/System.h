#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"

///// Oron, what do think if we will separate this class to system of buyers and system of sellers? ////

//forward declarations
class Buyer; 
class Seller;

class System //how do we want to allocate each user? allocate and copy is an expensive action... will we set the number of users at the beginning?
{
public:
	static const int MAX_LEN_SYSTEM_NAME = 20;

private:
	char* m_systemName; // do we want is static?
	Buyer** m_allByers; //This is an array of pointers to the buyers
	Seller** m_allSellers; //This is an array of pointers to the sellers
	int m_CurrentByers; //the number of buyers and buyers that sign in
	int m_CurrentSellers; //the number of sellers and buyers that sign in
	int m_maxBuyres; //the maximum number of buyers in the system
	int m_maxSellers; //the maximum number of sellers in the system

	System(const System& other); //copy c'tor
public:
	bool setSystemName(const char* systemName);
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