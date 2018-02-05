#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int MakeFactorial(int number) {
	int total = 1;
	for (int counter = 1; counter <= number; counter++) {
		total = total * counter;
	}
	return total;
}

int Factorial() {
	int FactorialNumber;
	cout << "input a number: ";
	cin >> FactorialNumber;
	int outcome = MakeFactorial(FactorialNumber);
	cout << FactorialNumber << " Factorial is " << outcome << endl;
}