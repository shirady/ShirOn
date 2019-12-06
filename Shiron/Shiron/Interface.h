#ifndef __INTERFACE_H
#define __INTERFACE_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#include "system.h"
//#include "Seller.h"

class Interface
{
public:
	const char* category[Item::CATEGORY_SIZE] = { "KIDS", "ELECTRONICS", "OFFICE", "CLOTHING" };

private:
	System* m_system = nullptr; //where to initialize?

public:
	Interface();
	Interface(const System& other) = delete; //copt c'tor disabled
	~Interface(); //d'tor

	void headline();
	void menu();
	void menuOptions();

	void addItemToSellerMenu();
	void addItemToCartMenu();
	void addFeedbackToSellerMenu();
	void makeAnOrderMenu();

	void readSystem();
	const Address readAddress();
	const User readUser();
	Buyer* readBuyer();
	Seller* readSeller();
	Item* readItem(Seller* seller);
	Feedback* readFeedback(Buyer* buyer);

	bool setSystem(const char * systemName);

	void cleanBuffer();

	void showAllBuyers() const;
	void showAllSellers() const;
	void showUser(User& user) const;

	void showItem(const Item* item) const;
	void showOrder(Order* order) const;
	void showCart(Cart* cart) const;
	unsigned int ShowItemsOfSeller(Seller* seller, const char* itemName) const;

	bool showAllItemsMenu(const char* itemName) const;
	void showAllItemsOption() const;

	void chooseAllItemsFromCart(Buyer* buyer) const;
	void chooseCertainItemsFromCart(Buyer* buyer) const;
	void removeItemsFromOrder(Buyer* buyer) const;
	void payOrderMenu();

	bool findSellerInOrder(Order* order, const char* sellerName) const;
};

#endif// __INTERFACE_H