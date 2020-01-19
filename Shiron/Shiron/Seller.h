#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include <list> //STL

#include "User.h"
#include "Item.h"
#include "Feedback.h"
#include "Array.h"

class Seller : virtual public User //Public because seller can use methods of User
{
public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;

private:
	unsigned int m_logicSizeItems;
	unsigned int m_physSizeItems;
	list<Item*> m_allItemsList; //the seller is the one who defines the items he sells
	Array<const Feedback*> m_allFeedbacks;

public:
	Seller(const char* userName, const char* password, const Address& address); //c'tor 
	Seller(const Seller& other) = delete; //copy c'tor
	virtual ~Seller(); //d'tor
	void cleanItemsList();

	void show() const;
	void showMe() const;
	void showItemsOfSeller(const char* itemName) const;

	unsigned int numberOfItemsInSeller() const;
	const list<Item*>& getAllItemsList() const;

	void addItemToSeller(Item* item);
	void addFeedbackForSeller(const Feedback* feedback); //Relate to Array template class

	Item* findSerialNumber(int serialNumber) const;
	unsigned int countItemsOfSeller(const char* itemName) const;
	bool checkIfItemExistInASeller(const char* itemName) const;
};

#endif //__SELLER_H