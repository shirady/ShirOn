#include "user.h"

bool User::setUserName(const char* userName) //where do we check if the user exist?
{
	delete[] m_userName; //will not run unless m_userName was allocated
	unsigned int name_len = strlen(userName);

	if (name_len < MAX_LEN_NAME)
	{
		m_userName = new char[name_len + 1]; //check allocation is missing
		strcpy(m_userName, userName);
		return true;
	}
	else
		return false;
}

bool User::setPassword(const char* passward) //Do we want to check if the password is "strong"?
{
	delete[] m_password; //will not run unless m_userName was allocated
	unsigned int name_len = strlen(passward);

	if (name_len < MAX_LEN_NAME)
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


User::User(const char* userName, const char* password, Address&& address): m_UserAddress(address)
{
	setUserName(userName);
	setPassword(password);
}

//User::User(const User&)
//{
//
//}

//User::User(User&& other): m_UserAddress(other.m_UserAddress.getCountry, other.m_UserAddress.getCity(), other.m_UserAddress.getStreet(), other.m_UserAddress.getBuildNo(), other.m_UserAddress.getAppartmentNo(), other.m_UserAddress.getZipCode())
//{
//	//m_userName = other.m_userName; // "borrow" the address of the m_userName
//	setUserName(other.m_userName);
//	other.m_userName = nullptr;
//
//	//m_password = other.m_password; // "borrow" the address of the m_password
//	setPassword(other.m_password);
//	other.m_password = nullptr;
//
//	setUserType(other.m_userType);
//	//m_userType = other.m_userType;
//} //changed the move c'tor using setters + had problem init the address, maybe because there's no copy c'tor of address?

User::~User()
{
	delete[] m_userName;
	delete[] m_password;
}
