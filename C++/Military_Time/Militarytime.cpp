/***********************************************************
    Author:         William Seagle
    Project:        Military Time
    Date:           5/1/18
    Description:    Lets user convert time to military time
************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void convert_to_military (string input_time);

int main()
{
    bool inputCheck = true;
    string input_time;

	cout << "Input the current time to convert to military time" << endl;
    cout << "Enter the time 'HH:MM AM' or 'HH:MM PM'." << endl;

	while (inputCheck == true)
        {
		getline(cin, input_time);

		if (input_time.length() < 7)
            {
			cout << "Incorrect Input" << endl;
            }
		else if (input_time.length() == 8 || input_time.length() == 7)
            {
			inputCheck = false;
            }
        }

	convert_to_military(input_time);

	system("pause");
}


void convert_to_military (string input_time)
{
    string am_pmChecker, time, minute;
    int hour;
    char colonChecker, spaceChecker;

    colonChecker = input_time.find(":");
    spaceChecker = input_time.find(" ");
    am_pmChecker = input_time.substr(spaceChecker + 1, 2);
    time = input_time.substr(0, colonChecker);
    hour = atoi(time.c_str());
    minute = input_time.substr(colonChecker + 1, 2);

    if ((am_pmChecker == "PM") || (am_pmChecker == "pm"))
    {
        if (hour < 12)
        {
            hour += 12;
        }
    }

    else if (hour == 12)
    {
        hour = 0;
    }
    cout <<"Military Time: ";

    if (hour < 10)
    {
        cout << "0";
    }

    cout << hour << minute << " hours." << endl;
}
