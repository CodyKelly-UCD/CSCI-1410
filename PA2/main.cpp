/*
 Cody Kelly
 CSCI 1410-002
 Programming assignment #2
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "functions.h"
using namespace std;

int main(int argc, const char * argv[])
{
    const int MAX_SIZE = 100;
    Fish inventory[MAX_SIZE];
    int invSize = 0;
    
    int menuChoice = 0;
    
    
    // Display welcome message
    cout << "\nWelcome to FishMan, your ultimate fish management system.\n";
    
    do {
        displayMainMenu();
        menuChoice = getMenuChoice(9);
        
        switch (menuChoice) {
            case 1:
                if(fishInInventory(invSize))
                {
                    displayInventory(inventory, invSize, false);
                }
                break;
            case 2: readFromFile(inventory, invSize, MAX_SIZE);
                break;
            case 3: writeToFile(inventory, invSize);
                break;
            case 4: addFish(inventory, invSize, MAX_SIZE);
                break;
            case 5: removeFish(inventory, invSize);
                break;
            case 6: searchInventory(inventory, invSize, MAX_SIZE);
                break;
            case 7: updateQuantity(inventory, invSize, MAX_SIZE);
                break;
            case 8: updateLocation(inventory, invSize, MAX_SIZE);
                break;
            case 9:
                if (invSize) {
                    char choice;
                    cout << "\nDo you want to save your inventory before exiting? (Y/N)\n";
                    cin >> choice;
                    
                    if (choice == 'Y' || choice == 'y') {
                        writeToFile(inventory, invSize);
                    }
                }
            default:
                break;
        }
    } while (menuChoice != 9);
}







/*
 ╔═╗┬┌─┐┬ ┬╔╦╗┌─┐┌┐┌
 ╠╣ │└─┐├─┤║║║├─┤│││
 ╚  ┴└─┘┴ ┴╩ ╩┴ ┴┘└┘
 
 The Ultimate in Fish
 Management.
 */
