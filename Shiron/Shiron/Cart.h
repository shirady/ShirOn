#ifndef __Cart_H
#define __Cart_H

#include <iostream>
#include <string.h>
#include "Item.h"
using namespace std;
#pragma warning(disable: 4996)

class Cart
{
public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;

private:
	unsigned int m_logicSizeItems;
	unsigned int m_physSizeItems;
	const Item** m_allItemsOfCart; //an array of const item*

public:
	Cart(unsigned int physSizeItems = INITIAL_PHYSICAL_SIZE); //c'tor 
	Cart(const Cart& other) = delete; //copy c'tor
	~Cart(); //d'tor

	bool setLogicSizeItems(unsigned int logicSizeItems);
	bool setPhysSizeItems(unsigned int physSizeItems);

	unsigned int getLogicSizeItems() const;
	const Item** getAllItemsOfCart() const;

	void reallocItems();
	bool addItemToCart(const Item* item);
	void removeItemFromCart(const Item* item);

	const Item* findSerialNumber(unsigned int serialNumber) const;
};

#endif //__Cart_H
