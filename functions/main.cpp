#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Fibonacci(int NumberQuantity){
    double previous_number=0;
    double current_number=1;
    double next_number;
    if(NumberQuantity <= 0){
        return NULL;
    };


    for(int current_iteration = 2; current_iteration <= NumberQuantity; current_iteration++){
        //1. Finna hvert naesta gildi er.
        next_number=previous_number+current_number;


        previous_number=current_number;
        current_number=next_number;
        //next number er ordin osonn.
    };
    cout << current_number << endl;
}

int PowerOf(int number1, int number2){
    int Complete = number1;
    if(number2 < 0){
        return 0;
    };

    if(number2 == 0){
        return 1;
    };

    for(int i = 1; i < number2; i++){
        Complete = Complete * number1;
    };

    return Complete;
};

int PrintToNumber(int TopNumber){
    if(TopNumber < 0){
        cout << "the number is too low";
        return 0;
    };

    for(int i = 0; i <= TopNumber; i++){
        cout << i << endl;
    };
};

bool palindromeCheck(string Palindrome) {

    string originalName = Palindrome;

    std::transform(originalName.begin(), originalName.end(), originalName.begin(), ::tolower);
    std::transform(Palindrome.begin(), Palindrome.end(), Palindrome.begin(), ::tolower);

    originalName.erase(std::remove(originalName.begin(),originalName.end(), ' '),originalName.end());
    Palindrome.erase(std::remove(Palindrome.begin(),Palindrome.end(), ' '),Palindrome.end());


    int length = Palindrome.length();

	for (int i = 0; i < length/2; i++) {
        swap(Palindrome[i], Palindrome[length-i-1]);
	};

    if(originalName == Palindrome){
        return true;
	}
	else{
        return false;
	};
}

int main() {
	// Kallid a follin her inni
	double Input;
	cout << "Input a number: ";
	cin >> Input;
	Fibonacci(Input);

	/*
	//Power of
	int N1;
	int N2;
	int Total;
	cout << "Input one number: ";
	cin >> N1;
	cout << "Input another number: ";
	cin >> N2;

	Total = PowerOf(N1, N2);

	if(Total == 0){
        cout << "the second number cannot be lower or equal to 0";
	}
	else{
        cout << N1 << " to the power of " << N2 << " is " << Total;
	};*/

	/*
	//pring to number
	int InputNumber;
	cout << "input a number: ";
	cin >> InputNumber;
	PrintToNumber(InputNumber);*/

	/*
	//palindrome check
	string UIName;
	cout << "Enter a name: ";
	getline(cin, UIName);

	bool IsPalindrome = palindromeCheck(UIName);

	if(IsPalindrome){
        cout << "The word " << UIName << " is plaindrome!";
	}
	else{
        cout << "The word " << UIName << " is not palindrome :(";
	}*/
	return 0;
}
