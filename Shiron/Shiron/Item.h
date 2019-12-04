#ifndef __ITEM_H
#define __ITEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class Item
{
public:
	static constexpr unsigned int CATEGORY_SIZE = 4;
	enum eCategory { KIDS, ELECTRONICS, OFFICE, CLOTHING }; //0,1,2,3 //static const?
	const char* category[CATEGORY_SIZE] = { "KIDS", "ELECTRONICS", "OFFICE", "CLOTHING" };
	static constexpr int MIN_LEN_NAME = 2;
	static constexpr int MAX_LEN_NAME = 16;
	static constexpr unsigned int MIN_PRICE = 0; //free
	static constexpr unsigned int MAX_PRICE = 5000; //max price is up to 5,000 dollars
	static constexpr unsigned int MIN_SERIAL = 0;
	static constexpr unsigned int MAX_SERIAL = INT_MAX;

private:
	char* m_nameOfItem;
	eCategory m_categoryOfItem;
	unsigned int m_priceOfItem; //change the price to decimal
	unsigned int m_serialNumberOfItem; // need to have a mechanism a new serial number
	static unsigned int m_serialNumberCounter;

public:
	bool setNameOfItem(const char* nameOfItem);
	bool setCategoryOfItem(eCategory categoryOfItem);
	bool setPriceOfItem(unsigned int priceOfItem);

	const char* getNameOfItem() const;
	eCategory getCategoryOfItem() const;
	unsigned int getPriceOfItem() const;
	unsigned int getSerialNumberOfItem() const;

	bool CheckCharacters(const char* fieldName);

	void showItem() const;

	Item(const char* nameOfItem, eCategory categoryOfItem, unsigned int priceOfItem); //c'tor
	Item(const Item& other); //copy c'tor
	// move c'tor
	~Item(); //d'tor
};

#endif //__ITEM_H