/** *************************************************************************
*                                                                           *
* FILENAME     : calhousearea.cpp                                           *
* PROGRAMMER   : Carlos Marti                                               *
* PURPOSE      : Calculate the area of the property and house with pond     *
*****************************************************************************/



#include <iostream>
#include <string>


using namespace std;

int main()
{
	// Naming Variables
	double sodPrice = 1.39;
	string name = "";
	double propertyLength, propertyWidth;
	int houseLength, houseWidth;
	string pondSize = "";
	int pondDepth;

	//Input
	cout << "Hello and Welcome what is your name?" << endl;
	cin >> name;
	cout << "Ok " << name << " Please tell me the length of the property in feet that you would like to build" << endl;
	cin >> propertyLength;
	cout << "Now " << name << " give me the width of the property in feet" << endl;
	cin >> propertyWidth;
	cout << "Great now " << name << " tell me the length of the house in feet" << endl;
	cin >> houseLength;
	cout << "Alright " << name << " Tell me the width of the house in feet" << endl;
	cin >> houseWidth;

	// Pond width Restriction calculation
	double zoneRestriction = propertyWidth * .85;

	cout << "Ok " << name << " the biggest pond you can get is " << zoneRestriction << " feet would you like a smaller one (yes/no)" << endl;
	cin >> pondSize;
    
	//User pond with Desicion
	if (pondSize == "yes")
	   {
		cout << "Alright " << name << " How big would you like your pond to be." << endl;
		cin >> pondSize;
	   }
	
	//Input
	cout << "Alright " + name + " please tell me the depth you want the pond to be" << endl;
	cin >> pondDepth;

    // Property,House,Pond area calculation
	int propertyAreaBefore = propertyLength * propertyWidth;
	int houseArea = houseLength * houseWidth;
	int pondRadius = zoneRestriction / 2;
	int pondArea = 3.14 * pondRadius;
	int propertyAreaAfter = propertyAreaBefore - houseArea - pondArea;
	int totalPrice = propertyAreaAfter * sodPrice;


	// Output
	cout << "Your Property size is " << propertyAreaBefore << "sq feet" << endl;
	getchar();
    cout << "Your house size is " << houseArea << "sq Feet" << endl;
	getchar();
	cout << "Your Pond size is " << pondArea << "sq Feet" << endl;
	getchar();
	cout << "The Property size after the area of the house and pond comes to " << propertyAreaAfter << "sq Feet" << endl;
	getchar();
	cout << "Alright " << name << " The total price for the sod comes to $" << totalPrice << endl;
	getchar();
	cout << "Thank you for your business we hope that you are satisfide with our survice please come again." << endl;

    system("pause");
	return 0;
	 
} // end of program