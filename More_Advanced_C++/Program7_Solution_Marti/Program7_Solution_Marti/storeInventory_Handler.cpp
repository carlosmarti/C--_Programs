//File:storeInventory_Handler.cpp
//Pro:Carlos Marti
//Purp:To pass in the file directory into the class and to input the item id and how many of the item the customer wants 

#include<iostream>
#include<iomanip>

using namespace std;

#include"StoreInventoryClass.h"


int main()
{
	//Variable
	char ans = ' ';
	int storeItemId = 0;
	int amountOrdered = 0;
	int numOrders = 0;
	int amountItmFound = 0;
	int amountItmNotFound = 0;
	int seq;
	int bin;
	int binItemArr;
	double binPriceArr;
	int seqItemArr;
	double seqPriceArr;
	double total;
	string dataFile = "masterStoreInv.dat";

	//creating class and storing data in the arrays
	StoreInventory funStore(dataFile);
	

	//primer
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
		seq = funStore.seqSearch(storeItemId);
		binItemArr = funStore.getItemIdArr(bin);
		binPriceArr = funStore.getPriceArray(bin);
		seqItemArr = funStore.getItemIdArr(seq);
		seqPriceArr = funStore.getPriceArray(seq);

		//decision to see if the searches found the item
		if (seq < 0)
		{
			cout << "Sequential search did not find ID number: " << storeItemId << endl;
			amountItmNotFound++;
		}
		else
		{
			cout << fixed << "Sequential search found ID number: " << seqItemArr << " and it's price is: $" << setprecision(2) << seqPriceArr << endl;
		}

		//show result for binary search
		if (bin < 0)
		{
			cout << "Binary search did not find ID number: " << storeItemId << endl;
		}
		else
		{
			cout << fixed << "Binary search found ID number: " << binItemArr << " and it's price is: $" << setprecision(2) << binPriceArr << endl;
		}

		//amount the customer wants to order
		if (seq >= 0 && bin >= 0)
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
	//calculate the amount of orders found
	amountItmFound = numOrders - amountItmNotFound;

	// Show the last results for the amount of orders looked up and amount of items found and amount of items not found
	cout << "\n" << "Amount looked up" << setw(17) << "Items found" << setw(22) << "Items not found\n";
	cout << setw(8) << numOrders << setw(20) << amountItmFound << setw(19) << amountItmNotFound << endl;
	system("pause");
	return 0;
}