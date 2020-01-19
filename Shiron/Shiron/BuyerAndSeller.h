#ifndef __BUYERANDSELLER_H
#define __BUYERANDSELLER_H

#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)
#include "Buyer.h"
#include "Seller.h"

class BuyerAndSeller : public Buyer, Seller //Public because seller can use methods of User
{
public:
	BuyerAndSeller(const string& userName, const string& password, const Address& address);//c'tor when we do not have seller and buyer object which already created
	BuyerAndSeller(const BuyerAndSeller& other) = delete; //copy c'tor

	void show() const;
	void showMe() const;

	virtual ~BuyerAndSeller(); //d'tor
};

#endif //__BUYERANDSELLER_H
