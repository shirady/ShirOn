#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include <list> //STL

#include "User.h"
#include "Item.h"
#include "Order.h"
#include "Cart.h"

class Buyer: virtual public User //Public because buyer can use methods of User
{
private:
	Cart* m_cart;
	Order* m_currentOrder;
	list<const Order*> m_ordersHistoryList; //a list of const Order*

	void cleanOrderHistoryList();

public:
	Buyer(const char* userName, const char* password, const Address& address); //c'tor 
	Buyer(const Buyer& other) = delete; //copy c'tor
	virtual ~Buyer(); //d'tor
	void show() const;
	void showMe() const;
	bool operator>(const Buyer& other);

	Cart* getCart() const;
	Order* getCurrentOrder() const;
	const list<const Order*>& getOrdersHistoryList() const;

	void addOrderToHistory();
	bool checkIfSellerExistsInOrdersHistory(const Seller& seller) const;
};

#endif //__BUYER_H
