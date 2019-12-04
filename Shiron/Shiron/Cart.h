//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

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
	const Item** m_allItemsOfCart;
    
public:
	Cart(unsigned int physSizeItems = INITIAL_PHYSICAL_SIZE); //c'tor 
	Cart(const Cart& other); //copy c'tor
	~Cart(); //d'tor

	bool setLogicSizeItems(unsigned int logicSizeItems);
	bool setPhysSizeItems(unsigned int physSizeItems);
	void reallocItems();
	bool addItemToCart(const Item* item);
	void removeItemFromCart(const Item* item);


	unsigned int getLogicSizeItems() const;
	const Item** allItemsOfCart() const;
	const Item* findSerialNumber(unsigned int serialNumber) const;

	void showCart() const;
    };

#endif //__Cart_H
