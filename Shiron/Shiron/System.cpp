#include "System.h"

System::System(const char* systemName, unsigned int physUsers)
{
	m_systemName = nullptr;
	setSystemName(systemName);

	setLogicSizeUsers(INITIAL_LOGICAL_SIZE);
	setPhysSizeUsers(physUsers);
	m_allUsers = new User*[m_physSizeUsers];
}

System::~System()
{
	cleanUsersArray();
	delete[] m_systemName;
}

//void System::cleanBuyersArray()
//{
//	for (unsigned int i = 0; i < m_logicSizeBuyers; ++i)
//		delete m_allBuyers[i];
//	delete[] m_allBuyers;
//}
//
//void System::cleanSellersArray()
//{
//	for (unsigned int i = 0; i < m_logicSizeSellers; ++i)
//		delete m_allSellers[i];
//	delete[] m_allSellers;
//}

void System::cleanUsersArray()
{
	for (unsigned int i = 0; i < m_logicSizeUsers; ++i)
		delete m_allUsers[i];
	delete[] m_allUsers;
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

//bool System::setLogicSizeBuyers(unsigned int logicSizeBuyers)
//{
//	if (logicSizeBuyers >= INITIAL_LOGICAL_SIZE)
//	{
//		m_logicSizeBuyers = logicSizeBuyers;
//		return true;
//	}
//	return false;
//}
//
//bool System::setPhysSizeBuyers(unsigned int physSizeBuyers)
//{
//	if (physSizeBuyers >= INITIAL_PHYSICAL_SIZE)
//	{
//		m_physSizeBuyers = physSizeBuyers;
//		return true;
//	}
//	return false;
//}
//
//bool System::setLogicSizeSellers(unsigned int logicSizeSellers)
//{
//	if (logicSizeSellers >= INITIAL_LOGICAL_SIZE)
//	{
//		m_logicSizeSellers = logicSizeSellers;
//		return true;
//	}
//	return false;
//}
//
//bool System::setPhysSizeSellers(unsigned int physSizeSellers)
//{
//	if (physSizeSellers >= INITIAL_PHYSICAL_SIZE)
//	{
//		m_physSizeSellers = physSizeSellers;
//		return true;
//	}
//	return false;
//}

bool System::setLogicSizeUsers(unsigned int logicSizeUsers)
{
	if (logicSizeUsers >= INITIAL_LOGICAL_SIZE)
	{
		m_logicSizeUsers = logicSizeUsers;
		return true;
	}
	return false;
}

bool System::setPhysSizeUsers(unsigned int physSizeUsers)
{
	if (physSizeUsers >= INITIAL_PHYSICAL_SIZE)
	{
		m_physSizeUsers = physSizeUsers;
		return true;
	}
	return false;
}

const char* System::getSystemName() const
{
	return m_systemName;
}

//unsigned int System::getLogicSizeSellers() const
//{
//	return m_logicSizeSellers;
//}
//
//unsigned int System::getLogicSizeBuyers() const
//{
//	return m_logicSizeBuyers;
//}

unsigned int System::getLogicSizeUsers() const
{
	return m_logicSizeUsers;
}

//Buyer** System::getAllBuyers()
//{
//	return m_allBuyers;
//}
//
//Seller** System::getAllSellers()
//{
//	return m_allSellers;
//}

User** System::getAllUsers()
{
	return m_allUsers;
}

//void System::reallocBuyers()
//{
//	Buyer** newAllBuyers = new Buyer*[m_physSizeBuyers];
//	for (unsigned int i = 0; i < m_logicSizeBuyers; i++)
//	{
//		newAllBuyers[i] = m_allBuyers[i];
//	}
//	delete[]m_allBuyers;
//	m_allBuyers = newAllBuyers;
//}
//
//void System::reallocSellers()
//{
//	Seller** newAllSellers = new Seller*[m_physSizeSellers];
//	for (unsigned int i = 0; i < m_logicSizeSellers; i++)
//	{
//		newAllSellers[i] = m_allSellers[i];
//	}
//	delete[]m_allSellers;
//	m_allSellers = newAllSellers;
//}

void System::reallocUsers()
{
	User** newAllUsers = new User*[m_physSizeUsers];
	for (unsigned int i = 0; i < m_logicSizeUsers; i++)
	{
		newAllUsers[i] = m_allUsers[i];
	}
	delete[]m_allUsers;
	m_allUsers = newAllUsers;
}

//bool System::addBuyerToSystem(Buyer* buyer)
//{
//	if (m_logicSizeBuyers == m_physSizeBuyers)
//	{
//		m_physSizeBuyers *= 2;
//		reallocBuyers();
//	}
//	m_allBuyers[m_logicSizeBuyers++] = buyer;
//	return true;
//}
//
//bool System::addSellerToSystem(Seller* seller)
//{
//	if (m_logicSizeSellers == m_physSizeSellers)
//	{
//		m_physSizeSellers *= 2;
//		reallocSellers();
//	}
//	m_allSellers[m_logicSizeSellers++] = seller;
//	return true;
//}

bool System::addUserToSystem(User* user)
{
	if (m_logicSizeUsers == m_physSizeUsers)
	{
		m_physSizeUsers *= 2;
		reallocUsers();
	}
	m_allUsers[m_logicSizeUsers++] = user;
	return true;
}

//Seller* System::findSeller(const char* nameOfSeller) const
//{
//	Seller * foundSeller = nullptr;
//	bool sellerExists = false;
//	for (unsigned int i = 0; i < m_logicSizeSellers && !sellerExists; i++)
//	{
//		if (strcmp(m_allSellers[i]->getUserName(), nameOfSeller) == 0)
//		{
//			sellerExists = true;
//			foundSeller = m_allSellers[i];
//		}
//	}
//	return foundSeller;
//}
//
//Buyer* System::findBuyer(const char* nameOfBuyer) const
//{
//	Buyer* foundBuyer = nullptr;
//	bool BuyerExists = false;
//	for (unsigned int i = 0; i < m_logicSizeBuyers && !BuyerExists; i++)
//	{
//		if (strcmp(m_allBuyers[i]->getUserName(), nameOfBuyer) == 0)
//		{
//			BuyerExists = true;
//			foundBuyer = m_allBuyers[i];
//		}
//	}
//	return foundBuyer;
//}

User* System::findUser(const char* nameOfUser) const
{
	User* foundUser = nullptr;
	bool UserExists = false;
	for (unsigned int i = 0; i < m_logicSizeUsers && !UserExists; i++)
	{
		if (strcmp(m_allUsers[i]->getUserName(), nameOfUser) == 0)
		{
			UserExists = true;
			foundUser = m_allUsers[i];
		}
	}
	return foundUser;
}

bool System::checkIfItemExistInSellers(const char* itemName) const
{
	bool isExist = false;

	for (unsigned int i = 0; i < m_logicSizeUsers && !isExist; i++)
	{
		Seller* seller = dynamic_cast<Seller*>(m_allUsers[i]);
		if (seller !=nullptr)
			isExist = seller->checkIfItemExistInASeller(itemName);
	}

	return isExist;
}

unsigned int System::countItemsInAllSellers(const char* itemName) const
{
	unsigned int counter = 0;

	for (unsigned int i = 0; i < m_logicSizeUsers; i++)
	{
		Seller* seller = dynamic_cast<Seller*>(m_allUsers[i]);
		if (seller != nullptr)
		{
			if(seller->checkIfItemExistInASeller(itemName))
				counter += seller->countItemsOfSeller(itemName);
		}
	}
	return counter;
}

//Seller* System::isUserSeller(User* user) const
//{
//	return dynamic_cast<Seller*>(user);
//}
//
//bool System::isUserBuyer(User* user) const
//{
//	return (dynamic_cast<Buyer*>(user) != nullptr);
//}

//bool System::isUserBuyerAndSeller(User* user) const
//{
//	return (dynamic_cast<BuyerAndSeller*>(user) != nullptr);
//}

