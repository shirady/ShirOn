#include "Seller.h"

Seller::Seller(const string& userName, const string& password, const Address& address): User(userName, password, address)
{

}

Seller::~Seller()
{
	cleanItemsList();
}
void Seller::cleanItemsList()
{
	list<Item*>::iterator itr = m_allItemsList.begin();
	list<Item*>::iterator itrEnd = m_allItemsList.end();
	for (; itr != itrEnd; ++itr)
		delete *itr; //frees the pointer of item inside the cell of list

	m_allItemsList.clear();
}

void Seller::show() const
{
	User::show();
	showMe();
}

void Seller::showMe() const
{
	if (m_allFeedbacks.getLogicSize() > 0)
	{
		cout << "The feedbacks are:" << endl;
		cout << m_allFeedbacks;
	}
	else
		cout << this->getUserName() << " doesn't have feedbacks" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}

void Seller::showItemsOfSeller(const string& itemName) const
{
	list<Item*>::const_iterator itr = m_allItemsList.begin(); //const_iterator since the method is const
	list<Item*>::const_iterator itrEnd = m_allItemsList.end(); //const_iterator since the method is const

	for (; itr != itrEnd; ++itr)
		if ((*itr)->getNameOfItem().compare(itemName) == 0)
			cout << *(*itr);
}

unsigned int Seller::numberOfItemsInSeller() const
{
	return m_allItemsList.size();
}

const list<Item*>& Seller::getAllItemsList() const
{
	return m_allItemsList;
}

void Seller::addItemToSeller(Item* item)
{
	m_allItemsList.push_back(item);
}

void Seller::addFeedbackForSeller(const Feedback* feedback)
{
	m_allFeedbacks += feedback;
}

Item* Seller::findSerialNumber(int serialNumber) const
{
	Item* foundItem = nullptr;
	bool ItemExists = false;
	list<Item*>::const_iterator itr = m_allItemsList.begin(); //const_iterator since the method is const
	list<Item*>::const_iterator itrEnd = m_allItemsList.end(); //const_iterator since the method is const

	for (; itr != itrEnd && !ItemExists; ++itr)
	{
		if ((*itr)->getSerialNumberOfItem() == serialNumber)
		{
			ItemExists = true;
			foundItem = *itr;
		}
	}
	return foundItem;
}

unsigned int Seller::countItemsOfSeller(const string& itemName) const
{
	list<Item*>::const_iterator itr = m_allItemsList.begin(); //const_iterator since the method is const
	list<Item*>::const_iterator itrEnd = m_allItemsList.end(); //const_iterator since the method is const
	unsigned int counter = 0;

	for (; itr != itrEnd; ++itr)
		if (((*itr)->getNameOfItem().compare(itemName) == 0))
			counter++;

	return counter;
}

bool Seller::checkIfItemExistInASeller(const string& itemName) const
{
	list<Item*>::const_iterator itr = m_allItemsList.begin(); //const_iterator since the method is const
	list<Item*>::const_iterator itrEnd = m_allItemsList.end(); //const_iterator since the method is const
	bool isExist = false;

	for (; itr != itrEnd && !isExist; ++itr)
		if (((*itr)->getNameOfItem().compare(itemName) == 0))
			isExist = true;

	return isExist;
}
