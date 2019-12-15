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

class Buyer
{
public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;

private:
	User m_user;
	Cart* m_Cart;
	unsigned int m_logicSizeOrders;
	unsigned int m_physSizeOrders;
	Order** m_OrdersHistory;
	Order* m_currentOrder;
	void cleanOrderHistoryArray();

public:
	Buyer(const User& user, unsigned int physSizeOrders = INITIAL_PHYSICAL_SIZE); //c'tor 
	Buyer(const Buyer& other) = delete; //copy c'tor
	~Buyer(); //d'tor

	bool setLogicSizeOrders(unsigned int logicSizeOrders);
	bool setPhysSizeOrders(unsigned int physSizeOrders);

	const User& getUser() const;
	Cart* getCart() const;
	Order* getCurrentOrder() const;
	unsigned int getLogicSizeOrders() const;
	Order** getAllOrders();

	void reallocOrders();
	void addOrderToHistory();
	bool checkIfSellerExistsInOrdersHistory(const Seller* seller) const;
};

#endif //__BUYER_H
