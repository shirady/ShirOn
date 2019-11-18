//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class Date
{

public:
    static const int MAX_YEAR        = 3000;
    static const int MIN_YEAR        = 2019;
    static const int MAX_MONTH       = 12;
    static const int MIN_MONTH       = 1;
    static const int MAX_DAY         = 31;
    static const int MIN_DAY         = 1;
    
private:
    int m_year;
    int m_month;
    int m_day;

public:
    bool setYear(int year);
    bool setMonth(int month);
    bool setDay(int day);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    Date(int year, int month, int day); //c'tor
    ~Date(); //d'tor, Shira added parenthesis
}; //copy and move c'tor - we do not need since it does not have memory allocation

#endif /* Address_h */
