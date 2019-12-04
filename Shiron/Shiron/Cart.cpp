#include "Cart.h"

Cart::Cart(unsigned int physSizeItems)
{
	setLogicSizeItems(INITIAL_LOGICAL_SIZE);
	setPhysSizeItems(physSizeItems);
	m_allItemsOfCart = new Item*[m_physSizeItems];
}

Cart::Cart(const Cart& other)
{
	setLogicSizeItems(other.m_logicSizeItems);
	setPhysSizeItems(other.m_physSizeItems);
	m_allItemsOfCart = new Item*[m_physSizeItems];
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		m_allItemsOfCart[i] = new Item(*(other.m_allItemsOfCart[i]));
	}
}

Cart::~Cart()
{
	delete[] m_allItemsOfCart;
}


void Cart::reallocItems()
{
	Item** newAllItems = new Item*[m_physSizeItems];
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		newAllItems[i] = new Item(*(m_allItemsOfCart[i]));
	}
	delete[]m_allItemsOfCart;
	m_allItemsOfCart = newAllItems;
}

bool Cart::addItemToCart(Item* item)
{
	if (m_logicSizeItems == m_physSizeItems)
	{
		m_physSizeItems *= 2;
		reallocItems();
	}
	m_allItemsOfCart[m_logicSizeItems++] = item;
	return true;
}

bool Cart::setLogicSizeItems(unsigned int logicSizeItems)
{
	if (logicSizeItems >= 0)
	{
		m_logicSizeItems = logicSizeItems;
		return true;
	}
	return false;
}

bool Cart::setPhysSizeItems(unsigned int physSizeItems)
{
	if (physSizeItems >= 1)
	{
		m_physSizeItems = physSizeItems;
		return true;
	}
	return false;
}

unsigned int Cart::getLogicSizeItems()
{
	return m_logicSizeItems;
}

