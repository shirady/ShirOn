//
//  Address.cpp
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#include "Date.h"
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

Date::Date(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::~Date()
{

}