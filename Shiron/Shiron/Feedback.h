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
	static constexpr unsigned int MAX_LEN_FEEDBACK = 1500; //check

private:
	Buyer* m_buyer;
	char* m_feedback;
	Date m_date;

public:
	Feedback(const char* feedback, const Date& date, Buyer* buyer); //c'tor
	Feedback(const Feedback& other) = delete; //copy c'tor
	~Feedback(); //d'tor

	bool setBuyer(Buyer* buyer);
	bool setFeedback(const char* feedback);

	const char* getFeedback(const char* feedback);
	const Date& getDate();
};

#endif //__FEEDBACK_H
