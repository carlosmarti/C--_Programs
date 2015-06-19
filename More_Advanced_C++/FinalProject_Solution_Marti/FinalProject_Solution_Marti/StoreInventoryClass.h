//File:StoreInventoryClass.h
//Pro:Carlos Marti
//Purp:To open a file and to store the data into arrays and search the arrays and sort them

#include<iostream>
#include<fstream>

using namespace std;

class StoreInventory
{
private:
	double priceArray[300];
	int itemIdArr[300];
	int arrayCount;
	

public:
	StoreInventory(string);
	int getItemIdArr(int);
	double getPriceArray(int);
	int binSearch(int);
	void loadArrays(string);
	void sortArray();

};

StoreInventory::StoreInventory(string data)
{
	arrayCount = 0;

	//Instance the arrays
	for (int i = 0; i < 300; i++)
	{
		priceArray[i] = 0;
		itemIdArr[i] = 0;
	}

	loadArrays(data);

}

int StoreInventory::getItemIdArr(int num)
{
	return  itemIdArr[num];
}

double StoreInventory::getPriceArray(int num)
{
	return  priceArray[num];
}

void StoreInventory::sortArray()
{
	//Variables
	int last = arrayCount - 1;
	int count;
	int swap ;
	int itemArrHolder = 0;
	double priceArrHolder = 0.0;

	//sort the array
	while (last > 0)
	{
		count = 0;
		swap = 0;
		while (count < last)
		{
			if (itemIdArr[count] > itemIdArr[count + 1])
			{
				//sort the item id array
				itemArrHolder = itemIdArr[count + 1];
				itemIdArr[count + 1] = itemIdArr[count];
				itemIdArr[count] = itemArrHolder;

				//sort the price array
				priceArrHolder = priceArray[count + 1];
				priceArray[count + 1] = priceArray[count];
				priceArray[count] = priceArrHolder;

				swap = 1;
			}

			count++;
		}

		if (swap == 0)
		{
			last = 0;
		}
		else
		{
			last -= 1;
		}
	}
}

void StoreInventory::loadArrays(string dataFile)
{
	fstream storeItems;

	//Opening file
	storeItems.open(dataFile);
	if (storeItems.is_open())
	{
		storeItems >> itemIdArr[arrayCount] >> priceArray[arrayCount];

		//loop through the array
		while (!storeItems.eof())
		{
			arrayCount++;

			storeItems >> itemIdArr[arrayCount] >> priceArray[arrayCount];

		}

		//close the file
		storeItems.close();
	}
	else
	{
		arrayCount = -1;
		cout << "The file did not open./n";
	}
}

int StoreInventory::binSearch(int targetId)
{
	int first = 0;
	int last = arrayCount - 1;
	int found = 0;
	int mid = 0;

	// start the loop
	while (first <= last && found == 0)
	{

		mid = (first + last) / 2;
		if (itemIdArr[mid] == targetId)
		{
			found = 1;
		}
		else
		{
			if (itemIdArr[mid] < targetId)
			{
				first = mid + 1;
			}
			else
			{
				last = mid - 1;
			}
		}
	}//end of loop

	if (found == 0)
	{
		mid = -1;
	}

	return mid;

}

