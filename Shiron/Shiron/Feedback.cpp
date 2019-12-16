#include "Feedback.h"

Feedback::Feedback(const char* feedback, const Date& date, const Buyer* buyer) : m_date(date)
{
	feedback = nullptr;

	setBuyer(buyer);
	setFeedback(feedback);
}

Feedback::~Feedback()
{
	delete[] m_feedback;
}

bool Feedback::setBuyer(const Buyer* buyer)
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