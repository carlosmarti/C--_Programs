//File:storeInventory_Handler.cpp
//Pro:Carlos Marti
//Purp:To pass in the file directory into the class and to input the item id and how many of the item the customer wants 

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

#include"StoreInventoryClass.h"
#include"StoredOrdersClass.h"


int main()
{
	//Variable
	char ans = ' ';
	int storeItemId = 0;
	int amountOrdered = 0;
	int numOrders = 0;
	int amountItmFound = 0;
	int amountItmNotFound = 0;
	int bin;
	int binItemArr;
	double binPriceArr;
	double total;
	string dataFile = "D:\\CPT 233\\Final Program\\masterStoreInv.dat";
	string openDataFile = "processedOrders.dat";

	//creating class and storing data in the arrays
	StoreInventory funStore(dataFile);
	StoredOrders funStoreHolder(openDataFile);

	
	if (funStoreHolder.getFileOpenStatus() == true)
	{
		//primer
		cout << "Output file is open" << endl;
		cout << "Hello and welcome to the searchy app.\n";
		
		//orginazing the array
		funStore.sortArray();
		cout << "Would you like to enter a store item id number? (y = yes, n = no)\n";
		cin >> ans;

		//error check
		while (toupper(ans) != 'Y' && toupper(ans) != 'N')
		{
			cout << " You did not enter the correct character. You entered: " << ans << " Please enter the correct character." << endl;
			cout << "Would you still like to enter a store item id number? (y = yes, n = no)\n";
			cin >> ans;
		}


		//start the main loop
		while (toupper(ans) != 'N')
		{
			//input the item number
			cout << "Enter the stores item id number \n";
			cin >> storeItemId;
			numOrders++;

			// the methods to search threw the arrays and get the item number and the price
			bin = funStore.binSearch(storeItemId);
			binItemArr = funStore.getItemIdArr(bin);
			binPriceArr = funStore.getPriceArray(bin);

			//show result for binary search
			if (bin < 0)
			{
				cout << "Binary search did not find ID number: " << storeItemId << endl;
				amountItmNotFound++;
			}
			else
			{
				cout << fixed << "Binary search found ID number: " << binItemArr << " and it's price is: $" << setprecision(2) << binPriceArr << endl;
			}

			//amount the customer wants to order
			if (bin >= 0)
			{
			
				//Input
				cout << "How many of the item would you like?\n";
				cin >> amountOrdered;
				total = binPriceArr * amountOrdered;

				//error check
				if (amountOrdered < 0)
				{
					cout << "I'm sorry but i cannot complete that transaction. A negative number is not exceptable.\n";
				}
				else
				{
					cout << "\n" << setw(11) << "Item Id #" << setw(10) << "Price" << setw(20) << "Amount Ordered" << setw(16) << "Grand Total\n";
					cout << setw(8) << binItemArr << setw(9) << "$" << binPriceArr << setw(12) << amountOrdered << setw(14) << "$" << total << endl;
					funStoreHolder.saveOneRecord(binItemArr, amountOrdered, total);
				}
				
			}


			cout << "\nWould you like to enter another store item id number? (y = yes, n = no)\n";
			cin >> ans;

			//error check
			while (toupper(ans) != 'Y' && toupper(ans) != 'N')
			{
				cout << " You did not enter the correct character. You entered: " << ans << " Please enter the correct character." << endl;
				cout << "Would you still like to enter a store item id number? (y = yes, n = no)\n";
				cin >> ans;
			}
		}
	}
	else
	{
		cout << "Cannot let you make any orders without the output file open\n";
	}
	

	//clear the screen 
	system("cls");

	//close the output file
	funStoreHolder.closeOutputFile();

	//display the amount of orders
	funStoreHolder.displayAllOrders();

	//show all the pricess added together
	cout << "\n" << setw(62) << "Today's gross\n";
	cout << setw(53) << "$" << funStoreHolder.calcTotalCostOfOders() << endl;

	system("pause");
	return 0;
}