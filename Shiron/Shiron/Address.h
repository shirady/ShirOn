//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class Address
{
public:
	static const int MAX_LEN_COUNTRY = 255;
	static const int MAX_LEN_CITY = 255;
	static const int MAX_LEN_STREET = 255;
	static const int MAX_LEN_BUILD_NO = 1000;
	static const int MAX_LEN_APPARTMENT_NO = 1000;
	static const int MAX_LEN_ZIP_CODE = 15; //check if its fine

private:
	char* m_country;
	char* m_city;
	char* m_street;
	int m_buildNo;
	int m_appartmentNo;
	char* m_zipCode;

public:
	bool setCountry(const char* country);
	bool setCity(const char* city);
	bool setStreet(const char* street);
	bool setBuildNo(const int buildNo);
	bool setAppartmentNo(const int appartmentNo);
	bool setZipCode(const char* zipCode);

	const char* getCountry() const;
	const char* getCity() const;
	const char* getStreet() const;
	int getBuildNo() const;
	int getAppartmentNo() const;
	const char* getZipCode() const;

	Address(char* country, char* city, char* street, int buildNo, int appartmentNo, char* zipCode); //c'tor
	//Address(const Address&);
	~Address(); //d'tor

};

#endif /* Address_h */
