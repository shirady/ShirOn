#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include <list> //STL

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
	string m_systemName;
	list<User*> m_allUsersList;

	void cleanUsersList();

public:
	System(const string& systemName); //c'tor
	System(const System& other) = delete; //copy c'tor
	~System(); //d'tor

	const System& operator+=(Buyer* buyer);
	const System& operator+=(Seller* seller);

	bool setSystemName(const string& systemName);
	const string& getSystemName() const;
	unsigned int numberOfUsersInSystem() const;
	const list<User*>& getAllUsersList() const;

	void addUserToSystem(User* user);
	User* findUser(const string& UserName) const;
	bool checkIfItemExistInSellers(const string& itemName) const;
	unsigned int countItemsInAllSellers(const string& itemName) const;

	void showAllBuyers() const;
	void showAllSellers() const;
	void showAllBuyersThatAreSellers() const;
	void showAllItemsOfSellers(const string& itemName) const;

	void saveUsersToFile(const string& fileName) const;
	void loadAllUsers(const string& fileName, unsigned int& numOfUsers);
};

#endif //__SYSTEM_H