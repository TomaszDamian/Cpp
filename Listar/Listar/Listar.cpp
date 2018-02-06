﻿// Listar.cpp : Defines the entry point for the console application.
//you have to rename what you want to use into `int main(){}` or else it obviously wont work
//also you can just make another main and call the functions there.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include "conio.h"
#include <map>

using namespace std;

void LowHighMedianNumbers()
{
	int highestNumber;
	int lowestNumber;
	int MedianNumber;
	int MedianSelector = 0;
	int Average = 0;
	int AmountInArray = 5;
	array<int, 5> Listi{};
	for (int counter = 0; counter < AmountInArray; counter++) {
		int typed_number;
		cout << "insert a number: ";
		cin >> typed_number;
		Listi[counter] = typed_number;
	}
	
	//sort the list so that you can just select the first and last to get highest and lowest
	sort(begin(Listi), end(Listi));

	//defining lowest and highest number in array
	highestNumber = Listi[AmountInArray-1];
	lowestNumber = Listi[0];

	//average still has to be a for loop
	//this loop finds the total and then you devide it by the amount of numbers later
	for (const auto& number : Listi) {
		Average = Average + number;
	};
	Average = Average / AmountInArray;

	//need something to find the median
	//I need to know how many things are inside the array
	//I have a variable for that so thats not a problem
	
	if (AmountInArray % 2 == 1) {
		//normally I would do +1 but arrays start on 0 not 1
		MedianSelector = AmountInArray / 2;
		MedianNumber = Listi[MedianSelector];
	}
	//else is just if the AmountInArray is equal to an eaven number and so I can take both middle numbers and devide them by 2
	else {
		MedianSelector = AmountInArray;
		MedianNumber = (Listi[MedianSelector] + Listi[MedianSelector + 1]) / 2;
	}
	
	cout << "the lowest number is: " << lowestNumber << endl;
	cout << "the highest number is: " << highestNumber << endl;
	cout << "the average is: " << Average << endl;
	cout << "the median is: " << MedianNumber << endl;

	cout << "the list is: [";
	for (const auto& value : Listi) {
		cout << value << " ";
	};
	cout << "]" << endl;
}

void RemoveAllAstrings() {
	array<string, 5> Cities{"reykjnesber","keflavik","akureyri","sandgedi","hofn"};
	array<string, 5> CitiesWithouta{};
	int counter = 0;
	
	for (const auto& cityName : Cities) {
		size_t found = cityName.find("a");
		if (found == cityName.npos) {
			CitiesWithouta[counter] = cityName;
			counter++;
		}
	}

	for (const auto& cityName : CitiesWithouta) {
		cout << cityName << endl;
	}
}

void NameVectorAddingAndPrinting() {
	int amount = 4;
	vector<string> NameVector(amount);
	string NameInput;
	for (int i = 0; i < amount; i++) {
		cout << "Insert a name: ";
		cin >> NameInput;
		NameVector.push_back(NameInput);
	}

	for (vector<string>::iterator it = NameVector.begin(); it != NameVector.end(); ++it) {
		cout << *it << endl;
	}
}

void InsertNumbersIntoVectorAndFindAverage() {
	int Amount = 4;
	int NumberInsert;
	int total = 0;
	int number = 0;
	vector<int> NumberVector(Amount);
	for (int i = 0; i < Amount; i++) {
		cout << "insert a number: ";
		cin >> NumberInsert;
		NumberVector.push_back(NumberInsert);
	}
	for (vector<int>::iterator value = NumberVector.begin(); value != NumberVector.end(); ++value) {
		number = *value;
		total = total + number;
	}
	cout << "The average of these numbers is: " << total/Amount << endl;
}

void InsertTenThingsIntoVectorAndCheckForDupes() {
	int amount = 10;
	bool insertedBefore = false;
	string InsertData;
	vector<string> VectorList(amount);
	for (int i = 0; i < amount; i++) {
		cout << "insert something: ";
		cin >> InsertData;
		if (i == 0) {
			VectorList.push_back(InsertData);
		}
		else {
			for (vector<string>::iterator String = VectorList.begin(); String != VectorList.end(); ++String) {
				if (*String == InsertData) {
					insertedBefore = true;
					break;
				}
			}
			if (insertedBefore) {
				cout << "you've inserted that before!" << endl;
				i--;
				insertedBefore = false;
			}
			else {
				VectorList.push_back(InsertData);

			}
		}
	}
}

