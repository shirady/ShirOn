#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "Item.h"
#include <list> //STL

class Seller;
class Cart;

class Order
{
public:
	static constexpr bool INITIAL_OPEN_ORDER = true;

private:
	list<const Item*> m_allItemsOfOrderList; //list of const item*
	bool m_openOrder;
	unsigned int m_totalPriceOfOrder;

	bool setOpenOrder(bool openOrder);
	bool setTotalPriceOfOrder(unsigned int totalPriceOfOrder);

public:
	Order(); //c'tor
	Order(const Order& other) = delete; //copy c'tor

	friend ostream& operator<<(ostream& os, const Order& order);

	const list<const Item*>& getAllItemsOfOrderList() const;
	unsigned int getTotalPriceOfOrder() const;
	bool getIfOrderIsOpen() const;
	void closeOrder(unsigned int totalPriceOfOrder);
	unsigned int numberOfItemsInOrder() const;
	bool checkEmptyOrder() const;
	void addItemToOrder(const Item* item);
	void removeItemFromOrder(const Item* item);
	const Item* findSerialNumber(unsigned int serialNumber) const;
	bool checkIfSellerIsInAOrder(const Seller& seller) const;
	bool checkIfItemExists(const Item* item) const;
	void chooseAllItemsFromCart(Cart* cart);
};

#endif // __ORDER_H
