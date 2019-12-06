#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include <iostream>
#include <string.h>
#include "Date.h"
#include "Buyer.h"
using namespace std;
#pragma warning(disable: 4996)

//class Buyer

class Feedback
{
public:
	static constexpr unsigned int MAX_LEN_FEEDBACK = 1500; //check

private:
	Buyer* m_buyer;
	char* m_feedback;
	Date m_date;

public:
	bool setBuyer(Buyer* buyer);
	bool setFeedback(const char* feedback);

	const char* getFeedback(const char* feedback);
	const Date& getDate();

	Feedback(const char* feedback, const Date& date, Buyer* buyer);
	Feedback(const Feedback& other) = delete;
	~Feedback(); //d'tor
};

#endif //__FEEDBACK_H
