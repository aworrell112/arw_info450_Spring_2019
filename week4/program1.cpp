// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int numbers[10];

	for (int i = 0; i <= 9; i++) {
		cout << "Enter a whole number\n";
		cin >> numbers[i];
	}



	int sum = 0;
	double avg;
	for (int i = 0; i <= 9; i++) {
		sum += numbers[i];
	}

	avg = double(sum) / 10.0;

	double sq_diff[10];

	for (int i = 0; i <= 9; i++) {
		sq_diff[i] = pow((double(numbers[i]) - avg), 2);
	}

	double totalsqdiff = 0.0;
	for (int i = 0; i <= 9; i++) {
		totalsqdiff += sq_diff[i];
	}
	double totalvar = totalsqdiff / 10.0;
	cout << "The mean is: " << avg << endl;
	cout << "Standard Deviation is: " << sqrt(totalvar);


}
