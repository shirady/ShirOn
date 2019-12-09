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

	bool setSystem(const char * systemName);

	void headline() const;
	void menu() const;
	void menuOptions() const;

	void addItemToSellerMenu() const;
	void addItemToCartMenu() const;
	Seller* FindSellerByChoise(char* const itemName, unsigned int counterOfItemsInAllSellers) const;
	void addItemToCartMenuHelper(Seller* seller, char* const itemName, Buyer* buyer) const;
	void makeAnOrderMenu() const;
	void chooseOptionForMakeAnOrderMenu(Cart* cart) const;
	void chooseOptionForMakeAnOrder(Buyer* buyer, Cart* cart, unsigned int numberOfItemsInCart) const;
	void payOrderMenu() const;
	void payOrderMenuHelper(Buyer* buyer, Cart* cart, Order* order, unsigned int numberOfItemsInCart, unsigned int numberOfItemsInOrder, unsigned int totalPriceOfOrder) const;
	void addFeedbackToSellerMenu() const;
	void addFeedbackToSellerMenuHelper(Buyer* buyer) const;
	void showAllItemsOfCeratinNameMenu() const;

	void readSystem();
	void readNumericValuesOfAddress(int& apartmentNo, int& buildNo) const;
	const Address readAddress() const;
	const User readUser() const;
	Buyer* readBuyer() const;
	Seller* readSeller() const;
	Item* readItem(Seller* seller) const;
	Feedback* readFeedback(Buyer* buyer) const;
	const Date readDate() const;

	void cleanBuffer() const;
	void cleanAfterGetLine() const;

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

};

#endif// __INTERFACE_H