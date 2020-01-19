#include "BuyerAndSeller.h"

BuyerAndSeller::BuyerAndSeller(const string& userName, const string& password, const Address& address) : User(userName, password, Address(address)),Buyer(userName,password,address),Seller(userName,password,address)
{

}

BuyerAndSeller::~BuyerAndSeller()
{

}

void BuyerAndSeller::show() const
{
	User::show();
	showMe();
}

void BuyerAndSeller::showMe() const
{
	Buyer::showMe();
	Seller::showMe();
}
