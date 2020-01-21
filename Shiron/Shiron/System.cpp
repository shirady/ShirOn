#include "System.h"
#include "UserGenerator.h" //for loadAllUsers

System::System(const string& systemName)
{
	setSystemName(systemName);
}

System::~System()
{
	cleanUsersList();
}

void System::cleanUsersList()
{
	list<User*>::iterator itr = m_allUsersList.begin();
	list<User*>::iterator itrEnd = m_allUsersList.end();
	for (; itr != itrEnd; ++itr)
		delete *itr; //frees the pointer of User inside the cell of list
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

bool System::setSystemName(const string& systemName)
{
	unsigned int name_len = systemName.length();

	if ((name_len < MAX_LEN_SYSTEM_NAME) && (name_len >= MIN_LEN_SYSTEM_NAME))
	{
		m_systemName = systemName;
		return true;
	}
	else
		return false;
}

const list<User*>& System::getAllUsersList() const
{
	return m_allUsersList;
}

const string& System::getSystemName() const
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

User* System::findUser(const string& UserName) const
{
	User* foundUser = nullptr;
	bool UserExists = false;

	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd && !UserExists; ++itr)
	{
		if(UserName.compare((*itr)->getUserName()) == 0)
		{
			UserExists = true;
			foundUser = *itr;
		}
	}
	return foundUser;
}

bool System::checkIfItemExistInSellers(const string& itemName) const
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

unsigned int System::countItemsInAllSellers(const string& itemName) const
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

void System::showAllItemsOfSellers(const string& itemName) const
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

//saving in the file the number of elements
// for each object we save the type of the object and its data
void System::saveUsersToFile(const string& fileName) const
{
	ofstream outFile(fileName, ios::trunc);

	//save num of users
	outFile << numberOfUsersInSystem() << endl;

	list<User*>::const_iterator itr = m_allUsersList.begin(); //const_iterator since the method is const
	list<User*>::const_iterator itrEnd = m_allUsersList.end(); //const_iterator since the method is const

	for (; itr != itrEnd; ++itr)
	{
		(*itr)->saveType(outFile);
		(*itr)->save(outFile);
	}
	outFile.close();
}

void System::loadAllUsers(const string& fileName, unsigned int& numOfUsers)
{
	ifstream inFile(fileName); //by default ios::in
	if (!inFile.fail())
	{
		inFile >> numOfUsers;

		for (unsigned int i = 0; i < numOfUsers; i++)
			m_allUsersList.push_back(UsersGenerator::loadUser(inFile));
	}
	else
		cout << "*cannot open file of users" << endl;
	
	inFile.close();
}
