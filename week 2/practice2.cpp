// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	bool stopFlag = true;
	int i;
	while (stopFlag) {
		cout << "Please entera number to determine if it is prime, enter 0 to exit: ";
		cin >> i;
		if (i == 0) {
			stopFlag = false;
			cout << "Thank you for using my program \n";
			break;
		}
		else if (i == 2) {
			cout << "The number is prime \n";
			continue;
		}
		else if (i == 3) {
			cout << "The number is prime \n";
			continue;
		}
		else if (i % 2 == 0) {
			cout << "The number is not prime \n";
			continue;
		}
		else if (i % 3 == 0) {
			cout << "The number is not prime \n";
			continue;
		}
		
		else {
			bool breakout = true;
			int x = 5;
			int y = 2;
			while (x * x <= i) {
				if (i % x == 0) {
					cout << "The number is not prime \n";
					breakout = false;
					break;
				}


				x += y;
				y = 6 - y;
			}
			if (breakout) {
				cout << "The number is prime \n";
			}
			
		}
	}
    return 0;
}

