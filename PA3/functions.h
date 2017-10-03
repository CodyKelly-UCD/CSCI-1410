// All functions for the program.

#ifndef Employee_Management_System_functions_h
#define Employee_Management_System_functions_h
#include "employee.h"
#include <vector>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

/*******************************************************************************
 *                              displayMainMenu
 *
 *      Displays the main menu. Doesn't take any parameters, doesn't return
 *      anything. Just displays the main menu.
 ******************************************************************************/

void displayMainMenu()
{
    cout << "\n\nPlease make a selection from the menu.\n";
    
    cout << "\n\t1. Display employee directory"
    << "\n\t2. Add an employee"
    << "\n\t3. Update an employee"
    << "\n\t4. Delete an employee"
    << "\n\t5. Sort employees by ID"
    << "\n\t6. Search directory by email"
    << "\n\t7. Read directory from file"
    << "\n\t8. Write directory to file and exit";
}

/*******************************************************************************
 *                              getMenuChoice
 *
 *      Gets a choice from the user as an integer.
 *      Takes the maximum number of choices and returns the user's choice.
 ******************************************************************************/

int getMenuChoice(int numChoices)
{
    int choice; // Holds user's choice
    
    // Keep asking until a valid choice is made
    do {
        cout << "\n> ";
        cin >> choice;
        cin.ignore();
        
        // Valid choices range from 1 to numChoices
        if (choice < 1 || choice > numChoices)
        {
            cout << endl << choice << " is not a valid menu choice."
            << "\nPlease make a selection between 1 and " << numChoices << endl;
        }
        
    } while (choice < 1 || choice > numChoices);
    
    return choice;
}

/*******************************************************************************
 *                              inputName
 *
 *      Gets an employee name from the user.
 ******************************************************************************/

string inputName()
{
    string name;    // Holds employee name

    // Get Employee name
    cout << "\nEnter employee name. \n";
    cout << "Press Enter when done.\n";
    cout << "> ";
    getline(cin, name);
    
    return name;
}

/*******************************************************************************
 *                              inputEmail
 *
 *      Gets an employee email address from the user and provides error
 *      checking so no invalid addresses are returned.
 ******************************************************************************/

string inputEmail()
{
    string email;    // Holds employee name
    bool valid = false; // Is the address given valid?
    
    do
    {
        // Get address from user
        cout << "\nPlease enter employee email address (in format xxx@xxx.xxx).\n";
        cout << "Press Enter when done.\n";
        cout << "> ";
        getline(cin, email);
        
        double atPos;   // Holds position of first '@' symbol
        double dotPos;  // This holds the position of
                        // the first '.' after the first '@' (atPos)
        
        // Check if address given contains an at symbol '@' and a period '.'
        atPos = email.find('@'); // assign position of 1st '@' symbol (npos if none)
        
        if (atPos != string::npos)  // If there is a '@' symbol
        {
            dotPos = email.find('.', atPos);    // position of 1st '.' symbol
        }
        
        // Now that we've established that there is a '@', we can check if
        // there is a period after it.
        if (dotPos != string::npos) // If there is a '.' after the '@'
        {
            // If there is a period, we then finally check if there are spaces
            if (email.find(' ') == string::npos)
            {
                valid = true;    // If there are no spaces, the string is valid.
            }
        }

        if (!valid) {
            cout << "\nInvalid email address.\n";
        }
    } while(!valid);
    
    return email;
}

/*******************************************************************************
 *                              inputSSN
 *
 *      Gets an employee SSN from the user.
 ******************************************************************************/

string inputSSN()
{
    string ssn;    // Holds employee ssn
    bool valid = true;     // Holds whether or not the ssn is valid
    
    do
    {
        valid = true;
        // Get employee's ssn
        cout << "\nEnter employee's SSN (in format xxx-xx-xxxx or xxxxxxxxx). \n";
        cout << "Press Enter when done.\n";
        cout << "> ";
        getline(cin, ssn);
        
        // Now we check to see if the SSN given is valid. First we'll check to
        // see if the given SSN has a length of 9 or 11 (allowing the user to
        // enter dashes or not.)
        if (ssn.length() == 9)  // If the length is 9 (no dashes)
        {
            // First we check if all the characters are numbers.
            for (int count = 0; count < ssn.length(); count++) {
                if (!isdigit(ssn[count])) {
                    valid = false;
                }
            }
            // If the SSN is still valid, put dashes in the proper places.
            if (valid) {
                ssn.insert(3, "-");
                ssn.insert(6, "-");
            }
            // The formatted SSN is ready to be returned.
        }
        else if (ssn.length() == 11)  // If the SSN given is 11 characters long
        {
            // We check if all chars are numbers, except characters at positions
            // 3 and 6, which should be dashes if the SSN was entered correctly.
            for (int count = 0; count < ssn.length(); count++) {
                if (!isdigit(ssn[count]) && count != 3 && count != 6) {
                    valid = false;
                }
            }
            // If the user entered dashes already, no need to format it. We can
            // return it as-is.
        }
        else
        {
            // If the length isn't 9 or 11, then it's wrong. Probably.
            valid = false;
        }
        if (!valid) {
            // Tell the user if they entered an invalid SSN
            cout << "\nInvalid SSN.\n";
        }
    } while (!valid);   // Repeat until valid.
        
    return ssn;
}

