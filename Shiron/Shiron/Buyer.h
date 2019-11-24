#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Item.h"
#include "Order.h"
#include "Basket.h"

class Buyer
{
	static const int IDBUYER = 0;
private:
	int m_IDBuyer;
	User m_user;
	Basket m_basket;
	Order** m_CompletedOrders;
	Order* m_OpenOrder;
	int* m_IDSellers;

public:
	//Buyer(); //c'tor 
	//Buyer(const Buyer&);
	//Buyer(Buyer&& other); // move c'tor
	//~Buyer(); //d'tor
};

#endif //__BUYER_H
