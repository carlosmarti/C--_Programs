//File:ShuttleBoatClass.h
//Pro:Carlos Marti
//Purp:Simulate a shuttle boat that will pickup and drop off customers until there is no one on ether ports.

#include<iostream>
#include<time.h>
#include<stdlib.h>

class ShuttleBoat
{

private:
	int boatCapacity;
	int homePort;
	int movePort;
	int vacationPort;
	int homePassAmount = 0;
	int vacaPassAmount = 0;
	int homePortPeopBoarded = 0;
	int vacaPortPeopBoarded = 0;

public:
	ShuttleBoat(int, int, int, int, int);
	int getHomePort();
	int getVacationPort();
	int getHomePassAmount();
	int getVacaPassAmount();
	int getMovePort();
	int genRandNumber();
	void homePortLoadPassangers();
	void vacaPortLoadPassengers();
	void homePortOffLoadPassengers();
	void vacaPortOffLoadPassengers();
	void changePort(int);
};

ShuttleBoat::ShuttleBoat(int cruiseCapacity, int startPort, int destPort, int homePassengers, int vacaPassengers)
{
	homePortPeopBoarded = 0;
	vacaPortPeopBoarded = 0;
	movePort = 0;
	boatCapacity = cruiseCapacity;
	homePort = startPort;
	vacationPort = destPort;
	homePassAmount = homePassengers;
	vacaPassAmount = vacaPassengers;
	srand(time(0));
}

int ShuttleBoat::getHomePort()
{
	return homePort;
}

int ShuttleBoat::getVacaPassAmount()
{
	return vacaPassAmount;
}

int ShuttleBoat::getVacationPort()
{
	return vacationPort;
}

int ShuttleBoat::getHomePassAmount()
{
	return homePassAmount;
}

int ShuttleBoat::getMovePort()
{
	return movePort;
}

int ShuttleBoat::genRandNumber()
{
	return (rand() % (4 + 1));
}

void ShuttleBoat::homePortLoadPassangers()
{
	int passDelayed = genRandNumber();

	if (homePassAmount > boatCapacity)
	{
		homePortPeopBoarded = 125 - passDelayed;
			
		//Output and 1 calculation 
		cout << "\nThere are " << homePassAmount << " number of people to pick up at home port.\n";
		//if there where customers that missed the boat show how many
		if (passDelayed != 0)
		{
			cout << "Some passengers missed the boat the amount was: " << passDelayed << "they will have to catch the next one.\n";
		}
		homePassAmount = homePassAmount - homePortPeopBoarded;
		cout << "Boarding: " << homePortPeopBoarded << " For this trip.\n";
		cout << "There are " << homePassAmount << " Left on Home port.\n";
	}
	else if (homePassAmount == 0)
	{
		//Output
		cout << "\nAll of the customers have been picked up in Home Port # " << homePort << endl;
		
	}
	else
	{
		homePortPeopBoarded += homePassAmount - passDelayed;
		
		//Output
		cout << "There are " << homePassAmount << " number of people to pick up at home port.\n";
		//if there where customers that missed the boat show how many
		if (passDelayed != 0)
		{
			cout << "Some passengers missed the boat the amount was: " << passDelayed << "they will have to catch the next one.\n";
		}
		homePassAmount -= homePortPeopBoarded;
		cout << "Boarding: " << homePortPeopBoarded << " For this trip.\n";
		cout << "There are " << homePassAmount << " Left on Home port.\n";
	}

}

void ShuttleBoat::vacaPortLoadPassengers()
{	 

	if (vacaPassAmount > boatCapacity)
	{
		vacaPortPeopBoarded = 125;


		//Output and 1 calculation 
		cout << "\nThere are " << vacaPassAmount << " number of people to pick up at vacation hotspot Port# " << vacationPort << endl;
		vacaPassAmount -= vacaPortPeopBoarded;
		cout << "Only able to board: " << vacaPortPeopBoarded << " For this trip.\n";
		cout << "There are " << vacaPassAmount << " Left on Vacation port.\n";
	}
	else if (vacaPassAmount == 0)
	{
		//Output
		cout << "\nAll of the customers have been picked up in Port# " << vacationPort << " vacation hotspot.\n";
		
	}
	else
	{
		vacaPortPeopBoarded += vacaPassAmount;

		//Output
		cout << "\nThere are " << vacaPassAmount << " number of people to pick up at vacation hotspot.\n";
		vacaPassAmount -= vacaPortPeopBoarded;
		cout << "Boarding: " << vacaPortPeopBoarded << " For this trip.\n";
		cout << "There are " << vacaPassAmount << " Left on Vacation port.\n";
		
	}
}

void ShuttleBoat::homePortOffLoadPassengers()
{
	cout << "\nAmount of customers unboarding: " << homePortPeopBoarded << endl;
	homePortPeopBoarded = 0;
}

void ShuttleBoat::vacaPortOffLoadPassengers()
{
	cout << "\nAmount of customers unboarding: " << vacaPortPeopBoarded << endl;
	vacaPortPeopBoarded = 0;
}

void ShuttleBoat::changePort(int destinationPort)
{
	movePort = destinationPort;

	if (movePort == 1)
	{
		//Output
		cout << "\nLeaving vacation spot Port # " << vacationPort << " for port " << movePort << " with " << vacaPortPeopBoarded << " passengers.\n";

		cout << "We've arrived at Home Port #" << movePort;
	}
	else
	{
		//Output
		cout << "\nLeaving home port # " << homePort << " for port " << movePort << " with " << homePortPeopBoarded << " passengers.\n";

		cout << "We've arrived at Vacation Port #" << movePort;
	}
		
	

}