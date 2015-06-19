

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
	StoreInventory();
	int getItemIdArr(int);
	double getPriceArray(int);
	void loadArrays();
	int seqSearch(int);
	int binSearch(int);
	

};

StoreInventory::StoreInventory()
{
	arrayCount = 0;

	//Instance the arrays
	for (int i = 0; i < 300; i++)
	{
		priceArray[i] = 0;
		itemIdArr[i] = 0;
	}

}

int StoreInventory::getItemIdArr(int num)
{
	return  itemIdArr[num];
}

double StoreInventory::getPriceArray(int num)
{
	return  priceArray[num];
}

void StoreInventory::loadArrays()
{
	fstream storeItems;

	//Opening file
	storeItems.open("storeInv.dat");
		if (storeItems.is_open())
		{
			storeItems >> itemIdArr[arrayCount] >> priceArray[arrayCount];

			//loop through the array
			while(!storeItems.eof())
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

int StoreInventory::seqSearch(int targetId)
{
	//variables
	int count = 0;
	int found = -1;

	//loop through the array
	while (count < arrayCount)
	{
		if (targetId == itemIdArr[count])
		{
			found = count;
			count = arrayCount;
		}
		else
		{
			++count;
		}
	}

	
	return found;
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

