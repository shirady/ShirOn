#include "Item.h"

bool Item::setNameOfItem(const char* nameOfItem)
{
	delete[] m_nameOfItem; //will not run unless m_userName was allocated
	unsigned int name_len = strlen(m_nameOfItem);

	if (name_len < MAX_LEN_NAME)
	{
		m_nameOfItem = new char[name_len + 1]; //check allocation is missing
		strcpy(m_nameOfItem, nameOfItem);
		return true;
	}
	else
		return false;
}

bool Item::setCategoryOfItem(eCategory categoryOfItem)
{
	if (categoryOfItem >=0 && categoryOfItem <= 3) //is it O.K. to check it that way?
	{
		m_categoryOfItem = categoryOfItem;
		return true;
	}
	else
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

bool Item::setSerialNumberOfItem(int serialNumberOfItem)
{
	if (serialNumberOfItem >= MIN_SERIAL && MAX_SERIAL <= MAX_SERIAL)
	{
		m_serialNumberOfItem = serialNumberOfItem;
		return true;
	}
	else
		return false;
}

const char* Item::getNameOfItem()
{
	return m_nameOfItem;
}

Item::eCategory Item::getCategoryOfItem()
{
	return m_categoryOfItem;
}

int Item::getPriceOfItem()
{
	return m_priceOfItem;
}

int Item::getSerialNumberOfItem()
{
	return m_serialNumberOfItem;
}

Item::Item(const char* nameOfItem, eCategory categoryOfItem, int priceOfItem, int serialNumberOfIem)
{
	setNameOfItem(nameOfItem);
	setCategoryOfItem(categoryOfItem);
	setPriceOfItem(priceOfItem);
	setSerialNumberOfItem(serialNumberOfIem);
}

//Item::Item(const Item& other)
//{
//	m_categoryOfItem = other.m_categoryOfItem;
//	m_priceOfItem = other.m_priceOfItem;
//	m_serialNumberOfItem = other.m_serialNumberOfItem;
//	m_nameOfItem = new char[strlen(other.m_nameOfItem) + 1]; //check allocation
//	strcpy(m_nameOfItem, other.m_nameOfItem);
//}

//Item::Item(Item&& other)
//{
//	m_categoryOfItem = other.m_categoryOfItem;
//	m_priceOfItem = other.m_priceOfItem;
//	m_serialNumberOfItem = other.m_serialNumberOfItem;
//	m_nameOfItem = other.m_nameOfItem;
//	other.m_nameOfItem = nullptr;
//}

Item::~Item()
{
	delete[] m_nameOfItem;
}