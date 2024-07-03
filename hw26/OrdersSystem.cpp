#include "OrdersSystem.h"

void OrdersSystem::createNewOrder(Order order)
{
	orders.push_back(order);
}

void OrdersSystem::sortOrders()
{
	sort(orders.begin(), orders.end(), [](Order order1, Order order2) {
		return order1.getCookingTime() < order2.getCookingTime(); });
}

void OrdersSystem::comleteFirstOrder()
{
	sortOrders();
	orders.erase(orders.begin());
}

void OrdersSystem::showAll() const
{
	for (auto it = orders.begin(); it != orders.end(); it++) {
		it->showInfo();
		cout << endl;
	}
}
