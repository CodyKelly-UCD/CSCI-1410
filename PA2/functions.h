// All functions for the program.
// And a fish.

#ifndef FishMan_functions_h
#define FishMan_functions_h
using namespace std;


struct Fish
{
    string name;    // Type of fish
    int tank;       // Current fish tank
    int quantity;   // How many fish in the tank
    double price;   // Price of fish
};

/*******************************************************************************
 *                              fishInInventory
 *
 *      Checks if invSize is more than zero. If it isn't, then an error
 *      will print for the user.
 *      Returns
 ******************************************************************************/

bool fishInInventory(int inventorySize)
{
    if (inventorySize == 0)
    {
        cout << "\nThere are no fish in your inventory.\n";
        cout << "\nEither ";
        cout << "\n\t2. Read Fish Inventory From a File or";
        cout << "\n\t4. Add Fish to Inventory\n";
    }
    return inventorySize > 0;
}

/*******************************************************************************
 *                              displayInventory
 *
 *      Displays contents of the inventory array.
 *      Takes a Fish array, the current inventory size, and the maximum
 *      inventory size.
 ******************************************************************************/

void displayInventory(Fish inventory[], int invSize, bool showIndex)
{
    cout << "\nThere are " << invSize;
    cout << " different kinds of fish in your inventory.\n";
    for (int count = 0; count < invSize; count++)
    {
        if(showIndex){
            cout << setw(21) << left << "\nFish index number:" << right << (count + 1) << endl;
        }
        else
        {
            cout << endl;
        }
        cout << setw(20) << left << "Name:" << right << inventory[count].name << endl;
        cout << setw(20) << left << "Tank number:" << right << inventory[count].tank << endl;
        cout << setw(20) << left << "Quantity of fish:" << right << inventory[count].quantity << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << setw(20) << left << "Price:" << right << "$" << inventory[count].price << endl;
    }
}

/*******************************************************************************
 *                              displayFish
 *
 *      Displays information on one fish in the inventory.
 *      Takes a Fish array, the current inventory size, the maximum inventory
 *      size, and the index of the fish displayed.
 ******************************************************************************/

void displayFish(Fish inventory[], int invSize, int index, bool showIndex)
{
    while(index > invSize || index < 1) // Check if index number is valid
    {
        cout << "\nNot a valid index number.\n"
        // If index is not valid, show the user a valid range of index numbers.
        << "Choose a number between 1 and " << invSize << "." << endl;
    }
    
    if(showIndex){
        cout << setw(21) << left << "\nFish index number:" << right << index << endl;
    }
    else
    {
        cout << endl;
    }
    cout << setw(20) << left << "Name:" << right << inventory[(index - 1)].name << endl;
    cout << setw(20) << left << "Tank number:" << right << inventory[(index - 1)].tank << endl;
    cout << setw(20) << left << "Quantity of fish:" << right << inventory[(index - 1)].quantity << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << setw(20) << left << "Price:" << right << "$" << inventory[(index - 1)].price << endl;
}

/*******************************************************************************
 *                              displayMainMenu
 *
 *      Displays the main menu. Doesn't take any parameters, doesn't return
 *      anything. Just displays the main menu.
 ******************************************************************************/

void displayMainMenu()
{
    cout << "\nPlease make a selection from the menu.\n";
    
    cout << "\n\t1. View Fish Inventory"
    << "\n\t2. Read Fish Inventory From a File"
    << "\n\t3. Write Fish Inventory to a File"
    << "\n\t4. Add Fish to Inventory"
    << "\n\t5. Remove Fish from Inventory"
    << "\n\t6. Search for Fish"
    << "\n\t7. Update Quantity"
    << "\n\t8. Update Tank/Location"
    << "\n\t9. Exit\n";
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
    
    // Keep asking for choice until a valid choice is made
    do {
        cout << "\n> ";
        cin >> choice;
        
        // Valid choices range from 1 to numChoices
        if (choice < 1 || choice > numChoices)
        {
            cout << "\nPlease select a choice from the menu.";
        }
        
    } while (choice < 1 || choice > numChoices);
    
    // "Choice" starts to sound weird after you say it a lot.
    
    return choice;
}

