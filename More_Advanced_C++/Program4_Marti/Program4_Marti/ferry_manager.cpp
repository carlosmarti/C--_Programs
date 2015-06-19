//File:ferry_manager.cpp
//Pro:Carlos Marti
//Purp:Manages the ferry boat class

#include<iostream>


using namespace std;

//Class file
#include"ferryBoatClass.h"

int main()
{
	//Variable
	const int AMOUNTPORTS = 20;
    const int HOMEPORT = 1;
	int port = 1;

	//Creating the object
	FerryBoat coolBoat(AMOUNTPORTS, 125, HOMEPORT, "8836fgh");
	

	//Starting boat 
	cout << "All aboard the Ferry!\n";
	coolBoat.loadPassengers();
	for (int ct = 0; ct <= 18; ct++)
	{
		port++;
		coolBoat.changePort(port);
		coolBoat.offLoadPassengers();
		coolBoat.loadPassengers();	
	}

	//Boat heading back to home port
	cout << "\nWe are heading back to home port.\n";
	coolBoat.changePort(HOMEPORT);
	

	system("pause");
	return 0;
}