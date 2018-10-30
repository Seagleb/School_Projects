#include <iostream>
#include <string>
#ifndef _Accounts_h_
#define _Accounts_h_

using namespace std;

class Account
{
    private:
        int id;
        float interestRate;
        float totalBalance;
        string type;

    public:
        Account()
        {
            id = 0;
            interestRate = 0;
            totalBalance = 0;
            type = "Checking";
        }
        void setID(int);
        void setInterestRate(float);
        void setTotalBalance(float);
        void setType(string);

        float calculateTotalBalance();
        void deposit(float);
        void withdraw(float);

        string getType();
        int getID();
        float getInterestRate();
        float getTotalBalance();

        void printAccount();
};

#endif
