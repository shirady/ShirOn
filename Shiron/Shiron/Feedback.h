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
    static constexpr unsigned int MAX_LEN_SELLER_NAME      = 255;
    static constexpr unsigned int MAX_LEN_RESPONDER_NAME   = 255;
    static constexpr unsigned int MAX_LEN_FEEDBACK         = 255;

private:
    char* m_sellerName;
    char* m_responderName;
    char* m_feedback;
    Date m_date;
    
public:
    bool setSellerName(const char* sellerName);
    bool setResponderName(const char* responderName);
    bool setFeedback(const char* feedback);
    //bool setfeedBackDate(const char* feedback);

    const char* getSellerName(const char* sellerName);
    const char* getResponderName(const char* responderName);
    const char* getFeedback(const char* feedback);

    Feedback(const char* sellerName, const char* responderName, const char* feedback, Date&& date) : m_date(date)//c'tor;
    {
        setSellerName(sellerName);
        setResponderName(responderName);
        setFeedback(feedback);
        cout << "The date is: " <<m_date.getYear() << "/" << m_date.getMonth() << "/" << m_date.getDay();
        cout << "The seller name is: " << m_sellerName;
        cout << "The responder name is: " << m_responderName;
        cout << "The feedback is: " << m_feedback;
    }
    ~Feedback(); //d'tor
    };

#endif //__FEEDBACK_H
