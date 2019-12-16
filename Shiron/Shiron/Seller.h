#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Item.h"
#include "Feedback.h"

class Seller
{
public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;

private:
	User m_user;
	unsigned int m_logicSizeItems;
	unsigned int m_physSizeItems;
	Item** m_allItems; //the seller is the one who defines the items he sells

	unsigned int m_logicSizeFeedbacks;
	unsigned int m_physSizeFeedbacks;
	const Feedback** m_allFeedbacks; //an array of const Feedback

	bool setLogicSizeItems(unsigned int logicSizeItems);
	bool setPhysSizeItems(unsigned int physSizeItems);
	bool setLogicSizeFeedbacks(unsigned int logicSizeFeedbacks);
	bool setPhysSizeFeedbacks(unsigned int physSizeFeedbacks);

public:
	Seller(const User& user, unsigned int physSizeItems = INITIAL_PHYSICAL_SIZE, unsigned int physSizeFeedbacks = INITIAL_PHYSICAL_SIZE); //c'tor 
	Seller(const Seller& other) = delete; //copy c'tor
	~Seller(); //d'tor

	unsigned int getLogicSizeFeedbacks() const;
	const Feedback** getAllFeedbacks() const;
	unsigned int getLogicSizeItems() const;
	Item** getAllItems() const;
	const User& getUser() const;

	bool addItemToSeller(Item* item); //const item? //<----------- stopped here
	bool addFeedbackToSeller(const Feedback* feedback);
	void reallocItems();
	void reallocFeedbacks();

	Item* findSerialNumber(int serialNumber) const;
	unsigned int countItemsOfSeller(const char* itemName) const;
	bool checkIfItemExistInASeller(const char* itemName) const;
};

#endif //__SELLER_H