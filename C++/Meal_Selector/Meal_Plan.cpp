#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Food
{
	int id;
	string foodName;
	string foodGroup;
	float calories;
	float dailyPercent;
	Food *next;
};

Food *ReadFood(fstream& file, int counter);
void PrintFood(Food *);
int GetChoice();

int main()
{
    int choice = 0;
    string foodSelect[3];
    int randFoodSelect[3];
    string memFood;
    int memCal =0;
    float memDaily =0.00;
    bool valid = false;
	Food *head, *tail, *newp, *tmp;
	head = tail = newp = tmp = NULL;
	cout << setiosflags(ios::left);

	//fstream in( "/home/staff/dbock/csc125/projects/project1/foods.txt", ios::in );
	fstream in( "D:/School/CSC125/foods.txt", ios::in);

	if (in.fail()) {
		cout << "Error Opening File" << endl;
		return(1);
	}

	int counter = 1;

	while (newp = ReadFood(in, counter))
	{
		if (head == NULL)
		{
			head = newp;
			tail = newp;
		}
		else
		{
			tail->next = newp;
			tail = newp;
		}
		counter++;
	}
	tail->next = NULL;
	in.close();
	choice = 0;

	while (choice != 5)
	{
		choice = GetChoice();

		switch (choice)
		{
		case 1:
			cout << "============================================================================" << endl;
			cout << setw(5) << "ID" << setw(20) << "Name" << setw(20) << "Group" << setw(20) << "Calories" << setw(20) << "Daily percentage" << endl;
			cout << "============================================================================" << endl;
			for (tmp = head; tmp != NULL; tmp = tmp->next)
			{
				PrintFood(tmp);
			}

			break;
		case 2:

		    while (valid != true)
            {
                cout << "Enter first food name: ";
                cin >> foodSelect[0];
                for (tmp = head; tmp != NULL; tmp = tmp->next)
                {
                    if (tmp->foodName == foodSelect[0])
                    {
                        valid = true;
                    }
                }
                if (valid == false){cout << "Invalid Selection" << endl;}
            }

            while (valid != true)
            {
                cout << "Enter second food name: ";
                cin >> foodSelect[0];
                for (tmp = head; tmp != NULL; tmp = tmp->next)
                {
                    if (tmp->foodName == foodSelect[1])
                    {
                        valid = true;
                    }
                }
                if (valid == false){cout << "Invalid Selection" << endl;}
            }

            while (valid != true)
            {
                cout << "Enter third food name: ";
                cin >> foodSelect[2];
                for (tmp = head; tmp != NULL; tmp = tmp->next)
                {
                    if (tmp->foodName == foodSelect[2])
                    {
                        valid = true;
                    }
                }
                if (valid == false){cout << "Invalid Selection" << endl;}
            }
            cout << "Enter second food name: ";
            cin >> foodSelect[1];
            cout << "Enter third food name: ";
            cin >> foodSelect[2];
            for (tmp = head; tmp != NULL; tmp = tmp->next)
            {
                if (tmp->foodName == foodSelect[0] || tmp->foodName == foodSelect[1] || tmp->foodName == foodSelect[2])
                {
                    memCal += tmp-> calories;
                    memDaily += tmp-> dailyPercent;
                    memFood += tmp-> foodName + " ";
                }
            }
        cout << "your Meal Plan" << endl;
        cout << "Foods: " << memFood << endl;
        cout << "Calories: " << memCal << endl;
        cout << "Daily Percentage: %" << memDaily << endl;
        foodSelect[0] = "NULL";
        foodSelect[1] = "NULL";
        foodSelect[2] = "NULL";
        memFood = "";
        memCal = 0;
        memDaily = 0;
        valid = false;
			break;
		case 3:
		    randFoodSelect[0] = (rand()%(counter-1))+1;
		    randFoodSelect[1] = (rand()%(counter-1))+1;
		    while (randFoodSelect[1] == randFoodSelect[0]){randFoodSelect[1] = (rand()%(counter-1))+1;}
		    randFoodSelect[2] = (rand()%(counter-1))+1;
		    while (randFoodSelect[2] == randFoodSelect[0] || randFoodSelect[2] == randFoodSelect[1] ){randFoodSelect[2] = (rand()%(counter-1))+1;}
            for (tmp = head; tmp != NULL; tmp = tmp->next)
            {
                if (tmp->id == randFoodSelect[0] || tmp->id == randFoodSelect[1] || tmp->id == randFoodSelect[2])
                {
                    memCal += tmp-> calories;
                    memDaily += tmp-> dailyPercent;
                    memFood += tmp-> foodName + " ";
                }
            }
            cout << "your Meal Plan" << endl;
            cout << "Foods: " << memFood << endl;
            cout << "Calories: " << memCal << endl;
            cout << "Daily Percentage: %" << memDaily << endl;
            randFoodSelect[0] = 0;
            randFoodSelect[1] = 0;
            randFoodSelect[2] = 0;
            memFood = "";
            memCal = 0;
            memDaily = 0;

			break;
		case 4:
            int callimit;
			cout << "Enter calorie limit: ";
			cin >> callimit;
			Food *lastFood, *newHead, *newTail;
			lastFood = head;
			for (tmp = head; tmp != NULL; tmp = tmp->next)
			{
				if (tmp->calories > callimit)
				{
					if (tmp == head)
					{
						head = tmp->next;
						lastFood = tmp->next;

					}
					else if (tmp == tail)
					{
						lastFood->next = NULL;
						tail = lastFood;
					}
					else
					{
						lastFood->next = tmp->next;
					}
					delete tmp;
				}
				else
				{
					lastFood = tmp;
				}
			}
			break;
		case 5:
			break;
		default:
			cout << "Your choice is invalid." << endl;
		}

	}

}

Food *ReadFood(fstream& file, int counter)
{
	Food *tmp = NULL;
	string name, group;
	float cal, per;
    file >> name >> group >> cal >> per;

	if (!file.eof())
	{
		tmp = new Food;
		tmp->id = counter;
		tmp->foodName = name;
		tmp->foodGroup = group;
		tmp->calories = cal;
		tmp->dailyPercent = per;
	}

	return tmp;
}
void PrintFood(Food *f)
{
	cout << setw(5) << f->id << setw(20) << f->foodName << setw(20) << f->foodGroup << setw(20) << f->calories << setw(20) << f->dailyPercent << endl;
}
int GetChoice()
{
	int selection;
	cout << "=================================" << endl;
	cout << "Welcome to Parkland Meal Selector" << endl;
	cout << "=================================" << endl;
	cout << "Please select from the following" << endl;
	cout << "1 - List food database" << endl;
	cout << "2 - Create meal by manual selection" << endl;
	cout << "3 - Create meal by random selection" << endl;
	cout << "4 - Remove foods high in calorie" << endl;
	cout << "5 - Exit" << endl;
	cout << endl;
	cout << "Choice: ";
	cin >> selection;
	return selection;
}
