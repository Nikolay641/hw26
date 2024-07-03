#include "Order.h"

Order::Order(string description, float price)
{   
    counter++;
    orderDate = Date();
    orderTime = Time_();
    cookingTime = Time_(0, 15,0);
    this->description = description;
    this->price = price;
    orderNumber = counter;
}

Date Order::getOrderDate() const
{
    return orderDate;
}

Time_ Order::getOrderTime() const
{
    return orderTime;
}

Time_ Order::getCookingTime() const
{
    return cookingTime;
}

string Order::getDescription() const
{
    return description;
}

float Order::getPrice() const
{
    return price;
}

int Order::getOrderNumber() const
{
    return orderNumber;
}

void Order::setCookingTime(Time_ cookingTime)
{
    this->cookingTime.setSeconds(cookingTime.getSeconds());
    this->cookingTime.setMinutes(cookingTime.getMinutes());
    this->cookingTime.setHour(cookingTime.getHour());
}

void Order::setDescription(string description)
{
    this->description = description;
}

void Order::setPrice(float price)
{
    this->price = price;
}

void Order::showInfo() const
{
    cout << "Date: " << orderDate << endl;
    cout << "Time: " << orderTime << endl;
    cout << "Approximate cooking time: " << cookingTime << endl;
    cout << "Description: " << description << endl;
    cout << "To pay: " << price << endl;
    cout << "Your number: " << orderNumber << endl;
}
