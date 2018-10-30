/***********************************************************
    Author:         William Seagle
    Project:        Lab 3B
    Date:           2/20/18
    Description:    Play a game of 23 Match Sticks
************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int main()
{
    int user_sticks;
    int computer_sticks;
    int total_sticks;
    total_sticks = 23;
    while (total_sticks > 0)
    {
        cout << "There are " << total_sticks << " sticks remaining" << endl;
        cout << "How many do you take: ";
        cin >> user_sticks;
        if (user_sticks > 0 && user_sticks < 4)
        {
            total_sticks = total_sticks - user_sticks;
            if (total_sticks < 1)
            {
                cout << "You Lose!!";
                break;
            }
            cout << "There are " << total_sticks << " sticks remaining" << endl;
            computer_sticks = 4-user_sticks;
            cout << "The computer takes " << computer_sticks << endl;
            total_sticks= total_sticks - computer_sticks;
            if (total_sticks < 1)
            {
                cout << "You Win!!";
                break;
            }
            cout << endl;
        }
        else
        {
            cout << "You need to choose 1-3 sticks." << endl;
        }


    }


}