/*******************************************************************************
 *                              inputID
 *
 *      Gets an employee ID from the user.
 ******************************************************************************/

int inputID()
{
    int ID;    // Holds employee ID
    
    // Prompt user for ID
    cout << "\nEnter employee ID. \n";
    cout << "Press Enter when done.\n";
    cout << "> ";
    cin >> ID;
    cin.ignore();   // Flush input and ignore extra whitespace.
    
    return ID;
}

/*******************************************************************************
 *                              inputYOB
 *
 *      Gets an employee year of birth from the user.
 ******************************************************************************/

int inputYOB()
{
    int yob;    // Holds employee yob
    
    // Get yob
    cout << "\nEnter employee year of birth (in format YYYY). \n";
    cout << "Press Enter when done.\n";
    cout << "> ";
    cin >> yob;
    cin.ignore();   // Flush input and ignore extra whitespace.
    
    return yob;
}

/*******************************************************************************
 *                              addEmployee
 *
 *      Adds an employee to the directory.
 ******************************************************************************/

void addEmployee(vector<Employee> &dir)
{
    // First get all Employee information from user with our handy "input"
    // functions.
    string name = inputName();
    int ID = inputID();
    string SSN = inputSSN();
    string email = inputEmail();
    int yob = inputYOB();
    
    // Then we create a new Employee object using the given information
    Employee newEmployee = Employee(ID, name, SSN, email, yob);
    
    // And add it to the end of the directory.
    dir.push_back(newEmployee);
}

/*******************************************************************************
 *                              employeesInDirectory
 *
 *      Checks if there are employees in the directory. If not, returns false
 ******************************************************************************/

bool employeesInDirectory(vector<Employee>& dir)
{
    if (dir.size() == 0)
    {
        cout << "\nThere are no employees in the directory.\n";
        cout << "\nEither ";
        cout << "\n\t2. Add an employee";
        cout << "\n\t7. Read directory from file\n";
    }
    return dir.size() > 0;
}

/*******************************************************************************
 *                              displayDirectory
 *
 *      Displays contents of the employee directory in an easy to read list
 ******************************************************************************/

void displayDirectory(vector<Employee>& dir)
{
    // First check if there are employees in the directory.
    if (employeesInDirectory(dir)) {
        
        // Tell user how many employees are currently in the directory.
        if (dir.size() != 1) {
            cout << "\nThere are " << dir.size();
            cout << " employees in the directory.\n";
        }
        else
        {
            cout << "\nThere is 1 employee in the directory.\n";
        }
        
        // Then go through and display each employee's information.
        for (int count = 0; count < dir.size(); count++)
        {
            int width = 10; // whitespace padding width (to make it look neat)
            cout << endl;
            // Display the employee's position in the directory (starting at 1).
            cout << setw(width) << left
                 << "Employee:" << right << count + 1 << endl;
            // Display ID
            cout << setw(width) << left
                 << "ID:" << right << dir[count].getID() << endl;
            // You got the point.
            cout << setw(width) << left
                 << "Name:" << right << dir[count].getName() << endl;
            cout << setw(width) << left
                 << "SSN:" << right << dir[count].getSsn() << endl;
            cout << setw(width) << left
                 << "Email:" << right << dir[count].getEmail() << endl;
            cout << setw(width) << left
                 << "Year:" << right << dir[count].getYearOfBirth() << endl;
        }
    }
}

/*******************************************************************************
 *                              updateEmployee
 *
 *      Updates a specific employee's data
 ******************************************************************************/

