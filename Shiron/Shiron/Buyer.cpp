#include "Buyer.h"

Buyer::Buyer(const User& user, unsigned int physSizeOrders): m_user(user)
{
	m_Cart = new Cart;
	m_currentOrder = new Order;

	setLogicSizeOrders(INITIAL_LOGICAL_SIZE);
	setPhysSizeOrders(physSizeOrders);
	m_OrdersHistory = new Order*[m_physSizeOrders];
}
/*
Buyer::Buyer(const Buyer& other): m_user(other.m_user)
{
	m_Cart = new Cart(*(other.getCart()));
	m_currentOrder = new Order(*(other.getCurrentOrder()));

	setLogicSizeOrders(other.m_logicSizeOrders);
	setPhysSizeOrders(other.m_physSizeOrders);
	m_OrdersHistory = new Order*[m_physSizeOrders];
	for (unsigned int i = 0; i < m_logicSizeOrders; i++)
	{
		m_OrdersHistory[i] = new Order(*(other.m_OrdersHistory[i]));
	}
}*/

Buyer::~Buyer()
{
	delete m_Cart;
	delete m_currentOrder;
	cleanOrderHistoryArray();
}

void Buyer::cleanOrderHistoryArray()
{
	for (unsigned int i = 0; i < m_logicSizeOrders; ++i)
		delete m_OrdersHistory[i];
	delete[] m_OrdersHistory;
}

bool Buyer::setLogicSizeOrders(unsigned int logicSizeOrders)
{
	if (logicSizeOrders >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeOrders = logicSizeOrders;
		return true;
	}
	return false;
}

bool Buyer::setPhysSizeOrders(unsigned int physSizeOrders)
{
	if (physSizeOrders >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeOrders = physSizeOrders;
		return true;
	}
	return false;
}

User& Buyer::getUser() 
{
	return m_user;
}

Cart* Buyer::getCart() const
{
	return m_Cart;
}

Order* Buyer::getCurrentOrder() const
{
	return m_currentOrder;
}

unsigned int Buyer::getLogicSizeOrders() const
{
	return m_logicSizeOrders;
}

Order** Buyer::getAllOrders()
{
	return m_OrdersHistory;
}

void Buyer::reallocOrders()
{
	Order** newAllOrders = new Order*[m_physSizeOrders];
	for (unsigned int i = 0; i < m_logicSizeOrders; i++)
	{
		newAllOrders[i] = m_OrdersHistory[i]; //changed from new Order(*(m_allOrders[i]))
	}
	delete[]m_OrdersHistory;
	m_OrdersHistory = newAllOrders;
}

void Buyer::addOrderToHistory()
{
	if (!m_currentOrder->getIfOrderIsOpen())
	{
		if (m_logicSizeOrders == m_physSizeOrders)
		{
			m_physSizeOrders *= 2;
			reallocOrders();
		}
		m_OrdersHistory[m_logicSizeOrders++] = m_currentOrder;
		m_currentOrder = new Order;
	}
}

const Seller* Buyer::findSellerInOrdersHistory(const char* sellerName) const
{
	const Seller* foundSeller = nullptr;
	bool sellerExists = false;

	for (unsigned int i = 0; i < m_logicSizeOrders && !sellerExists; i++)
	{
		const Seller* seller = m_OrdersHistory[i]->findSellerInOrder(sellerName);
		if (seller != nullptr)
		{
			foundSeller = seller;
			sellerExists = true;
		}
	}
	return foundSeller;
}