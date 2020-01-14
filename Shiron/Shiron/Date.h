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
	int m_year;
	int m_month;
	int m_day;

	bool setYear(int year);
	bool setMonth(int month);
	bool setDay(int day);

public:
	Date(int year, int month, int day); //c'tor
	 //copy and move c'tor - we do not need to implement and we use the default constructor since it does not have memory allocation
	//~Date(); //d'tor

	friend ostream& operator<<(ostream& os, const Date& date);

	int getYear() const;
	int getMonth() const;
	int getDay() const;
};

#endif //__DATE_H
