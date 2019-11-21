#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "Busket.h"
#include "User.h"
#include "Order.h"


class Seller
{
public:
	static const int MAX_LEN_PASSWORD = 16;
	static const int MAX_LEN_NAME = 16;
	enum eUserType { BUYER, SELLER};

private:
    int m_IdBuyer;
    User m_user;
    Busket m_busket;
    //Order* sellingList;
    int m_IdSellers;
    int m_currentOrderArraySize;

public:
	bool setIdBuyer(int IdBuyer);
	bool IdSellers(int IdSellers);
	bool setCurrentOrderArraySize(int currentOrderArraySize);

	int getIdBuyer() const;
	int getIdSellers() const;
	int getCurrentOrderArraySize() const;

    Seller(int IdBuyer, int IdSellers, int currentOrderArraySize, User& user, Busket& busket) : m_user(user),m_busket(busket)
    {
        
    }//c'tor
	Seller(User&& other); // move c'tor
	~Seller(); //d'tor
};

#endif //__USER_H
