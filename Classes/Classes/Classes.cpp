// Classes.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class Human {
public:
	std::string NameOfHuman;
	double x, y;
	void Talk(std::string SpeakingContent);
	void WalkForward();
	void WalkBackwards();
	void GoLeft();
	void GoRight();
	void reportLocation();
};

void Human::WalkForward() {
	y += 1;
}

void Human::WalkBackwards() {
	y -= 1;
}

void Human::GoLeft() {
	x -= 1;
}

void Human::GoRight() {
	x += 1;
}

void Human::Talk(std::string SpeakingContent) {
	std::cout << NameOfHuman << ": " << SpeakingContent << std::endl;
}

void Human::reportLocation() {
	std::cout << NameOfHuman << ":" << std::endl << "x: " << x << std::endl << "y: " << y << std::endl;
}

void TalkingHumans()
{
	std::string Char;
	Human Person1 = { "Auriel",69,100 };
	Human Person2 = { "Miriada",250,55 };
	Person1.Talk("hello my name is " + Person1.NameOfHuman);
	std::this_thread::sleep_for(1s);
	Person2.Talk("hello " + Person1.NameOfHuman + " my name is " + Person2.NameOfHuman);
	std::this_thread::sleep_for(1s);
	Person1.Talk(Person1.NameOfHuman + ": This was a great conversation");
	std::cout << "press a arrow key:" << std::endl;
	while (true)
	{
		Char = _getch();
		//left is K
		//up is H
		//down is P
		//right is M
		if (Char == "K") {
			Person1.GoLeft();
		}
		else if (Char == "H") {
			Person1.WalkForward();
		}
		else if (Char == "P") {
			Person1.WalkBackwards();
		}
		else if (Char == "M") {
			Person1.GoRight();
		}
		system("cls");
		Person1.reportLocation();
	}
}

class Car {
	public:
		std::string Name;
		int horsepower;
		double x, y;

		void ReportLocation();

		Car(std::string name, int hp, double x, double y) :Name(name), horsepower(hp), x(x), y(y) {}
};

void Car::ReportLocation() {
	std::cout << Name << std::endl << "x: " << x << std::endl << "y: " << y << std::endl;
}

class ArmouredCar : public Car {
	public:
		float ArmourRating;
	
		ArmouredCar(std::string name, int hp, double x, double y, float rating) : ArmourRating(rating), Car(name, hp, x, y) {}
};


int main() {
	float rating = 1.2;
	ArmouredCar ThisCar{ "name",33,100,50,rating };
	Car OtherCar{ "Other Car",100,50,10 };
	ThisCar.ReportLocation();
	OtherCar.ReportLocation();
}