#include "Order.h"
#include "OrdersSystem.h"
#include <cstdlib>

int Order::counter = 0;

int main()
{
	srand(time(0));
	OrdersSystem cafe;
	while (true) {
		string description;
		
		cout << "What do you want? ";
		getline(cin, description);
		float randomPrice = rand() % 70 + 30;
		float minutes = rand() % 14 + 1;
		Order order(description, randomPrice);
		order.setCookingTime(Time_(0, minutes, 0));
		cafe.createNewOrder(order);
		int choice = 0;
		cout << "Something else?(1-yes): ";
		cin >> choice;
		cin.ignore();
		if (choice == 1) {}
		else{
			break;
		}
	}
	cout << endl;
	cafe.showAll();

	cafe.comleteFirstOrder();
	cout << "\n---------------------------------------------------------\n\n";
	cafe.sortOrders();
	cafe.showAll();
}