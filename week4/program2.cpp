// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
string classNames[1][30];

string emptyString = "";
bool stopFlag = true;

int main()
{
	int count = 0;
	while ((stopFlag) && count < 30) {
		string input;
		cout << "Enter a name, or press enter to terminate\n";
		getline(cin, input);
		if (input == "") {
			stopFlag = false;
		}
		else {
			classNames[0][count] = input;
			count++;
		}


	}
	cout << "These are the students in the class\n";
	for (int i = 0; i < 30; i++) {
		if (classNames[0][i] == "") {
			continue;
		}
		cout << classNames[0][i] << "\n";
	}
	return 0;
}