/*******************************************************************************
 *                              inputFishName
 *
 *      Gets a fish name from the user. First letter must be capatalized
 *      for the function to return the name.
 ******************************************************************************/

string inputFishName()
{
    string name;    // Holds fish name
    bool lowercase; // Holds true if name starts with a lowercase letter
    
    // Gotta watch out for any stray return characters.
    cin.ignore();
    
    do {
        
        // Get fish name
        name = "";
        cout << "\nEnter the name of the fish: \n";
        cout << "> ";
        getline(cin, name);
        
        
        lowercase = name < "A" || name > "Z";
        if(lowercase)
        {
            // Fish name must be capitalized for sorting later.
            // Also it just makes everything easier.
            // Literally eveything.
            cout << "\nFirst letter of fish name must be capitalized.\n";
        }
        
    } while (lowercase);
    
    return name;
}

/*******************************************************************************
 *                              sortByName
 *
 *      Sorts a Fish array by fish names, alphabetically.
 *      Takes a Fish array, the current inventory size, and the maximum
 *      inventory size.
 *      Doesn't return anything.
 ******************************************************************************/

void sortByName(Fish inventory[], int invSize)
{
    Fish lowestFish;    // Holds a Fish if inventory elements are swapped
    bool swap = false;  // This is true if there was a swap
    
    do {
        swap = false;
        
        for (int count = 0; count < invSize - 1; count++)
        {
            if(inventory[count].name > inventory[count + 1].name)
            {
                lowestFish = inventory[count + 1];
                inventory[count + 1] = inventory[count];
                inventory[count] = lowestFish;
                
                swap = true;
            }
        }
    } while (swap);
}

/*******************************************************************************
 *                              addFish
 *
 *      Adds a Fish to the inventory.
 *      Takes a Fish array, the current inventory size, and the maximum
 *      inventory size.
 *      Doesn't return nothin'.
 ******************************************************************************/

void addFish(Fish inventory[], int &invSize, int MAX_SIZE)
{
    // Check if user has reached inventory limit
    if(invSize == MAX_SIZE)
    {
        cout << "\nYou have already reached the maximum number of fish. (100)\n";
        cout << "\nIf you want to add more, you'll have to remove others first.\n";
    }
    else
    {
        string name;
        int location;
        int quantity;
        double price;
        
        // This will be true if the user gives a name already given to other
        // fish.
        bool alreadyNamed = false;
        
        name = inputFishName();
        
        // Check for other fish with that name.
        for (int count = 0; count < invSize; count++) {
            if (inventory[count].name == name) {
                cout << "\nYou already have fish with that name.\n";
                alreadyNamed = true;
            }
        }
        
        if (!alreadyNamed) {
            // Gather fish info from user
            cout << "\nEnter the fish tank number: \n";
            cout << "> ";
            cin >> location;
            
            cout << "\nEnter the quantity of fish: \n";
            cout << "> ";
            cin >> quantity;
            
            cout << "\nEnter the price per fish: \n";
            cout << "> ";
            cin >> price;
            
            // Make a new Fish and put it on the end of the array
            Fish fish = {name, location, quantity, price};
            inventory[invSize] = fish;
            
            // Increase inventory size
            invSize++;
            
            // Lastly, sort the inventory alphabetically by fish name
            sortByName(inventory, invSize);
        }
    }
}

/*******************************************************************************
 *                              removeFish
 *
 *      Removes a Fish from the inventory.
 *      Takes a Fish array, the current inventory size, and the maximum
 *      inventory size.
 *      Doesn't return anything.
 ******************************************************************************/

