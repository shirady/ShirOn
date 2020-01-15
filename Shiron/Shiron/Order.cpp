#include "Order.h"
#include "Seller.h"
#include "General.h" //For printCollection

Order::Order(unsigned int physSizeItems)
{
	//(INITIAL_LOGICAL_SIZE);
	//setPhysSizeItems(physSizeItems);
	//m_allItemsOfOrder = new const Item*[m_physSizeItems];
	setOpenOrder(INITIAL_OPEN_ORDER);
}

Order::~Order()
{
	m_allItemsOfOrderList.clear();
	//delete[] m_allItemsOfOrder;
}

ostream& operator<<(ostream& os, const Order& order) //global function
{
	if (!order.m_allItemsOfOrderList.empty())
	{
		os << "The order's details" << endl;
		General::printCollection(order.m_allItemsOfOrderList);
		os << "Total price of order: " << order.getTotalPriceOfOrder() << endl;
	}
	else
		os << "order is empty" << endl;

	return os;
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

bool Order::addItemToOrder(const Item* item)
{
	m_allItemsOfOrderList.push_back(item); //add a copy to the end of the list
	return true;
}

void Order::removeItemFromOrder(const Item* item)
{
	list<const Item*>::iterator itr = m_allItemsOfOrderList.begin();
	list<const Item*>::iterator itrEnd = m_allItemsOfOrderList.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr == item)
		{
			m_allItemsOfOrderList.erase(itr);
			return;
		}
	}
}

list<const Item*> Order::getAllItemsOfOrderList() const
{
	return m_allItemsOfOrderList;
}

unsigned int Order::getTotalPriceOfOrder() const
{
	list<const Item*>::const_iterator itr = m_allItemsOfOrderList.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfOrderList.end(); ////const_iterator since the method is const
	unsigned int totalPriceOfOrder = 0;

	for (; itr != itrEnd; ++itr)
		totalPriceOfOrder += (*itr)->getPriceOfItem();
	
	return totalPriceOfOrder;
}

bool Order::getIfOrderIsOpen() const
{
	return m_openOrder;
}

int Order::numberOfItemsInOrder() const
{
	return m_allItemsOfOrderList.size();
}

bool Order::checkEmptyOrder() const
{
	return m_allItemsOfOrderList.empty();
}

const Item* Order::findSerialNumber(unsigned int serialNumber) const
{
	list<const Item*>::const_iterator itr = m_allItemsOfOrderList.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfOrderList.end(); ////const_iterator since the method is const
	const Item* foundItem = nullptr;
	bool ItemExists = false;

	for (; itr != itrEnd && !ItemExists; ++itr)
	{
		if ((*itr)->getSerialNumberOfItem() == serialNumber)
		{
			ItemExists = true;
			foundItem = (*itr);
		}
	}
	return foundItem;
}

bool Order::checkIfSellerIsInAOrder(const Seller& seller) const
{
	list<const Item*>::const_iterator itr = m_allItemsOfOrderList.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfOrderList.end(); ////const_iterator since the method is const
	bool sellerExists = false;

	for (; itr != itrEnd && !sellerExists; ++itr)
	{
		if (strcmp((*itr)->getSeller().getUserName(), seller.getUserName()) == 0)
			sellerExists = true;
	}
	return sellerExists;
}

bool Order::checkIfItemExists(const Item* item) const
{
	list<const Item*>::const_iterator itr = m_allItemsOfOrderList.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfOrderList.end(); ////const_iterator since the method is const
	bool itemFound = false;

	for (; itr != itrEnd && !itemFound; ++itr)
	{
		if (item == (*itr))
			itemFound = true;
	}
	return itemFound;
}
