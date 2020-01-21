#include "UserGenerator.h"
#include "Seller.h"
#include "Buyer.h"
#include "BuyerAndSeller.h"

User* UsersGenerator::loadUser(ifstream& inFile)
{
	eUsersType type;
	int tempType; //temporary since it cannot get enum type

	inFile >> tempType; //reads the type of the object
	type = (eUsersType)tempType;

	//creating the object from the specific type
	if (type == SELLER)
		return new Seller(inFile);
	else if (type == BUYER)
		return new Buyer(inFile);
	else if (type == BUYER_AND_SELLER)
		return new BuyerAndSeller(inFile);
	else //we should never get here
		return nullptr;
}

UsersGenerator::eUsersType UsersGenerator::getType(const User* user)
{
	if (typeid(*user) == typeid(Seller))
		return SELLER;
	else if (typeid(*user) == typeid(Buyer))
		return BUYER;
	else if (typeid(*user) == typeid(BuyerAndSeller))
		return BUYER_AND_SELLER;
	else //we should never get here
		return UNKNWON;
}