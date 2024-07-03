#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Date
{
	int day;
	int month;
	int year;

	bool isLeapYear() const; //Проверка на високосный год

	int monthDays() const; //Количество дней по месяцу

	void nextDate(); //Следующая дата

	void prevDate(); //Предыдущая дата

public:
	Date(); // По умолчанию  - текущая дата

	Date(int year, int month, int day); //С параметрами - заданная дата

	Date(const Date& obj); //Копирование

	Date& operator = (const Date& obj);

	~Date();// Деструктор

	void showDate() const;

	//---------АКСЕССОРЫ---------

	void setYear(int year);

	int getYear()const;

	void setMonth(int month);

	int getMonth()const;

	void setDay(int day);

	int getDay()const;

	bool valid()const; //Проверка даты на корректность
	
	//--------- ОПЕРАТОРЫ СРАВНЕНИЯ ---------

	bool operator == (const Date& obj)const&;

	bool operator != (const Date& obj)const&;

	bool operator > (const Date& obj)const&;

	bool operator < (const Date& obj)const&;

	bool operator >= (const Date& obj)const&;

	bool operator <= (const Date& obj)const&;

	//--------- ОПЕРАТОРЫ ПРИСВОЕНИЯ ---------     

	Date& operator += (int days); //добавить days дней к дате

	Date& operator -= (int days); //вычесть days дней из даты

	Date& operator += (float months); //добавить months месяцев к дате

	Date& operator -= (float months); //вычесть months месяцев из даты

	Date& operator += (long years); //добавить years лет к дате

	Date& operator -= (long years); //вычесть years лет из даты

	//--------- Arithmetic operators ---------

	Date operator + (int days)const&;

	Date operator - (int days)const&;

	Date operator + (float months)const&;

	Date operator - (float months)const&;

	Date operator + (long years)const&;

	Date operator - (long years)const&;

	//--------- Input/output operators ---------

	friend ostream& operator << (ostream& os, const Date& t);

	friend istream& operator >> (istream& is, Date& t);

	//--------- v2 arithmetic operators ---------

	friend Date operator + (int n, Date a);

	friend Date operator - (int n, Date a);

	Date& operator -- (); //prefix

	Date operator -- (int n); //postfix
	 
	Date& operator ++ (); //prefix

	Date operator ++ (int n); //postfix
};

