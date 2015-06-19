//File:ListOfAgesClass.h
//Pro:Carlos Marti
//Purp:To open a file and to store the data in the array also to get the average and how many ages are below average

#include <iostream>
#include <fstream>

using namespace std;

class ListOfAges
{
private:
	int ageArray[500];
	int ageCount;
	

public:
	ListOfAges(); 
	void loadAges();
	void displayAges();
	double calcAveraAge();
	int countBelowAVG(double);
	int getAgeCount();
	

};

ListOfAges::ListOfAges()
{
	ageCount = 0;
	// initializine the array
	for (int ct = 0; ct < 500; ++ct)
		ageArray[ct] = 0;
}

int ListOfAges::getAgeCount()
{
	return ageCount;
}

void ListOfAges::loadAges()
{
	ifstream ages;
	

	ages.open("ageData.dat");
	if (ages.is_open())
	{
		//Prime read
		ages >> ageArray[ageCount];

		while (!ages.eof())
		{
			++ageCount;			//Count the record just read

			ages >> ageArray[ageCount];
		} //END WHILE

		ages.close();
		
	}//End if file opened

	else	//If file does not open, set the counter to -1
	{
		ageCount = -1;
		cout << "File failed to open.";
	}
}

void ListOfAges::displayAges()
{
	int count = 0;

	//Begin reading the array
	while (count < ageCount)
	{
		cout << ageArray[count] << endl;
		++count;
	}
}

double ListOfAges::calcAveraAge()
{
	double ageAdded = 0.0;
	double averageAge = 0.0;
	int count = 0.0;

	
	//read the array and store its value
	while (count < ageCount)
	{	
		ageAdded += ageArray[count];
		++count;
	}

	//get the average of the array
	averageAge = ageAdded / count;

	return  averageAge;
}

int ListOfAges::countBelowAVG(double averageAge)
{
	int count = 0;
	int belowAvgAge = 0;
	
	while (count < ageCount)
	{
		//check to see if the value is lesser than the average
		if (ageArray[count] < averageAge)
		{
			belowAvgAge++;
		}
		
		count++;

	}

	return belowAvgAge;
}