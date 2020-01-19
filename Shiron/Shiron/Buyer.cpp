#include "Buyer.h"

Buyer::Buyer(const string& userName, const string& password, const Address& address) : User(userName, password, address)
{
	m_cart = new Cart;
	m_currentOrder = new Order;
}

Buyer::~Buyer()
{
	delete m_cart;
	delete m_currentOrder;
	cleanOrderHistoryList();
}

bool Buyer::operator>(const Buyer& other)
{
	return(*(this->getCart()) > *(other.getCart()));
}

void Buyer::show() const
{
	User::show();
	showMe();
}

void Buyer::showMe() const
{
	cout << *m_currentOrder;
	cout << *m_cart;
	cout << "--------------" << endl;
}

void Buyer::cleanOrderHistoryList()
{
	list<const Order*>::iterator itr = m_ordersHistoryList.begin();
	list<const Order*>::iterator itrEnd = m_ordersHistoryList.end();
	for (; itr != itrEnd; ++itr)
		delete *itr; //frees the pointer of order inside the cell of list

	m_ordersHistoryList.clear();
}

Cart* Buyer::getCart() const
{
	return m_cart;
}

Order* Buyer::getCurrentOrder() const
{
	return m_currentOrder;
}

const list<const Order*>& Buyer::getOrdersHistoryList() const
{
	return m_ordersHistoryList;
}

void Buyer::addOrderToHistory()
{
	if (!m_currentOrder->getIfOrderIsOpen())
	{
		m_ordersHistoryList.push_back(m_currentOrder); //add a copy to the end of the list
		m_currentOrder = new Order;
	}
}

bool Buyer::checkIfSellerExistsInOrdersHistory(const Seller& seller) const
{
	list<const Order*>::const_iterator itr = m_ordersHistoryList.begin(); //const_iterator since the method is const
	list<const Order*>::const_iterator itrEnd = m_ordersHistoryList.end(); ////const_iterator since the method is const
	bool foundSeller = false;

	for (; itr != itrEnd && !foundSeller; ++itr)
		if ((*itr)->checkIfSellerIsInAOrder(seller))
			foundSeller = true;
	
	return foundSeller;
}
