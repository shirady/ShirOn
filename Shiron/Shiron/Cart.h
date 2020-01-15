#ifndef __Cart_H
#define __Cart_H

#include <iostream>
#include <string.h>
#include "Item.h"
using namespace std;
#pragma warning(disable: 4996)
#include <list> //STL

class Cart
{
private:
	list<const Item*> m_allItemsOfCart; //an array of const item*

public:
	Cart(); //c'tor 
	Cart(const Cart& other) = delete; //copy c'tor
	~Cart(); //d'tor

	bool operator>(const Cart& other);
	friend ostream& operator<<(ostream& os, const Cart& cart);

	list<const Item*>  getAllItemsOfCart() const;
	int numberOfItemsInCart() const;
	bool checkEmptyCart() const;

	bool addItemToCart(const Item* item);
	void removeItemFromCart(const Item* item);
	const Item* findSerialNumber(unsigned int serialNumber) const;
	unsigned int getTotalPriceOfCart() const;
	bool checkIfItemExists(const Item* item) const;
};

#endif //__Cart_H
