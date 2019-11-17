#ifndef __USER_H
#define __USER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class User
{
public:
	static const int MAX_LEN_PASSWORD = 16;
	static const int MAX_LEN_NAME = 16;

private:
	char* m_userName;
	char* m_password;
	bool m_userType;

public:
	bool setUserName(const char* userName);
	bool setPassword(const char* passward);
	bool setUserType(bool userType);

	char* getUserName() const;
	char* getPassword() const;
	bool getUserType() const;

	User(const char* userName, const char* password, bool userType); //c'tor
	~User; //d'tor
};

#endif //__USER_H
