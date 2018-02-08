// Listar.cpp : Defines the entry point for the console application.
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

void LowHighMedianNumbers()
{
	int highestNumber;
	int lowestNumber;
	int MedianNumber;
	int MedianSelector = 0;
	int Average = 0;
	int AmountInArray = 5;
	std::array<int, 5> Listi{};
	for (int counter = 0; counter < AmountInArray; counter++) {
		int typed_number;
		std::cout << "insert a number: ";
		std::cin >> typed_number;
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
	
	std::cout << "the lowest number is: " << lowestNumber << std::endl;
	std::cout << "the highest number is: " << highestNumber << std::endl;
	std::cout << "the average is: " << Average << std::endl;
	std::cout << "the median is: " << MedianNumber << std::endl;

	std::cout << "the list is: [";
	for (const auto& value : Listi) {
		std::cout << value << " ";
	};
	std::cout << "]" << std::endl;
}

void RemoveAllAstrings() {
	std::array<std::string, 5> Cities{"reykjnesber","keflavik","akureyri","sandgedi","hofn"};
	std::array<std::string, 5> CitiesWithouta{};
	int counter = 0;
	
	for (const auto& cityName : Cities) {
		size_t found = cityName.find("a");
		if (found == cityName.npos) {
			CitiesWithouta[counter] = cityName;
			counter++;
		}
	}

	for (const auto& cityName : CitiesWithouta) {
		std::cout << cityName << std::endl;
	}
}

void NameVectorAddingAndPrinting() {
	int amount = 4;
	std::vector<std::string> NameVector(amount);
	std::string NameInput;
	for (int i = 0; i < amount; i++) {
		std::cout << "Insert a name: ";
		std::cin >> NameInput;
		NameVector.push_back(NameInput);
	}

	for (std::vector<std::string>::iterator it = NameVector.begin(); it != NameVector.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

void InsertNumbersIntoVectorAndFindAverage() {
	int Amount = 4;
	int NumberInsert;
	int total = 0;
	int number = 0;
	std::vector<int> NumberVector(Amount);
	for (int i = 0; i < Amount; i++) {
		std::cout << "insert a number: ";
		std::cin >> NumberInsert;
		NumberVector.push_back(NumberInsert);
	}
	for (std::vector<int>::iterator value = NumberVector.begin(); value != NumberVector.end(); ++value) {
		number = *value;
		total = total + number;
	}
	std::cout << "The average of these numbers is: " << total/Amount << std::endl;
}

void InsertTenThingsIntoVectorAndCheckForDupes() {
	int amount = 10;
	bool insertedBefore = false;
	std::string InsertData;
	std::vector<std::string> VectorList(amount);
	for (int i = 0; i < amount; i++) {
		std::cout << "insert something: ";
		std::cin >> InsertData;
		if (i == 0) {
			VectorList.push_back(InsertData);
		}
		else {
			for (std::vector<std::string>::iterator String = VectorList.begin(); String != VectorList.end(); ++String) {
				if (*String == InsertData) {
					insertedBefore = true;
					break;
				}
			}
			if (insertedBefore) {
				std::cout << "you've inserted that before!" << std::endl;
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
	std::vector<std::string>FirstV = {"name","text","something","this","things","computers"};
	std::vector<std::string>SecondV = { "computers","number","fun","name","else","isnt" };
	std::vector<std::string>BothVectors;
	std::vector<std::string>OnlyInFirst;
	std::vector<std::string>OnlyInSecond;
	std::vector<std::string>InBoth;

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

	std::cout << "these are only in vector a:" << std::endl;
	for (auto value : OnlyInFirst) {
		std::cout << value << std::endl;
	}
	std::cout << "these are only in vector b:" << std::endl;
	for (auto value : OnlyInSecond) {
		std::cout << value << std::endl;
	}
	std::cout << "these are in both: " << std::endl;
	for (auto value : InBoth) {
		std::cout << value << std::endl;
	}
}

void SortingOnTheGo() {
	std::vector<int>NumberVector = {1, 10, 6, 2, 9, 3, 5};
	int cought = 0;
	std::cout << "this is your current vector: " << std::endl;
	for (auto OriginalVector : NumberVector) {
		std::cout << OriginalVector << std::endl;
	}
	while (cought != '3')
	{
		std::cout << "choose your sorting methood" << std::endl << "1. sort it by size" << std::endl << "2. sort it by size in reverse" << std::endl << "3. exit" << std::endl;
		cought = _getch();
		if (cought == '1') {
			system("CLS");
			sort(NumberVector.begin(), NumberVector.end());
			std::cout << "your sorted vector: " << std::endl;
			for (auto value : NumberVector) {
				std::cout << value << std::endl;
			}
		}
		else if (cought == '2') {
			system("CLS");
			sort(NumberVector.rbegin(), NumberVector.rend());
			std::cout << "your sorted vector: " << std::endl;
			for (auto value : NumberVector) {
				std::cout << value << std::endl;
			}
		}
		else if (cought == '3'){}
		else {
			system("CLS");
			std::cout << "this is not an option" << std::endl;
		}
	}
}

void KeyValueVectorSortingOnTheGo() {
	std::map<std::string, int> ValueKeyMap = { {"Name", 12}, {"Another Name", 33}, {"Tomasz",11}, {"Milan", 30}, {"Daniel", 40} };
	std::vector<std::pair<std::string, int>> MapVector;
	int KeyPressed = 0;
	for (auto Val = ValueKeyMap.begin(); Val != ValueKeyMap.end(); Val++) {
		MapVector.push_back(*Val);
	}
	
	
	std::cout << "this is your list: " << std::endl;
	for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
		std::cout << Sorted->second << "    " << Sorted->first << std::endl;
	}

	while (KeyPressed != '5')
	{
		std::cout << "1. Sort Alphabetically" << std::endl << "2. Sort reverse Alphabetical" << std::endl << "3. by age in reverse" << std::endl << "4. Sort by age Sort" << std::endl << "5. exit";
		KeyPressed = _getch();
		if (KeyPressed == '1') {
			system("CLS");
			sort(MapVector.begin(), MapVector.end());
			for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
				std::cout << Sorted->second << "    " << Sorted->first << std::endl;
			}
		}

		else if (KeyPressed == '2') {
			system("CLS");
			sort(MapVector.rbegin(), MapVector.rend());
			for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
				std::cout << Sorted->second << "    " << Sorted->first << std::endl;
			}
		}
		else if (KeyPressed == '3') {
			system("CLS");
			sort(MapVector.begin(), MapVector.end(), [](auto &left, auto &right) {
				return left.second < right.second;
			});
			for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
				std::cout << Sorted->second << "    " << Sorted->first << std::endl;
			}
		}
		else if (KeyPressed == '4') {
			system("CLS");
			sort(MapVector.rbegin(), MapVector.rend(), [](auto &left, auto &right) {
				return left.second < right.second;
			});
			for (auto Sorted = MapVector.begin(); Sorted != MapVector.end(); Sorted++) {
				std::cout << Sorted->second << "    " << Sorted->first << std::endl;
			}
		}
		else if (KeyPressed == '5') {
			system("CLS");
			std::cout << "goodbye!" << std::endl;
		}
		else {
			system("CLS");
			std::cout << "this is not a valid option" << std::endl;
		}
	}
}

void VectorTuple() {
	std::vector<std::tuple<std::string, std::string, std::string, std::string>> IDVector{ {"One", "ID2", "3", "0000000000"},{ "Two", "ID1", "2", "1111111111" },{ "Jack", "ID4", "1", "2222222222" },{ "Tomasz", "ID3", "4", "3333333333" } };
	int TypedKey = 0;
	bool SortedByName = true;
	bool SortedByID = true;
	bool SortedByAge = true;
	bool SortedBySocialNumber = true;
	while (TypedKey != 'q') {
		std::cout << "SocialN(4)\t" << "Age(3)\t" << "ID(2)\t" << "Name(1)\t" << std::endl;
		for (const auto& value : IDVector) {
			std::cout << std::get<3>(value) << "\t" << std::get<2>(value) << "\t" << std::get<1>(value) << "\t" << std::get<0>(value) << std::endl;
		}
		std::cout << "You can sort by pressing the number inside the bracket, use q to quit";
		TypedKey = _getch();
		if (TypedKey == '1') {
			system("CLS");
			if (SortedByName) {
				sort(begin(IDVector), end(IDVector), [](auto const &t1, auto const &t2) {
					return std::get<0>(t1) < std::get<0>(t2); // or use a custom compare function
				});
				SortedByName = false;
			}
			else {
				sort(rbegin(IDVector), rend(IDVector), [](auto const &t1, auto const &t2) {
					return std::get<0>(t1) < std::get<0>(t2); // or use a custom compare function
				});
				SortedByName = true;
			}
		}
		else if (TypedKey == '2') {
			system("CLS");
			if (SortedByID) {
				sort(begin(IDVector), end(IDVector), [](auto const &t1, auto const &t2) {
					return std::get<1>(t1) < std::get<1>(t2); // or use a custom compare function
				});
				SortedByID = false;
			}
			else {
				sort(rbegin(IDVector), rend(IDVector), [](auto const &t1, auto const &t2) {
					return std::get<1>(t1) < std::get<1>(t2); // or use a custom compare function
				});
				SortedByID = true;
			}
		}
		else if (TypedKey == '3') {
			system("CLS");
			if (SortedByAge) {
				sort(begin(IDVector), end(IDVector), [](auto const &t1, auto const &t2) {
					return std::get<2>(t1) < std::get<2>(t2); // or use a custom compare function
				});
				SortedByAge = false;
			}
			else {
				sort(rbegin(IDVector), rend(IDVector), [](auto const &t1, auto const &t2) {
					return std::get<2>(t1) < std::get<2>(t2); // or use a custom compare function
				});
				SortedByAge = true;
			}
		}
		else if (TypedKey == '4') {
			system("CLS");
			if (SortedBySocialNumber) {
				sort(begin(IDVector), end(IDVector), [](auto const &t1, auto const &t2) {
					return std::get<3>(t1) < std::get<3>(t2); // or use a custom compare function
				});
				SortedBySocialNumber = false;
			}
			else {
				sort(rbegin(IDVector), rend(IDVector), [](auto const &t1, auto const &t2) {
					return std::get<3>(t1) < std::get<3>(t2); // or use a custom compare function
				});
				SortedBySocialNumber = true;
			}
		}
		else if (TypedKey == 'q') {
			system("CLS");
			std::cout << "goodbye!" << std::endl;
		}
		else {
			system("cls");
		}
	}
}

void VectorStructSorting() {
	struct Person
	{
		std::string Name;
		std::string ID;
		int Age;
		std::string SocialNumber;
	};
	std::vector<Person> people;
	int keyPressed = 0;
	bool sortedBySocialNum = false;
	bool sortedByID = false;
	bool sortedByAge = false;
	bool sortedByName = true;
	people.push_back(Person{ "Ao","ID3",17,"3005003660" });
	people.push_back(Person{ "Skitts","ID1",19,"0785982571" });
	people.push_back(Person{ "Akko","ID7",20,"1572973579" });
	people.push_back(Person{ "Boble","ID8",18,"0897994658" });

	while (keyPressed != 'q') {	
		std::cout << "Social Num(1)\t" << "ID(2)\t" << "Age(3)\t" << "Name(4)\t" << std::endl;
		for (auto PersonInfo : people) {
			std::cout << PersonInfo.SocialNumber << "\t" << PersonInfo.ID << "\t" << PersonInfo.Age << "\t" << PersonInfo.Name << std::endl;
		}
		std::cout << "press the number in the bracket to sort by it and press q to quit";
		keyPressed = _getch();
		system("cls");
		switch (keyPressed)
		{		
		case '1':
			if (sortedBySocialNum) {
				std::sort(people.begin(), people.end(), [](const Person& lhs, const Person& rhs) {return lhs.SocialNumber < rhs.SocialNumber; });
				sortedBySocialNum = false;
			}
			else {
				std::sort(people.rbegin(), people.rend(), [](const Person& lhs, const Person& rhs) {return lhs.SocialNumber < rhs.SocialNumber; });
				sortedBySocialNum = true;
			}
			break;

		case '2':
			if (sortedByID) {
				std::sort(people.begin(), people.end(), [](const Person& person1, const Person& person2) {return person1.ID < person2.ID; });
				sortedByID = false;
			}
			else {
				std::sort(people.rbegin(), people.rend(), [](const Person& lhs, const Person& rhs) {return lhs.ID < rhs.ID; });
				sortedByID = true;
			}
			break;

		case '3':
			if (sortedByAge) {
				std::sort(people.begin(), people.end(), [](const Person& lhs, const Person& rhs) {return lhs.Age < rhs.Age; });
				sortedByAge = false;
			}
			else {
				std::sort(people.rbegin(), people.rend(), [](const Person& lhs, const Person& rhs) {return lhs.Age < rhs.Age; });
				sortedByAge = true;
			}
			break;

		case '4':
			if (sortedByName) {
				std::sort(people.begin(), people.end(), [](const Person& lhs, const Person& rhs) {return lhs.Name < rhs.Name; });
				sortedByName = false;
			}
			else {
				std::sort(people.rbegin(), people.rend(), [](const Person& lhs, const Person& rhs) {return lhs.Name < rhs.Name; });
				sortedByName = true;
			}
			break;

		case 'q':
			std::cout << "goodbye!" << std::endl;
			break;
		
		default:
			break;
		}	
	}
}

int main() {
	//call what functions you want below here
	//functions avalible:
	//LowHighMedianNumbers, RemoveAllAstrings, NameVectorAddingAndPrinting, InsertNumbersIntoVectorAndFindAverage
	//InsertTenThingsIntoVectorAndCheckForDupes, OnlyInOne_OnlyInFirst_OnlyInSecond, SortingOnTheGo, KeyValueVectorSortingOnTheGo
	//VectorTuple and VectorStructSorting
	//you call them by using the name and adding (); at the end
}