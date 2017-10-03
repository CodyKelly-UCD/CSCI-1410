// This is the employee class

#include "employee.h"

Employee::Employee()
{
    
}

Employee::Employee(int id, string employeeName, string social, string address, int yob)
{
    ID = id;
    name = employeeName;
    ssn = social;
    emailAddress = address;
    yearOfBirth = yob;
}

int Employee::getID()
{   return ID;  }

string Employee::getName()
{   return name;    }

string Employee::getSsn()
{   return ssn; }

int Employee::getYearOfBirth()
{   return yearOfBirth; }

string Employee::getEmail()
{   return emailAddress;    }

void Employee::setID(int id)
{   ID = id;    }

void Employee::setName(string n)
{   name = n;   }

void Employee::setSsn(string s)
{   ssn = s;    }

void Employee::setYearOfBirth(int y)
{   yearOfBirth = y;    }

void Employee::setEmail(string e)
{   emailAddress = e;   }