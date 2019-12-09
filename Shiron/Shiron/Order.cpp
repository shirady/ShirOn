#include "Order.h"

Order::Order(unsigned int physSizeItems)
{
	setLogicSizeItems(INITIAL_LOGICAL_SIZE);
	setPhysSizeItems(physSizeItems);
	m_allItemsOfOrder = new const Item*[m_physSizeItems];
	setOpenOrder(INITIAL_OPEN_ORDER);
}

Order::~Order()
{
	delete[] m_allItemsOfOrder;
}

bool Order::setLogicSizeItems(unsigned int logicSizeItems)
{
	if (logicSizeItems >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeItems = logicSizeItems;
		return true;
	}
	return false;
}

bool Order::setPhysSizeItems(unsigned int physSizeItems)
{
	if (physSizeItems >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeItems = physSizeItems;
		return true;
	}
	return false;
}

bool Order::setOpenOrder(bool openOrder)
{
	m_openOrder = openOrder;
	return true;
}

void Order::closeOrder(unsigned int totalPriceOfOrder)
{
	setOpenOrder(false);
	setTotalPriceOfOrder(totalPriceOfOrder);
}

bool Order::setTotalPriceOfOrder(unsigned int totalPriceOfOrder)
{
	m_totalPriceOfOrder = totalPriceOfOrder;
	return true;
}

void Order::reallocItems()
{
	const Item** newAllItems = new const Item*[m_physSizeItems];
	unsigned int newArrSize = 0;
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		if (m_allItemsOfOrder[i] != nullptr)
			newAllItems[newArrSize++] = m_allItemsOfOrder[i];
	}
	if (newArrSize < m_logicSizeItems)
		setLogicSizeItems(newArrSize);
	delete[]m_allItemsOfOrder;
	m_allItemsOfOrder = newAllItems;
}

bool Order::addItemToOrder(const Item* item)
{
	if (m_logicSizeItems == m_physSizeItems)
	{
		m_physSizeItems *= 2;
		reallocItems();
	}
	m_allItemsOfOrder[m_logicSizeItems++] = item;
	return true;
}

void Order::removeItemFromOrder(const Item* item)
{
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		if (m_allItemsOfOrder[i] == item)
		{
			m_allItemsOfOrder[i] = nullptr;
			return;
		}
	}
}

unsigned int Order::getLogicSizeItems() const
{
	return m_logicSizeItems;
}

const Item** Order::getAllItemsOfOrder() const
{
	return m_allItemsOfOrder;
}

unsigned int Order::getTotalPriceOfOrder() const
{
	unsigned int totalPriceOfOrder = 0;
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
		totalPriceOfOrder += m_allItemsOfOrder[i]->getPriceOfItem();
	
	return totalPriceOfOrder;
}

bool Order::getIfOrderIsOpen() const
{
	return m_openOrder;
}

const Item* Order::findSerialNumber(unsigned int serialNumber) const
{
	const Item* foundItem = nullptr;
	bool ItemExists = false;
	for (unsigned int i = 0; i < m_logicSizeItems && !ItemExists; i++)
	{
		if (m_allItemsOfOrder[i]->getSerialNumberOfItem() == serialNumber)
		{
			ItemExists = true;
			foundItem = m_allItemsOfOrder[i];
		}
	}
	return foundItem;
}

bool Order::checkIfSellerIsInAOrder(Seller* seller) const
{
	bool sellerExists = false;
	for (unsigned int i = 0; i < m_logicSizeItems && !sellerExists; i++)
	{
		if (m_allItemsOfOrder[i]->getSeller() == seller)
			sellerExists = true;
	}
	return sellerExists;
}