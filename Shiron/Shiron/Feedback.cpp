#include "Feedback.h"

Feedback::Feedback(const string& feedback, const Date& date, const Buyer& buyer) : m_date(date), m_buyer(buyer)
{
	setFeedback(feedback);
}

ostream& operator<<(ostream& os, const Feedback& feedback) //global function
{
	os << "From buyer: " << feedback.m_buyer.getUserName() << ", Date: " << feedback.m_date << ", The feedback:" << feedback.m_feedback;
	return os;
}

bool Feedback::setFeedback(const string& feedback)
{
    unsigned int feedback_len = feedback.length();
	if (feedback_len < (MAX_LEN_FEEDBACK - 1))
	{
        m_feedback=feedback;
		return true;
	}
	else
		return false;
}

const string& Feedback::getFeedback() const
{
	return m_feedback;
}

const Date& Feedback::getDate() const
{
	return m_date;
}