void updateEmployee(vector<Employee>& dir)
{
    // First check if there are employees in the directory.
    if (employeesInDirectory(dir)) {
        int choice, choice2; // For menu selections
        
        displayDirectory(dir);  // Display the current directory to the user
        
        cout << "\nPlease enter the number of the employee you would like to update.\n";
        choice = getMenuChoice(dir.size()) - 1;
        
        // Now that we know which employee the user wants to update, we can ask
        // WHAT they want to update about that employee.
        cout << "\nYou have chosen " << dir[choice].getName() << ".\n";
        cout << "\nWould you like to update their:"
        << "\n\t1. ID"
        << "\n\t2. Name"
        << "\n\t3. SSN"
        << "\n\t4. Email"
        << "\n\t5. Year of birth";
        
        choice2 = getMenuChoice(5); // Holds sub-menu choice.
        
        switch (choice2) {
            case 1:
                dir[choice].setID(inputID());
                break;
            case 2:
                dir[choice].setName(inputName());
                break;
            case 3:
                dir[choice].setSsn(inputSSN());
                break;
            case 4:
                dir[choice].setEmail(inputEmail());
                break;
            case 5:
                dir[choice].setYearOfBirth(inputYOB());
                break;
            default:
                break;
        }
        
        cout << "\nEmployee updated.\n";
    }
}

/*******************************************************************************
 *                              deleteEmployee
 *
 *      Deletes an employee from directory
 ******************************************************************************/

void deleteEmployee(vector<Employee> &dir)
{
    // First check if there are employees in the directory.
    if (employeesInDirectory(dir)) {
        
        displayDirectory(dir);
        
        cout << "\nPlease select the employee you would like to remove.\n";
        int choice = getMenuChoice(dir.size()) - 1;
        
        dir.erase(dir.begin()+choice);  // Pass an iterator at the position of
                                        // the employee plus the beginning of
                                        // the directory
        
        cout << "\nEmployee removed from directory.\n";
    }
}

/*******************************************************************************
 *                              searchEmail
 *
 *      Searches directory for an employee with the email given.
 ******************************************************************************/

void searchEmail(vector<Employee> &dir)
{
    if(employeesInDirectory(dir))
    {
        // Get email from user
        string email = inputEmail();
        
        bool found = false; // True if employee has been found
        
        // Run through inventory and search for the employee with that name
        int count;  // counter
        
        for (count = 0; count < dir.size(); count++) {
            if (dir[count].getEmail() == email) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "\nEmployee found at index #" << count + 1 << endl;
        }
        else
        {
            cout << "\nNo employees were found with that email address.\n";
        }
    }
}

/*******************************************************************************
 *                              writeToFile
 *
 *      Writes the current directory to a file.
 ******************************************************************************/

void writeToFile(vector<Employee>& dir)
{
    string fileName = "./directory.dat";        // File to output to
    ofstream outputFile;    // output file stream object
    
    outputFile.open(fileName);
    
    // output information
    for (int count = 0; count < dir.size(); count++) {
        outputFile << dir[count].getID() << endl;
        outputFile << dir[count].getName() << endl;
        outputFile << dir[count].getSsn() << endl;
        outputFile << dir[count].getEmail() << endl;
        outputFile << dir[count].getYearOfBirth() << endl;
    }
    
    outputFile.close();
}

/*******************************************************************************
 *                              readFromFile
 *
 *      Reads data from file and adds to current directory
 ******************************************************************************/

void readFromFile(vector<Employee>& dir)
{
    string fileName = "./directory.dat";
    ifstream inputFile;
    
    inputFile.open(fileName);
    
    // If we actually opened the file
    if(inputFile.is_open()){
        
        // variables to hold information from file
        int ID;
        string name;
        string ssn;
        string email;
        int yob;
        
        // While we can extract information from the file, we put that info
        // into the variables above.
        while (inputFile >> ID)
        {
            inputFile.ignore();
            getline(inputFile, name);
            getline(inputFile, ssn);
            getline(inputFile, email);
            inputFile >> yob;
            inputFile.ignore();
            
            // Make a new employee and push it into the directory.
            Employee newEmployee = Employee(ID, name, ssn, email, yob);
            dir.push_back(newEmployee);
        }
        
        cout << "\nDone.\n";
    }
    else
    {
        cout << "\nError opening file.\n";
    }
    
    
    inputFile.close();
}

/*******************************************************************************
 *                              sortByID
 *
 *      Sorts directory by employees' IDs using a bubble sort algorithm
 ******************************************************************************/

void sortByID(vector<Employee>& dir)
{
    if (employeesInDirectory(dir)) {
        bool swap;  // True if elements were swapped
        Employee temp;
        int end = dir.size();   // End of unsorted directory
        
        do
        {
            swap = false;
            for (int count = 0; count < end; count++)
            {
                // Check if the current employee's ID is smaller than the next.
                if (dir[count].getID() < dir[count+1].getID())
                {
                    // the next three lines do a swap
                    temp = dir[count];  // holds a copy of the current employee
                    dir[count] = dir[count+1];  // puts the next employee in the
                                                // current element
                    dir[count+1] = temp;    // Put the first employee in the
                                            // next element
                    swap = true;    // There was a swap.
                }
            }
            end--;  // decrement end because that part of the
            // directory is already sorted.
            
        } while(swap != false);
    }
}



#endif
