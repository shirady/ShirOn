#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include <iostream>
#include <string.h>
#include "Date.h"
#include "Buyer.h"
using namespace std;
#pragma warning(disable: 4996)

class Feedback
{
public:
	static constexpr unsigned int MAX_LEN_FEEDBACK = 1500; 

private:
	const Buyer* m_buyer;
	char* m_feedback;
	Date m_date;

	bool setBuyer(const Buyer* buyer);
	bool setFeedback(const char* feedback); //you cannot change a feedback after it was sent

public:
	Feedback(const char* feedback, const Date& date, const Buyer* buyer); //c'tor // decide to stay without const Buyer buyer* since we had assignment between non-const pointer and const pointer
	Feedback(const Feedback& other) = delete; //copy c'tor
	~Feedback(); //d'tor

	const char* getFeedback(const char* feedback) const;
	const Date& getDate() const;
};

#endif //__FEEDBACK_H
