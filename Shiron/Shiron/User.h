#ifndef __USER_H
#define __USER_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#include <string>
#include <fstream> //for files

#include "Address.h"

class User
{
public:
	static constexpr unsigned int MAX_LEN_PASSWORD = 16;
	static constexpr unsigned int MAX_LEN_NAME = 16;
	static constexpr unsigned int MIN_LEN_PASSWORD = 6;
	static constexpr unsigned int MIN_LEN_NAME = 3;

private:
	string m_userName;
	string m_password;
	Address m_userAddress;

	bool setUserName(const string& userName);
	bool CheckWhiteSpace(const string& fieldName) const;

protected:
	User(const string& userName, const string& password, const Address& address); //c'tor - Protected because User is Abstract
	User(ifstream& inFile); // c'tor - Protected because User is Abstract

	void showMe() const;

public:
	virtual ~User() {};

	bool setPassword(const string& password); //password can be change after it was created

	void show() const;

	const string& getUserName() const;
	const string& getPassword() const;
	const Address& getAddress() const;

	void saveType(ofstream& outFile) const;
	void save(ofstream& outFile) const;
};

#endif //__USER_H