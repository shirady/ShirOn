#include "System.h"

bool System::setSystemName(const char* systemName)
{
	delete[] m_systemName; //will not run unless m_systemName was allocated
	unsigned int name_len = strlen(systemName);

	if (name_len < MAX_LEN_SYSTEM_NAME)
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
	if (logicSizeBuyers >= 0)
	{
		m_logicSizeBuyers = logicSizeBuyers;
		return true;
	}
	return false;
}

bool System::setPhysSizeBuyres(unsigned int physSizeBuyres)
{
	if (physSizeBuyres >= 1)
	{
		m_PhysSizeBuyres = physSizeBuyres;
		return true;
	}
	return false;
}

const char* System::getSystemName()
{
	return m_systemName;
}

Buyer** System::getAllBuyers()
{
	return m_allBuyers;
}

//Seller** System::getAllSellers()
//{
//	return m_allSellers;
//}

System::System(char* systemName, unsigned int PhysSizeBuyres)
{
	setSystemName(systemName);

	setLogicSizeBuyers(INITIAL_LOGICAL_SIZE);
	setPhysSizeBuyres(PhysSizeBuyres);
}

System::~System()
{
	for (int i = 0; i < m_logicSizeBuyers; ++i)
		delete m_allBuyers[i];
	delete[] m_allBuyers;

	//for (int i = 0; i < m_CurrentSellers; ++i)
	//	delete m_allSellers[i];
	//delete[] m_allSellers;
}

void System::reallocBuyers()
{
	Buyer** newAllBuyers = new Buyer*[m_PhysSizeBuyres];
	for (int i = 0; i < m_logicSizeBuyers; i++)
	{
		newAllBuyers[i] = new Buyer(*(m_allBuyers[i]));
	}
	delete []m_allBuyers;
	m_allBuyers=newAllBuyers;
}

bool System::addBuyerToSystem(Buyer& buyer)
{
	if (m_logicSizeBuyers == m_PhysSizeBuyres)
	{
		m_PhysSizeBuyres *= 2;
		reallocBuyers();
	}
	m_allBuyers[m_logicSizeBuyers] = &buyer;

}

//Buyer* System::readBuyer()
//{
//	char name[20];
//	cin.ignore(); // clean the buffer
//	cout << "Enter your name: ";
//	cin.getline(name, 20);
//
//	int age;
//	cout << "Enter you age:  ";
//	cin >> age;
//
//	int statusNumber;
//	cout << "Enter your status: \n 1.Single \n 2.Married \n 3.In A Relationship \n";
//	cin >> statusNumber;
//
//	return new Survivor(name, age, (Survivor::eFamilyStatus)statusNumber);
//}

/*
void showAllByers() const
{

}

void showAllSellers() const
{

}
*/