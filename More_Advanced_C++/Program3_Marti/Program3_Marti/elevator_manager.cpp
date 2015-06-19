//File:elevatorClass.h
//Pro:Carlos Marti
//Purp:Simulate an elevator releasing and adding people as well as changing floors

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>


using namespace std;

#include "elevatorClass.h"

int main()
{
	//srand(time(0));

	//Variables
	int floorEntered;
	int peopEntering = 0;
	int peopLeaving = 0;
	//Creating object
	elevator elevatorA(18, 1, 99, 40);

	//starting elevator 
	cout << "How many people would like to board?\n";
	cin >> peopEntering;
	elevatorA.loadPassengers(peopEntering);
	cout << "Enter the floor you would like to go to\n";
	cin >> floorEntered;
	elevatorA.changeFloors(floorEntered);

	//Second call
	cout << "How many people are unbaording?\n";
	cin >> peopLeaving;
	elevatorA.offloadPassengers(peopLeaving);
	cout << "How many people would like to board?\n";
	cin >> peopEntering;
    elevatorA.loadPassengers(peopEntering);
	cout << "Enter the floor you would like to go to\n";
	cin >> floorEntered;
	elevatorA.changeFloors(floorEntered);

	//Third call
	cout << "How many people are unbaording?\n";
	cin >> peopLeaving;
	elevatorA.offloadPassengers(peopLeaving);
	cout << "How many people would like to board?\n";
	cin >> peopEntering;
	elevatorA.loadPassengers(peopEntering);
	cout << "Enter the floor you would like to go to\n";
	cin >> floorEntered;
	elevatorA.changeFloors(floorEntered);

	//Fourth call
	cout << "How many people are unbaording?\n";
	cin >> peopLeaving;
	elevatorA.offloadPassengers(peopLeaving);
	cout << "How many people would like to board?\n";
	cin >> peopEntering;
	elevatorA.loadPassengers(peopEntering);
	cout << "Enter the floor you would like to go to\n";
	cin >> floorEntered;
	elevatorA.changeFloors(floorEntered);

	//Fifth call
	elevatorA.offloadPassengers(rand() % elevatorA.getPassengers());
	elevatorA.loadPassengers(rand() % peopEntering);
	cout << "Enter the floor you would like to go to\n";
	cin >> floorEntered;
	elevatorA.changeFloors(floorEntered);

	system("pause");
	return 0;

}