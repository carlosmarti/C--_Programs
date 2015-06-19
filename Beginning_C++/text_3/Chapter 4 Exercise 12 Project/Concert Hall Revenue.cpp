//FILE : Concert Hall Revenue.cpp
//PROG : 
//PURP : Calculates and displays the revenue for different seating categories
//as well as the total revenue

#include <iostream>
using namespace std;

int main()
{
	//declare constants and variables
	const int ORCHESTRA_PRICE  = 25;
	const int MAIN_FLOOR_PRICE = 30;
	const int BALCONY_PRICE    = 15;
	int orchestraTickets = 0;
	int mainFloorTickets = 0;
	int balconyTickets   = 0;
 	int orchestraRevenue = 0;
	int mainFloorRevenue = 0;
	int balconyRevenue   = 0;
	int totalRevenue     = 0;

	//enter number of tickets in each seating category
	cout << "Orchestra tickets: ";
	cin >> orchestraTickets;
	cout << "Main floor tickets: ";
	cin >> mainFloorTickets;
	cout << "Balcony tickets: ";
	cin >> balconyTickets;

	//calculate all revenues
	//You must complete all four assignment statements correctly
	//so that the owner can see the correct revenue figures.
	orchestraRevenue = ORCHESTRA_PRICE * orchestraTickets;
	mainFloorRevenue = MAIN_FLOOR_PRICE * mainFloorTickets;
	balconyRevenue = BALCONY_PRICE * balconyTickets;
	totalRevenue = orchestraRevenue + mainFloorRevenue + balconyRevenue;

	//display revenues
	cout << "Orchestra revenue: $" << orchestraRevenue << endl;
	cout << "Main floor revenue: $" << mainFloorRevenue << endl;
	cout << "Balcony revenue: $" << balconyRevenue << endl;
	cout << "Total revenue: $" << totalRevenue << endl;

	system("pause");
	return 0;
}	//end of main function
