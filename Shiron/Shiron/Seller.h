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
	Item** m_allItems;

	unsigned int m_logicSizeFeedbacks;
	unsigned int m_physSizeFeedbacks;
	Feedback ** m_allFeedbacks;

public:
	Seller(const User& user, unsigned int physSizeItems = INITIAL_PHYSICAL_SIZE, unsigned int physSizeFeedbacks = INITIAL_PHYSICAL_SIZE); //c'tor 
	Seller(const Seller& other)=delete; //copy c'tor
	~Seller(); //d'tor

	bool addItemToSeller(Item* item);
	bool addFeedbackToSeller(Feedback* feedback);

	void reallocItems();
	void reallocFeedbacks();

	bool setLogicSizeItems(unsigned int logicSizeItems);
	bool setPhysSizeItems(unsigned int physSizeItems);

	bool setLogicSizeFeedbacks(unsigned int logicSizeFeedbacks);
	bool setPhysSizeFeedbacks(unsigned int physSizeFeedbacks);

	unsigned int getLogicSizeFeedbacks() const;
	Feedback** getAllFeedbacks() const;
	unsigned int getLogicSizeItems() const;
	Item** getAllItems() const;
	User& getUser();

	//unsigned int ShowItemsOfSeller(const char* name) const;
	Item* findSerialNumber(int serialNumber);
};

#endif //__SELLER_H