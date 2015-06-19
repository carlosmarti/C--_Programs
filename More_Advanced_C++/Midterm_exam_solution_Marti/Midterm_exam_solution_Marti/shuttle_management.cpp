//File:shuttle_management
//Pro:Carlos Marti
//Purp: To move the shuttle boat from port to port and give the values for amount of customers waiting on each port

//Libraries
#include<iostream>

using namespace std;

//Class
#include"ShuttleBoatClass.h"

int main()
{
	//Variables
	int firsPortPass = 0;
	int secondPortPass = 0;
	int destPortNum = 0;
	int homePortNum = 1;
	int maxCapacity = 125;
	
	
	//Input for class
	cout << "Port number of vacation hot spot?\n";
	cin >> destPortNum;

	cout << "What is the amount of people waiting in the first port?\n";
	cin >> firsPortPass;

	cout << "The number of people waiting in the vacation hotspot to go back home?\n";
	cin >> secondPortPass;

	//Build object
	ShuttleBoat funBoat(maxCapacity, homePortNum, destPortNum, firsPortPass, secondPortPass);
	int homePortPassLeft = funBoat.getHomePassAmount();
	int vacaPortPassLeft = funBoat.getVacaPassAmount();
	int portChange = 0;

	//Transporting customers
	while (homePortPassLeft > 0 || vacaPortPassLeft > 0)
	{
		funBoat.homePortLoadPassangers();
		funBoat.changePort(destPortNum);
		funBoat.homePortOffLoadPassengers();
		homePortPassLeft = funBoat.getHomePassAmount();

		funBoat.vacaPortLoadPassengers();
		funBoat.changePort(homePortNum);
		funBoat.vacaPortOffLoadPassengers();
		vacaPortPassLeft = funBoat.getVacaPassAmount();
	}

	//Check to see if boat is at home port.
	portChange = funBoat.getMovePort();
	if (portChange != 1)
	{
		funBoat.vacaPortLoadPassengers();
		funBoat.changePort(homePortNum);
	}

	cout << "\nThere are no more customers to pick up mission accomplished.\n";

	
	system("pause");
	return 0;
}