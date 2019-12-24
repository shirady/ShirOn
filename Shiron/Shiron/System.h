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

	unsigned int m_logicSizeUsers; //the number of users that sign in
	unsigned int m_physSizeUsers; //the maximum number of users in the system

	bool setLogicSizeUsers(unsigned int logicSizeUsers);
	bool setPhysSizeUsers(unsigned int physSizeUsers);

	void cleanUsersArray();

	void reallocUsers();

public:
	System(const char* systemName, unsigned int physUsers = INITIAL_PHYSICAL_SIZE); //c'tor
	System(const System& other) = delete; //copy c'tor
	~System(); //d'tor

	bool setSystemName(const char* systemName);

	const char* getSystemName() const;
	unsigned int getLogicSizeUsers() const;

	User** getAllUsers(); //not const by permission from Keren because it made problems (Users* const *)

	bool addUserToSystem(User* user);

	User* findUser(const char* nameOfUser) const; //check

	bool checkIfItemExistInSellers(const char* itemName) const;
	unsigned int countItemsInAllSellers(const char* itemName) const;
};

#endif //__SYSTEM_H