#include "user.h"

bool User::setUserName(const char* userName) //where do we check if the user exist?
{
	//delete[] m_userName; //will not run unless m_userName was allocated
	unsigned int name_len = strlen(userName);

	if ((name_len < MAX_LEN_NAME) && (CheckWhiteSpace(userName)))
	{
		m_userName = new char[name_len + 1]; //check allocation is missing
		strcpy(m_userName, userName);
		return true;
	}
	else
		return false;
}

bool User::CheckWhiteSpace(const char* userName)
{
	int i = 0;
	while (userName[i] != '\0')
	{
		if (isspace(userName[i]))
			return false;
		i++;
	}
	return true;
}

bool User::setPassword(const char* passward) //Do we want to check if the password is "strong"?
{
	//delete[] m_password; //will not run unless m_userName was allocated
	unsigned int name_len = strlen(passward);

	if ( (name_len < MAX_LEN_NAME) && ( CheckWhiteSpace(passward)) )
	{
		m_password = new char[name_len + 1]; //check allocation is missing
		strcpy(m_password, passward);
		return true;
	}
	else
		return false;
}

const char* User::getUserName() const
{
	return m_userName;
}

const char* User::getPassword() const
{
	return m_password;
}


User::User(const char* userName, const char* password, const Address& address): m_UserAddress(address)
{
	setUserName(userName);
	setPassword(password);
}

User::User(const User& other) : m_UserAddress(other.m_UserAddress)
{
	setUserName(other.m_userName);
	setPassword(other.m_password);
}

User::~User()
{
	delete[] m_userName;
	delete[] m_password;
}
