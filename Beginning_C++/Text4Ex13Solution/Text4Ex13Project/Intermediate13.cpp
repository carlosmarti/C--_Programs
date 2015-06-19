//Intermediate13.cpp - displays the gallons of water used and the total water charge
//Created/revised by <your name> on <current date>

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declare variables and named constants
	int current  = 0;
	int previous = 0;
	int gallons  = 0;
	double total = 0.0;
	const double CHG_PER_GAL = .007;
	const double MINIMUM_CHG = 16.67;

	//enter input items
	cout << "Current reading: ";
	cin >> current;
	cout << "Previous reading: ";
	cin >> previous;

	 gallons = current - previous;
	 total = gallons * CHG_PER_GAL;

	//determine whether total charge is at least the minimum
	if (total < 16.67)
	{
		cout << "This does not pass the minimum required " << endl;
	}
	//end if

	//display gallons used and total charge
	cout << setprecision(2);
	cout << fixed;

	cout << "The amount of gallons used " << gallons << endl;
	cout << "The total charge comes to $" << total << endl;
	system("pause");
	return 0;
}	//end of main function
