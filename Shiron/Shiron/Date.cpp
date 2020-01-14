#include "Date.h"

Date::Date(int year, int month, int day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

//Empty d'tor - hidden
//Date::~Date()
//{
//
//}

ostream& operator<<(ostream& os, const Date& date)//global function
{
	os << date.m_day << "/" << date.m_month << "/" << date.m_year;
	return os;
}


bool Date::setYear(int year)
{
    if(year >= MIN_YEAR && year <= MAX_YEAR)
    {
        m_year=year;
        return true;
    }
    else
        return false;
}

bool Date::setMonth(int month)
{
    if(month >= MIN_MONTH && month <= MAX_MONTH)
    {
        m_month=month;
        return true;
    }
    else
        return false;
}

bool Date::setDay(int day)
{
    if(day >= MIN_DAY && day <= MAX_DAY)
    {
        m_day=day;
        return true;
    }
    else
        return false;
}

int Date::getYear() const
{
    return m_year;
}

int Date::getMonth() const
{
    return m_month;
}

int Date::getDay() const
{
    return m_day;
}