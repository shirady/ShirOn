#ifndef __USERS_GENERATOR
#define __USERS_GENERATOR

#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include <fstream> //for files

class User; //forward declaration

class UsersGenerator
{

public:
	enum eUsersType { UNKNWON, SELLER, BUYER, BUYER_AND_SELLER }; //all the types that can be

	static User* loadUser(ifstream& inFile);
	static eUsersType getType(const User* user);
};

#endif // __USERS_GENERATOR