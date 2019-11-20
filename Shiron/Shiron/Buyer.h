#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Item.h"
#include "Order.h"

class Buyer
{
private:
	//User* m_user; //had no choice but using pointer... else there's errors about enters a private attribute in class User
	//Item* m_basket; //do we want to create a class for items? // is it an array of the items or pointers to the items?
	//Order* m_orderList;

	Buyer(const Buyer&); // copy c'tor - we will not implement, it is  declaration for the compiler

public: // do we nee setters?
	//const User* getUser() const;
	//const Item* getBasket() const;
	//const Order* getOrder() const;

	//Buyer(); //c'tor 
	//Buyer(Buyer&& other); // move c'tor
	//~Buyer(); //d'tor
};

#endif //__BUYER_H