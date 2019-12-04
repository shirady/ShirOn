#include "Buyer.h"

Buyer::Buyer(const User& user): m_user(user)
{
	m_Cart = new Cart;
}

Buyer::Buyer(const Buyer& other): m_user(other.m_user)
{
	m_Cart = new Cart(* (other.getCart()));
}

Buyer::~Buyer()
{
	delete m_Cart;
}

User& Buyer::getUser() 
{
	return m_user;
}

Cart* Buyer::getCart() const
{
	return m_Cart;
}
