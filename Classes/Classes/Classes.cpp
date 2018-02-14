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
};

void Human::Talk(std::string SpeakingContent) {
	std::cout << SpeakingContent << std::endl;
}

int main()
{
	Human Person1 = { "Name",2,3 };
	Human Person2 = { "Miriada",3,3 };
	
	Person1.Talk("hello my name is " + Person1.NameOfHuman);
	std::this_thread::sleep_for(2s);
	Person2.Talk("hello " + Person1.NameOfHuman + " my name is " + Person2.NameOfHuman);

    return 0;
}

