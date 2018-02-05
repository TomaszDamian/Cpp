// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int AmountAfterXYears(float Years,float Percent,float state) {
	for (int i = 0; Years > i; i++) {
		state = state * Percent;
		cout << state << endl;
	}
	state = round(state);
	cout << "you will have " << state << " after " << Years << " years." << endl;
	return 0;
}

int AfterXyears() {
	float AmountOfYears;
	float GrowthPercent;
	float CurrentState;
	cout << "Input the amount of years: ";
	cin >> AmountOfYears;
	cout << "Input the growth percent: ";
	cin >> GrowthPercent;
	GrowthPercent = (GrowthPercent / 100) + 1;
	cout << "Input your current account state: ";
	cin >> CurrentState;
	AmountAfterXYears(AmountOfYears, GrowthPercent, CurrentState);
	return 0;
};

