#include "System.h"

System::System(const char* systemName, unsigned int physSizeBuyers, unsigned int physSizeSellers)
{
	m_systemName = nullptr;
	setSystemName(systemName);

	setLogicSizeBuyers(INITIAL_LOGICAL_SIZE);
	setPhysSizeBuyers(physSizeBuyers);
	m_allBuyers = new Buyer*[m_physSizeBuyers];

	setLogicSizeSellers(INITIAL_LOGICAL_SIZE);
	setPhysSizeSellers(physSizeSellers);
	m_allSellers = new Seller*[m_physSizeSellers];
}

System::~System()
{
	cleanBuyersArray();
	cleanSellersArray();
	delete[] m_systemName;
}

void System::cleanBuyersArray()
{
	for (unsigned int i = 0; i < m_logicSizeBuyers; ++i)
		delete m_allBuyers[i];
	delete[] m_allBuyers;
}

void System::cleanSellersArray()
{
	for (unsigned int i = 0; i < m_logicSizeSellers; ++i)
		delete m_allSellers[i];
	delete[] m_allSellers;
}

bool System::setSystemName(const char* systemName)
{
	delete[] m_systemName;
	unsigned int name_len = strlen(systemName);

	if ((name_len < MAX_LEN_SYSTEM_NAME) && (name_len >= MIN_LEN_SYSTEM_NAME))
	{
		m_systemName = new char[name_len + 1];
		strcpy(m_systemName, systemName);
		return true;
	}
	else
		return false;
}

bool System::setLogicSizeBuyers(unsigned int logicSizeBuyers)
{
	if (logicSizeBuyers >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeBuyers = logicSizeBuyers;
		return true;
	}
	return false;
}

bool System::setPhysSizeBuyers(unsigned int physSizeBuyers)
{
	if (physSizeBuyers >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeBuyers = physSizeBuyers;
		return true;
	}
	return false;
}

bool System::setLogicSizeSellers(unsigned int logicSizeSellers)
{
	if (logicSizeSellers >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeSellers = logicSizeSellers;
		return true;
	}
	return false;
}

bool System::setPhysSizeSellers(unsigned int physSizeSellers)
{
	if (physSizeSellers >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeSellers = physSizeSellers;
		return true;
	}
	return false;
}

const char* System::getSystemName() const
{
	return m_systemName;
}

unsigned int System::getLogicSizeSellers() const
{
	return m_logicSizeSellers;
}

unsigned int System::getLogicSizeBuyers() const
{
	return m_logicSizeBuyers;
}

Buyer** System::getAllBuyers()
{
	return m_allBuyers;
}

Seller** System::getAllSellers()
{
	return m_allSellers;
}

void System::reallocBuyers()
{
	Buyer** newAllBuyers = new Buyer*[m_physSizeBuyers];
	for (unsigned int i = 0; i < m_logicSizeBuyers; i++)
	{
		newAllBuyers[i] = m_allBuyers[i];
	}
	delete[]m_allBuyers;
	m_allBuyers = newAllBuyers;
}

void System::reallocSellers()
{
	Seller** newAllSellers = new Seller*[m_physSizeSellers];
	for (unsigned int i = 0; i < m_logicSizeSellers; i++)
	{
		newAllSellers[i] = m_allSellers[i];
	}
	delete[]m_allSellers;
	m_allSellers = newAllSellers;
}

bool System::addBuyerToSystem(Buyer* buyer)
{
	if (m_logicSizeBuyers == m_physSizeBuyers)
	{
		m_physSizeBuyers *= 2;
		reallocBuyers();
	}
	m_allBuyers[m_logicSizeBuyers++] = buyer;
	return true;
}

bool System::addSellerToSystem(Seller* seller)
{
	if (m_logicSizeSellers == m_physSizeSellers)
	{
		m_physSizeSellers *= 2;
		reallocSellers();
	}
	m_allSellers[m_logicSizeSellers++] = seller;
	return true;
}

Seller* System::findSeller(const char* nameOfSeller) const
{
	Seller * foundSeller = nullptr;
	bool sellerExists = false;
	for (unsigned int i = 0; i < m_logicSizeSellers && !sellerExists; i++)
	{
		if (strcmp(m_allSellers[i]->getUser().getUserName(), nameOfSeller) == 0)
		{
			sellerExists = true;
			foundSeller = m_allSellers[i];
		}
	}
	return foundSeller;
}

Buyer* System::findBuyer(const char* nameOfBuyer) const
{
	Buyer* foundBuyer = nullptr;
	bool BuyerExists = false;
	for (unsigned int i = 0; i < m_logicSizeBuyers && !BuyerExists; i++)
	{
		if (strcmp(m_allBuyers[i]->getUser().getUserName(), nameOfBuyer) == 0)
		{
			BuyerExists = true;
			foundBuyer = m_allBuyers[i];
		}
	}
	return foundBuyer;
}

bool System::checkIfItemExistInSellers(const char* itemName) const
{
	bool isExist = false;

	for (unsigned int i = 0; i < m_logicSizeSellers && !isExist; i++)
		isExist = m_allSellers[i]->checkIfItemExistInASeller(itemName);

	return isExist;
}

unsigned int System::countItemsInAllSellers(const char* itemName) const
{
	unsigned int counter = 0;

	for (unsigned int i = 0; i < m_logicSizeSellers; i++)
	{
		if (m_allSellers[i]->checkIfItemExistInASeller(itemName))
			counter += m_allSellers[i]->countItemsOfSeller(itemName);
	}

	return counter;
}