// TextFileReading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
int main() {
	std::ifstream ColumnOne;
	std::ifstream ColumnTwo;
	std::string output;
	std::vector<NameAndAge> people;
	while (std::getline(ColumnOne, output)) {
		people.push_back(NameAndAge{ output, 0 });
	}
	while (std::getline(ColumnTwo, output)) {
		toint
		output
		people[counter].age = output;
	}
	return 0;
}