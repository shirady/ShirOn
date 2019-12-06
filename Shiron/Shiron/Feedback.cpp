#include "Feedback.h"


bool Feedback::setBuyer(Buyer* buyer)
{
	if (buyer != nullptr)
	{
		m_buyer = buyer;
		return true;
	}
	else
		return false;
}

bool Feedback::setFeedback(const char* feedback)
{
	//delete[] m_feedback; //will not run unless m_userName was allocated
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

const char* Feedback::getFeedback(const char* feedback)
{
	return m_feedback;
}

const Date& Feedback::getDate()
{
	return m_date;
}

Feedback::Feedback(const char* feedback, const Date& date, Buyer* buyer) : m_date(date)
{
	setBuyer(buyer);
	setFeedback(feedback);
}

Feedback::~Feedback()
{
	delete[] m_feedback;
}
