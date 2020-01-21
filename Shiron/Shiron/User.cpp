#include "User.h"
#include "UserGenerator.h"

User::User(const string& userName, const string& password, const Address& address) : m_userAddress(address)
{
	setUserName(userName);
	setPassword(password);
}

User::User(ifstream& inFile): m_userAddress(inFile)
{
	getline(inFile, m_userName);
	getline(inFile, m_password);
}

/*User::User(const User& other) : m_userAddress(other.m_userAddress)
{
}

User::User(User&& other) : m_userAddress(other.m_userAddress)
{
}*/
void User::show() const
{
	showMe();
}

void User::showMe() const
{
	cout << "User name: " << m_userName << endl;
	cout << m_userAddress;
}

bool User::setUserName(const string& userName)
{
	unsigned int name_len = userName.length();

	if ((name_len < MAX_LEN_NAME) && (name_len >= MIN_LEN_NAME) && (CheckWhiteSpace(userName)))
	{
		m_userName = userName;
		return true;
	}
	else
		return false;
}

bool User::CheckWhiteSpace(const string& fieldName) const
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

bool User::setPassword(const string& password)
{
	unsigned int name_len = password.length();

	if ((name_len < MAX_LEN_NAME) && (name_len >= MIN_LEN_NAME) && (CheckWhiteSpace(password)))
	{
		m_password = password;
		return true;
	}
	else
		return false;
}

const string& User::getUserName() const
{
	return m_userName;
}

const string& User::getPassword() const
{
	return m_password;
}

const Address& User::getAddress() const
{
	return m_userAddress;
}

//This method writes to the file the first 3 letters of the object type
void User::saveType(ofstream& outFile) const
{
	UsersGenerator::eUsersType type = UsersGenerator::getType(this);
	outFile << type << endl;
}

void User::save(ofstream& outFile) const
{
	m_userAddress.save(outFile); //the address is contain in User, that's why we write it first

	//int lenUserName = m_userName.length();
	//outFile << lenUserName << endl;
	outFile << m_userName << endl;

	//int lenPassword = m_password.length();
	//outFile << lenPassword << endl;
	outFile << m_password << endl;
}