// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	bool stopFlag = true;
	int i;
	while (stopFlag) {
		cout << "Please enter a positive integer, or enter 0 to exit: ";
		cin >> i;
		if (i == 0) {
			stopFlag = false;
			cout << "Thank you for using my program \n";
			break;
		}
		cout << i * i << "\n";

	}
    return 0;
}

