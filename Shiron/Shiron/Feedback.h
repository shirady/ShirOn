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
    

public:
    bool setSellerName(const char* sellerName);
    bool setResponderName(const char* responderName);
    bool setFeedback(const char* feedback);
    const char* getSellerName(const char* sellerName);
    const char* getResponderName(const char* responderName);
    const char* getFeedback(const char* feedback);

    Feedback(char* sellerName, char* responderName, char* feedback); //c'tor
    ~Feedback(); //d'tor, Shira added parenthesis

};

#endif /* Address_h */ //Shira moved it to the end
