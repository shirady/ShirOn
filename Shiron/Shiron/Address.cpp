//
//  Address.cpp
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#include "Address.h"

bool Address::setCountry(const char* country)
{
    delete[] m_country; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(country);
    if (name_len < (MAX_LEN_COUNTRY - 1))
    {
        m_country = new char[strlen(country) + 1]; //check allocation is missing
        strcpy(m_country, country);
        return true;
    }
    else
        return false;
}

bool Address::setCity(const char* city)
{
    delete[] m_city; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(city);
    if (name_len < (MAX_LEN_CITY - 1))
    {
        m_city = new char[strlen(city) + 1]; //check allocation is missing
        strcpy(m_city, city);
        return true;
    }
    else
        return false;

}

bool Address::setStreet(const char* street)
{
    delete[] m_street; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(street);
    if (name_len < (MAX_LEN_STREET - 1))
    {
        m_street = new char[strlen(street) + 1]; //check allocation is missing
        strcpy(m_street, street);
        return true;
    }
    else
        return false;

}

bool Address::setBuildNo(const int buildNo)
{
    m_buildNo=buildNo;
    return true;
}

bool Address::setAppartmentNo(const int appartmentNo)
{
    m_appartmentNo=appartmentNo;
    return true;

}

bool Address::setZipCode(const int zipCode)
{
    m_zipCode=zipCode;
    return true;
}


const char* Address::getCountry() const
{
    return m_country;
    
}
const char* Address::getCity() const
{
    return m_city;
}
const char* Address::getStreet() const
{
    return m_street;
}
int Address::getBuildNo() const
{
    return m_buildNo;
}
int Address::getAppartmentNo() const
{
    return m_appartmentNo;
}
int Address::getZipCode() const
{
    return m_zipCode;
}

Address::Address(char* country, char* city, char* street, int buildNo, int appartmentNo, int zipCode) //c'tor
{
    setCountry(country);
    setCity(city);
    setStreet(street);
    setBuildNo(buildNo);
    setAppartmentNo(appartmentNo);
    setZipCode(zipCode);
}

Address::~Address() //d'tor
{
    delete[] m_country;
    delete[] m_city;
    delete[] m_street;
}
