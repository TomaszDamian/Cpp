#include <iostream>
#include <string>
#include <algorithm>

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

}

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

int longestMatch(string str) {
	int maxCount = 0;

	// Herna finnid thid lengstu eins runu

	return maxCount;
}

int main() {
	// Kallid a follin her inni
	string UIName;
	cout << "Enter a name: ";
	getline(cin, UIName);

	bool IsPalindrome = palindromeCheck(UIName);

	if(IsPalindrome){
        cout << "The word " << UIName << " is plaindrome!";
	}
	else{
        cout << "The word " << UIName << " is not palindrome :(";
	}
	return 0;
}
