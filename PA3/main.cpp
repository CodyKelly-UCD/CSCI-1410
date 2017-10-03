/*
 Cody Kelly
 CSCI 1410-002
 Programming assignment #3
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "functions.h"
#include "employee.h"
#include <vector>
using namespace std;

int main()
{
    vector<Employee> employeeDirectory(0);  // Employee directory; holds
                                            // all Employee instances.
    
    int menuChoice = 0; // Holds user menu choice.
    
    
    // Display welcome message.
    cout << "\nWelcome to your Employee Management System.\n";
    
    do {
        // Main loop
        
        displayMainMenu();  // Display menu
        menuChoice = getMenuChoice(8);  // Get user menu choice
        
        switch (menuChoice) {
            case 1: displayDirectory(employeeDirectory);
                break;
            case 2: addEmployee(employeeDirectory);
                break;
            case 3: updateEmployee(employeeDirectory);
                break;
            case 4: deleteEmployee(employeeDirectory);
                break;
            case 5: sortByID(employeeDirectory);
                break;
            case 6: searchEmail(employeeDirectory);
                break;
            case 7: readFromFile(employeeDirectory);
                break;
            case 8: writeToFile(employeeDirectory);
                break;
            default:
                break;
        }
    } while (menuChoice != 8);
}







/*
 .----------------.  .----------------.  .----------------.
 | .--------------. || .--------------. || .--------------. |
 | |  _________   | || | ____    ____ | || |    _______   | |
 | | |_   ___  |  | || ||_   \  /   _|| || |   /  ___  |  | |
 | |   | |_  \_|  | || |  |   \/   |  | || |  |  (__ \_|  | |
 | |   |  _|  _   | || |  | |\  /| |  | || |   '.___`-.   | |
 | |  _| |___/ |  | || | _| |_\/_| |_ | || |  |`\____) |  | |
 | | |_________|  | || ||_____||_____|| || |  |_______.'  | |
 | |              | || |              | || |              | |
 | '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'
 
      Employee            Management            System
 
 
  Solutions for a 21st century business, presented in a 17th
                 century Command Line program.
 */