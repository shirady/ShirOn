#include "Buyer.h"

Buyer::Buyer(const User& user): m_user(user)
{
	m_Cart = new Cart;
	m_Order = new Order;
}

Buyer::Buyer(const Buyer& other): m_user(other.m_user)
{
	m_Cart = new Cart(*(other.getCart()));
	m_Order = new Order(*(other.getOrder()));
}

Buyer::~Buyer()
{
	delete m_Cart;
	delete m_Order;
}

User& Buyer::getUser() 
{
	return m_user;
}

Cart* Buyer::getCart() const
{
	return m_Cart;
}

Order* Buyer::getOrder() const
{
	return m_Order;
}