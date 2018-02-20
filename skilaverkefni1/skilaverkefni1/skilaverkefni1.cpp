// skilaverkefni1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
		while (std::cin.fail() || std::cin.eof() || UserInput.find_first_not_of("0123456789") != std::string::npos) {

			std::cout << "The input is not correct please re-enter: ";

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
	std::vector<std::string> StringVecOne{ "this","is","fancy","microwave" };
	std::vector<std::string> StringVecTwo{ "this", "not", "so","fancy" };

}

int main() {
	FindMedianAverageLowHig();
	//std::cout << std::endl << std::endl;
	//SortingOut();
}