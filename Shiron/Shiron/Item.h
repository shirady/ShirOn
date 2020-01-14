#ifndef __ITEM_H
#define __ITEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class Seller; //forward declaration 


class Item
{
public:
	static constexpr unsigned int CATEGORY_SIZE = 4;
	enum eCategory { KIDS, ELECTRONICS, OFFICE, CLOTHING };
	static const char* category[CATEGORY_SIZE];
	static constexpr int MIN_LEN_NAME = 2;
	static constexpr int MAX_LEN_NAME = 16;
	static constexpr unsigned int MIN_PRICE = 0; //free item
	static constexpr unsigned int MAX_PRICE = 5000; //max price is up to 5,000
	static constexpr unsigned int MIN_SERIAL = 0;
	static constexpr unsigned int MAX_SERIAL = INT_MAX;

private:
	char* m_itemName;
	eCategory m_categoryOfItem;
	int m_priceOfItem;
	unsigned int m_serialNumberOfItem;
	static unsigned int m_serialNumberCounter;
	const Seller& m_seller; //m_Seller is const ref as it must not be null

	bool CheckCharacters(const char* fieldName) const;
	bool setNameOfItem(const char* itemName);

public:
	Item(const char* nameOfItem, eCategory categoryOfItem, int priceOfItem, const Seller& seller); //c'tor 
	Item(const Item& other) = delete; //copy c'tor
	~Item(); //d'tor

	friend ostream& operator<<(ostream& os, const Item& item);

	bool setCategoryOfItem(eCategory categoryOfItem);
	bool setPriceOfItem(int priceOfItem);

	const char* getNameOfItem() const;
	eCategory getCategoryOfItem() const;
	int getPriceOfItem() const;
	unsigned int getSerialNumberOfItem() const;
	const Seller& getSeller() const;
};


#endif //__ITEM_H

