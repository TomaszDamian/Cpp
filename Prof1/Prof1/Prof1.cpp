// Prof1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

//voiding every function because they dont return anything anyway so what's the point
void printColumns()
{
	cout << "input 4 numbers" << endl;
	array<int, 4> NumberArray = {};
	int typedNumber;
	for (int counter = 0; counter < 4; counter++) {
		cout << "input your number " << counter + 1 << ": ";
		cin >> typedNumber;
		NumberArray[counter] = typedNumber;
	};

	for (const auto& value : NumberArray) {
		for (int counter = 0; counter < value; counter++) {
			cout << "x";
		}
		cout << endl;
	}
}

//draws a triangle with the base at the bottom
void DrawTriangleDown(int Length) {
	for (int counter = 1; counter <= Length; counter++) {
		for (int amount = 0; amount < counter; amount++) {
			cout << "x";
		}
		cout << endl;
	}
}

//draws a box
void DrawBox(int size) {
	for (int counter = 0; counter < size; counter++) {
		for (int amount = 0; amount < size; amount++) {
			cout << "x";
		}
		cout << endl;
	}
}

//prints the base of the triangle on the top
void DrawTriangleUp(int length) {
	for (int counter = 0; counter < length; counter++) {
		for (int amount = 0; amount < length - counter; amount++) {
			cout << "x";
		}
		cout << endl;
	}
}

void DrawBranch(int BranchLength) {
	//made it < not <= so the triangle is just the spike and the box is the middle
	for (int SpikeDown = 1; SpikeDown < BranchLength; SpikeDown++) {
		for (int SpikeFat = 0; SpikeFat < SpikeDown; SpikeFat++) {
			cout << "x";
		}
		cout << endl;
	}
	for (int Boxheight = 0; Boxheight < BranchLength; Boxheight++) {
		for (int Boxlength = 0; Boxlength < BranchLength; Boxlength++) {
			cout << "x";
		}
		cout << endl;
	}
	//making this -1 so that the box is the middle of the tree and this triangle is the spike
	for (int SpikeUp = 0; SpikeUp < BranchLength - 1; SpikeUp++) {
		for (int SpikeUpFat = 0; SpikeUpFat < BranchLength - 1 - SpikeUp; SpikeUpFat++) {
			cout << "x";
		}
		cout << endl;
	}
}

//int can be a void but its not a standard
int main() {
	//print columns
	printColumns();
	
	//all variables needed in this
	int TriangleSize;
	int BoxSize;
	int ChristmasBranchSize;

	//triangle and box drawing
	cout << "input the size of the triangle: ";
	cin >> TriangleSize;
	cout << "input the box size: ";
	cin >> BoxSize;
	DrawTriangleDown(TriangleSize);
	cout << endl;
	DrawBox(BoxSize);
	cout << endl;
	DrawTriangleUp(TriangleSize);
	cout << endl;

	//branch Drawing
	cout << "how big do you want your christmas branch to be?: ";
	cin >> ChristmasBranchSize;
	DrawBranch(ChristmasBranchSize);
}

