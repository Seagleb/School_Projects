#include "Customers.h"
#include <string>

void Customer::setSocialSecurity(int ss)
{
    socialSecurity = ss;
}

int Customer::getSocialSecurity()
{
    return socialSecurity;
}

void Customer::setID( int idnum )
{
    id = idnum;
}

int Customer::getID()
{
    return id;
}

void Customer::setFirstName(string fn)
{
    firstName = fn;
}

string Customer::getFirstName()
{
    return firstName;
}

void Customer::setLastName(string ln)
{
    lastName = ln;
}

string Customer::getLastName()
{
    return lastName;
}

void Customer::setAddress(string a)
{
    address = a;
}

string Customer::getAddress()
{
    return address;
}

void Customer::printCustomer()
{
  cout << "ID: " << id << " Social Security: " << socialSecurity << " Name: " << firstName << " " << lastName << " Address: " << address << endl;
}
