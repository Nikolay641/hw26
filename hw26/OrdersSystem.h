#pragma once
#include <vector>
#include <algorithm>
#include "Order.h"

class OrdersSystem
{
	vector<Order> orders;

public:
	void createNewOrder(Order order);
	void sortOrders();
	void comleteFirstOrder();
	void showAll()const;
};

