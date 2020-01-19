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

private:
	char* m_systemName;
	list<User*> m_allUsersList;

	void cleanUsersList();

public:
	System(const char* systemName); //c'tor
	System(const System& other) = delete; //copy c'tor
	~System(); //d'tor

	const System& operator+=(Buyer* buyer);
	const System& operator+=(Seller* seller);


	bool setSystemName(const char* systemName);

	const char* getSystemName() const;
	unsigned int numberOfUsersInSystem() const;

	const list<User*>& getAllUsersList() const;
	void addUserToSystem(User* user);

	User* findUser(const char* nameOfUser) const;

	bool checkIfItemExistInSellers(const char* itemName) const;
	unsigned int countItemsInAllSellers(const char* itemName) const;

	void showAllBuyers() const;
	void showAllSellers() const;
	void showAllBuyersThatAreSellers() const;
	void showAllItemsOfSellers(const char* itemName) const;
};

#endif //__SYSTEM_H