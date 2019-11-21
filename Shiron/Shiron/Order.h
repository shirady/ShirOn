//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <string.h>
#include "Item.h"
using namespace std;
#pragma warning(disable: 4996)

class Order
{
public:
   // static const int MAX_LEN_SELLER_NAME      = 255;

private:
    int m_current;
    Item* m_order;
    bool payment;
    bool openOrder;
    
public:
    bool setCurrent(int current);
    //Function to set busket
    Order(int current);
    ~Order(); //d'tor, Shira added parenthesis
    };

#endif /* Address_h */ //Shira moved it to the end
