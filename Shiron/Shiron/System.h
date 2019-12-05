#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Buyer.h"
#include "Seller.h"

class System
{
public:
	static constexpr unsigned int MIN_LEN_SYSTEM_NAME = 2;
	static constexpr unsigned int MAX_LEN_SYSTEM_NAME = 20;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;

private:
	char* m_systemName;
	Buyer** m_allBuyers;
	Seller** m_allSellers;

	unsigned int m_logicSizeBuyers; //the number of buyers and buyers that sign in
	unsigned int m_physSizeBuyers; //the maximum number of buyers in the system
	unsigned int m_logicSizeSellers; //the number of buyers and buyers that sign in
	unsigned int m_physSizeSellers; //the maximum number of buyers in the system

public:
	bool setSystemName(const char* systemName);
	bool setLogicSizeBuyers(unsigned int logicSizeBuyers);
	bool setPhysSizeBuyers(unsigned int physSizeBuyers);
	bool setLogicSizeSellers(unsigned int logicSizeSellers);
	bool setPhysSizeSellers(unsigned int physSizeSellers);
	void cleanBuyersArray();
	void cleanSellersArray();
	const char* getSystemName();
	unsigned int getLogicSizeSellers() const;
	unsigned int getLogicSizeBuyers() const;
	Buyer** getAllBuyers(); //const?
	Seller** getAllSellers(); //const?

	void reallocBuyers();
	void reallocSellers();

	System(const char* systemName, unsigned int physSizeBuyers = INITIAL_PHYSICAL_SIZE, unsigned int physSizeSellers = INITIAL_PHYSICAL_SIZE); //c'tor
	~System(); //d'tor

	bool addBuyerToSystem(Buyer* buyer);
	bool addSellerToSystem(Seller* seller);

	Buyer* findBuyer(const char* nameOfBuyer) const;
	Seller* findSeller(const char* nameOfSeller) const;

};

#endif //__SYSTEM_H