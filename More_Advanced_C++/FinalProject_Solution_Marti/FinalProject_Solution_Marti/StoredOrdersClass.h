

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class StoredOrders
{
private:
	ofstream outputFile;
	bool fileOpenSuccess;
	string storeFile;
	void openOutputFile(string);

public:
	StoredOrders(string);
	bool getFileOpenStatus();
	void saveOneRecord(int,int,double);
	void closeOutputFile();
	void displayAllOrders();
	double calcTotalCostOfOders();

};

StoredOrders::StoredOrders(string file)
{
	storeFile = file;

	//open the file
	openOutputFile(storeFile);

}

void StoredOrders::openOutputFile(string file)
{

	//open file as output
	outputFile.open(file, ios::out);
	if (outputFile.is_open())
	{
		fileOpenSuccess = true;
	}
	else
	{
		fileOpenSuccess = false;
	}
}

bool StoredOrders::getFileOpenStatus()
{
	return fileOpenSuccess;
}

void StoredOrders::saveOneRecord(int idNum, int quantity, double totalPrice)
{
	outputFile << idNum << '\t' << quantity << '\t' << totalPrice << endl;
}

void StoredOrders::closeOutputFile()
{
	outputFile.close();
}

void StoredOrders::displayAllOrders()
{
	int arrCount = 0;
	int userCount = 1;
	int idArr[200];
	int numOrdered[200];
	double priceArr[200];
	fstream storedOrders;

	//Open output file as input
	storedOrders.open(storeFile);
	if (storedOrders.is_open())
	{
		
		//primer
		storedOrders >> idArr[arrCount] >> numOrdered[arrCount] >> priceArr[arrCount];

		while (!storedOrders.eof())
		{
			arrCount++;
			storedOrders >> idArr[arrCount] >> numOrdered[arrCount] >> priceArr[arrCount];
		}
	}
	else
	{
		arrCount = -1;
		cout << "File did not open\n";
	}

	cout << setw(13) << "Item Id #" << setw(19) << "Amount Ordered" << setw(15) << "Total\n";
	// display the oders
	for (int ind = 0; ind < arrCount; ind++)
	{
		cout << userCount << "." << setw(9) << idArr[ind] << setw(14) << numOrdered[ind] << setw(17) << "$" << priceArr[ind] << endl;
		userCount++;
	}
}

double StoredOrders::calcTotalCostOfOders()
{
	int id = 0;
	int numOrdered = 0;
	double priceArr[200];
	int arrCount = 0;
	double grandTotal = 0.0;
	fstream storedOrders;

	//Open output file as input
	storedOrders.open(storeFile);
	if (storedOrders.is_open())
	{

		//primer
		storedOrders >> id >> numOrdered >> priceArr[arrCount];

		while (!storedOrders.eof())
		{
			arrCount++;
			storedOrders >> id >> numOrdered >> priceArr[arrCount];
		}
	}
	else
	{
		arrCount = -1;
		cout << "File did not open\n";
	}

	// add all the prices together
	for (int ind = 0; ind < arrCount; ind++)
	{		
		grandTotal += priceArr[ind];
	}

	return grandTotal;
}