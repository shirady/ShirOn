#ifndef __INTERFACE_H
#define __INTERFACE_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#include "system.h"

class Interface
{
public:
	const char* category[Item::CATEGORY_SIZE] = { "KIDS", "ELECTRONICS", "OFFICE", "CLOTHING" };

private:
	System* m_system = nullptr; //where to initialize?

public:
	Interface(); //c'tor
	Interface(const System& other) = delete; //copy c'tor disabled
	~Interface(); //d'tor

	void headline();
	void menu();
	void menuOptions();

	void addItemToSellerMenu();
	void addItemToCartMenu();
	void makeAnOrderMenu();
	void payOrderMenu();
	void addFeedbackToSellerMenu();

	void readSystem();
	const Address readAddress();
	const User readUser();
	Buyer* readBuyer();
	Seller* readSeller();
	Item* readItem(Seller* seller);
	Feedback* readFeedback(Buyer* buyer);
	const Date readDate();

	bool setSystem(const char * systemName);

	void cleanBuffer();

	void showAllBuyers() const;
	void showAllSellers() const;
	void showUser(User& user) const;

	void showItem(const Item* item) const;
	void showOrder(Order* order) const;
	void showCart(Cart* cart) const;
	void showItemsOfSeller(Seller* seller, const char* itemName) const;

	void showAllItemsOfSellers(const char* itemName) const;
	void showAllItemsOption() const;

	void chooseAllItemsFromCart(Buyer* buyer) const;
	void chooseCertainItemsFromCart(Buyer* buyer) const;
	void removeItemsFromOrder(Buyer* buyer) const; 

	//bool findSellerInOrder(Order* order, const char* sellerName) const;
	//bool findSellerInAOrder(Order* order, Seller* seller) const; //*****
};

#endif// __INTERFACE_H