//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#ifndef __BASKET_H
#define __BASKET_H

#include <iostream>
#include <string.h>
#include "Item.h"
using namespace std;
#pragma warning(disable: 4996)

class Basket
{
public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;

private:
	unsigned int m_logicSizeItems;
	unsigned int m_physSizeItems;
	Item** m_allItemsOfBasket;
    
public:
	Basket(unsigned int physSizeItems = INITIAL_PHYSICAL_SIZE); //c'tor 
	Basket(const Basket& other); //copy c'tor
	~Basket(); //d'tor

	bool setLogicSizeItems(unsigned int logicSizeItems);
	bool setPhysSizeItems(unsigned int physSizeItems);
	void reallocItems();
	bool addItemToBasket(Item* item);

	unsigned int getLogicSizeItems();

    };

#endif //__BASKET_H
