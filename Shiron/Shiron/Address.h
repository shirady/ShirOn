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
	static constexpr unsigned int MAX_LEN_ZIP_CODE = 15; //check if its fine
	static constexpr unsigned int MIN_LEN_ADDRESS_FIELD = 3;

private:
	char* m_country;
	char* m_city;
	char* m_street;
	unsigned int m_buildNo;
	unsigned int m_apartmentNo;
	char* m_zipCode;

	bool CheckCharacters(const char* fieldName);
	bool CheckCharactersOfZip(const char* zipCode);

public:
	Address(char* country, char* city, char* street, unsigned int buildNo, unsigned int apartmentNo, char* zipCode); //c'tor
	Address(const Address& other); //copy c'tor
	~Address(); //d'tor

	bool setCountry(const char* country);
	bool setCity(const char* city);
	bool setStreet(const char* street);
	bool setBuildNo(const unsigned int buildNo);
	bool setApartmentNo(const unsigned int apartmentNo);
	bool setZipCode(const char* zipCode);

	const char* getCountry() const;
	const char* getCity() const;
	const char* getStreet() const;
	unsigned int getBuildNo() const;
	unsigned int getApartmentNo() const;
	const char* getZipCode() const;
};

#endif /* Address_h */
