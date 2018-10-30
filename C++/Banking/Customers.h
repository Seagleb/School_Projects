#include <iostream>
#include <string>
#ifndef _Customers_h_
#define _Customers_h_

using namespace std;

class Customer
{
    private:
        int id;
        int socialSecurity;
        string firstName;
        string lastName;
        string address;


    public:
        Customer()
        {
            id = 0;
            socialSecurity = 0;
            firstName = "";
            lastName = "";
            address = "";
        }
        void setID(int);
        void setSocialSecurity(int);
        void setFirstName(string);
        void setLastName(string);
        void setAddress(string);

        int getID();
        int getSocialSecurity();
        string getFirstName();
        string getLastName();
        string getAddress();

        void printCustomer();
};

#endif
