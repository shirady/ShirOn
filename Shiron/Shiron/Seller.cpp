#include "Seller.h"

Seller::Seller(const User& user, unsigned int physSizeItems) : m_user(user)
{
	setLogicSizeItems(INITIAL_LOGICAL_SIZE);
	setPhysSizeItems(physSizeItems);
	m_allItems = new Item*[m_physSizeItems];
}

Seller::Seller(const Seller& other) : m_user(other.m_user)
{

}

Seller::~Seller()
{

}

User& Seller::getUser()
{
	return m_user;
}

void Seller::reallocItems()
{
	Item** newAllItems = new Item*[m_physSizeItems];
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		newAllItems[i] = new Item(*(m_allItems[i]));
	}
	delete[]m_allItems;
	m_allItems = newAllItems;
}

bool Seller::addItemToSeller(Item* item)
{
	if (m_logicSizeItems == m_physSizeItems)
	{
		m_physSizeItems *= 2;
		reallocItems();
	}
	m_allItems[m_logicSizeItems++] = item;
	return true;
}

bool Seller::setLogicSizeItems(unsigned int logicSizeItems)
{
	if (logicSizeItems >= 0)
	{
		m_logicSizeItems = logicSizeItems;
		return true;
	}
	return false;
}

bool Seller::setPhysSizeItems(unsigned int physSizeItems)
{
	if (physSizeItems >= 1)
	{
		m_physSizeItems = physSizeItems;
		return true;
	}
	return false;
}


unsigned int Seller::ShowItemsOfSeller(const char* name) const
{
	unsigned int counter = 0;
	for (unsigned int i = 0; i < m_logicSizeItems ; i++)
	{
		if (strcmp(m_allItems[i]->getNameOfItem(), name) == 0)
		{
			m_allItems[i]->showItem();
			counter++;
		}
	}
	return counter;
}