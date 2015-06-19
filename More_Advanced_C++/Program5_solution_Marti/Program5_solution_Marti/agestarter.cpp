//File:agestarter.cpp
//Pro:Carlos Marti
//Purp:To call the class ListOfAgesClass and load the array with the values and to get all the values.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include"ListofAgesClass.h"

int main()
{
	
	//Creating the object
	ListOfAges peopleAges;
	
	//calling to load the array
	peopleAges.loadAges();

	//Outputing to screen 
	cout << "This is all the ages on the array: \n";
	peopleAges.displayAges();
	cout << "This is the average age: "<< setprecision(5) << peopleAges.calcAveraAge() << endl;
	cout << "This is the amount of people under the average age: " << peopleAges.countBelowAVG(peopleAges.calcAveraAge()) << endl;

	system("pause");
	return 0;
}