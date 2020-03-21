// Homework 21
/* File:        main.cpp
 * Author:      Shannon Rose Woodside
 * Purpose:     Average Word Length Program
 * Created on March 15, 2020, 7:01 PM
 */
// preprocessor directives
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
// declare function
void wordLength (ifstream &bob);
// precondition: reads and accepts bob.txt
// postcondition: determines and sorts the words and characters from bob.txt
////////////////////////////////////////////////////////////////////////////
// main function 
int main(int argc, char** argv) 
{
    // declare variable
    ifstream bob;  
    // opens file bob.txt and checks for errors
    bob.open("bob.txt");
    if(bob.fail())
    {
        // prints error message if file fails to open
        cout << "The input file \"bob.txt\" failed to open.\n";
        exit (EXIT_FAILURE);
    }
    // calls wordLength function
    wordLength (bob);
    // closes file bob.txt
    bob.close();
    // exits program 
    exit (EXIT_SUCCESS);
}
/////////////////////////////////////////////////////////////////////////////
// wordLength function
void wordLength (ifstream &bob)
{
    // declare variables
    char input, input2; 
    int charCount = 1, wordCount = 0; 
    // initialize file variable 
    bob.get(input);
    // loop runs as long as file is not empty    
    while (!bob.eof())
    {    
        // prints results in column format
        cout << "\n" << input << "\tChars: " << charCount << "\tWords: " << wordCount 
             << endl;
      
        // copy previous input into new input
        input2 = input;
        bob.get(input);
        
        // whitespace if function to determine when a word is formed   
        if (isspace(input) && (!isspace(input2) || input2 != '-'))
            wordCount++;
        else if (!isspace(input))
        {
            if (isalpha(input))
                charCount++;
            else if ((input == '\'' || input == '-') && (input2 != '\'' || input2 != '-'))
                charCount++; 
        }
    }


    // average character per word calculations/ printout 
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "\n\t" << "Average Chars/Word: ";
    cout << static_cast<double>(charCount)/ wordCount << endl;
    
    // exit function
    return;
}