void OnlyInOne_OnlyInFirst_OnlyInSecond() {
	vector<string>FirstV = {"name","text","something","this","things","computers"};
	vector<string>SecondV = { "computers","number","fun","name","else","isnt" };
	vector<string>BothVectors;
	vector<string>OnlyInFirst;
	vector<string>OnlyInSecond;
	vector<string>InBoth;

	for (auto value : FirstV) {
		BothVectors.push_back(value);
	}

	for (auto value : SecondV) {
		BothVectors.push_back(value);
	}
 
	for (auto value : FirstV) {
		if (find(SecondV.begin(), SecondV.end(), value) != SecondV.end()) {
			InBoth.push_back(value);
		}
		else {
			OnlyInFirst.push_back(value);
		}
	}

	for (auto value : SecondV) {
		if (find(FirstV.begin(), FirstV.end(), value) != FirstV.end()) {}
		else {
			OnlyInSecond.push_back(value);
		}
	}

	cout << "these are only in vector a:" << endl;
	for (auto value : OnlyInFirst) {
		cout << value << endl;
	}
	cout << "these are only in vector b:" << endl;
	for (auto value : OnlyInSecond) {
		cout << value << endl;
	}
	cout << "these are in both: " << endl;
	for (auto value : InBoth) {
		cout << value << endl;
	}
}

void SortingOnTheGo() {
	vector<int>NumberVector = {1, 10, 6, 2, 9, 3, 5};
	int cought = 0;
	cout << "this is your current vector: " << endl;
	for (auto OriginalVector : NumberVector) {
		cout << OriginalVector << endl;
	}
	while (cought != '3')
	{
		cout << "choose your sorting methood" << endl << "1. sort it by size" << endl << "2. sort it by size in reverse" << endl << "3. exit" << endl;
		cought = _getch();
		if (cought == '1') {
			system("CLS");
			sort(NumberVector.begin(), NumberVector.end());
			cout << "your sorted vector: " << endl;
			for (auto value : NumberVector) {
				cout << value << endl;
			}
		}
		else if (cought == '2') {
			system("CLS");
			sort(NumberVector.rbegin(), NumberVector.rend());
			cout << "your sorted vector: " << endl;
			for (auto value : NumberVector) {
				cout << value << endl;
			}
		}
		else if (cought == '3'){}
		else {
			system("CLS");
			cout << "this is not an option" << endl;
		}
	}
}

int KeyValueVectorSortingOnTheGo() {
	map<string, int> ValueKeyMap = { {"Name", 12}, {"Another Name", 33}, {"Tomasz",11}, {"Milan", 30}, {"Daniel", 40} };
	vector<pair<string, int>> MapVector;
	int KeyPressed = 0;
	for (auto Val = ValueKeyMap.begin(); Val != ValueKeyMap.end(); Val++) {
		MapVector.push_back(*Val);
	}
	
	
	cout << "this is your list: " << endl;
	for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
		cout << Sorted->second << "    " << Sorted->first << endl;
	}

	while (KeyPressed != '5')
	{
		cout << "1. Sort Alphabetically" << endl << "2. Sort reverse Alphabetical" << endl << "3. by age in reverse" << endl << "4. Sort by age Sort" << endl << "5. exit";
		KeyPressed = _getch();
		if (KeyPressed == '1') {
			system("CLS");
			sort(MapVector.begin(), MapVector.end());
			for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
				cout << Sorted->second << "    " << Sorted->first << endl;
			}
		}

		else if (KeyPressed == '2') {
			system("CLS");
			sort(MapVector.rbegin(), MapVector.rend());
			for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
				cout << Sorted->second << "    " << Sorted->first << endl;
			}
		}
		else if (KeyPressed == '3') {
			system("CLS");
			sort(MapVector.begin(), MapVector.end(), [](auto &left, auto &right) {
				return left.second < right.second;
			});
			for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
				cout << Sorted->second << "    " << Sorted->first << endl;
			}
		}
		else if (KeyPressed == '4') {
			system("CLS");
			sort(MapVector.rbegin(), MapVector.rend(), [](auto &left, auto &right) {
				return left.second < right.second;
			});
			for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
				cout << Sorted->second << "    " << Sorted->first << endl;
			}
		}
		else if (KeyPressed == '5') {
			system("CLS");
			cout << "goodbye!" << endl;
		}
		else {
			system("CLS");
			cout << "this is not a valid option" << endl;
		}
	}
}
