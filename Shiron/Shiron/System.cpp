#include "System.h"

System::System(const char* systemName)
{
	m_systemName = nullptr;
	setSystemName(systemName);

}

System::~System()
{
	cleanUsersList();
	delete[] m_systemName;
}

void System::cleanUsersList()
{
	list<User*>::iterator itr = m_allUsersList.begin();
	list<User*>::iterator itrEnd = m_allUsersList.end();
	for (; itr != itrEnd; ++itr)
		delete *itr; //frees the pointer of User inside the cell of list

	m_allUsersList.clear();
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

const list<User*>& System::getAllUsersList() const
{
	return m_allUsersList;
}

const char* System::getSystemName() const
{
	return m_systemName;
}

unsigned int System::numberOfUsersInSystem() const
{
	return m_allUsersList.size();
}

void System::addUserToSystem(User* user)
{
	m_allUsersList.push_back(user);
}

User* System::findUser(const char* nameOfUser) const
{
	User* foundUser = nullptr;
	bool UserExists = false;

	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd && !UserExists; ++itr)
	{
		if (strcmp((*itr)->getUserName(), nameOfUser) == 0)
		{
			UserExists = true;
			foundUser = *itr;
		}
	}
	return foundUser;
}

bool System::checkIfItemExistInSellers(const char* itemName) const
{
	bool isExist = false;

	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd && !isExist; ++itr)
	{
		Seller* seller = dynamic_cast<Seller*>(*itr);
		if (seller !=nullptr)
			isExist = seller->checkIfItemExistInASeller(itemName);
	}

	return isExist;
}

unsigned int System::countItemsInAllSellers(const char* itemName) const
{
	unsigned int counter = 0;
	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd; ++itr)
	{
		Seller* seller = dynamic_cast<Seller*>((*itr));
		if (seller != nullptr)
			if(seller->checkIfItemExistInASeller(itemName))
				counter += seller->countItemsOfSeller(itemName);
	}
	return counter;
}


void System::showAllBuyers() const
{
	unsigned int counter = 0;
	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd; ++itr)
	{
		Buyer* buyer = dynamic_cast<Buyer*>(*itr);
		if (buyer != nullptr)
		{
			cout << "#" << counter + 1 << ": ";
			buyer->show();
			counter++;
		}
	}
	cout << "__________________________________________________" << endl
		<< "There are " << counter << " buyers in the system" << endl;
}

void System::showAllSellers() const
{
	unsigned int counter = 0;
	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd; ++itr)
	{
		Seller* seller = dynamic_cast<Seller*>(*itr);
		if (seller != nullptr)
		{
			cout << "#" << counter + 1 << ": ";
			seller->show();
			counter++;
		}
	}
	cout << "__________________________________________________" << endl
		<< "There are " << counter << " sellers in the system" << endl;
}


void System::showAllBuyersThatAreSellers() const
{
	unsigned int counter = 0;
	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd; ++itr)
	{
		BuyerAndSeller* seller = dynamic_cast<BuyerAndSeller*>(*itr);
		if (seller != nullptr)
		{
			cout << "#" << counter + 1 << ": ";
			seller->show();
			counter++;
		}
	}
	cout << "__________________________________________________" << endl
		<< "There are " << counter << " sellers in the system" << endl;
}

void System::showAllItemsOfSellers(const char* itemName) const
{
	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd; ++itr)
	{
		Seller* seller = dynamic_cast<Seller*>(*itr);
		if (seller != nullptr)
		{
			unsigned int counter = seller->countItemsOfSeller(itemName);
			if (counter > 0)
			{
				seller->showItemsOfSeller(itemName);
				cout << "The seller " << seller->getUserName() << " has " << counter << " items" << endl;
				cout << "--------------------------------------------------------" << endl << endl;
			}
		}
	}
}
