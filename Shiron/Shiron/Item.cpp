#include "Item.h"
#include "Seller.h" //There is forward declaration of seller in item.h

unsigned int Item::m_serialNumberCounter = 0;
const char* Item::category[CATEGORY_SIZE] = { "KIDS", "ELECTRONICS", "OFFICE", "CLOTHING" };

Item::Item(const char* itemName, Item::eCategory categoryOfItem, int priceOfItem, const Seller& seller): m_seller(seller)
{
	m_itemName = nullptr;

	setNameOfItem(itemName);
	setCategoryOfItem(categoryOfItem);
	setPriceOfItem(priceOfItem);
	//setSeller(seller);
	m_serialNumberOfItem = ++m_serialNumberCounter;
}

Item::~Item()
{
	delete[] m_itemName;
}

ostream& operator<<(ostream& os, const Item& item)
{
	os << "Item name: " << item.m_itemName
		<< ", Category: " << item.category[item.m_categoryOfItem]
		<< ", Price: " << item.m_priceOfItem
		<< ", Serial Number: " << item.m_serialNumberOfItem
		<< ", Seller name: " << item.m_seller.getUserName() << endl;
	return os;
}

bool Item::setNameOfItem(const char* itemName)
{
	delete[] m_itemName;
	unsigned int name_len = strlen(itemName);
	if ((name_len < MAX_LEN_NAME) && (name_len >= MIN_LEN_NAME) && (CheckCharacters(itemName)))
	{
		m_itemName = new char[strlen(itemName) + 1];
		strcpy(m_itemName, itemName);
		return true;
	}
	else
		return false;
}

bool Item::CheckCharacters(const char* fieldName) const
{
	int i = 0;
	while (fieldName[i] != '\0')
	{
		if (isalpha(fieldName[i]) || isdigit(fieldName[i]) || fieldName[i] == ' ' || fieldName[i] == '-')
			i++;
		else
			return false;
	}
	return true;
}

bool Item::setCategoryOfItem(Item::eCategory categoryOfItem)
{
	int numOfCategory = (int)(categoryOfItem);

	if ((numOfCategory >= 0) && (numOfCategory <= 3))
	{
		m_categoryOfItem = categoryOfItem;
		return true;
	}
	return false;
}

bool Item::setPriceOfItem(int priceOfItem)
{
	if (priceOfItem >= MIN_PRICE && priceOfItem <= MAX_PRICE)
	{
		m_priceOfItem = priceOfItem;
		return true;
	}
	else
		return false;
}

//bool Item::setSeller(const Seller& seller)
//{
//	m_seller = seller;
//	return true;
//}

const char* Item::getNameOfItem() const
{
	return m_itemName;
}

Item::eCategory Item::getCategoryOfItem() const
{
	return m_categoryOfItem;
}

int Item::getPriceOfItem() const
{
	return m_priceOfItem;
}

unsigned int Item::getSerialNumberOfItem() const
{
	return m_serialNumberOfItem;
}

const Seller& Item::getSeller() const
{
	return m_seller;
}