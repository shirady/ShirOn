//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#ifndef __BASKET_H
#define __BASKET_H

#include <iostream>
#include <string.h>
#include "Item.h"
using namespace std;
#pragma warning(disable: 4996)

class Basket
{
public:
   // static const int MAX_LEN_SELLER_NAME      = 255;

private:
    int m_current;
    Item* m_basket;
    
public:
    bool setCurrent(int current);
    //Function to set basket
    Basket(int current);
    ~Basket(); //d'tor, Shira added parenthesis
    };

#endif //__BASKET_H
