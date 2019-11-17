//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#ifndef __USER_H
#define __USER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class Address
{
public:
    static const int MAX_LEN_COUNTRY        = 255;
    static const int MAX_LEN_CITY           = 255;
    static const int MAX_LEN_STREET         = 255;
    static const int MAX_LEN_BUILD_NO       = 1000;
    static const int MAX_LEN_APPARTMENT_NO  = 1000;
    static const int MAX_LEN_ZIP_CODE       = 1000;

private:
    char* m_country;
    char* m_city;
    char* m_street;
    int m_buildNo;
    int m_appartmentNo;
    int m_zipCode;

public:
    bool setCountry(const char* country);
    bool setCity(const char* city);
    bool setStreet(const char* street);
    bool setBuildNo(const int buildNo);
    bool setAppartmentNo(const int appartmentNo);
    bool setZipCode(const int zipCode);

    const char* getCountry() const;
    const char* getCity() const;
    const char* getStreet() const;
    int getBuildNo() const;
    int getAppartmentNo() const;
    int getZipCode() const;

    Address(char* country, char* city, char* street, int buildNo, int appartmentNo, int zipCode); //c'tor
    ~Address(); //d'tor, Shira added parenthesis

};

#endif /* Address_h */ //Shira moved it to the end
