// skilaverkefni1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string>
#include <vector>

void FindMedianAverageLowHig()
{
	//initialising the vector and userInput so I can append it into the vector
	std::string UserInput;
	int UserInputAsInt;
	
	std::vector<int> Numbers;
	//for loop to input 5 numbers into the array I should prob be doing some kind of check if the number is a number not a string
	for (int amountOfNumbersInVector = 1; amountOfNumbersInVector <= 5; amountOfNumbersInVector++) {
		std::cout << "insert a number:";
		std::getline(std::cin, UserInput);
		//checks if the cin has letters inside of it
		while (std::cin.fail() || std::cin.eof() || UserInput.find_first_not_of("0123456789") != std::string::npos) {

			std::cout << "The input is not correct please re-enter: ";
			//asks for the input again
			if (UserInput.find_first_not_of("0123456789") == std::string::npos) {
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}

			std::getline(std::cin, UserInput);
		}
		std::string::size_type st;
		UserInputAsInt = std::stoi(UserInput, &st);
		Numbers.push_back(UserInputAsInt);
	}
	system("cls");
	std::cout << "Assignment 1:" << std::endl;
	//to find the median of the number you have to find the middle
	int VectorLength = Numbers.size();
	
	//then divide it by two and you have the number because the vectors start on a 0 not a 1
	//also I should add that the number 2.5 doesnt become 3 when inted but 2 so it works perfectly
	int MiddleAmount = VectorLength / 2;

	//sorting it by size so that I can just select the middle number
	std::sort(Numbers.begin(), Numbers.end());

	//check if the number is even or odd
	if (VectorLength % 2 == 0) {
		//inside here it will take the 2 numbers that are in the middle and find the average of them
		int firstMedian = Numbers[MiddleAmount];
		int secondMedian = Numbers[MiddleAmount + 1];
		int MedianAverage = firstMedian + secondMedian / 2;
		std::cout << "the median of the list is: " << MedianAverage << std::endl;
	}
	else {
		//the same thing as above but it doesnt have to find the average but just the middle number
		int firstMedian = Numbers[MiddleAmount];
		std::cout << "the median of the list is: " << firstMedian << std::endl;
	}
	
	//find the highest number is easy since I can just select the last thing in the vector
	//lowest number is basically the same thing but I'm selecting the first thing in the vector
	int LowestNumber = Numbers[0];
	int HighestNumber = Numbers[VectorLength - 1];
	std::cout << "Highest number: " << HighestNumber << std::endl << "Lowest Number: " << LowestNumber << std::endl;

	//finding the average isn't too complicated you jus go with a for loop throught the whole vector adding the amount to one veriable
	int total = 0;
	for (auto Number : Numbers) {
		total = total + Number;
	}
	//then you just divide it by the amount in the vector
	int Average = total / VectorLength;
	std::cout << "The Average of the list is: " << Average << std::endl;
	
	//now just print out the vector
	std::cout << "this is your sorted list: [ ";
	for (auto Number : Numbers) {
		std::cout << Number << " ";
	}
	std::cout << "]" << std::endl;
}

void SortingOut() {
	std::cout << "Assignment 2:" << std::endl;
	//made vectors for each thing I needed to know
	std::vector<std::string> VectorOne{ "this","is","fancy","microwave" };
	std::vector<std::string> VectorTwo{ "this", "not", "so","fancy" };
	std::vector<std::string> InBoth;
	std::vector<std::string> OnlyInFirst;
	std::vector<std::string> OnlyInSecond;
	
	std::cout << "vector one: [ ";
	for (auto Value : VectorOne) {
		//finds if the value can be found inside the VectorTwo vector and appends into InBoth if its found
		if (std::find(VectorTwo.begin(), VectorTwo.end(), Value) != VectorTwo.end()) {
			InBoth.push_back(Value);
		}
		//else its appended into a vector that has only things from VectorOne
		else {
			OnlyInFirst.push_back(Value);
		}
		//just printing the value while I'm at in for the cout above
		std::cout << Value << ", ";
	}
	std::cout << "]" << std::endl;

	std::cout << "vector two: [ ";
	for (auto Value : VectorTwo) {
		//if its found in VectorOne do nothing
		if (std::find(VectorOne.begin(), VectorOne.end(), Value) != VectorOne.end()) {}
		//else append into vector with values only from VectorTwo
		else {
			OnlyInSecond.push_back(Value);
		}
		//do the same as above printing out the values while I have them
		std::cout << Value << ", ";
	}
	std::cout << "]" << std::endl;
	
	std::cout << "These values are in both: [ ";
	for (auto val : InBoth) {
		std::cout << val << ", ";
	}
	std::cout << "]" << std::endl;

	std::cout << "These are only in the first Vector: [";
	for (auto val : OnlyInFirst) {
		std::cout << val << ", ";
	}
	std::cout << "]" << std::endl;

	std::cout << "These are only in the second Vector: [";
	for (auto val : OnlyInSecond) {
		std::cout << val << ", ";
	}
	std::cout << "]" << std::endl;
}

void SortingOntheFly() {
	std::cout << "Assignment 3: " << std::endl;
	std::string Coughtcharacter = "";
	std::vector<int> NumberVector{ 123,243,23423445,435342,123,54,34213,34 };
	bool sorted = false;
	while (Coughtcharacter != "q") {
		std::cout << "Here is your list of numbers: [" <<std::endl;
		for (auto val: NumberVector)
		{
			std::cout << val << "," << std::endl;
		}
		std::cout << "]" << std::endl;
		std::cout << "Press F to sort by size and then press again to sort it in reverse, q to exit" << std::endl;
		std::cout << "!!!WARNING THIS WILL CLEAR THE SCREEN!!!";
		Coughtcharacter = _getch();
		if (Coughtcharacter == "f") {
			//sorting normally
			if (sorted) {
				sort(NumberVector.begin(), NumberVector.end());
				sorted = false;
			}
			//sorting the other way around
			else {
				sort(NumberVector.rbegin(), NumberVector.rend());
				sorted = true;
			}
		}
		system("cls");
		if (Coughtcharacter == "q") {
			std::cout << "goodbye!" << std::endl;
		}
	}
}

int main() {
	//verkefni 1
	FindMedianAverageLowHig();
	std::cout << std::endl << std::endl;
	//verkefni 2
	SortingOut();
	std::cout << std::endl << std::endl;
	//verkefni 3
	SortingOntheFly();
}