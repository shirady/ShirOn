#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Item.h"
#include "Order.h"
#include "Cart.h"

class Seller;

class Buyer
{
private:
	User m_user;
	Cart* m_Cart;
	//Order** m_OrdersHistory;
	//Order* m_OpenOrder;

public:
	Buyer(const User& user); //c'tor 
	Buyer(const Buyer& other); //copy c'tor
	~Buyer(); //d'tor

	User& getUser(); //const method?
	Cart* getCart() const;
};

#endif //__BUYER_H
