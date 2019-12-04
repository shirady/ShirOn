#include "Order.h"
//
//Order::Order(unsigned int LogicSizeItemsOfCart)
//{
//	setLogicSizeItems(INITIAL_LOGICAL_SIZE);
//	setPhysSizeItems(LogicSizeItemsOfCart); //LogicSizeItemsOfCart is the physicSize of the order
//	m_allItemsOfOrder = new Item*[m_physSizeItems];
//	setOpenOrder(INITIAL_OPEN_ORDER);
//}
//
//bool Order::setLogicSizeItems(unsigned int logicSizeItems)
//{
//	if (logicSizeItems >= 0)
//	{
//		m_logicSizeItems = logicSizeItems;
//		return true;
//	}
//	return false;
//}
//
//bool Order::setPhysSizeItems(unsigned int physSizeItems)
//{
//	if (physSizeItems >= 1)
//	{
//		m_physSizeItems = physSizeItems;
//		return true;
//	}
//	return false;
//}
//
//bool Order::setOpenOrder(bool openOrder)
//{
//	m_openOrder = openOrder;
//}
//
