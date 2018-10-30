#include "Accounts.h"
#include "Customers.h"
#include <vector>
#include <string>
#include <iomanip>

int GetChoice();

main()
{
    vector<Account> listofaccounts;
    vector<Customer> listofcustomers;
    Account *newAccount;
    Customer *newCustomer;

    int choice = 0;
    int accounts = 0;
    string typeOfAccount = "";
    string firstName = "";
    string lastName = "";
    string address = "";
    int ssn = 0;
    float intRate = 0.00;
    float initialDeposit = 0.00;
    int idchoice = 0;
    float amount = 0.00;

    vector<Account>::iterator oneAccount;
    vector<Customer>::iterator oneCustomer;
    cout << setiosflags(ios::left);

    while (choice != 7)
	{
		choice = GetChoice();
		switch (choice)
		{
		case 1:
            newAccount = new Account;
		    newCustomer = new Customer;

		    cout << "Enter first and last name: ";
		    cin >> firstName >> lastName;
		    cout << "Enter address: " ;
		    cin.ignore();
            getline(cin, address);
		    cout << "Enter Social Security Number: ";
		    cin >> ssn;
		    cout << "Enter Interest Rate: ";
		    cin >> intRate;
		    cout << "Enter account type: ";
		    cin >> typeOfAccount;
		    cout << "Initial Deposit: ";
		    cin >> initialDeposit;

		    newAccount -> setType(typeOfAccount);
		    newAccount -> setID(accounts);
		    newAccount -> setInterestRate(intRate);
		    newAccount -> setTotalBalance(initialDeposit);
		    newCustomer -> setID(accounts);
		    newCustomer -> setFirstName(firstName);
		    newCustomer -> setLastName(lastName);
		    newCustomer -> setAddress(address);
		    newCustomer -> setSocialSecurity(ssn);

		    listofcustomers.push_back(*newCustomer);
		    listofaccounts.push_back(*newAccount);
		    accounts++;
			break;
		case 2:
			cout << "========================================================================================================" << endl;
			cout << setw(5) << "ID" << setw(20) << "Name"<< setw(25) << "Address"<< setw(20) << "Social Security"<<  setw(10) <<"Interest"<< setw(10) << "Type"<< setw(15) << "Balance" << endl;
			cout << "========================================================================================================" << endl;
            for (int i = 0; i < listofaccounts.size(); i++)
            {
                cout << setfill(' ');

                cout << setw(5) << listofaccounts[i].getID() << setw(20) << listofcustomers[i].getFirstName() + " " + listofcustomers[i].getLastName() << setw(25) << listofcustomers[i].getAddress() << setw(20) << listofcustomers[i].getSocialSecurity() << setw(10) << listofaccounts[i].getInterestRate()<< setw(10) << listofaccounts[i].getType()<< setw(15) << listofaccounts[i].getTotalBalance() <<endl;
            }
            /*for (oneCustomer = listofcustomers.begin(); oneCustomer != listofcustomers.end(); ++oneCustomer)
            {
                cout << "Name: " << oneCustomer->getFirstName() << " " << oneCustomer->getLastName() << endl;
            }*/
		    break;
        case 3:
            cout << "Enter ID# of account: ";
            cin >> idchoice;
            cout << setw(5) << listofaccounts[idchoice].getID() << setw(20) << listofcustomers[idchoice].getFirstName() + " " + listofcustomers[idchoice].getLastName() << setw(25) << listofcustomers[idchoice].getAddress() << setw(20) << listofcustomers[idchoice].getSocialSecurity() << setw(10) << listofaccounts[idchoice].getInterestRate()<< setw(10) << listofaccounts[idchoice].getType()<< setw(15) << listofaccounts[idchoice].getTotalBalance() <<endl;
            break;
        case 4:
            cout << "Enter ID# of account for deposit: ";
            cin >> idchoice;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            listofaccounts[idchoice].deposit(amount);
            cout << "Deposit Succesful" << endl;
            amount = 0;
            break;
        case 5:
            cout << "Enter ID# of account for withdraw: ";
            cin >> idchoice;
            cout << "Enter amount to withdraw: ";
            do
            {
                cin >> amount;
            }
            while (amount > listofaccounts[idchoice].getTotalBalance());
            listofaccounts[idchoice].withdraw(amount);
            cout << "Withdraw Succesful" << endl;
            amount = 0;
            break;
        case 6:
            cout << "Enter ID# of account to receive interest: ";
            cin >> idchoice;
            listofaccounts[idchoice].calculateTotalBalance();
            cout << "Interest Accrued" << endl;
            break;
        case 7:
            break;
		}
	}

}

int GetChoice()
{
	int selection;
	cout << "=============================================" << endl;
	cout << "Welcome to Bank of Parkland -- Account System" << endl;
	cout << "=============================================" << endl;
	cout << "Please select from the following" << endl;
	cout << "1 - Create Account" << endl;
	cout << "2 - Print Accounts" << endl;
	cout << "3 - Select Account" << endl;
	cout << "4 - Deposit" << endl;
	cout << "5 - Withdraw" << endl;
    cout << "6 - Accrue Interest" << endl;
	cout << "7 - Exit" << endl;
	cout << endl;
	cout << "Choice: ";
	cin >> selection;
	return selection;
}
