//
//  employee.h
//  Employee Management System
//
//  Created by Not Cody on 11/30/14.
//  Copyright (c) 2014 thingy. All rights reserved.
//

#ifndef Employee_Management_System_employee_h
#define Employee_Management_System_employee_h

#include <string>
using namespace std;

class Employee
{
private:
    int ID;
    string name;
    string ssn;
    string emailAddress;
    int yearOfBirth;
    
public:
    Employee(int ID, string Name, string SSN, string Email, int yearOfBirth);
    Employee();
    
    int getID();
    string getName();
    string getSsn();
    int getYearOfBirth();
    string getEmail();
    void setID(int);
    void setName(string);
    void setSsn(string);
    void setYearOfBirth(int);
    void setEmail(string);
};

#endif
