#include "Basket.h"

bool Basket::setCurrent(int current)
{
	m_current = current;
	return true;
}

//Basket::Basket()
//{
//	m_current = 0;
//	m_basket = nullptr;
//}

//Basket::~Basket()
//{
//	for (int i = 0; i < m_current; i++)
//		delete m_basket[i];
//
//	delete[] m_basket;
//}
