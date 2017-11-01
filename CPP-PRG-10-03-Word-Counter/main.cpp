//
//  main.cpp
//  CPP-PRG-10-03-Word-Counter
//
//  Created by Keith Smith on 11/1/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a function that accepts a pointer to a C-string as an argument and returns the
//  number of words contained in the string. For instance, if the string argument is "Four
//  score and seven years ago" the function should return the nunber 6. Demonstrate the
//  function in a program that asks the user to input a string then passes it to the function.
//  The number of words in the string should be displayed on the screen. Optional
//  Exercise: Write an overloaded version of this function that accepts a string class
//  object as its argument.

#include <iostream>
#include <cstring>

using namespace std;

char *getUserInput(int *);
int *calculateCharactersTotal(char *, int *);
int *calculateWordsTotal(char *, int *);
void displayResults(int *);

int main()
{
    int *intSize = nullptr;
    intSize = new int;
    *intSize = 999;
    
    int *intChars = nullptr;
    int *intWords = nullptr;
    
    char *chrUserInput = nullptr;
    
    chrUserInput = getUserInput(intSize);
    
    intChars = calculateCharactersTotal(chrUserInput, intSize);
    
    intWords = calculateWordsTotal(chrUserInput, intChars);
    
    displayResults(intWords);
    
    return 0;
}

char *getUserInput(int *intSize)
{
    char *chrTemp = nullptr;
    chrTemp = new char[*intSize];
    
    cout << "Please enter a sentence:\n";
    cin.getline(chrTemp, *intSize);
    
    return chrTemp;
}

int *calculateCharactersTotal(char *chrChars, int *intSize)
{
    int *intCharacters = nullptr;
    intCharacters = new int;
    *intCharacters = 0;
    
    for (int i = 0 ; i < *intSize ; i++)
    {
        *intCharacters += 1;
        
        if (chrChars[i] == '\0')
        {
            break;
        }
    }
    
    return intCharacters;
}

int *calculateWordsTotal(char *chrChars, int *intChars)
{
    int *intCounter = nullptr;
    intCounter = new int;
    *intCounter = 0;
    
    for (int i = 0 ; i < *intChars ; i++)
    {
        if (chrChars[i] == ' ' || chrChars[i] == '\0')
        {
            *intCounter += 1;
        }
    }
    
    return intCounter;
}

void displayResults(int *intResult)
{
    cout << "There are " << *intResult << " words in that string." << endl;
}
