#include "Cart.h"

Cart::Cart(unsigned int physSizeItems)
{
	setLogicSizeItems(INITIAL_LOGICAL_SIZE);
	setPhysSizeItems(physSizeItems);
	m_allItemsOfCart = new const Item*[m_physSizeItems];
}

Cart::~Cart()
{
	delete[] m_allItemsOfCart;
}

bool Cart::setLogicSizeItems(unsigned int logicSizeItems)
{
	if (logicSizeItems >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeItems = logicSizeItems;
		return true;
	}
	return false;
}

bool Cart::setPhysSizeItems(unsigned int physSizeItems)
{
	if (physSizeItems >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeItems = physSizeItems;
		return true;
	}
	return false;
}

unsigned int Cart::getLogicSizeItems() const
{
	return m_logicSizeItems;
}

const Item** Cart::getAllItemsOfCart() const
{
	return m_allItemsOfCart;
}

void Cart::reallocItems()
{
	const Item** newAllItems = new const Item*[m_physSizeItems];
	unsigned int newArrSize = 0;

	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		if (m_allItemsOfCart[i] != nullptr)
		{
			newAllItems[newArrSize++] = m_allItemsOfCart[i];
		}
	}
	if (newArrSize < m_logicSizeItems)
		setLogicSizeItems(newArrSize);
	delete[]m_allItemsOfCart;
	m_allItemsOfCart = newAllItems;
}

bool Cart::addItemToCart(const Item* item)
{
	if (m_logicSizeItems == m_physSizeItems)
	{
		m_physSizeItems *= 2;
		reallocItems();
	}
	m_allItemsOfCart[m_logicSizeItems++] = item;
	return true;
}

void Cart::removeItemFromCart(const Item* item)
{
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		if (m_allItemsOfCart[i] == item)
		{
			m_allItemsOfCart[i] = nullptr;
			return;
		}
	}
}

const Item* Cart::findSerialNumber(unsigned int serialNumber) const
{
	const Item* foundItem = nullptr;
	bool ItemExists = false;
	for (unsigned int i = 0; i < m_logicSizeItems && !ItemExists; i++)
	{
		if (m_allItemsOfCart[i]->getSerialNumberOfItem() == serialNumber)
		{
			ItemExists = true;
			foundItem = m_allItemsOfCart[i];
		}
	}
	return foundItem;
}