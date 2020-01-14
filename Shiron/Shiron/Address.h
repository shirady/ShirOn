#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

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
	char* m_country;
	char* m_city;
	char* m_street;
	int m_buildNo;
	int m_apartmentNo;
	char* m_zipCode;

	bool CheckCharacters(const char* fieldName) const;
	bool CheckCharactersOfZip(const char* zipCode) const;

public:
	Address(const char* country, const char* city, const char* street, int buildNo, int apartmentNo, const char* zipCode); //c'tor
	Address(const Address& other); //copy c'tor
	Address(Address&& other); //move c'tor
	~Address(); //d'tor

	const Address& operator=(const Address& other);
	const Address& operator=(Address&& other);
	friend ostream& operator<<(ostream& os, const Address& address);

	bool setCountry(const char* country);
	bool setCity(const char* city);
	bool setStreet(const char* street);
	bool setBuildNo(int buildNo);
	bool setApartmentNo(int apartmentNo);
	bool setZipCode(const char* zipCode);

	const char* getCountry() const;
	const char* getCity() const;
	const char* getStreet() const;
	int getBuildNo() const;
	int getApartmentNo() const;
	const char* getZipCode() const;
};

#endif /* Address_h */
