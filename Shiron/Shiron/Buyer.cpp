#include "Buyer.h"

Buyer::Buyer(const User& user): m_user(user)
{
	m_basket = new Basket;
}

Buyer::Buyer(const Buyer& other): m_user(other.m_user)
{
	m_basket = new Basket(* (other.getBasket()));
}

Buyer::~Buyer()
{
	delete m_basket;
}

User& Buyer::getUser() 
{
	return m_user;
}

Basket* Buyer::getBasket() const
{
	return m_basket;
}
