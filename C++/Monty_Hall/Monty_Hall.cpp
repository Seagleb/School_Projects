/***********************************************************
    Author:         William Seagle
    Project:        Lab 3A
    Date:           2/12/18
    Description:    Lets user either play Lets Make A Deal
                    or to simulate the odds of either staying
                    or switching doors for input attempts
************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(time(NULL));

    int user_door;
    int shown_door;

    double stayed_success = 0;
    double switched_success = 0;
    int attempts;
    int clk_attempts;
    int stayed_odds;
    int switched_odds;
    int total_success;
    int main_choice;

    cout << "Select a door between 1 and 3: ";
    cin >> user_door;
    cout << endl <<"1-Play or 2-Simulate: ";
    cin >> main_choice;
    cout << endl;
    if (main_choice == 1)
    {
        int correct_door = rand()%3+1;
        int switch_choice;
        if (user_door==correct_door)
        {
            switch(correct_door)
            {
                case 1: shown_door = rand()%2+2;
                         break;
                case 2: shown_door = rand()%2;
                        if(shown_door==0)
                        {
                            shown_door = 1;
                        }
                        else
                        {
                            shown_door = 3;
                        }
                         break;
                case 3: shown_door = rand()%2+1;
                         break;
            }
            cout << "Door number " << shown_door << " contains a goat!" << endl;
            cout << endl;
            cout << "1-Stay or 2-Switch?: ";
            cin >> switch_choice;
            cout << endl;
            if (switch_choice == 1)
            {
                cout << "You stayed and you were correct!" << endl;
            }
            else
            {
                cout << "You switched and you were wrong!" << endl;
            }

        }
        else
        {
            if (correct_door == 1 && user_door == 2)
            {
                shown_door = 3;
            }
            else if (correct_door == 2 && user_door == 1)
            {
                shown_door = 3;
            }
            else if (correct_door == 2 && user_door == 3)
            {
                shown_door = 1;
            }
            else if (correct_door == 3 && user_door == 2)
            {
                shown_door = 1;
            }
            else if (correct_door == 3 && user_door == 1)
            {
                shown_door = 2;
            }
            else if (correct_door == 1 && user_door == 3)
            {
                shown_door = 2;
            }
            cout << "Door number " << shown_door << " contains a goat!" << endl;
            cout << endl;
            cout << "1-Stay or 2-Switch?: ";
            cin >> switch_choice;
            cout << endl;
            if (switch_choice == 1)
            {
                cout << "You stayed and you were wrong!" << endl;
            }
            else
            {
                cout << "You switched and you were correct!" << endl;
            }

        }
    }
    else if (main_choice == 2)
    {
        cout << "Enter amount of attempts: ";
        cin >> attempts;
        clk_attempts= attempts;

        while(attempts > 0)
        {
            int correct_door = rand()%3+1;
            if (user_door==correct_door)
            {
                stayed_success++;
            }
            else
            {
                switched_success++;
            }
            attempts--;
        }
    cout << endl;
    total_success = stayed_success + switched_success;
    stayed_odds = 100*(stayed_success/total_success);
    switched_odds = 100*(switched_success/total_success);
    cout << "Attempts: " << clk_attempts << endl;
    cout << "Stay Success Rate: " << stayed_odds << "%" <<endl;
    cout << "Switched Success Rate: " << switched_odds <<"%"<< endl;

    }
    else
    {
        cout << "Invalid option, please try again";
    }



    return 0;
}
