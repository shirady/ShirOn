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
	static constexpr unsigned int MAX_LEN_PASSWORD = 16;
	static constexpr unsigned int MAX_LEN_NAME = 16;
	static constexpr unsigned int MIN_LEN_PASSWORD = 6;
	static constexpr unsigned int MIN_LEN_NAME = 3;

private:
	char* m_userName;
	char* m_password;
	Address m_userAddress;

	bool setUserName(const char* userName);
	bool CheckWhiteSpace(const char* fieldName) const;

protected:
	User(const char* userName, const char* password, const Address& address); //c'tor - Protected because User is Abstract
	User(const User& other); // copy c'tor - Protected because User is Abstract

public:
	virtual ~User(); //d'tor

	bool setPassword(const char* password); //password can be change after it was created

	const char* getUserName() const;
	const char* getPassword() const;
	const Address& getAddress() const;
};

#endif //__USER_H