void removeFish(Fish inventory[], int &invSize)
{
    if (fishInInventory(invSize)) {
        int index;
        
        displayInventory(inventory, invSize, true);
        
        // Ask the user for an index number until they input a valid one.
        do {
            cout << "\nPlease select a fish by its index number:\n";
            cout << "> ";
            cin >> index;
            
            if(index > invSize || index < 1)
            {
                cout << "\nNot a valid index number.\n"
                << "Choose a number between 1 and " << invSize << "." << endl;
            }
        } while (index > invSize || index < 1);
        
        string fishName = inventory[index - 1].name;
        
        inventory[index - 1] = inventory[invSize - 1];
        
        invSize--;
        
        sortByName(inventory, invSize);
        
        cout << endl << fishName << " was removed.\n";
    }
}

/*******************************************************************************
 *                              updateQuantity
 *
 *      Allows the user to change quantity data for a single fish
 *      Takes a Fish array, the current size and max size, and doesn't return
 *      anything.
 ******************************************************************************/

void updateQuantity(Fish inventory[], int invSize, int MAX_SIZE)
{
    int index;  // Index of fish to edit
    int choice; // User's menu choice
    
    
    // First, display inventory to user. Calling this first will also
    // tell the user if they don't have any fish in their inventory
    displayInventory(inventory, invSize, true);
    
    // Then check if there's fish in the inventory
    if(fishInInventory(invSize)){
        
        // Ask the user for an index number until they input a valid one.
        do {
            cout << "\nPlease select a fish by its index number:\n";
            cout << "> ";
            cin >> index;
            
            if(index > invSize || index < 1)
            {
                cout << "\nNot a valid index number.\n"
                << "Choose a number between 1 and " << invSize << "." << endl;
            }
        } while (index > invSize || index < 1);
        
        // Display info about the fish the user chose.
        
        string fishName = inventory[index - 1].name;
        int fishQuant = inventory[index - 1].quantity;
        
        cout << "\nThere are currently " << fishQuant << " " << fishName << "s.\n";
        
        // Display sub-menu
        cout << "\nPlease make a selection from the menu.\n";
        cout << "\n\t1. New total quantity";
        cout << "\n\t2. Decrease by one";
        cout << "\n\t3. Increase by one";
        
        choice = getMenuChoice(3);
        
        int newFishQuant;   // Holds new fish quantity
        
        switch (choice) {
            case 1:
                cout << "\nEnter new quantity of " << fishName << "s:" << endl;
                cout << "> ";
                cin >> newFishQuant;
                inventory[(index - 1)].quantity = newFishQuant;
                break;
            case 2:
                inventory[(index - 1)].quantity--;
                break;
            case 3:
                inventory[(index - 1)].quantity++;
                break;
            default:
                break;
        }
        
        // Display the chosen fish data again, with updated quantity data
        cout << "\nThere are now " << inventory[(index - 1)].quantity << " " << fishName << "s.\n";
    }
}

/*******************************************************************************
 *                              updateLocation
 *
 *      Allows the user to change tank data for a single fish
 *      Takes a Fish array, the current size and max size, and doesn't return
 *      anything.
 ******************************************************************************/

void updateLocation(Fish inventory[], int invSize, int MAX_SIZE)
{
    int index;  // Index of fish to edit
    int newTank;    // new tank number
    
    // First, display inventory to user. Calling this first will also
    // tell the user if they don't have any fish in their inventory
    
    // Then check if there's fish in the inventory
    if(fishInInventory(invSize)){
        displayInventory(inventory, invSize, true);
        
        // Ask the user for an index number until they input a valid one.
        do {
            cout << "\nPlease select a fish by its index number:\n";
            cout << "> ";
            cin >> index;
            
            if(index > invSize || index < 1)
            {
                cout << "\nNot a valid index number.\n"
                << "Choose a number between 1 and " << invSize << "." << endl;
            }
        } while (index > invSize || index < 1);
        
        string fishName = inventory[index - 1].name;
        int tankNum = inventory[index - 1].tank;
        
        cout << "\nThe " << fishName << "'s current tank is tank #"
        << tankNum << endl;
        
        cout << "Enter the new tank number:\n";
        cout << "> ";
        cin >> newTank;
        
        inventory[index - 1].tank = newTank;
        
        // Display the chosen fish data again, with updated quantity data
        cout << "\nThe " << fishName << "s have been moved to tank #"
        << newTank << ".\n";
    }
}

