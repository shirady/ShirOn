#include "Feedback.h"

Feedback::Feedback(const char* feedback, const Date& date, const Buyer& buyer) : m_date(date), m_buyer(buyer)
{
	m_feedback = nullptr;

	//setBuyer(buyer);
	setFeedback(feedback);
}

Feedback::~Feedback()
{
	delete[] m_feedback;
}

ostream& operator<<(ostream& os, const Feedback& feedback) //global function
{
	os << "From buyer: " << feedback.m_buyer.getUserName() << ", Date: " << feedback.m_date << ", The feedback:" << feedback.m_feedback;
	return os;
}

bool Feedback::setFeedback(const char* feedback)
{
	delete[] m_feedback;
	unsigned int name_len = strlen(feedback);
	if (name_len < (MAX_LEN_FEEDBACK - 1))
	{
		m_feedback = new char[strlen(feedback) + 1];
		strcpy(m_feedback, feedback);
		return true;
	}
	else
		return false;
}

const char* Feedback::getFeedback(const char* feedback) const
{
	return m_feedback;
}

const Date& Feedback::getDate() const
{
	return m_date;
}