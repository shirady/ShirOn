#include "Buyer.h"

Buyer::Buyer(User& user): m_user(user)
{

}

Buyer::Buyer(const Buyer& other): m_user(other.m_user)
{

}

Buyer::~Buyer()
{

}