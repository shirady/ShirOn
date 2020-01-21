#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#include <string.h>
#include <string>
#include <fstream> //for files

class Address
{
public:
	static constexpr unsigned int MAX_LEN_COUNTRY = 100;
	static constexpr unsigned int MAX_LEN_CITY = 100;
	static constexpr unsigned int MAX_LEN_STREET = 100;
	static constexpr unsigned int MAX_LEN_BUILD_NO = 1000;
	static constexpr unsigned int MAX_LEN_APARTMENT_NO = 1000;
	static constexpr unsigned int MAX_LEN_ZIP_CODE = 15;
	static constexpr unsigned int MIN_LEN_ADDRESS_FIELD = 3;

private:
	string m_country;
	string m_city;
	string m_street;
	int m_buildNo;
	int m_apartmentNo;
	string m_zipCode;

	bool CheckCharacters(const string& fieldName) const;
	bool CheckCharactersOfZip(const string& zipCode) const;

public:
	Address(const string& country, const string& city, const string& street, int buildNo, int apartmentNo, const string& zipCode); //c'tor
	Address(ifstream& inFile); //c'tor for reading from file
	friend ostream& operator<<(ostream& os, const Address& address);

	bool setCountry(const string& country);
	bool setCity(const string& city);
	bool setStreet(const string& street);
	bool setBuildNo(int buildNo);
	bool setApartmentNo(int apartmentNo);
	bool setZipCode(const string& zipCode);

	const string& getCountry() const;
	const string& getCity() const;
	const string& getStreet() const;
	int getBuildNo() const;
	int getApartmentNo() const;
	const string& getZipCode() const;

	void save(ofstream& outFile) const;
};

#endif // __ADDRESS_H
