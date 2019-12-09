#include "Seller.h"

Seller::Seller(const User& user, unsigned int physSizeItems, unsigned int physSizeFeedbacks) : m_user(user)
{
	setLogicSizeItems(INITIAL_LOGICAL_SIZE);
	setPhysSizeItems(physSizeItems);
	m_allItems = new Item*[m_physSizeItems];

	setLogicSizeFeedbacks(INITIAL_LOGICAL_SIZE);
	setPhysSizeFeedbacks(physSizeFeedbacks);
	m_allFeedbacks = new Feedback*[m_physSizeFeedbacks];
}

/*Seller::Seller(const Seller& other) : m_user(other.m_user)
{
	setLogicSizeItems(other.m_logicSizeItems);
	setPhysSizeItems(other.m_physSizeItems);
	m_allItems = new Item*[m_physSizeItems];
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		m_allItems[i] = new Item(*(other.m_allItems[i]));
	}

	setLogicSizeFeedbacks(other.m_logicSizeFeedbacks);
	setPhysSizeFeedbacks(other.m_physSizeFeedbacks);
	m_allFeedbacks = new Feedback*[m_physSizeFeedbacks];
	for (unsigned int i = 0; i < m_logicSizeFeedbacks; i++)
	{
		m_allFeedbacks[i] = new Feedback(*(other.m_allFeedbacks[i]));
	}
}*/

Seller::~Seller()
{
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
		delete m_allItems[i];

	delete[] m_allItems;
}

User& Seller::getUser()
{
	return m_user;
}

void Seller::reallocItems()
{
	Item** newAllItems = new Item*[m_physSizeItems];
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		newAllItems[i] = m_allItems[i];
	}
	delete[]m_allItems;
	m_allItems = newAllItems;
}

bool Seller::addItemToSeller(Item* item)
{
	if (m_logicSizeItems == m_physSizeItems)
	{
		m_physSizeItems *= 2;
		reallocItems();
	}
	m_allItems[m_logicSizeItems++] = item;
	return true;
}

bool Seller::setLogicSizeItems(unsigned int logicSizeItems)
{
	if (logicSizeItems >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeItems = logicSizeItems;
		return true;
	}
	return false;
}

bool Seller::setPhysSizeItems(unsigned int physSizeItems)
{
	if (physSizeItems >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeItems = physSizeItems;
		return true;
	}
	return false;
}


void Seller::reallocFeedbacks()
{
	Feedback** newAllFeedbacks = new Feedback*[m_physSizeFeedbacks];
	for (unsigned int i = 0; i < m_logicSizeFeedbacks; i++)
	{
		newAllFeedbacks[i] = m_allFeedbacks[i];
	}
	delete[]m_allFeedbacks;
	m_allFeedbacks = newAllFeedbacks;
}

bool Seller::addFeedbackToSeller(Feedback* feedback)
{
	if (m_logicSizeFeedbacks == m_physSizeFeedbacks)
	{
		m_physSizeFeedbacks *= 2;
		reallocFeedbacks();
	}
	m_allFeedbacks[m_logicSizeFeedbacks++] = feedback;
	return true;
}

bool Seller::setLogicSizeFeedbacks(unsigned int logicSizeFeedbacks)
{
	if (logicSizeFeedbacks >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeFeedbacks = logicSizeFeedbacks;
		return true;
	}
	return false;
}

bool Seller::setPhysSizeFeedbacks(unsigned int physSizeFeedbacks)
{
	if (physSizeFeedbacks >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeFeedbacks = physSizeFeedbacks;
		return true;
	}
	return false;
}

unsigned int Seller::getLogicSizeFeedbacks() const
{
	return m_logicSizeFeedbacks;
}

Feedback** Seller::getAllFeedbacks() const
{
	return m_allFeedbacks;
}



unsigned int Seller::getLogicSizeItems() const
{
	return m_logicSizeItems;
}

Item** Seller::getAllItems() const
{
	return m_allItems;
}


//unsigned int Seller::ShowItemsOfSeller(const char* name) const
//{
//	unsigned int counter = 0;
//	for (unsigned int i = 0; i < m_logicSizeItems ; i++)
//	{
//		if (strcmp(m_allItems[i]->getNameOfItem(), name) == 0)
//		{
//			m_allItems[i]->showItem();
//			counter++;
//		}
//	}
//	return counter;
//}


Item* Seller::findSerialNumber(int serialNumber)
{
	Item* foundItem = nullptr;
	bool ItemExists = false;
	for (unsigned int i = 0; i < m_logicSizeItems && !ItemExists; i++)
	{
		if (m_allItems[i]->getSerialNumberOfItem() == serialNumber)
		{
			ItemExists = true;
			foundItem = m_allItems[i];
		}
	}
	return foundItem;
}

unsigned int Seller::countItemsOfSeller(const char* itemName) const
{
	unsigned int counter = 0;
	for (unsigned int i = 0; i < m_logicSizeItems; i++)
	{
		if (strcmp(m_allItems[i]->getNameOfItem(), itemName) == 0)
			counter++;
	}
	return counter;
}

bool Seller::checkIfItemExistInASeller(const char* itemName) const
{
	bool isExist = false;
	for (unsigned int i = 0; i < m_logicSizeItems && !isExist; i++)
	{
		if (strcmp(m_allItems[i]->getNameOfItem(), itemName) == 0)
			isExist = true;
	}
	return isExist;
}