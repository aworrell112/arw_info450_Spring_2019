// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	bool stopFlag = true;
	int i;
	while (stopFlag) {
		cout << "Please enter a positive year value, enter 0 to exit: ";
		cin >> i;
		if (i == 0) {
			cout << "Thank you for using my program \n";
			return 0;
		}
		else if (i % 100 == 0) {
			if (i % 400 == 0) {
				cout << "It is a leap year \n";
			}
			cout << "It is not a leap year \n";
		}
		else if (i % 4 == 0) {
			cout << "It is a leap year\n";
		}
		
	}
	

    return 0;
}

