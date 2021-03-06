// prof2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include "conio.h"
#include <map>


// verkefni 1
void NamesUpperLower()
{
	std::cout << "assignment I" << std::endl;
	//vector made
	std::vector<std::string> Names{"Andres","Joel","Nicole","Camilla","Brian"};
	//variables that are needed
	std::string Pressed = "";
	int AmountPressed = 0;
	//while loop so you can just keep going
	while (Pressed != "q") {
		std::cout << "press H to display the names" << std::endl << "press it again to display the names in upper case" << std::endl << "press it the third time to display them all in lower case" << std::endl << "q to quit" << std::endl;
		Pressed = _getch();
		system("cls");
		std::cout << "Names: ";
		//catch if the pressed key is h
		if (Pressed == "h") {
			//if its the first press then this runs
			if (AmountPressed == 0) {
				for (auto value : Names) {
					//std::transform(Names.begin(), Names.end(), Names.begin(), ::tolower);
					std::cout << value << ", ";
				}
			}
			//second press 
			if (AmountPressed == 1) {
				for (auto value : Names) {
					std::transform(value.begin(), value.end(), value.begin(), ::toupper);
					std::cout << value << ", ";
				}
			}
			//third press
			if (AmountPressed == 2) {
				for (auto value : Names) {
					std::transform(value.begin(), value.end(), value.begin(), ::tolower);
					std::cout << value << ", ";
				}
			}
			//if its equal to 2 which is the thrid press it reserts down to 0 again
			//else the counter goes up by one
			if (AmountPressed != 2) {
				AmountPressed++;
			}
			else {
				AmountPressed = 0;
			}
			std::cout << std::endl;
		}
	}
}

//verkefni 2
void findInVectorAndAppend() {
	std::cout << "assignment II" << std::endl;
	std::vector<std::string> NamesInserted;
	std::vector<std::string> BannedNames{ "Victor","Adam","Kamilla" };
	std::string typed = "";
	std::string OriginalType;
	while (typed != "exit") {
		std::cout << "names in the list: ";
		for (auto val : NamesInserted) {
			std::cout << val << ", ";
		}
		std::cout << std::endl;
		bool isInList = false;
		bool CantInsert = false;
		std::cout << "enter the name you want to insert below here, you can type 'exit' to exit out" << std::endl;
		std::cout << "banned names are: ";
		for (auto val : BannedNames) { std::cout << val << ", "; }
		std::cout << std::endl;
		std::cin >> OriginalType;
		typed = OriginalType;
		std::transform(typed.begin(), typed.end(), typed.begin(), ::tolower);
		system("cls");
		for (auto BanName : BannedNames) {
			std::transform(BanName.begin(), BanName.end(), BanName.begin(), ::tolower);
			if (BanName == typed) {
				CantInsert = true;
				break;
			}
		}
		if (CantInsert) {
			std::cout << "You cannot add this name to the list!" << std::endl;
		}
		else {
			for (auto NameInArr : NamesInserted) {
				std::transform(NameInArr.begin(), NameInArr.end(), NameInArr.begin(), ::tolower);
				if (NameInArr == typed) {
					std::cout << "this name is already in the list" << std::endl;
					isInList = true;
					break;
				}
			}
			if (isInList){}
			else {
				NamesInserted.push_back(OriginalType);
			}
		}
	}
}

class Human {
	public:
		double x, y;
		std::string NameOfHuman;
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
void Human::reportLocation() {
	std::cout << NameOfHuman << ": " << std::endl << "x: " << x << std::endl << "y: " << y << std::endl;
}

void WalkingHuman(){
	std::string Char = "";
	Human Person1 = { 69,100,"player" };
	std::cout << "assignment III" << std::endl;;
	Person1.reportLocation();
	while (Char != "q"){
		Char = _getch();
		//left is a
		//up is w
		//down is s
		//right is d
		if (Char == "a") {
			Person1.GoLeft();
		}
		else if (Char == "w") {
			Person1.WalkForward();
		}
		else if (Char == "s") {
			Person1.WalkBackwards();
		}
		else if (Char == "d") {
			Person1.GoRight();
		}
		system("cls");
		std::cout << "assignment III" << std::endl;
		Person1.reportLocation();
		std::cout << "q to exit" << std::endl;
	}
}

int main() {
	//assignment 1
	NamesUpperLower();
	//assignment 2
	findInVectorAndAppend();
	//assignment 3
	WalkingHuman();
}