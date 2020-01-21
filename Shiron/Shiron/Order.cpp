#include "Order.h"
#include "Seller.h"
#include "General.h" //For printCollection
#include "Cart.h" //For the method chooseAllItemsFromCart

Order::Order(unsigned int physSizeItems)
{
	setOpenOrder(INITIAL_OPEN_ORDER);
}

//Order::~Order()
//{
//
//}

ostream& operator<<(ostream& os, const Order& order) //global function
{
	if (!order.m_allItemsOfOrderList.empty())
	{
		os << "The order's details" << endl;
		General::printCollection(order.m_allItemsOfOrderList);
		//os << "Total price of order: " << order.getTotalPriceOfOrder() << endl;
		os << "Total price of order: " << General::getTotalPrice(order.m_allItemsOfOrderList) << endl;
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

const list<const Item*>& Order::getAllItemsOfOrderList() const
{
	return m_allItemsOfOrderList;
}

//unsigned int Order::getTotalPriceOfOrder() const
//{
//	list<const Item*>::const_iterator itr = m_allItemsOfOrderList.begin(); //const_iterator since the method is const
//	list<const Item*>::const_iterator itrEnd = m_allItemsOfOrderList.end(); //const_iterator since the method is const
//	unsigned int totalPriceOfOrder = 0;
//
//	for (; itr != itrEnd; ++itr)
//		totalPriceOfOrder += (*itr)->getPriceOfItem();
//	
//	return totalPriceOfOrder;
//}

bool Order::getIfOrderIsOpen() const
{
	return m_openOrder;
}

unsigned int Order::numberOfItemsInOrder() const
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
	list<const Item*>::const_iterator itrEnd = m_allItemsOfOrderList.end(); //const_iterator since the method is const
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
	list<const Item*>::const_iterator itrEnd = m_allItemsOfOrderList.end(); //const_iterator since the method is const
	bool sellerExists = false;

	for (; itr != itrEnd && !sellerExists; ++itr)
		if ((*itr)->getSeller().getUserName().compare(seller.getUserName()) == 0)
			sellerExists = true;
	
	return sellerExists;
}

bool Order::checkIfItemExists(const Item* item) const
{
	list<const Item*>::const_iterator itr = m_allItemsOfOrderList.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfOrderList.end(); //const_iterator since the method is const
	bool itemFound = false;

	for (; itr != itrEnd && !itemFound; ++itr)
	{
		if (item == (*itr))
			itemFound = true;
	}
	return itemFound;
}

void Order::chooseAllItemsFromCart(Cart* cart)
{
	list<const Item*>::const_iterator itr = cart->getAllItemsOfCart().begin();
	list<const Item*>::const_iterator itrEnd = cart->getAllItemsOfCart().end();

	if (this->checkEmptyOrder()) //in case the order is empty we put all the items in the order
		for (; itr != itrEnd; ++itr)
			this->addItemToOrder(*itr);
	else
		for (; itr != itrEnd; ++itr)
			if (!this->checkIfItemExists(*itr))
				this->addItemToOrder(*itr);
}