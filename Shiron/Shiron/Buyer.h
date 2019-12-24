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

class Buyer: virtual public User //Public because buyer can use methods of User
{
public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;

private:
	Cart* m_Cart;
	unsigned int m_logicSizeOrders;
	unsigned int m_physSizeOrders;
	const Order** m_OrdersHistory; //an array of const Order*
	Order* m_currentOrder;

	void cleanOrderHistoryArray();
	bool setLogicSizeOrders(unsigned int logicSizeOrders);
	bool setPhysSizeOrders(unsigned int physSizeOrders);

	void reallocOrders(); 

public:
	Buyer(const char* userName, const char* password, const Address& address, unsigned int physSizeOrders = INITIAL_PHYSICAL_SIZE); //c'tor 
	Buyer(const Buyer& other) = delete; //copy c'tor
	virtual ~Buyer(); //d'tor
	
	bool operator>(const Buyer& other);

	Cart* getCart() const;
	Order* getCurrentOrder() const;
	unsigned int getLogicSizeOrders() const;
	const Order** getAllOrders();

	void addOrderToHistory();
	bool checkIfSellerExistsInOrdersHistory(const Seller* seller) const;
};

#endif //__BUYER_H
