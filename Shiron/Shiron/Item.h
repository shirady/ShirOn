#ifndef __ITEM_H
#define __ITEM_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class Item
{
public:
	enum eCategory { KIDS, ELECTRONICS, OFFICE, CLOTHING }; //0,1,2,3
	static const int MAX_LEN_NAME = 16;
	static const int MIN_PRICE = 0; //free
	static const int MAX_PRICE = 5000; //max price is up to 5,000 dollars
	static const int MIN_SERIAL = 0;
	static const int MAX_SERIAL = INT_MAX;

private:
	//static unsigned int generalSerialNumber;
	char* m_nameOfItem;
	eCategory m_categoryOfItem;
	int m_priceOfItem;
	int m_serialNumberOfItem; // need to have a mechanism for a new serial number

public:
	bool setNameOfItem(const char* nameOfItem);
	bool setCategoryOfItem(eCategory categoryOfItem);
	bool setPriceOfItem(int priceOfItem);
	//bool setSerialNumberOfItem(int serialNumberOfItem);

	const char* getNameOfItem() const;
	eCategory getCategoryOfItem() const;
	int getPriceOfItem() const;
	int getSerialNumberOfItem() const;

	bool CheckCharacters(const char* fieldName);

	Item(const char* nameOfItem, eCategory categoryOfItem, int priceOfItem, int serialNumberOfItem); //c'tor
	//Item(const Item& other, int m_serialNumberOfItem); // copy c'tor //causes problems of static variables
	//Item(Item&& other, int m_serialNumberOfItem); // move c'tor  //causes problems of static variables
	~Item(); //d'tor
};

#endif //__ITEM_H
