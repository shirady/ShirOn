#include "Cart.h"
#include "General.h" //For printCollection

//delete later
Cart::Cart()
{

}

Cart::~Cart()
{
	m_allItemsOfCart.clear();
}

bool Cart::operator>(const Cart& other)
{
	return(this->getTotalPriceOfCart() > other.getTotalPriceOfCart());
}

ostream& operator<<(ostream& os, const Cart& cart) //global function
{
	if(!(cart.m_allItemsOfCart.empty()))
	{
		os << "The cart's details" << endl;
		General::printCollection(cart.m_allItemsOfCart);
		os << "Total price of cart: " << cart.getTotalPriceOfCart() << endl;
	}
	else
		os << "cart is empty" << endl;

	return os;
}

list<const Item*> Cart::getAllItemsOfCart() const
{
	return m_allItemsOfCart;
}

int Cart::numberOfItemsInCart() const
{
	return m_allItemsOfCart.size();
}

bool Cart::checkEmptyCart() const
{
	return m_allItemsOfCart.empty();
}

bool Cart::addItemToCart(const Item* item)
{
	m_allItemsOfCart.push_back(item); //add a copy to the end of the list
	return true;
}

void Cart::removeItemFromCart(const Item* item)
{
	list<const Item*>::iterator itr = m_allItemsOfCart.begin();
	list<const Item*>::iterator itrEnd = m_allItemsOfCart.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr == item)
		{
			m_allItemsOfCart.erase(itr);
			return;
		}
	}
}

const Item* Cart::findSerialNumber(unsigned int serialNumber) const
{
	list<const Item*>::const_iterator itr = m_allItemsOfCart.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfCart.end(); ////const_iterator since the method is const
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
	list<const Item*>::const_iterator itr = m_allItemsOfCart.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfCart.end(); ////const_iterator since the method is const
	unsigned int totalPriceOfOrder = 0;

	for (; itr != itrEnd; ++itr)
		totalPriceOfOrder += (*itr)->getPriceOfItem();

	return totalPriceOfOrder;
}

bool Cart::checkIfItemExists(const Item* item) const
{
	list<const Item*>::const_iterator itr = m_allItemsOfCart.begin(); //const_iterator since the method is const
	list<const Item*>::const_iterator itrEnd = m_allItemsOfCart.end(); ////const_iterator since the method is const
	bool itemFound = false;

	for (; itr != itrEnd && !itemFound; ++itr)
	{
		if (item == (*itr))
			itemFound = true;
	}
	return itemFound;
}
