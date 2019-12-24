#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"
#include "Buyer.h"
#include "Seller.h"
#include "BuyerAndSeller.h"

class System
{
public:
	static constexpr unsigned int MIN_LEN_SYSTEM_NAME = 2;
	static constexpr unsigned int MAX_LEN_SYSTEM_NAME = 20;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;

private:
	char* m_systemName;
	User** m_allUsers;
	//Buyer** m_allBuyers;
	//Seller** m_allSellers;

	//unsigned int m_logicSizeBuyers; //the number of buyers and buyers that sign in
	//unsigned int m_physSizeBuyers; //the maximum number of buyers in the system
	//unsigned int m_logicSizeSellers; //the number of buyers and buyers that sign in
	//unsigned int m_physSizeSellers; //the maximum number of buyers in the system

	unsigned int m_logicSizeUsers; //the number of buyers and buyers that sign in
	unsigned int m_physSizeUsers; //the maximum number of buyers in the system

	//bool setLogicSizeBuyers(unsigned int logicSizeBuyers);
	//bool setPhysSizeBuyers(unsigned int physSizeBuyers);

	//bool setLogicSizeSellers(unsigned int logicSizeSellers);
	//bool setPhysSizeSellers(unsigned int physSizeSellers);

	bool setLogicSizeUsers(unsigned int logicSizeUsers);
	bool setPhysSizeUsers(unsigned int physSizeUsers);

	//void cleanBuyersArray();
	//void cleanSellersArray();
	void cleanUsersArray();

	//void reallocBuyers();
	//void reallocSellers();
	void reallocUsers();

public:
	//System(const char* systemName, unsigned int physSizeBuyers = INITIAL_PHYSICAL_SIZE, unsigned int physSizeSellers = INITIAL_PHYSICAL_SIZE); //c'tor
	System(const char* systemName, unsigned int physUsers = INITIAL_PHYSICAL_SIZE); //c'tor

	System(const System& other) = delete; //copy c'tor
	~System(); //d'tor

	bool setSystemName(const char* systemName);

	const char* getSystemName() const;
	//unsigned int getLogicSizeSellers() const;
	//unsigned int getLogicSizeBuyers() const;
	unsigned int getLogicSizeUsers() const;

	//Buyer** getAllBuyers(); //not const by permission from Keren because it made problems (Buyer* const *)
	//Seller** getAllSellers(); //not const by permission from Keren because it made problems (Seller* const *)
	User** getAllUsers(); //not const by permission from Keren because it made problems (Users* const *)

	//bool addBuyerToSystem(Buyer* buyer); 
	//bool addSellerToSystem(Seller* seller);
	bool addUserToSystem(User* user);

	//Buyer* findBuyer(const char* nameOfBuyer) const;
	//Seller* findSeller(const char* nameOfSeller) const;
	User* findUser(const char* nameOfUser) const; //check

	bool checkIfItemExistInSellers(const char* itemName) const;
	unsigned int countItemsInAllSellers(const char* itemName) const;

	//Seller* isUserSeller(User* user) const;
	//bool isUserBuyer(User* user) const;
	//bool isUserBuyerAndSeller(User* user) const;

};

#endif //__SYSTEM_H