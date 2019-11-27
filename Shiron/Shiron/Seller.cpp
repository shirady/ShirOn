#include "Seller.h"

Seller::Seller(const User& user) : m_user(user)
{

}

Seller::Seller(const Seller& other) : m_user(other.m_user)
{

}

Seller::~Seller()
{

}
