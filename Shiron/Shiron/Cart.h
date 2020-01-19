#ifndef __Cart_H
#define __Cart_H

#include <iostream>
#include <string.h>
#include "Item.h"
using namespace std;
#pragma warning(disable: 4996)
#include <list> //STL

class Order;

class Cart
{
private:
	list<const Item*> m_allItemsOfCartList; //an array of const item*

public:
	Cart(); //c'tor 
	Cart(const Cart& other) = delete; //copy c'tor
	~Cart(); //d'tor

	bool operator>(const Cart& other);
	friend ostream& operator<<(ostream& os, const Cart& cart);

	const list<const Item*>&  getAllItemsOfCart() const;
	unsigned int numberOfItemsInCart() const;
	bool checkEmptyCart() const;

	void addItemToCart(const Item* item);
	void removeItemFromCart(const Item* item);
	const Item* findSerialNumber(unsigned int serialNumber) const;
	unsigned int getTotalPriceOfCart() const;
	bool checkIfItemExists(const Item* item) const;

	void RemoveItemByOrder(Order* order);
};

#endif //__Cart_H