/*******************************************************************************
 *                              searchInventory
 *
 *      Searches inventory for fish with a specific name. If found, it
 *      displays the fish's information. If not, an error is displayed.
 *      Takes a Fish array and the current and max size of the array.
 *      It doesn't return anything.
 ******************************************************************************/

void searchInventory(Fish inventory[], int invSize, int MAX_SIZE)
{
    if(fishInInventory(invSize)) // Check if there's fish in the array
    {
        // Get fish name from user
        string name = inputFishName();
        
        bool notFound = true; // False if fish has been found
        
        // Run through inventory and search for fish with that name
        for (int count = 0; count < invSize; count++) {
            if (inventory[count].name == name) {
                displayFish(inventory, invSize, count + 1, true);
                notFound = false;
            }
        }
        if (notFound) {
            cout << "\nNo fish were found with that name.\n";
        }
    }
}

/*******************************************************************************
 *                              writeToFile
 *
 *      Writes the current inventory to a file.
 ******************************************************************************/

void writeToFile(Fish inventory[], int invSize)
{
    if (fishInInventory(invSize)) {
        string fileName;        // File to output to
        ofstream outputFile;    // output file stream object
        
        // Get file name from user
        cout << "\nPlease enter a file name to save to (ex. FishInventory):\n";
        cout << "> ";
        cin >> fileName;
        
        outputFile.open(fileName + ".dat");
        
        for (int count = 0; count < invSize; count++) {
            outputFile << inventory[count].name << endl;
            outputFile << inventory[count].tank << endl;
            outputFile << inventory[count].quantity << endl;
            outputFile << fixed << showpoint << setprecision(2);
            outputFile << inventory[count].price << endl;
        }
        
        outputFile.close();
        
        cout << endl << invSize << " fish written to " << fileName << ".dat\n";
    }
}

/*******************************************************************************
 *                              readFromFile
 *
 *      Reads data from file and adds to current inventory
 ******************************************************************************/

void readFromFile(Fish inventory[], int &invSize, int MAX_SIZE)
{
    string fileName;
    ifstream inputFile;
    
    bool alreadyExists = false;
    
    cout << "\nPlease enter name of file to read from:\n";
    cout << "> ";
    cin >> fileName;
    
    inputFile.open(fileName + ".dat");
    
    if(inputFile.is_open()){
        
        string name;
        int tank;
        int quantity;
        double price;
        
        int fishCount;  // Number of new fish
        
        while (inputFile)
        {
            alreadyExists = false;
            
            getline(inputFile, name);
            inputFile >> tank;
            inputFile.ignore();
            inputFile >> quantity;
            inputFile.ignore();
            inputFile >> price;
            inputFile.ignore();
            
            if (invSize == MAX_SIZE) {
                cout << "\nYou have already reached the maximum number of fish. (100)\n";
                cout << "\nIf you want to add more, you'll have to remove others first.\n";
                break;
            }
            else
            {
                
                for (int count = 0; count < invSize; count++) {
                    if (inventory[count].name == name) {
                        alreadyExists = true;
                    }
                }
                
                if(!alreadyExists && name != "")
                {
                    Fish newFish = {name, tank, quantity, price};
                    inventory[invSize] = newFish;
                    invSize++;
                    fishCount++;
                }
            }
        }
        
        sortByName(inventory, invSize);
        
        cout << endl << fishCount << " new fish from "
        << fileName << ".dat added to inventory.\n";
    }
    else
    {
        cout << "\nNo file found with that name.\n";
    }
    
    
    inputFile.close();
}

#endif
