// TextFileReading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>



int printIntoSixFiles() {
	std::string Input;
	std::ofstream myfile;
	for (int i = 1; i < 6; i++) {
		std::string name = std::to_string(i);
		myfile.open(name);
		std::cout << "what do you want to insert into the file?: " << std::endl;
		std::getline(std::cin, Input);
		myfile << Input;
		myfile.close();
	}

	for (int i = 1; i < 6; i++) {
		std::string name = std::to_string(i);
		std::ifstream file(name);
		std::string output;
		while (std::getline(file, output)) {
			std::cout << name << ":" << std::endl;
			//std::transform(output.begin(), output.end(), output.begin(), ::toupper);
			std::cout << output << std::endl;
		}
	}
	/*
	std::ifstream file("new_file");
	std::string str;
	while (std::getline(file, str)) {
		std::cout << str << std::endl;
	}
	*/
	return 0;
}
struct NameAndAge
{
	std::string Name;
	int age;
};
void SaveChanges(std::vector<std::string> FileNames, std::vector<NameAndAge> data) {
	std::ofstream AgeFile;
	std::ofstream NameFile;
	NameFile.open(FileNames[0]);
	AgeFile.open(FileNames[1]);
	for (auto val : data) {
		NameFile << val.Name << std::endl;
	}
	for (auto val : data) {
		AgeFile << val.age << std::endl;
	}
	NameFile.close();
	AgeFile.close();
}
NameAndAge AddPerson() {
	std::string Name;
	int age;
	std::cout << "Insert the new person's name: ";
	std::cin >> Name;
	std::cout << "Insert the new person's age: ";
	std::cin >> age;
	return NameAndAge{ Name, age };
}
int main() {
	std::ifstream ColumnOne("columnOne.txt");
	std::ifstream ColumnTwo("columnTwo.txt");
	std::string output;
	std::vector<NameAndAge> people;
	std::vector<std::string> files{ "columnOne.txt","columnTwo.txt" };
	int counter = 0;
	int Keycought = 0;
	int selected = 0;
	while (std::getline(ColumnOne, output)) {
		people.push_back(NameAndAge{ output, 0 });
	}
	while (std::getline(ColumnTwo, output)) {
		int intOutput = std::stoi(output);
		people[counter].age = intOutput;
		counter++;
	}

	counter = 0;
	while (Keycought != 'q') {

		std::cout << "w to go up in the list and s to go down in the list" << std::endl;
		std::cout << "press 1 to edit selected's age and 2 to edit their name" << std::endl;
		std::cout << "press 3 to add a new person to the table and 4 to delete the selected person" << std::endl;
		counter = 0;
		for (auto val : people) {
			if (counter == selected) {
				std::cout << val.age << "\t\t" << "(" << val.Name << ")" << std::endl;
			}
			else {
				std::cout << val.age << "\t\t" << val.Name << std::endl;
			}
			counter++;
		}
		std::cout << "q to quit" << std::endl;

		Keycought = _getch();
		system("cls");
		auto VectorSize = people.size();

		switch (Keycought)
		{
			case 's': {
				selected++;
				if (selected >= VectorSize) {
					selected = 0;
				}
				break;
			}
			case 'w': {
				selected--;
				if (selected < 0) {
					selected = VectorSize - 1;
				}
				break;
			}

			case '1': {
				int newAge;
				std::cout << "Insert your new age here: ";
				std::cin >> newAge;
				people[selected].age = newAge;
				SaveChanges(files, people);
				break;
			}

			case '2': {
				std::string NewName;
				std::cout << "Insert your new name here: ";
				std::cin >> NewName;
				people[selected].Name = NewName;
				system("cls");
				SaveChanges(files, people);
				break;
			}
			case '3': {
				NameAndAge NewPerson = AddPerson();
				people.push_back(NewPerson);
				SaveChanges(files, people);
				break;
			}
			case '4': {
				std::string CselectedName = people[selected].Name;
				std::cout << CselectedName;
				people.erase(
					std::remove_if(people.begin(), people.end(), [&](NameAndAge const & person) {
					return person.Name == CselectedName;
				}),
				people.end());
				SaveChanges(files, people);
				break;
			}
		}
		
	}
	return 0;
}

