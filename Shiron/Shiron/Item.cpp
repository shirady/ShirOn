#include "item.h"
#include "System.h"

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

//bool Item::setSerialNumberOfItem(int serialNumberOfItem)
//{
//	if (serialNumberOfItem >= 0)
//	{
//		m_serialNumberOfItem = serialNumberOfItem;
//		return true;
//	}
//	return false;
//}

const char* Item::getNameOfItem() const
{
	return m_nameOfItem;

}

Item::eCategory Item::getCategoryOfItem() const
{
	return m_categoryOfItem;
}

int Item::getPriceOfItem() const
{
	return m_priceOfItem;
}

int Item::getSerialNumberOfItem() const
{
	return m_serialNumberOfItem;
}

Item::Item(const char* nameOfItem, Item::eCategory categoryOfItem, int priceOfItem, int serialNumberOfItem)
{
	setNameOfItem(nameOfItem);
	setCategoryOfItem(categoryOfItem);
	setPriceOfItem(priceOfItem);
	m_serialNumberOfItem = serialNumberOfItem;
	//setSerialNumberOfItem(serialNumberOfItem);
}

Item::~Item()
{
	delete[] m_nameOfItem;
}





