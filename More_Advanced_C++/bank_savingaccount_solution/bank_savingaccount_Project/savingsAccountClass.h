//File:savingsAccountClass.h
//Pro:Carlos Marti
//Purp:Simulate a bank savings a account for deposites and withdraws

#include <string>

using namespace std;

class SavingAccount
{
private:
	string accountNumber;
	double balance;
	double interestRate;
	int compoundFreq;

public:
	SavingAccount(double, string, double);
	double getBalance();
	void   deposit(double);
	void   withDraw(double);
	void setInterestRate(double);
	double getInterestRate();
	string getAccountNumber();
	int    getCompoundFreq();
};

SavingAccount::SavingAccount(double startBalance, string startAccntNo, double startRate)
{
	
	balance = startBalance;
	accountNumber = "77hgj54";
	interestRate = startRate;
	compoundFreq = 12;
}


double SavingAccount::getBalance()
{
	return balance;

}

void SavingAccount::deposit(double amtToDeposite)
{
	balance += amtToDeposite;
}

void SavingAccount::withDraw(double amtToWithDraw)
{

	balance -= amtToWithDraw;
}

double SavingAccount::getInterestRate()
{

	return interestRate;
}

string SavingAccount::getAccountNumber()
{

	return accountNumber;
}

int SavingAccount::getCompoundFreq()
{
	return compoundFreq;
}

void SavingAccount::setInterestRate(double setRate)
{
	interestRate = setRate;
}