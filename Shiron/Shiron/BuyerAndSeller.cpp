#include "BuyerAndSeller.h"

BuyerAndSeller::BuyerAndSeller(const char* userName, const char* password, const Address& address) : User(userName, password, Address(address)),Buyer(userName,password,address),Seller(userName,password,address)
{

}

BuyerAndSeller::~BuyerAndSeller()
{

}
