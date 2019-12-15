#include "user.h"

User::User(const char* userName, const char* password, const Address& address) : m_userAddress(address)
{
	m_userName = nullptr;
	m_password = nullptr;

	setUserName(userName);
	setPassword(password);
}

User::User(const User& other) : m_userAddress(other.m_userAddress)
{
	m_userName = nullptr;
	m_password = nullptr;

	setUserName(other.m_userName);
	setPassword(other.m_password);
}

User::~User()
{
	delete[] m_userName;
	delete[] m_password;
}

bool User::setUserName(const char* userName)
{
	delete[] m_userName;
	unsigned int name_len = strlen(userName);

	if ((name_len < MAX_LEN_NAME) && (name_len >= MIN_LEN_NAME) && (CheckWhiteSpace(userName)))
	{
		m_userName = new char[name_len + 1];
		strcpy(m_userName, userName);
		return true;
	}
	else
		return false;
}

bool User::CheckWhiteSpace(const char* fieldName) const
{
	unsigned int i = 0;
	while (fieldName[i] != '\0')
	{
		if (isspace(fieldName[i]))
			return false;
		i++;
	}
	return true;
}

bool User::setPassword(const char* password) 
{
	delete[] m_password;
	unsigned int name_len = strlen(password);

	if ((name_len < MAX_LEN_NAME) && (name_len >= MIN_LEN_NAME) && (CheckWhiteSpace(password)))
	{
		m_password = new char[name_len + 1];
		strcpy(m_password, password);
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

const Address& User::getAddress() const
{
	return m_userAddress;
}
