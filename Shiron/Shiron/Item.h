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
	static constexpr int MIN_LEN_NAME = 2;
	static constexpr int MAX_LEN_NAME = 16;
	static constexpr unsigned int MIN_PRICE = 0; //free item
	static constexpr unsigned int MAX_PRICE = 5000; //max price is up to 5,000
	static constexpr unsigned int MIN_SERIAL = 0;
	static constexpr unsigned int MAX_SERIAL = INT_MAX;

private:
	char* m_itemName;
	eCategory m_categoryOfItem;
	unsigned int m_priceOfItem;
	unsigned int m_serialNumberOfItem;
	static unsigned int m_serialNumberCounter;
	const Seller* m_seller; //need to decided

	bool CheckCharacters(const char* fieldName) const;
	bool setNameOfItem(const char* itemName);
	bool setSeller(const Seller* seller);

public:
	Item(const char* nameOfItem, eCategory categoryOfItem, unsigned int priceOfItem, const Seller* seller = nullptr); //c'tor //// decide to stay without const Seller seller* since we had assignment between non-const pointer and const pointer
	Item(const Item& other) = delete; //copy c'tor
	~Item(); //d'tor

	bool setCategoryOfItem(eCategory categoryOfItem);
	bool setPriceOfItem(unsigned int priceOfItem);

	const char* getNameOfItem() const;
	eCategory getCategoryOfItem() const;
	unsigned int getPriceOfItem() const;
	unsigned int getSerialNumberOfItem() const;
	const Seller* getSeller() const;
};

#endif //__ITEM_H