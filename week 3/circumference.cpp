// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
double calculateCircumference(double radius);
const double pi = 3.14159;
double x = 0.0;

using namespace std;

int main()
{
	cout << "Please provide a radius for a circle you want to know the circumference of: ";
	cin >> x;
	cout << "The circumference is: " << calculateCircumference(x) << endl;
    return 0;
}

double calculateCircumference(double radius) {
	double cir = 2 * radius * pi;
	return cir;
}