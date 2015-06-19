//File:bank_Accountmanager
//Pro:Carlos Marti
//Purp:Manage a savings account using the SavingAccount class

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

#include "SavingsAccountClass.h"

//Funtion Prototype
void displayFutureInterestRate(double, double, int);
void newCustomer(SavingAccount &newAccount);

int main()
{
	
	//Variables
	char depositeAnswer = ' ';
	double depositeAmount = 7000;
	char withDrawAnswer = ' ';
	double withDrawAmount = 0.0;
	char newCustomerAns = ' ';

	//Setting up the account
	cout << "Hello welcome to Banking united, Are you a new custemor (Y,N)\n";
	cin >> newCustomerAns;
	SavingAccount accountOne(depositeAmount, "77hjei48", .25);
	
	if (toupper(newCustomerAns) == 'N')
	{
			//Print to screen
	cout << setw(20) <<"Welcome to Your account valued customer.\n";
	cout << "The amount in your account is $" << accountOne.getBalance() << endl;
	cout << "Your interest rate is " << accountOne.getInterestRate() << "%\n";
	cout << "Would you like to deposite to your account? (Y/N)\n";
	cin >> depositeAnswer;
	//Decision to deposit to the account
	if (toupper(depositeAnswer) == 'Y')
	{
		cout << "How much would you like to deposit today?\n";
		cin >> depositeAmount;
		accountOne.deposit(depositeAmount);
	}
	//Decision to Withdraw from the account
	cout << "Would you like to make a withdraw today?\n";
	cin >> withDrawAnswer;
	if (toupper(withDrawAnswer) == 'Y')
	{
		cout << "How much would you like to withdraw today?\n";
		cin >> withDrawAmount;
		accountOne.withDraw(withDrawAmount);
	}

	

    //Call a function to display 12 month rate
	displayFutureInterestRate(accountOne.getBalance(), accountOne.getInterestRate(), accountOne.getCompoundFreq());
	}
	else
	{
		newCustomer(accountOne);
	}
	


	system("pause");
	return 0;
}

void displayFutureInterestRate(double amount, double rate, int time)
{
	double total = amount;
	double interest = 0.0;
	double amountOfInterest = 0.0;
	int    monthCount = 0;
	double accountAfter = 0.0;

	cout << "Thank you for your business, here is your interest rate calculated for 1 year\n";
	cin.get();

	interest = rate / 100;

	cout << "Month" << setw(19) << "Starting Balance" << setw(15) << "InterestRate" << setw(18) << "EndingBalance\n";
	for (int i = 0; i <= 11; i++)
	{
		monthCount++;
		if (monthCount > 1)
		{
			total = accountAfter;
		}
		
		amountOfInterest = total * interest;
		accountAfter = total + amountOfInterest;

		
		cout << setw(3) << monthCount << setw(16)<< fixed << setprecision(2) << total << setw(15) << setprecision(2) << amountOfInterest << setw(19) << accountAfter << endl;
		
		
	}
}

void newCustomer(SavingAccount &newAccount)
{
	double depositAmount = 0.0;
	double interest = 0.0;
	double amountOfInterest = 0.0;
	double rate = newAccount.getInterestRate();
	int    monthCount = 0;
	double accountAfter = 0.0;

	cout << "\nWelcome to your new account, How much would you like to deposite?\n";
	cin >> depositAmount;

	cout << "Thank you for your business, here is your interest rate calculated for 1 year\n";

	interest = rate / 100;

	cout << "Month" << setw(19) << "Starting Balance" << setw(15) << "InterestRate" << setw(18) << "EndingBalance\n";
	for (int i = 0; i <= 11; i++)
	{
		monthCount++;
		if (monthCount > 1)
		{
			depositAmount = accountAfter;
		}

		amountOfInterest = depositAmount * interest;
		accountAfter = depositAmount + amountOfInterest;


		cout << setw(3) << monthCount << setw(16) << fixed << setprecision(2) << depositAmount << setw(15) << setprecision(2) << amountOfInterest << setw(19) << accountAfter << endl;


	}

}