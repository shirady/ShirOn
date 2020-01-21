#include "Cart.h"
#include "General.h" //For printCollection
#include "Order.h" //For RemoveItemByOrder

Cart::Cart()
{

}

bool Cart::operator>(const Cart& other)
{
	return(General::getTotalPrice(m_allItemsOfCartList) > General::getTotalPrice(other.m_allItemsOfCartList));
}

ostream& operator<<(ostream& os, const Cart& cart) //global function
{
	if(!(cart.m_allItemsOfCartList.empty()))
	{
		os << "The cart's details" << endl;
		General::printCollection(cart.m_allItemsOfCartList);
		os << "Total price of cart: " << General::getTotalPrice(cart.m_allItemsOfCartList) << endl;
	}
	else
		os << "cart is empty" << endl;

	return os;
}

const list<const Item*>& Cart::getAllItemsOfCart() const
{
	return m_allItemsOfCartList;
}

unsigned int Cart::numberOfItemsInCart() const
{
	return m_allItemsOfCartList.size();
}

bool Cart::checkEmptyCart() const
{
	return m_allItemsOfCartList.empty();
}

void Cart::addItemToCart(const Item* item)
{
	m_allItemsOfCartList.push_back(item); //add a copy to the end of the list
}

void Cart::removeItemFromCart(const Item* item)
{
	list<const Item*>::iterator itr = m_allItemsOfCartList.begin();
	list<const Item*>::iterator itrEnd = m_allItemsOfCartList.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr == item)
		{
			m_allItemsOfCartList.erase(itr);
			return;
		}
	}
}

const Item* Cart::findSerialNumber(unsigned int serialNumber) const
{
	list<const Item*>::const_iterator itr = m_allItemsOfCartList.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfCartList.end(); //const_iterator since the method is const
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

unsigned int Cart::getTotalPriceOfCart() const
{
	return (General::getTotalPrice(m_allItemsOfCartList));
}

bool Cart::checkIfItemExists(const Item* item) const
{
	list<const Item*>::const_iterator itr = m_allItemsOfCartList.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfCartList.end(); //const_iterator since the method is const
	bool itemFound = false;

	for (; itr != itrEnd && !itemFound; ++itr)
	{
		if (item == (*itr))
			itemFound = true;
	}
	return itemFound;
}

void Cart::RemoveItemByOrder(Order* order)
{
	list<const Item*>::const_iterator itr = m_allItemsOfCartList.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfCartList.end(); //const_iterator since the method is const

	while(itr != itrEnd)
	{
		if (order->checkIfItemExists(*itr))
		{
			list<const Item*>::const_iterator itrTmp = ++itr;
			--itr;
			this->removeItemFromCart(*itr);
			itr = itrTmp;
		}
		else
			++itr;
	}
}
