#include "user.h"

void User::setUserName(const char* userName) //where do we check if the user exist?
{
	delete[] m_userName; //will not run unless m_userName was allocated
	m_userName = new char[strlen(userName) + 1]; //check allocation is missing
	strcpy(m_userName, userName);
}