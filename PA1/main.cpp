/*
 // Made by Cody Kelly (Student ID #101886601)
 // CSCI 1410-002
 // Sunday, September 28th, 2014
 // Programming assignment #1
 
 // I forgot if you wanted us to put this on the top or bottom so I'll
 // just put it both places.
 
 // I also forgot what you wanted us to put in these header
 // comments so I apologize if I put too much or too little information.
 
 // aaallllsssooooo forgot if this was supposed to be a block comment
 // or just regular ones so I'll make it both of those.
 
 // In retrospect, I probably should have emailed you about this.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    string name;	// User's name
    
    // Prompt user for their name
    cout << "Please enter your name: ";
    getline(cin, name);
    
    // Welcome user to this beautifully crafted program
    cout << "\n\t" << name << ", welcome to your ASCII Art Program!";
    
    while(true)
    {
        cout << endl << endl;
        
        char choice;	// Holds user's choice at the menu
        
        // Output menu and prompt user for choice
        cout << "\nPlease select a geometric shape:\n"
        << "s:\tSquare\n"
        << "c:\tCircle\n"
        << "d:\tDiamond\n"
        << "t:\tTriangle\n"
        << "e:\tExit\n"
        << "> ";
        cin >> choice;
        cout << endl;
        
        if(choice == 'e' || choice == 'E')
        {
            break;
        }
        
        int charCount = 0;	// Counts how many characters are in shape
        
        if(choice == 's' || choice == 'S')
        {
            int width;
            char character;
            
            do
            {
                // Prompt user for square width
                cout << "Input a shape width of 80 or less\n"
                << "> ";
                cin >> width;
            }while(width > 80);
            
            // Prompt user for character
            cout << "\nInput ASCII character (any one letter,"
            << "number, or symbol on your keyboard)\n"
            << "> ";
            cin >> character;
            
            cout << endl << endl;
            
            int height = width;	// The height is adjusted to account
            // for stretching in the terminal
            
            // Add some space (to make output less clumped together)
            cout << endl << endl;
            
            for(int c = 0; c < height; c++)
            {
                // output one full line of characters
                cout << setfill(character) << setw(width) << "" << endl;
                
                charCount += width;
            }
            
            // Output the number of characters used in the square
            cout << "\nYour square has " << charCount << " '" << character << "' characters in it.\n\n";
        }
        else if(choice == 't' || choice == 'T')
        {
            int width;
            char character;
            
            do
            {
                // Prompt user for square width
                cout << "Input a shape width of 80 or less\n"
                << "> ";
                cin >> width;
            }while(width > 80);
            
            // Prompt user for character
            cout << "\nInput ASCII character (any one letter,"
            << "number, or symbol on your keyboard)\n"
            << "> ";
            cin >> character;
            
            cout << endl << endl;
            
            int rows = width / 2;		// How many lines tall the triangle is in the terminal.
            int middle = width / 2 - 1;	// The middle of the triangle
            int outputCounter = width % 2;	// How many characters to output each row
            for(int r = 0; r <= rows; r++)
            {
                for(int x = 0; x <= middle - r; x++)
                {
                    cout << ' ';
                }
                for(int x = 0; x < outputCounter; x++)
                {
                    cout << character;
                    charCount++;
                }
                outputCounter += 2;
                cout << endl;
            }
            
            // Output the number of characters used in the triangle
            cout << "\nYour triangle has " << charCount << " '" << character << "' characters in it.\n\n";
        }
        else if(choice == 'd' || choice == 'D')
        {
            int width;
            char character;
            
            do
            {
                // Prompt user for square width
                cout << "Input a shape width of 80 or less\n"
                << "> ";
                cin >> width;
            }while(width > 80);
            
            // Prompt user for character
            cout << "\nInput ASCII character (any one letter,"
            << "number, or symbol on your keyboard)\n"
            << "> ";
            cin >> character;
            
            cout << endl << endl;
            
            int rows = width;		 // How many lines tall the diamond is in the terminal.
            int middle = width / 2 - 1;	 // The middle of the triangle
            int outputCounter = width % 2;	 // How many characters to output each line
            int whitespaceCounter = middle;	 // How much whitespace to output each line
            for(int r = 0; r <= rows; r++)
            {
                for(int x = 0; x <= whitespaceCounter; x++)
                {
                    // First print the whitespace
                    cout << ' ';
                }
                for(int x = 0; x < outputCounter; x++)
                {
                    // Then print each character
                    // and increment the character
                    // counter each time.
                    cout << character;
                    charCount++;
                }
                
                if(r < rows / 2)
                {
                    // If loop is less than halfway
                    // done, whitespace is decremented
                    // and two more characters
                    // are printed next line
                    whitespaceCounter--;
                    outputCounter += 2;
                }
                else
                {
                    // If loop is more than halfway
                    // done, whitespace is incremented
                    // and two less characters are printed
                    whitespaceCounter++;
                    outputCounter -= 2;
                }
                cout << endl;	// Row done, add line
            }
            
            // Output the number of characters used in the triangle
            cout << "\nYour diamond has " << charCount << " '" << character << "' characters in it.\n\n";
        }
        else if(choice == 'c' || choice == 'C')
        {
            int width;
            char character;
            
            do
            {
                // Prompt user for square width
                cout << "Input a shape width of 80 or less\n"
                << "> ";
                cin >> width;
            }while(width > 80);
            
            // Prompt user for character
            cout << "\nInput ASCII character (any one letter,"
            << "number, or symbol on your keyboard)\n"
            << "> ";
            cin >> character;
            
            cout << endl << endl;
            
            int r = width / 2;	// Circle radius
            int rSqrd = pow(r, 2);	// Radius squared
            int middle = r;		// Middle of circle
            
            // Going from r to negative r makes it simpler to
            // calculate the x value, as counter is the current
            // y value and the circle is calculated from
            // the origin
            for(int counter = r; counter >= -r; counter--)
            {
                int xSqrd = rSqrd - pow(counter, 2); // x squared equals r squared minus y squared
                int x = sqrt(abs(xSqrd)); // Take the square root of the absolute value
                // of xSqrd to get x
                // (the absolute value function here makes sure
                //  no negative numbers are used in the sqrt
                //  function)
                
                int charWidth = x * 2; // The number of characters in this row
                
                if(width % 2 == 0)
                {
                    // charWidth is always one too large
                    // in even-width(ed?) circles
                    charWidth -= 1;
                }
                
                int whitespace = (middle - charWidth / 2); // Amount of whitespace before characters are printed
                
                if(width % 2 == 0)
                {
                    // Even circles' whitespaces
                    // are also always
                    // one too large
                    whitespace--;
                }
                for(int c = 0; c < whitespace; c++)
                {
                    // Output whitespace
                    cout << ' ';
                }
                for(int c = 0; c <= charWidth; c++)
                {
                    // Then output character and increment character counter
                    cout << character;
                    charCount++;
                }
                cout << endl;	// Row is done, end line.
            }
            cout << "\nYour circle has " << charCount << " '" << character << "' characters in it.\n\n";
        }
        else
        {
            cout << "\nPlease enter a choice from the menu. \n"
            << "(Either s, c, d, t, or e.)\n";
        }
    }
    return 0;
}

/*
 // Made by Cody Kelly (Student ID #101886601)
 // CSCI 1410-002
 // Sunday, September 28th, 2014
 // Programming assignment #1
 */

// You're not gonna take off points because of these top and bottom comments, are you?
// Please don't. I worked hard for those extra credit circle points.
// Slaved over a hot keyboard for a while, if not longer.
