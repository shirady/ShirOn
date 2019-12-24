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

void System::cleanUsersArray()
{
	for (unsigned int i = 0; i < m_logicSizeUsers; ++i)
		delete m_allUsers[i];
	delete[] m_allUsers;
}

const System& System::operator+=(Buyer* buyer)
{
	addUserToSystem(buyer);
	return *this;
}

const System& System::operator+=(Seller* seller)
{
	addUserToSystem(seller);
	return *this;
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

unsigned int System::getLogicSizeUsers() const
{
	return m_logicSizeUsers;
}

User** System::getAllUsers()
{
	return m_allUsers;
}

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

