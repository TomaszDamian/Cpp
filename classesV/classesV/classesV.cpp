// classesV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class DayOfYear {
public:
	void input();
	void output();

	void set(int new_month, int new_day);
	int get_month();
	int get_day();

private:
	void check_date();
	int month;
	int day;
};

void Date()
{
	DayOfYear today, bach_birthday;
	std::cout << "Ener today's date: " << std::endl;
	today.input();
	std::cout << "Today's date is: " << std::endl;
	today.output();

	bach_birthday.set(3, 21);
	std::cout << "J.S. Bach's birthday is : " << std::endl;
	bach_birthday.output();

	if (today.get_month() == bach_birthday.get_month() && today.get_day() == bach_birthday.get_day())
		std::cout << "Happy Birthday Johann Sebastian! " << std::endl;
	else
		std::cout << "Happy unbirthday Johann Sebastian! " << std::endl;
}

void DayOfYear::input() {
	std::cout << "Enter the month as number: ";
	std::cin >> month;
	std::cout << "Enterthe day of the month: ";
	std::cin >> day;
	check_date();
}

void DayOfYear::output() {
	std::cout << month << "/" << day << std::endl;
}

void DayOfYear::set(int new_month, int new_day) {
	month = new_month;
	day = new_day;
	check_date();
}

void DayOfYear::check_date() {
	if ((month < 1) || (month > 12) || (day < 1) || (day > 31)) {
		std::cout << "Illegal date. Aborting program." << std::endl;
		exit(1);
	}
}

int DayOfYear::get_month() {
	return month;
}

int DayOfYear::get_day() {
	return day;
}

int main() {
	//Date();
}
