#ifndef __USER_H
#define __USER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class User
{
public:
	static const int MAX_LEN_PASSWORD = 15;
	static const int MAX_LEN_NAME = 10;

private:
	char* m_userName;
	char* m_password;
	bool m_userType;

public:
	void setUserName(const char* userName);

	User(char* userName, char* password, bool userType); //c'tor
	~User; //d'tor


};

#endif //__USER_H
