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
	User m_user;
	//Item* m_basket; //do we want to create a class for items? // is it an array of the items or pointers to the items?
	//Order* m_orderList;

public:
	//Buyer(); //c'tor 
	//Buyer(const Buyer&);
	//Buyer(Buyer&& other); // move c'tor
	//~Buyer(); //d'tor
};

#endif //__BUYER_H