#include "user.h"

bool User::setUserName(const char* userName) //where do we check if the user exist?
{
	delete[] m_userName; //will not run unless m_userName was allocated
	unsigned int name_len = strlen(userName);
	if (name_len < (MAX_LEN_NAME - 1))
	{
		m_userName = new char[strlen(userName) + 1]; //check allocation is missing
		strcpy(m_userName, userName);
		return true;
	}
	else
		return false;
}

bool User::setPassword(const char* passward)
{

}

bool User::setUserType(bool userType)
{

}

char* User::getUserName() const
{

}

char* User::getPassword() const
{

}

bool User::getUserType() const
{

}
