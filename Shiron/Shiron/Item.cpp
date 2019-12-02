#include "item.h"

unsigned int Item::m_serialNumberCounter = 0;

bool Item::setNameOfItem(const char* nameOfItem)
{
	//delete[] m_nameOfItem; //will not run unless m_userName was allocated
	unsigned int name_len = strlen(nameOfItem);
	if ((name_len < MAX_LEN_NAME) && (CheckCharacters(nameOfItem)))
	{
		m_nameOfItem = new char[strlen(nameOfItem) + 1]; //check allocation is missing
		strcpy(m_nameOfItem, nameOfItem);
		return true;
	}
	else
		return false;
}

bool Item::CheckCharacters(const char* fieldName)
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

bool Item::setPriceOfItem(unsigned int priceOfItem)
{
	if (priceOfItem >= MIN_PRICE && priceOfItem <= MAX_PRICE)
	{
		m_priceOfItem = priceOfItem;
		return true;
	}
	else
		return false;
}

const char* Item::getNameOfItem() const
{
	return m_nameOfItem;

}

Item::eCategory Item::getCategoryOfItem() const
{
	return m_categoryOfItem;
}

unsigned int Item::getPriceOfItem() const
{
	return m_priceOfItem;
}

unsigned int Item::getSerialNumberOfItem() const
{
	return m_serialNumberOfItem;
}

Item::Item(const char* nameOfItem, Item::eCategory categoryOfItem, unsigned int priceOfItem)
{
	setNameOfItem(nameOfItem);
	setCategoryOfItem(categoryOfItem);
	setPriceOfItem(priceOfItem);
	m_serialNumberOfItem = ++m_serialNumberCounter;
}

Item::Item(const Item& other)
{
	setNameOfItem(other.m_nameOfItem);
	setCategoryOfItem(other.m_categoryOfItem);
	setPriceOfItem(other.m_priceOfItem);
	m_serialNumberOfItem = other.m_serialNumberOfItem; //should it be the same number??
}

Item::~Item()
{
	delete[] m_nameOfItem;
}

void Item::showItem() const
{
	cout << "Item name: " << m_nameOfItem
		<< ", Category: " << category[m_categoryOfItem]
		<< ", Price: " << m_priceOfItem
		<< ", Serial Number: " << m_serialNumberOfItem << endl;
}