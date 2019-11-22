//
//  Address.h
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include <iostream>
#include <string.h>
#include "Date.h"
using namespace std;
#pragma warning(disable: 4996)

class Feedback
{
public:
    static const int MAX_LEN_SELLER_NAME      = 255;
    static const int MAX_LEN_RESPONDER_NAME   = 255;
    static const int MAX_LEN_FEEDBACK         = 255;

private:
    char* m_sellerName;
    char* m_responderName;
    char* m_feedback;
    Date feedBackDate; // did you omit the "m_" on purpose?
    
public:
    bool setSellerName(const char* sellerName);
    bool setResponderName(const char* responderName);
    bool setFeedback(const char* feedback);
    bool setfeedBackDate(const char* feedback);

    const char* getSellerName(const char* sellerName);
    const char* getResponderName(const char* responderName);
    const char* getFeedback(const char* feedback);

    Feedback(const char* sellerName, const char* responderName, const char* feedback, int year, int month, int day) : feedBackDate(year, month, day)//c'tor
    {
        setSellerName(sellerName);
        setResponderName(responderName);
        setFeedback(feedback);
        cout << "The date is: " <<feedBackDate.getYear() << "/" << feedBackDate.getMonth() << "/" << feedBackDate.getDay();
        cout << "The seller name is: " << m_sellerName;
        cout << "The responder name is: " << m_responderName;
        cout << "The feedback is: " << m_feedback;
    }
    ~Feedback(); //d'tor, Shira added parenthesis
    };

#endif /* Address_h */ //Shira moved it to the end
