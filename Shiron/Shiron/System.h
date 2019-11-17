#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "User.h" // maybe we will want to use forward declaration

class System //how do we want to allocate each user? allocate and copy is an expensive action... will we set the number of users at the beginning?
{
public:
	static const int MAX_LEN_SYSTEM_NAME = 16;

private:
	char m_systemName[MAX_LEN_SYSTEM_NAME]; // do we want is static?
	User** m_allUsers; //This is an array of pointers to the users

public:
	System(); //c'tor
	char* GetSystemName();
	User** GetAllUsers();

	bool AddUserToSystem(User* user);
	void ShowUsers() const;
	~System(); //d'tor
};

#endif //__SYSTEM_H