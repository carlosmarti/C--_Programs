/** ******************************************************************
*                                                                    *
* FILENAME     : hardwarecal.cpp                                     *
* PROGRAMMER   : Carlos Marti                                        *
* PURPOSE      : Calculate discount for hardware items               *
**********************************************************************/



#include <iostream>
#include <string>
using namespace std;


int main()
{
	// declaration of variables
	const double discount = .35;
	string customerName = "";
	int communityYears = 0;
	string item = "";
	double itemPrice = 0.0;
	int numOfItem;
	double discountPrice = 0.0;
	double totalPrice = 0.0;


	//entering input
	cout << "Hello how are you doing today, Welcome to johns hardware store.What is your name" << endl;
	cin >> customerName;
	cout << "Hi " << customerName << ", How many years have you lived here?" << endl;
	cin >> communityYears;
	cout << " WoW you have lived here for " << communityYears << "years Hope you have enjoyed your time here and at the store." << endl;
	cout << "Now please tell me the name of the item you would like to purchase." << endl;
	cin >> item;
	cout << "Great now tell me the price of the item." << endl;
	cin >> itemPrice;
	cout << "How many of the " << item << " would you like." << endl;
	cin >> numOfItem;

	// calculating the discount and adding the total amount
	discountPrice = itemPrice * discount;
	totalPrice = discountPrice * numOfItem;

	// Output total and discount price
	cout << "The price of " << item << " is $" << itemPrice << " but with the discount of 35% it comes to $" << discountPrice << endl;
	cout << "For " << numOfItem << " of the " << item << " It comes out to a Grand total of $" << totalPrice << endl;
	cout << "Thank You very much for choosing us for your hardware needs Please come again." << endl;

	system("pause");
	return 0;


}   //end of program 