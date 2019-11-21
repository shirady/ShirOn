//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#ifndef __BUSKET_H
#define __BUSKET_H

#include <iostream>
#include <string.h>
#include "Item.h"
using namespace std;
#pragma warning(disable: 4996)

class Busket
{
public:
   // static const int MAX_LEN_SELLER_NAME      = 255;

private:
    int m_current;
    Item* m_busket;
    
public:
    bool setCurrent(int current);
    //Function to set busket
    Busket(int current);
    ~Busket(); //d'tor, Shira added parenthesis
    };

#endif /* Address_h */ //Shira moved it to the end
