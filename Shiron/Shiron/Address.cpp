#include "Address.h"

Address::Address(const string& country, const string& city, const string& street, int buildNo, int apartmentNo, const string& zipCode)
{
	setCountry(country);
	setCity(city);
	setStreet(street);
	setBuildNo(buildNo);
	setApartmentNo(apartmentNo);
	setZipCode(zipCode);
}


//Assumption: all attributes from the file are valid (that's why we don't use the setter)
Address::Address(ifstream& inFile)
{
	string temp; //for the '\n' after reading a number
	getline(inFile, temp); //for the '\n' after reading the type enum
	getline(inFile, m_country);
	getline(inFile, m_city);
	getline(inFile, m_street);
	inFile >> m_buildNo;
	inFile >> m_apartmentNo;
	getline(inFile, temp); //for the '\n' after reading the apartmentNo 
	getline(inFile, m_zipCode);
}

ostream& operator<<(ostream& os, const Address& address) //global function
{
	os << "Country: " << address.m_country
		<< ", City: " << address.m_city
		<< ", Street: " << address.m_street
		<< ", Building Number: " << address.m_buildNo
		<< ", Apartment Number: " << address.m_apartmentNo
		<< ", Zip Code: " << address.m_zipCode << endl;
	return os;
}

bool Address::setCountry(const string& country)
{
    unsigned int name_len = country.length();
    if ( (name_len < MAX_LEN_COUNTRY) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(country)) )
    {
		m_country = country;
        return true;
    }
    else
        return false;
}

bool Address::CheckCharacters(const string& fieldName) const
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

bool Address::CheckCharactersOfZip(const string& zipCode) const
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

bool Address::setCity(const string& city)
{
	unsigned int name_len = city.length();
    if (name_len < (MAX_LEN_CITY - 1) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(city)))
    {
		m_city = city;
        return true;
    }
    else
        return false;

}

bool Address::setStreet(const string& street)
{
	unsigned int name_len = street.length();
    if (name_len < (MAX_LEN_STREET - 1) && (name_len >= MIN_LEN_ADDRESS_FIELD) && (CheckCharacters(street)))
    {
		m_street = street;
        return true;
    }
    else
        return false;

}

bool Address::setBuildNo(int buildNo)
{
	if (buildNo > 0)
	{
		m_buildNo = buildNo;
		return true;
	}
	else
		return false;

}

bool Address::setApartmentNo(int apartmentNo)
{
	if (apartmentNo > 0)
	{
		m_apartmentNo = apartmentNo;
		return true;
	}
	else
		return false;
}

bool Address::setZipCode(const string& zipCode)
{
	unsigned int name_len = zipCode.length();
	if (name_len < (MAX_LEN_STREET - 1) && (name_len >= MIN_LEN_ADDRESS_FIELD) && CheckCharactersOfZip(zipCode))
	{
		m_zipCode = zipCode;
		return true;
	}
	else
		return false;
}

const string& Address::getCountry() const
{
    return m_country;
}

const string& Address::getCity() const
{
    return m_city;
}

const string& Address::getStreet() const
{
    return m_street;
}

int Address::getBuildNo() const
{
    return m_buildNo;
}

int Address::getApartmentNo() const
{
    return m_apartmentNo;
}

const string& Address::getZipCode() const
{
    return m_zipCode;
}

void Address::save(ofstream& outFile) const
{
	outFile << m_country << endl;
	outFile << m_city << endl;
	outFile << m_street << endl;
	outFile << m_buildNo << endl;
	outFile << m_apartmentNo << endl;
	outFile << m_zipCode << endl;
}