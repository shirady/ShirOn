#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Item.h"

class Seller
{

public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;
private:
    User m_user;
	unsigned int m_logicSizeItems;
	unsigned int m_physSizeItems;
	Item** m_allItems;

public:
	Seller(const User& user, unsigned int physSizeItems = INITIAL_PHYSICAL_SIZE); //c'tor 
	Seller(const Seller& other); //copy c'tor
	~Seller(); //d'tor

	bool addItemToSeller(Item* item);
	void reallocItems();
	bool setLogicSizeItems(unsigned int logicSizeItems);
	bool setPhysSizeItems(unsigned int physSizeItems);

	unsigned int ShowItemsOfSeller(const char* name) const;
	Item* findSerialNumber(int serialNumber);

	User& getUser();
};

#endif //__SELLER_H