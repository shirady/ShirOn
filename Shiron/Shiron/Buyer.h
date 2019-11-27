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
	//Basket m_basket;
	//Order** m_OrdersHistory;
	//Order* m_OpenOrder;

public:
	Buyer(const User& user); //c'tor 
	Buyer(const Buyer& other); //copy c'tor
	~Buyer(); //d'tor

	User& getUser();

};

#endif //__BUYER_H
