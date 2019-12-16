#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class Date
{
public:
	static constexpr unsigned int MAX_YEAR = 3000;
	static constexpr unsigned int MIN_YEAR = 2000;
	static constexpr unsigned int MAX_MONTH = 12;
	static constexpr unsigned int MIN_MONTH = 1;
	static constexpr unsigned int MAX_DAY = 31;
	static constexpr unsigned int MIN_DAY = 1;

private:
	unsigned int m_year;
	unsigned int m_month;
	unsigned int m_day;

	bool setYear(unsigned int year);
	bool setMonth(unsigned int month);
	bool setDay(unsigned int day);

public:
	Date(unsigned int year, unsigned int month, unsigned int day); //c'tor
	 //copy and move c'tor - we do not need to implement and we use the default constructor since it does not have memory allocation
	~Date(); //d'tor

	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
};

#endif //__DATE_H
