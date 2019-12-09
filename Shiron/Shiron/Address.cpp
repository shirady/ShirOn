#include "Address.h"

bool Address::setCountry(const char* country)
{
    //delete[] m_country; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(country);
    if ( (name_len < MAX_LEN_COUNTRY) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(country)) )
    {
        m_country = new char[strlen(country) + 1]; //check allocation is missing
        strcpy(m_country, country);
        return true;
    }
    else
        return false;
}

bool Address::CheckCharacters(const char* fieldName)
{
	unsigned int i = 0;
	while (fieldName[i] != '\0')
	{
		if (isalpha(fieldName[i]) || isdigit(fieldName[i])|| fieldName[i] == ' ' || fieldName[i] == '-')
			i++;
		else
			return false;
	}
	return true;
}

bool Address::CheckCharactersOfZip(const char* fieldName)
{
	unsigned int i = 0;
	while (fieldName[i] != '\0')
	{
		if (isalnum(fieldName[i]) || fieldName[i] == '-')
			i++;
		else
			return false;
	}
	return true;
}

bool Address::setCity(const char* city)
{
    //delete[] m_city; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(city);
    if (name_len < (MAX_LEN_CITY - 1) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(city)))
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
    //delete[] m_street; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(street);
    if (name_len < (MAX_LEN_STREET - 1) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(street)))
    {
        m_street = new char[strlen(street) + 1]; //check allocation is missing
        strcpy(m_street, street);
        return true;
    }
    else
        return false;

}

bool Address::setBuildNo(const unsigned int buildNo)
{
    m_buildNo = buildNo;
    return true;
}

bool Address::setApartmentNo(const unsigned int apartmentNo)
{
    m_apartmentNo = apartmentNo;
    return true;
}

bool Address::setZipCode(const char* zipCode)
{
	//delete[] m_zipCode; 
	unsigned int name_len = strlen(zipCode);
	if (name_len < (MAX_LEN_STREET - 1) && (name_len >= MIN_LEN_ADDRESS_FIELD) && CheckCharactersOfZip(zipCode))
	{
		m_zipCode = new char[strlen(zipCode) + 1];
		strcpy(m_zipCode, zipCode);
		return true;
	}
	else
		return false;
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

unsigned int Address::getBuildNo() const
{
    return m_buildNo;
}

unsigned int Address::getApartmentNo() const
{
    return m_apartmentNo;
}

const char* Address::getZipCode() const
{
    return m_zipCode;
}

Address::Address(char* country, char* city, char* street, unsigned int buildNo, unsigned int apartmentNo, char* zipCode)
{
    setCountry(country);
    setCity(city);
    setStreet(street);
    setBuildNo(buildNo);
    setApartmentNo(apartmentNo);
    setZipCode(zipCode);
}

Address::Address(const Address& other)
{
	setCountry(other.m_country);
	setCity(other.m_city);
	setStreet(other.m_street);
	setBuildNo(other.m_buildNo);
	setApartmentNo(other.m_apartmentNo);
	setZipCode(other.m_zipCode);
}

Address::~Address()
{
    delete[] m_country;
    delete[] m_city;
    delete[] m_street;
	delete[] m_zipCode;
}
