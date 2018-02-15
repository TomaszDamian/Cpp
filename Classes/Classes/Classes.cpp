// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
};

void Human::WalkForward() {
	x += 1;
}

void Human::WalkBackwards() {
	x -= 1;
}

void Human::GoLeft() {
	y += 1;
}

void Human::GoRight() {
	y -= 1;
}

void Human::Talk(std::string SpeakingContent) {
	std::cout << SpeakingContent << std::endl;
}

int main()
{
	Human Person1 = { "Auriel",69,100 };
	Human Person2 = { "Miriada",250,55 };
	
	Person1.Talk("hello my name is " + Person1.NameOfHuman);
	std::this_thread::sleep_for(1s);
	Person2.Talk("hello " + Person1.NameOfHuman + " my name is " + Person2.NameOfHuman);
	std::this_thread::sleep_for(1s);
	Person1.Talk(Person1.NameOfHuman + ": This was a great conversation");
    return 0;
}

