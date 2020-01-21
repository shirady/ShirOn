#ifndef __BUYERANDSELLER_H
#define __BUYERANDSELLER_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#include <string>
#include <fstream> //for files

#include "Buyer.h"
#include "Seller.h"

class BuyerAndSeller : public Buyer, Seller //Public because seller can use methods of User
{
public:
	BuyerAndSeller(const string& userName, const string& password, const Address& address);//c'tor when we do not have seller and buyer object which already created
	BuyerAndSeller(ifstream& inFile); //c'tor when reading from file
	BuyerAndSeller(const BuyerAndSeller& other) = delete; //copy c'tor
	virtual ~BuyerAndSeller() {}; //d'tor

	void show() const;
	void showMe() const;
};

#endif //__BUYERANDSELLER_H
