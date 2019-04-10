// Week9Hw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
class road_vehicle {
	int wheels;
	int passengers;
public:
	void set_wheels(int num) {
		wheels = num;
	}
	int get_wheels() {
		return wheels;
	}
	void set_passengers(int num) {
		passengers = num;
	}
	int get_passengers() {
		return passengers;
	}
};

class truck : public road_vehicle {
	int cargo;
	
public:
	char name[255] = "truck";
	void set_cargo(int size) {
		cargo = size;
	}
	int get_cargo() {
		return cargo;
	}
	void show(); //not yet defined!
	
};
ostream &operator<<(ostream &stream, truck obj) {
	stream << obj.name << endl;
	stream << obj.get_wheels() << endl;
	stream << obj.get_passengers() << endl;
	stream << obj.get_cargo();
	return stream; //Hyper important.
}

enum type { car, van, wagon };

class automobile : public road_vehicle {
	enum type car_type;
	
public:
	char name[255] = "automobile";
	void set_type(type t) { car_type = t; }
	enum type get_type() { return car_type; }
	void show();
};
ostream &operator<<(ostream &stream, automobile obj) {
	stream << obj.name << endl;
	stream << obj.get_wheels() << endl;
	stream << obj.get_passengers() << endl;
	switch (obj.get_type()) {
	case car:
		stream << "car";
		break;
	case van:
		stream << "van";
		break;
	case wagon:
		stream << "wagon";
		break;
	}
	return stream; //Hyper important.
}

struct node
{
	road_vehicle data;
	node *next;
};

class list
{
private:
	node *head, *tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void createnode(road_vehicle value){
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void display()
	{
		node *temp = new node;
		temp = head;
		while (temp != NULL)
		{
			//some display code here
			temp = temp->next;
		}
	}
};


int main()
{
	char vehtype[255];
	int wheels;
	int passengers;
	int cargo;
	char cartype[255];
	bool stopflag = true;
	char input[255];
	list vehiclelist;
	
	
	while (stopflag) {
		cout << "Is this an automobile or a truck? Enter 'automobile' or 'truck'" << endl;
		cin >> vehtype;
		cout << "How many wheels does this vehicle have?" << endl;
		cin >> wheels;
		cout << "How many passengers can this vehicle hold?" << endl;
		cin >> passengers;
		if (strcmp(vehtype, "truck")==0) {
			cout << "How much cargo (in pounds) can this vehicle hold?" << endl;
			cin >> cargo;
			truck t;
			t.set_wheels(wheels);
			t.set_passengers(passengers);
			t.set_cargo(cargo);
			vehiclelist.createnode(t);
			cout << t << endl;
		}
		else if (strcmp(vehtype, "automobile") == 0) {
			cout << "What type of automobile is this?   Enter van, car or wagon" << endl;
			cin >> cartype;
			automobile a;
			a.set_wheels(wheels);
			a.set_passengers(passengers);
			if (strcmp(cartype, "car") == 0) {
				a.set_type(car);
			}
			else if (strcmp(cartype, "van") == 0) {
				a.set_type(van);
			}
			else if (strcmp(cartype, "wagon") == 0) {
				a.set_type(wagon);
			}
			vehiclelist.createnode(a);
			cout << a << endl;
		}
		cout << "Would you like to enter another vehicle? yes or no" << endl;
		cin >> input;
		if (strcmp(input, "no") == 0) {
			stopflag = false;
		}
	}

	vehiclelist.display();


	return 0;

}

void truck::show() {
	cout << "wheels: " << get_wheels() << endl;
	cout << "passengers: " << get_passengers() << endl;
	cout << "cargo: " << get_cargo() << endl;
}

void automobile::show() {
	cout << "wheels: " << get_wheels() << endl;
	cout << "passengers: " << get_passengers() << endl;
	cout << "type: ";
	switch (get_type()) {
	case car:
		cout << "car";
		break;
	case van:
		cout << "van";
		break;
	case wagon:
		cout << "wagon";
		break;
	}
	cout << endl;
}