#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class Order
{
	Date orderDate;
	Time_ orderTime;
	Time_ cookingTime;
	string description;
	float price;
	int orderNumber;

	static int counter;

public:
	Order(string description, float price);
	Date getOrderDate()const;
	Time_ getOrderTime()const;
	Time_ getCookingTime()const;
	string getDescription()const;
	float getPrice()const;
	int getOrderNumber()const;

	void setCookingTime(Time_ cookingTime);
	void setDescription(string description);
	void setPrice(float price);

	void showInfo()const;
};

