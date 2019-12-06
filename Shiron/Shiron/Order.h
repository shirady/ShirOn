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

private:
	unsigned int m_logicSizeItems;
	unsigned int m_physSizeItems;
	const Item** m_allItemsOfOrder;
	bool m_openOrder;

public:
	Order(unsigned int physSizeItems = INITIAL_PHYSICAL_SIZE); //c'tor
	Order(const Order& other); //copy c'tor
	~Order(); //d'tor

	bool setLogicSizeItems(unsigned int logicSizeItems);
	bool setPhysSizeItems(unsigned int physSizeItems);
	bool setOpenOrder(bool openOrder);
	void reallocItems();
	bool addItemToOrder(const Item* item);
	void removeItemFromOrder(const Item* item);

	unsigned int getLogicSizeItems() const;
	const Item** getAllItemsOfOrder() const;

	//void showOrder() const;

	const Item* findSerialNumber(unsigned int serialNumber) const;
	unsigned int getTotalPriceOfOrder() const;

};

#endif // __ORDER_H
