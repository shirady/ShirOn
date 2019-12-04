#include "Order.h"

Order::Order(unsigned int LogicSizeItemsOfCart)
{
	setLogicSizeItems(INITIAL_LOGICAL_SIZE);
	setPhysSizeItems(LogicSizeItemsOfCart); //LogicSizeItemsOfCart is the physicSize of the order
	m_allItemsOfOrder = new Item*[m_physSizeItems];
	setOpenOrder(INITIAL_OPEN_ORDER);
	setOpenPayment(INITIAL_OPEN_PAYMENT);
}

Order::Order(const Order& other)
{
	setOpenOrder(other.m_openOrder);
	setOpenPayment(other.m_openPayment);
	setLogicSizeItems(other.m_logicSizeItems);
	setPhysSizeItems(other.m_physSizeItems);
	m_allItemsOfOrder = new Item*[m_physSizeItems];
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		m_allItemsOfOrder[i] = new Item(*(other.m_allItemsOfOrder[i]));
	}
}

Order::~Order()
{
	delete[] m_allItemsOfOrder;
}

bool Order::setLogicSizeItems(unsigned int logicSizeItems)
{
	if (logicSizeItems >= 0)
	{
		m_logicSizeItems = logicSizeItems;
		return true;
	}
	return false;
}

bool Order::setPhysSizeItems(unsigned int physSizeItems)
{
	if (physSizeItems >= 1)
	{
		m_physSizeItems = physSizeItems;
		return true;
	}
	return false;
}

bool Order::setOpenOrder(bool openOrder)
{
	m_openOrder = openOrder;
}

bool Order::setOpenPayment(bool openPayment)
{
	m_openPayment = openPayment;
}

void Order::reallocItems()
{
	Item** newAllItems = new Item*[m_physSizeItems];

	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		newAllItems[i] = m_allItemsOfOrder[i];
	}
	delete[]m_allItemsOfOrder;
	m_allItemsOfOrder = newAllItems;
}

bool Order::addItemToOrder(Item* item)
{
	if (m_logicSizeItems == m_physSizeItems)
	{
		m_physSizeItems *= 2;
		reallocItems();
	}
	m_allItemsOfOrder[m_logicSizeItems++] = item;
	return true;
}
