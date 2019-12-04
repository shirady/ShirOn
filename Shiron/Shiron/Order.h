#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
#include "Item.h"

class Order
{
public:
	static constexpr unsigned int INITIAL_PHYSICAL_SIZE = 1;
	static constexpr unsigned int INITIAL_LOGICAL_SIZE = 0;
	static constexpr bool INITIAL_OPEN_ORDER = true;
	static constexpr bool INITIAL_OPEN_PAYMENT = true;

private:
	unsigned int m_logicSizeItems;
	unsigned int m_physSizeItems;
	Item** m_allItemsOfOrder;
	bool m_openOrder;
	bool m_openPayment;

public:
	Order(unsigned int LogicSizeItemsOfCart); //c'tor
	Order(const Order& other); //copy c'tor
	~Order(); //d'tor

	bool setLogicSizeItems(unsigned int logicSizeItems);
	bool setPhysSizeItems(unsigned int physSizeItems);
	bool setOpenOrder(bool openOrder);
	bool setOpenPayment(bool openPayment);
	void reallocItems();
	bool addItemToOrder(Item* item);
};

#endif // __ORDER_H
