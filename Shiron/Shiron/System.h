#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Buyer.h"
#include "Seller.h"
//#include "Item.h"

class System
{
public:
	static constexpr unsigned int MAX_LEN_SYSTEM_NAME = 20;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;

private:
	char* m_systemName;
	Buyer** m_allBuyers;
	Seller** m_allSellers;

	unsigned int m_logicSizeBuyers; //the number of buyers and buyers that sign in
	unsigned int m_physSizeBuyers; //the maximum number of buyers in the system
	unsigned int m_logicSizeSellers; //the number of buyers and buyers that sign in
	unsigned int m_physSizeSellers; //the maximum number of buyers in the system

public:
	bool setSystemName(const char* systemName);
	bool setLogicSizeBuyers(unsigned int logicSizeBuyers);
	bool setPhysSizeBuyers(unsigned int physSizeBuyers);
	bool setLogicSizeSellers(unsigned int logicSizeSellers);
	bool setPhysSizeSellers(unsigned int physSizeSellers);
	void cleanBuyersArray();
	void cleanSellersArray();
	const char* getSystemName();
	Buyer** getAllBuyers(); //const?
	Seller** getAllSellers(); //const?

	void reallocBuyers();
	void reallocSellers();

	System(char* systemName, unsigned int physSizeBuyers = INITIAL_PHYSICAL_SIZE, unsigned int physSizeSellers = INITIAL_PHYSICAL_SIZE); //c'tor
	~System(); //d'tor

	void headline();
	void menu();
	void menuOptions();
	bool addBuyerToSystem(Buyer* buyer);
	bool addSellerToSystem(Seller* seller);
	void addItemToSellerMenu();
	void addItemToBasketMenu();

	const Address readAddress();
	const User readUser();
	Buyer* readBuyer();
	Seller* readSeller();
	void cleanBuffer();

	Item* readItem();
	Buyer* findBuyer(const char* nameOfBuyer) const;
	Seller* findSeller(const char* nameOfSeller) const;
	void showAllBuyers() const;
	void showAllSellers() const;

	bool showAllItemsMenu(const char* itemName) const;
	void showAllItemsOption() const;
};

#endif //__SYSTEM_H