//
//  Address.cpp
//  Shiron
//
//  Created by Oron Bortman on 17/11/2019.
//  Copyright © 2019 Oron Bortman. All rights reserved.
//

#include "Feedback.h"
/*
 static const int MAX_LEN_SELLER_NAME      = 255;
 static const int MAX_LEN_RESPONDER_NAME   = 255;
 static const int MAX_LEN_FEEDBACK         = 255;

 */
bool Feedback::setSellerName(const char* sellerName)
{
    delete[] m_sellerName; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(sellerName);
    if (name_len < (MAX_LEN_SELLER_NAME - 1))
    {
        m_sellerName = new char[strlen(sellerName) + 1]; //check allocation is missing
        strcpy(m_sellerName, sellerName);
        return true;
    }
    else
        return false;
}
bool Feedback::setResponderName(const char* responderName)
{
    delete[] m_responderName; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(responderName);
    if (name_len < (MAX_LEN_RESPONDER_NAME - 1))
    {
        m_responderName = new char[strlen(responderName) + 1]; //check allocation is missing
        strcpy(m_responderName, responderName);
        return true;
    }
    else
        return false;
}
bool Feedback::setFeedback(const char* feedback)
{
    delete[] m_feedback; //will not run unless m_userName was allocated
    unsigned int name_len = strlen(feedback);
    if (name_len < (MAX_LEN_FEEDBACK - 1))
    {
        m_feedback = new char[strlen(feedback) + 1]; //check allocation is missing
        strcpy(m_feedback, feedback);
        return true;
    }
    else
        return false;
}
const char* Feedback::getSellerName(const char* sellerName)
{
    return m_sellerName;
}
const char* Feedback::getResponderName(const char* responderName)
{
    return m_responderName;
}
const char* Feedback::getFeedback(const char* feedback)
{
    return m_feedback;
}

Feedback::Feedback(char* sellerName, char* responderName, char* feedback)//c'tor
{
    setSellerName(sellerName);
    setResponderName(responderName);
    setFeedback(feedback);
}

Feedback::~Feedback()//d'tor, Shira added parenthesis
{
    delete[] m_sellerName;
    delete[] m_responderName;
    delete[] m_feedback;
}
