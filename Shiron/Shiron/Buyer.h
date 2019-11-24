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

class Seller;

class Buyer
{
private:
	User m_user;
	Basket m_basket;
	Order** m_OrdersHistory;
	Order* m_OpenOrder;
	Seller** m_SellersHistory;

public:
	//Buyer(); //c'tor 
	//Buyer(const Buyer&);
	//Buyer(Buyer&& other); // move c'tor
	//~Buyer(); //d'tor
};

#endif //__BUYER_H
