#ifndef __USER_H
#define __USER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "Address.h"


class User
{
public:
	static const int MAX_LEN_PASSWORD = 16;
	static const int MAX_LEN_NAME = 16;
	enum eUserType { BUYER, SELLER};

private:
	char* m_userName;
	char* m_password;
	eUserType m_userType;
	//Address m_address; //the address is not found

public:
	bool setUserName(const char* userName);
	bool setPassword(const char* passward);
	bool setUserType(eUserType userType);

	const char* getUserName() const;
	const char* getPassword() const;
	eUserType getUserType() const;

    User(const User&); // copy c'tor - we will not implement, it is  declaration for the compiler
	User(const char* userName, const char* password, eUserType userType); //c'tor
	User(User&& other); // move c'tor
	~User(); //d'tor
};

#endif //__USER_H
