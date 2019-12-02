#include "Basket.h"

Basket::Basket(unsigned int physSizeItems)
{
	setLogicSizeItems(INITIAL_LOGICAL_SIZE);
	setPhysSizeItems(physSizeItems);
	m_allItemsOfBasket = new Item*[m_physSizeItems];
}

Basket::Basket(const Basket& other)
{
	setLogicSizeItems(other.m_logicSizeItems);
	setPhysSizeItems(other.m_physSizeItems);
	m_allItemsOfBasket = new Item*[m_physSizeItems];
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		m_allItemsOfBasket[i] = new Item(*(other.m_allItemsOfBasket[i]));
	}
}

Basket::~Basket()
{
	delete[] m_allItemsOfBasket;
}


void Basket::reallocItems()
{
	Item** newAllItems = new Item*[m_physSizeItems];
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		newAllItems[i] = new Item(*(m_allItemsOfBasket[i]));
	}
	delete[]m_allItemsOfBasket;
	m_allItemsOfBasket = newAllItems;
}

bool Basket::addItemToBasket(Item* item)
{
	if (m_logicSizeItems == m_physSizeItems)
	{
		m_physSizeItems *= 2;
		reallocItems();
	}
	m_allItemsOfBasket[m_logicSizeItems++] = item;
	return true;
}

bool Basket::setLogicSizeItems(unsigned int logicSizeItems)
{
	if (logicSizeItems >= 0)
	{
		m_logicSizeItems = logicSizeItems;
		return true;
	}
	return false;
}

bool Basket::setPhysSizeItems(unsigned int physSizeItems)
{
	if (physSizeItems >= 1)
	{
		m_physSizeItems = physSizeItems;
		return true;
	}
	return false;
}

unsigned int Basket::getLogicSizeItems()
{
	return m_logicSizeItems;
}

