#include "Address.h"

Address::Address(const char* country, const char* city, const char* street, unsigned int buildNo, unsigned int apartmentNo, const char* zipCode)
{
	m_country = nullptr;
	m_city = nullptr;
	m_street = nullptr;
	m_zipCode = nullptr;

	setCountry(country);
	setCity(city);
	setStreet(street);
	setBuildNo(buildNo);
	setApartmentNo(apartmentNo);
	setZipCode(zipCode);
}

Address::Address(const Address& other)
{
	m_country = nullptr;
	m_city = nullptr;
	m_street = nullptr;
	m_zipCode = nullptr;

	*this = other;
}

Address::Address(Address&& other)
{
	m_country = nullptr;
	m_city = nullptr;
	m_street = nullptr;
	m_zipCode = nullptr;

	*this = other;
}

Address::~Address()
{
	delete[] m_country;
	delete[] m_city;
	delete[] m_street;
	delete[] m_zipCode;
}

const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		setCountry(other.m_country);
		setCity(other.m_city);
		setStreet(other.m_street);
		setBuildNo(other.m_buildNo);
		setApartmentNo(other.m_apartmentNo);
		setZipCode(other.m_zipCode);
	}
	return *this;
}

const Address& Address::operator=(Address&& other)
{
	if (this != &other)
	{
		swap(m_country, other.m_country);
		swap(m_city, other.m_city);
		swap(m_street, other.m_street);
		setBuildNo(other.m_buildNo);
		setApartmentNo(other.m_apartmentNo);
		swap(m_zipCode, other.m_zipCode);
	}
	return *this;
}

ostream& operator<<(ostream& os, const Address& address) //global function
{
	os << "Country: " << address.getCountry()
		<< ", City: " << address.getCity()
		<< ", Street: " << address.getStreet()
		<< ", Building Number: " << address.getBuildNo()
		<< ", Apartment Number: " << address.getApartmentNo()
		<< ", Zip Code: " << address.getZipCode() << endl;
	return os;
}

bool Address::setCountry(const char* country)
{
    delete[] m_country;
    unsigned int name_len = strlen(country);
    if ( (name_len < MAX_LEN_COUNTRY) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(country)) )
    {
        m_country = new char[strlen(country) + 1];
        strcpy(m_country, country);
        return true;
    }
    else
        return false;
}

bool Address::CheckCharacters(const char* fieldName) const
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

bool Address::CheckCharactersOfZip(const char* zipCode) const
{
	unsigned int i = 0;
	while (zipCode[i] != '\0')
	{
		if (isalnum(zipCode[i]) || zipCode[i] == '-')
			i++;
		else
			return false;
	}
	return true;
}

bool Address::setCity(const char* city)
{
	delete[] m_city;
    unsigned int name_len = strlen(city);
    if (name_len < (MAX_LEN_CITY - 1) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(city)))
    {
        m_city = new char[strlen(city) + 1];
        strcpy(m_city, city);
        return true;
    }
    else
        return false;

}

bool Address::setStreet(const char* street)
{
    delete[] m_street;
    unsigned int name_len = strlen(street);
    if (name_len < (MAX_LEN_STREET - 1) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(street)))
    {
        m_street = new char[strlen(street) + 1];
        strcpy(m_street, street);
        return true;
    }
    else
        return false;

}

bool Address::setBuildNo(unsigned int buildNo)
{
    m_buildNo = buildNo;
    return true;
}

bool Address::setApartmentNo(unsigned int apartmentNo)
{
    m_apartmentNo = apartmentNo;
    return true;
}

bool Address::setZipCode(const char* zipCode)
{
	delete[] m_zipCode; 
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