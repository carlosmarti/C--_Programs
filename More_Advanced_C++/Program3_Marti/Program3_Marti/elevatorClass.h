//File:elevatorClass.h
//Pro:Carlos Marti
//Purp:Simulate an elevator releasing and adding people as well as changing floors

#include<string>
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class elevator
{
private:
	int capacity;
	int passengers;
	int lowestFloor;
	int highestFloor;
	int currentFloor;
	int destinationFloor;

public:
	elevator(int, int, int, int);
	int getCapcity();
	int getPassengers();
	int getLowestFloor();
	int getHighestFloor();
	int getCurrentFloor();
	int getDestinationFloor();
	void loadPassengers(int);
	void offloadPassengers(int);
	void changeFloors(int);


};

elevator::elevator(int maxCap, int lowFloor, int highFloor, int curntFloor)
{
	passengers = 0;
	capacity = maxCap;
	lowestFloor = lowFloor;
	highestFloor = highFloor;
	currentFloor = curntFloor;
}

int elevator::getCapcity()
{
	return capacity;
}

int elevator::getPassengers()
{
	return passengers;
}

int elevator::getLowestFloor()
{
	return lowestFloor;
}

int elevator::getHighestFloor()
{
	return highestFloor;
}

int elevator::getCurrentFloor()
{
	return currentFloor;
}

int elevator::getDestinationFloor()
{
	return destinationFloor;
}

void elevator::loadPassengers(int passBoarding)
{
	//Variables
	int passNotAllowed;
	int passAllowed = 0;
	passengers += passBoarding;

	//Decision
	cout << "Amount of people tryng to board is: " << passBoarding << endl;
	if (passengers > capacity)
	{
		cout << "Cannot board That amount of people\n";
		
		passNotAllowed = passengers - capacity;
		cout << "The amount of people not allowed to board: " << passNotAllowed << endl;
		passengers -= passNotAllowed;
		passAllowed = passBoarding - passNotAllowed;
		
		cout << "Amount of people allowed to board: " << passAllowed << endl;
		cout << "The Amount of people on board: " << passengers << endl;
		
	}
	else
	{
		
		cout << "Amount of people on board: " << passengers << endl;
	}
}

void elevator::offloadPassengers(int passLeaving)
{
	
	cout << "The amount of people unboarding: " << passLeaving << endl;
	passengers -= passLeaving;
}

void elevator::changeFloors(int targetFloor)
{
	if (targetFloor <= highestFloor && targetFloor >= lowestFloor && targetFloor != currentFloor)
	{
		destinationFloor = targetFloor;
		if (destinationFloor > currentFloor)
		{
			while (currentFloor < destinationFloor - 1)
			{
				currentFloor++;
				cout << "\nPassing floor " << currentFloor;
			}
			cout << "\nYou have arrived at your Floor " << currentFloor + 1 << endl;
		}
		else
		{
			while (currentFloor > destinationFloor + 1)
			{
				currentFloor--;
				cout << "\nPassing Floor " << currentFloor;
			}
			cout << "\nYou have arrived at your Floor " << currentFloor - 1 << endl;
		}

	}
	if (targetFloor > highestFloor || targetFloor < lowestFloor)
	{
		
		cout << "The floor you have choosen is not a recongized floor.\n";
	}		
    if (targetFloor == currentFloor)
	{
		cout << "The elevator is already on this floor\n";
	}
	 
	
}