#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "User.h"


class Seller
{
private:
    User m_user;

public:
	Seller(const User& user); //c'tor 
	Seller(const Seller& other); //copy c'tor
	~Seller(); //d'tor

	User& getUser();
};

#endif //__SELLER_H
