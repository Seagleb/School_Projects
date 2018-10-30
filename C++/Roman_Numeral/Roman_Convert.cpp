/*********************************************************
    Author:         William Seagle
    Project:        Lab 2A
    Date:           2/7/18
    Description:    Input year, returns Roman Numeral Year
**********************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int M=1000, D=500, C=100, L=50, X=10,V=5,I=1;
    const int IV=4,XL=40,CD=400,IX=9,XC=90,CM=900;
    int year;
    string roman = "";

    cout << "Insert year to be turned into Roman: ";
    cin >> year;
    while (year > 0)
    {
        if (year >= M)
        {
            year -=M;
            roman +="M";
        }
        else if (year >= CM)
        {
            year -=CM;
            roman +="CM";
        }
        else if (year >= D)
        {
            year -=D;
            roman +="D";
        }
        else if (year >= CD)
        {
            year -=CD;
            roman +="CD";
        }
        else if (year >= C)
        {
            year -=C;
            roman +="C";
        }
        else if (year >= XC)
        {
            year -=XC;
            roman +="XC";
        }
        else if (year >= L)
        {
            year -=L;
            roman +="L";
        }
        else if (year >= XL)
        {
            year -=XL;
            roman +="XL";
        }
        else if (year >= X)
        {
            year -=X;
            roman +="X";
        }
        else if (year >= IX)
        {
            year -=IX;
            roman +="IX";
        }
        else if (year >= V)
        {
            year -=V;
            roman +="V";
        }
        else if (year >= IV)
        {
            year -=IV;
            roman +="IV";
        }
        else if (year >= I)
        {
            year -=I;
            roman +="I";
        }
        else
        {
            cout << "Error";
        }
    }
    cout << "Roman Year: " << roman;
}
