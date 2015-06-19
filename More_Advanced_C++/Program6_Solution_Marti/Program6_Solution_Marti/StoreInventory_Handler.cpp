

#include<iostream>
#include<iomanip>

using namespace std;

#include"StoreInventoryClass.h"


//function prototype
void displaySearch(StoreInventory &, int &);

int main()
{
	//Variable
	char ans = ' ';
	int storeItemId = 0;

	//creating class
	StoreInventory funStore;

	funStore.loadArrays();

	cout << "Hello and welcome to the searchy app.\n";
	//primer
	cout << "Would you like to enter a store item id number? (y = yes, n = no)\n";
	cin >> ans;

	//error check
	while (toupper(ans) != 'Y' && toupper(ans) != 'N')
	{
		cout << " You did not enter the correct character. You entered: " << ans <<" Please enter the correct character." << endl;
		cout << "Would you still like to enter a store item id number? (y = yes, n = no)\n";
		cin >> ans;
	}

	
	//start the main loop
	while (toupper(ans) != 'N')
	{
		//input the item number
		cout << "Enter the stores item id number \n";
		cin >> storeItemId;
		
		// the function to show the items found
		displaySearch(funStore, storeItemId);
		
		
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

	system("pause");
	return 0;
}

void displaySearch(StoreInventory &funStoreInventory, int &storeItem)
{
	//variable
	int seq = funStoreInventory.seqSearch(storeItem);
	int bin = funStoreInventory.binSearch(storeItem);
	int binItemArr = funStoreInventory.getItemIdArr(bin);
	double binPriceArr = funStoreInventory.getPriceArray(bin);
	int seqItemArr = funStoreInventory.getItemIdArr(seq);
	double seqPriceArr = funStoreInventory.getPriceArray(seq);

	//show result for sequential search
	if (seq < 0)
	{
		cout << "Sequential search did not find ID number: " << storeItem <<endl;
	}
	else
	{
		cout << fixed << "Sequential search found ID number: " << seqItemArr << " and it's price is: $" << setprecision(2) << seqPriceArr << endl;
	}

	//show result for binary search
	if (bin < 0)
	{
		cout << "Binary search did not find ID number: " << storeItem << endl;
	}
	else
	{
		cout << fixed << "Binary search found ID number: " << binItemArr << " and it's price is: $" << setprecision(2) << binPriceArr << endl;
	}
}