#include <string>
#include <iostream>

#include "Employee.h"
#include "Manager.h"
#include "Salesperson.h"
#include "Insurance.h"
#include "Auto_Insurance.h"
#include "Life_Insurance.h"
#include "Home_Insurance.h"

using namespace std;

int getChoice();

int main()
{

	int choice = 0;
	int subChoice = 0;
	float baseSalary = 0;
	int vin = 0;
	float liability;
	float collision;
	float dwelling;
	float contents;
	float termlife;
	float commission;
	int spChoice;
	int age;
	int sqrftg;
	vector<Employee *> employees;
	vector<Insurance *> sales;
	string name;
	string dname;
	string mkmodel;

	//BUILT IN TEST EMPLOYEES
	employees.push_back(new Manager("John Jaroldson", 100000));
	employees.push_back(new Manager("Steve Smithers", 95000));
	employees.push_back(new Salesperson("Alan Ackerson", 45000,0));
	employees.push_back(new Salesperson("Emma Esther", 56000,1));

	//BUILT IN TEST SALES
	sales.push_back(new LifeInsurance("Short Life", "Longer Life", 65, 2.3, 3));
	sales.push_back(new AutoInsurance("Crashes Alot", "Dumpsters Withwheels", 23254, 10000, 5000, 3));
	sales.push_back(new HomeInsurance("Burns Down", 16000, 65000, 20000, 40000, 2));
	sales.push_back(new LifeInsurance("Shortest Life", "Longest Life", 65, 2.3, 0));
	sales.push_back(new AutoInsurance("Crashes Alotmore", "Dumpster Withwheels", 23254, 10000, 5000, 1));
	sales.push_back(new HomeInsurance("Burns Downtotheground", 16000, 65000, 20000, 40000, 0));




	while (choice != 8)
	{
		choice = getChoice();
		switch (choice)
		{
		case 1:
			cout << "What type of Employee?" << endl;
			cout << "1 - Manager" << endl << "2 - Salesperson" << endl << "3 - Cancel"<<endl;
			cin >> subChoice;
			switch (subChoice)
			{
			case 1:
				cout << "Insert First and Last name."<<endl;
				cin.ignore();
				getline(cin, name);
				cout << "Enter Base Salary" << endl;
				cin >> baseSalary;
				employees.push_back(new Manager(name,baseSalary));
				break;
			case 2:
				cout << "Enter ID of Manager from the list" << endl;
				for (int i = 0; i < employees.size(); ++i)
				{
					if (employees[i]->getType() == "Manager")
					{
						cout << "ID " << i << ": " << employees[i]->getName();
						cout << endl;
					}
				}
				cin >> spChoice;
				cout << "Insert First and Last name." << endl;
				cin.ignore();
				getline(cin, name);
				cout << "Enter Base Salary." << endl;
				cin >> baseSalary;
				employees.push_back(new Salesperson(name,baseSalary,spChoice));
				break;
			case 3:
				break;
			}
			break;

		case 2:
			if (employees.size() == 0)
			{
				cout << "There are no employees to make a transaction" << endl << endl;
				break;
			}
			cout << "What type of sale was made?" << endl;
			cout << "1 - Auto Insurance" << endl;
			cout << "2 - Home Insurance" << endl;
			cout << "3 - Life Insurance" << endl;
			cout << "4 - Cancel" << endl;
			cin >> subChoice;
			switch (subChoice)
			{
			case 1:
				cout << "Enter ID of Sales Person from the list" << endl;
				for (int i = 0; i < employees.size(); ++i)
				{
					cout << "ID " << i << ": " << employees[i]->getName();
					cout << endl;
				}
				cin >> spChoice;
				cout << "Enter name of Insured" << endl;
				cin.ignore();
				getline(cin, name);
				cout << "Enter make and model of Vehicle" << endl;
				cin.ignore();
				getline(cin, mkmodel);
				cout << "Enter VIN number of Vehicle" << endl;
				cin >> vin;
				cout << "Enter amount of Liability Coverage" << endl;
				cin >> liability;
				cout << "Enter amount of Collision Coverage" << endl;
				cin >> collision;
				sales.push_back(new AutoInsurance(name,mkmodel,vin,liability,collision,spChoice));

				break;
			case 2:
				cout << "Enter ID of Sales Person from the list" << endl;
				for (int i = 0; i < employees.size(); ++i)
				{
					cout << "ID " << i << ": " << employees[i]->getName();
					cout << endl;
				}
				cin >> spChoice;
				cout << "Enter name of Insured" << endl;
				cin.ignore();
				getline(cin, name);
				cout << "Enter Square Footage of House" << endl;
				cin >> sqrftg;
				cout << "Enter amount of Dwelling Coverage" << endl;
				cin >> dwelling;
				cout << "Enter amount of Liability Coverage" << endl;
				cin >> liability;
				cout << "Enter amount of Contents Coverage" << endl;
				cin >> contents;
				sales.push_back(new HomeInsurance(name, sqrftg, dwelling, liability, contents, spChoice));

				break;
			case 3:
				cout << "Enter ID of Sales Person from the list" << endl;
				for (int i = 0; i < employees.size(); ++i)
				{
					cout << "ID " << i << ": " << employees[i]->getName();
					cout << endl;
				}
				cin >> spChoice;
				cout << "Enter name of Insured" << endl;
				cin.ignore();
				getline(cin, name);
				cout << "Enter name of Dependent" << endl;
				cin.ignore();
				getline(cin, dname);
				cout << "Enter Age of Insured" << endl;
				cin >> age;
				cout << "Enter amount of Term Life Coverage" << endl;
				cin >> termlife;
				sales.push_back(new LifeInsurance(name, dname, age, termlife, spChoice));
				break;
			case 4:
				break;
			}
			break;
		case 3:
			for (int i = 0; i < employees.size(); ++i)
			{
				cout << "Employee " << i << ": " << employees[i]->getName();
				cout << endl;
			}
			break;
		case 4:
			for (int i = 0; i < sales.size(); ++i)
			{
				cout << "Sale " << i << ": " << sales[i]->getName();
				cout << endl;
			}
			break;
		case 5:
			for (int i = 0; i < employees.size(); ++i)
			{
				cout << "Employee " << i << ": " << employees[i]->getName()<<endl;
				cout << "---------------------" << endl;
				cout << "Type" << "   " << "Name" << endl;
				for (int k = 0; k < sales.size(); ++k)
				{
					if (sales[k]->getSalesmanID() == i)
					{
						cout << sales[k]->getType() << "   " << sales[k]->getName() << endl;
					}
				}
				cout << endl;
			}
			break;
		case 6:
			cout << "Enter ID of Sales Person from the list" << endl;
			for (int i = 0; i < employees.size(); ++i)
			{
				cout << "ID " << i << ": " << employees[i]->getName();
				cout << endl;
			}
			cin >> spChoice;
			cout << "Employee " << spChoice << ": " << employees[spChoice]->getName() << endl;
			cout << "---------------------" << endl;
			cout << "Type" << "   " << "Name" << endl;
			for (int k = 0; k < sales.size(); ++k)
			{
				if (sales[k]->getSalesmanID() == spChoice)
				{
					cout << sales[k]->getType() << "   " << sales[k]->getName() << endl;
				}
			}
			break;
		case 7:
			cout << "Enter ID of Manager from the list" << endl;
			for (int i = 0; i < employees.size(); ++i)
			{
				employees[i]->setID(i);
				if (employees[i]->getType() == "Manager")
				{
					cout << "ID " << i << ": " << employees[i]->getName();
					cout << endl;
				}
			}
			cin >> spChoice;
			cout << "Manager " << spChoice << ": " << employees[spChoice]->getName() << endl;
			cout << "---------------------" << endl;
			cout << "Type" << "   " << "Name" << endl;
			for (int i = 0; i < employees.size(); ++i)
			{
				if (employees[i]->getType() == "Salesperson")
				{
					if (employees[i]->getManagerID() == spChoice)
					{
						for (int k = 0; k < sales.size(); ++k)
						{
							if (sales[k]->getSalesmanID() == employees[i]->getID())
							{
								cout << sales[k]->getType() << "   " << sales[k]->getName() << endl;
							}
						}
					}
				}
			}

			break;
		case 8:
			break;
		default:
			break;
		}
		/*
		for (int i = 0; i < sales.size(); ++i)
		{
			sales[i]->calcComission();
		}
		for (int i = 0; i < employees.size(); ++i)
		{
			for (int k = 0; k < sales.size(); ++k)
			{
				commission = 0;
				if (sales[k]->getSalesmanID == employees[i]->getID)
				{
					commission = (commission + sales[k]->getCommission);
					employees[i]->setCommission(commission);
				}
			}
		}*/


	}
}


int getChoice()
{
	int selection;
	cout << endl;
	cout << "Welcome to the Parkland Insurance Record-Keeping System" << endl;
	cout << "Please select from the following" << endl;
	cout << "1 - Input Employee" << endl;
	cout << "2 - Add Transaction" << endl;
	cout << "3 - List Employees" << endl;
	cout << "4 - List All Sales" << endl;
	cout << "5 - List All Sales With Employees" << endl;
	cout << "6 - List All Sales By An Employee" << endl;
	cout << "7 - List All Sales of Subordinates Of A Manager" << endl;
	cout << "8 - Exit" << endl;
	cout << endl;
	cout << "Choice: ";
	cin >> selection;
	return selection;
}