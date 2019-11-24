#include "System.h"

bool System::setSystemName(const char* systemName)
{
	delete[] m_systemName; //will not run unless m_systemName was allocated
	unsigned int name_len = strlen(systemName);

	if (name_len < MAX_LEN_SYSTEM_NAME)
	{
		m_systemName = new char[name_len + 1]; //check allocation is missing
		strcpy(m_systemName, systemName);
		return true;
	}
	else
		return false;
}

const char* System::getSystemName()
{
	return m_systemName;
}

Buyer** System::getAllBuyers()
{
	return m_allByers;
}

Seller** System::getAllSellers()
{
	return m_allSellers;
}

System::System(int maxBuyres, int maxSellers) //repetition in the code
{
	m_CurrentByers = 0;
	m_CurrentSellers = 0;
	m_maxBuyres = maxBuyres;
	m_maxSellers = maxSellers;

	m_allByers = new Buyer*[m_maxBuyres]; //check allocation
	m_allSellers = new Seller*[m_maxSellers]; //check allocation
}

System::System(System&& other)
{
	m_CurrentByers = other.m_CurrentByers;
	m_CurrentSellers = other.m_CurrentSellers;
	m_maxBuyres = other.m_maxBuyres;
	m_maxSellers = other.m_maxSellers;

	m_systemName = other.m_systemName;
	other.m_systemName = nullptr;
	m_allByers = other.m_allByers;
	other.m_allByers = nullptr;
	m_allSellers = other.m_allSellers;
	other.m_allSellers = nullptr;
}

//System::~System()
//{
//	for (int i = 0; i < m_CurrentByers; ++i)
//		delete m_allByers[i];
//	delete[] m_allByers;
//
//	for (int i = 0; i < m_CurrentSellers; ++i)
//		delete m_allSellers[i];
//	delete[] m_allSellers;
//}

////gets the address of the original array, the (larger) number of elements and the size of an element.
//void* reallocArray(void* A, int numberOfElementsBefore, int numberOfElementsAfter, int sizeOfAnElement)
//{
//	void* newArray = new type[numberOfElementsAfter];
//	memcpy(newArray, A, numberOfElementsBefore);
//	delete A;
//	return newArray;
//} //after returning the array need to cast for the appropriate kind of variables.

/*
bool System::addUserToSystem(User* user)
{

}

void showAllByers() const
{

}

void showAllSellers() const
{

}
*/