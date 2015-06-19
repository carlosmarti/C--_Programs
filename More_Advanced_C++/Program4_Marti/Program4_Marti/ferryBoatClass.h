//File:ferryBoatClass.h
//Pro:Carlos Marti
//Purp:Simulate a ferryboat running through ports and loading and unloading passengers
#include<string>
#include<stdlib.h>
#include<iostream>
#include<ctime>

using namespace std;

class FerryBoat
{
private:
	string boatID;
	int currentPort;
	int destPort;
	int numPorts;
	int passengers;
	int capacity;
	

public:
	FerryBoat(int, int, int, string);
	string getBoatID();
	int getCurrentPort();
	int getDestPort();
	int getNumPorts();
	int getPassengers();
	int getCapacity();
	bool FerryBoat::getBoatDown();
	int genRandNumber(int);
	void loadPassengers();
	void offLoadPassengers();
	void changePort(int);

};

FerryBoat::FerryBoat(int numPortsOnRoute, int maxCapacity, int startingPort, string shipID)
{
	//Giving the object values
	passengers = 0;
	numPorts = numPortsOnRoute;
	capacity = maxCapacity;
	currentPort = startingPort;
	boatID = shipID;
	destPort = currentPort;
	srand(time(0));
}

int FerryBoat::getCurrentPort()
{
	return currentPort;
}

string FerryBoat::getBoatID()
{
	return boatID;
}

int FerryBoat::getDestPort()
{
	return  destPort;
}

int FerryBoat::getNumPorts()
{
	return numPorts;
}

int FerryBoat::getPassengers()
{
	return passengers;
}

int FerryBoat::genRandNumber(int maxValue)
{
	return (rand() % (maxValue + 1));
}

void FerryBoat::loadPassengers()
{
	//Variables
	int passNotAllowed;
	int passAllowed = 0;
	int amountPeople = 0;
	int passBoarding = genRandNumber(125);
	int extraPassengers = 0;



	//Decision
	cout << "Amount of people wanting to board: " << passBoarding << endl;
	amountPeople = passengers + passBoarding;

	//Checking to see if the amount of people is greater than the amount allowed
	if (amountPeople > capacity)
	{
		cout << "The ferry boat Cannot hold that amount of people\n";

		passNotAllowed = amountPeople - capacity;
		cout << "The amount of people not allowed to board the ferry boat: " << passNotAllowed << endl;

		passAllowed = capacity - passengers;
		passengers += passAllowed;

		cout << "Amount of people allowed to board the ferry boat: " << passAllowed << endl;
		cout << "The Amount of people on board: " << passengers << endl;

	}
	else
	{
		passengers += passBoarding;
		cout << "Amount of people on board: " << passengers << endl;
	}
}

void FerryBoat::offLoadPassengers()
{
	//generating a random number of peple leaving
	int totalDeparting = genRandNumber(passengers);

	cout << "The amount of people departing: " << totalDeparting << endl;

	passengers -= totalDeparting;

}

void FerryBoat::changePort(int destinationPort)
{
	//Testing if destinationPort is greater than 20
	if (destinationPort > numPorts)
	{
		cout << " Port does not Exist.\n";
	}
	else
	{
		destPort = destinationPort;

		cout << "Leaving port " << currentPort << " for port " << destPort << " with " << passengers << " passengers.\n";
		currentPort = destPort;

		cout << "We've arrived at Port #" << currentPort << ".\n\n";
	}

}