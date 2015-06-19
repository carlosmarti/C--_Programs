//TryThis8.cpp - calculates and displays the commission
//Created/revised by <your name> on <current date>

/*********************************************************************
* FILENAME     : calcCommision.cpp                                   *
* PROGRAMMER   : Carlos Marti                                        *
* PURPOSE      : Calculate commision from sales                      *
**********************************************************************/

 #include <iostream>
using namespace std;

 int main()
 {
	 //declare variables
	 double sale1 = 0.0;
	 double sale2 = 0.0;
	 double commissionRate = 0.0;
	 double totalSales = 0.0;
	 double commission = 0.0;

		 //enter input items
	 cout << "Welcome This program will help you calculate your commision" << endl;
	 cout << "Please press Enter to continue";
	 getchar();
     cout << "Please enter your First sale? ";
	 cin >> sale1;
	 cout << "What is your Second sale? ";
	 cin >> sale2;
	 cout << "What is Commission rate in decimal format? ";
	 cin >> commissionRate;
	
	 //calculate total sales and commission
	 totalSales = sale1 + sale2;
	 commission = totalSales * commissionRate;
	
	 //display the commission
     cout << "Your Commission is: $" << commission << endl;
	 getchar();
	 cout << "Thank you for using my Program" << endl;
	 getchar();
	 cout << "I hope you continiue using the program for future use." << endl;

	 system("pause");
	 return 0;
 } //end of main function