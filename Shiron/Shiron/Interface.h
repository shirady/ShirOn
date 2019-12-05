#ifndef __INTERFACE_H
#define __INTERFACE_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#include "system.h"

class Interface
{
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
	 void makeAnOrderMenu();

	 void readSystem();
	 const Address readAddress();
	 const User readUser();
	 Buyer* readBuyer();
	 Seller* readSeller();

	 bool setSystem(const char * systemName);

	
	 void cleanBuffer();
	 Item* readItem();

	 void showUser(User& user) const;
	 bool showAllItemsMenu(const char* itemName) const;
	 void showAllItemsOption() const;
	 void showAllBuyers() const;
	 void showAllSellers() const;

	 void chooseAllItemsFromCart(Buyer* buyer) const;
	 void chooseCertainItemsFromCart(Buyer* buyer) const;
	 void removeItemsFromOrder(Buyer* buyer) const;
	 void payOrderMenu();
};

#endif// __INTERFACE_H