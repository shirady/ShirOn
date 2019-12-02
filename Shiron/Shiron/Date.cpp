#include "Date.h"

bool Date::setYear(unsigned int year)
{
    if(year >= MIN_YEAR && year <= MAX_YEAR)
    {
        m_year=year;
        return true;
    }
    else
        return false;
}

bool Date::setMonth(unsigned int month)
{
    if(month >= MIN_MONTH && month <= MAX_MONTH)
    {
        m_month=month;
        return true;
    }
    else
        return false;
}

bool Date::setDay(unsigned int day)
{
    if(day >= MIN_DAY && day <= MAX_DAY)
    {
        m_day=day;
        return true;
    }
    else
        return false;
}

unsigned int Date::getYear() const
{
    return m_year;
}

unsigned int Date::getMonth() const
{
    return m_month;
}

unsigned int Date::getDay() const
{
    return m_day;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::~Date()
{

}