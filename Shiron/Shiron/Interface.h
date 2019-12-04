#ifndef __INTERFACE_H
#define __INTERFACE_H

#include <iostream>;
using namespace std;
#include "system.h"

class Interface
{
private:
	System* m_system;

public:
	 Interface(System& system); //c'tor
	 Interface(const System& other) = delete; //copt c'tor disabled
	 ~Interface(); //d'tor

	 void headline();
	 void menu();
	 void menuOptions();

	 void addItemToSellerMenu();
	 void addItemToCartMenu();
	 void makeAnOrderMenu();

	 const Address readAddress();
	 const User readUser();
	 Buyer* readBuyer();
	 Seller* readSeller();
	
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