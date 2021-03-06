#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>


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
	virtual void show();
};
void road_vehicle::show() {
	cout << "it is working?" << endl;
}

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
	stream << obj.get_cargo() << endl;
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
		stream << "car" << endl;
		break;
	case van:
		stream << "van" << endl;
		break;
	case wagon:
		stream << "wagon" << endl;
		break;
	}
	return stream; //Hyper important.
}
struct node
{
	string data;
	node *next;
};

class list
{
private:
	node * head, *tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void createnode(string value) {
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
			cout << temp->data<<endl;
			temp = temp->next;
		}
	}
};

int main()
{
	ifstream myfile("output.txt");
	list vehlist;
	if (myfile.is_open())
	{
		bool stopFlag = true;
		int count = 1;
		while(stopFlag){
			char line[255];
			int wheels;
			int passengers;
			int cargo;
			char vehicletype[255];
			char automobiletype[255];
			
			myfile.getline(line, 255);
			if (strcmp(line, "") == 0) {
				stopFlag = false;
			}
			else {
				if (count == 1) {
					strcpy_s(vehicletype, line);
					count++;
				}
				else if (count == 2) {
					wheels = atoi(line);
					count++;
				}
				else if (count == 3) {
					passengers = atoi(line);
					count++;
				}
				else if (count == 4) {
					if (strcmp(vehicletype, "truck") == 0) {
						cargo = atoi(line);
						count = 1;
						string JSON = "{\"road_vehicle\": \"truck\", \"wheels\": "+to_string(wheels)+", \"passengers\": "+to_string(passengers)+", \"cargo\": "+to_string(cargo)+"}";
						vehlist.createnode(JSON);
					}
					else if (strcmp(vehicletype, "automobile") == 0) {
						strcpy_s(automobiletype, line);
						count = 1;
						string vehtype = automobiletype;
						string JSON = "{\"road_vehicle\": \"automobile\", \"wheels\": " + to_string(wheels) + ", \"passengers\": " + to_string(passengers) + ", \"type\": \""+vehtype+"\"}";
						vehlist.createnode(JSON);
					}
				}
			}
		}
		

	}

	vehlist.display();
    return 0;
}

