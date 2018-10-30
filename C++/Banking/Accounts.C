#include "Accounts.h"

void Account::setID( int idnum )
{
    id = idnum;
}

int Account::getID()
{
    return id;
}

void Account::setInterestRate(float ir)
{
    interestRate = ir;
}

float Account::getInterestRate()
{
    return interestRate;
}

void Account::setTotalBalance(float tb)
{
    totalBalance = tb;
}

float Account::getTotalBalance()
{
    return totalBalance;
}

float Account::calculateTotalBalance()
{
    totalBalance = totalBalance + (interestRate*totalBalance);
}

void Account::setType(string t)
{
    type = t;
}

string Account::getType()
{
    return type;
}

void Account::deposit(float amount)
{
    totalBalance += amount;
}

void Account::withdraw(float amount)
{
    totalBalance -= amount;
}

void Account::printAccount()
{
  cout << "ID: " << id << " Type: " << type << " Interest Rate: " << interestRate << " Total Balance: " << totalBalance << endl;
}
