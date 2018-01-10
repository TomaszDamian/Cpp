#include <iostream>

using namespace std;

void exampleFunction(string str) {
	int length = str.length();
	for(int i = 0; i < length; i++) {
		cout << str[i] << endl;
	}
}

string reverseString(string startString) {
	string reverseString = "";

	// Herna snuid thid vid inntakinu

	return reverseString;
}

bool palindromeCheck(string str) {

	int length = str.length();
    string OriginalName = str;

	for (int i = 0; i < length/2; i++) {
		swap(str[i], str[length-i-1]);
	};


    if(OriginalName == str){
        return true;
	}
	else{
        return false;
	};
}

int longestMatch(string str) {
	int maxCount = 0;

	// Herna finnid thid lengstu eins runu

	return maxCount;
}

int main() {
	// Kallid a follin her inni
	string UIName;
	cout << "Enter a name: ";
	cin >> UIName;

	bool IsPalindrome = palindromeCheck(UIName);

	if(IsPalindrome){
        cout << "The word " << UIName << " is plaindrome!";
	}
	else{
        cout << "The word " << UIName << " is not palindrome :(";
	}
	return 0;
}
