/*
Write a function that takes a sentence as a parameter and returns the acronym corresponding to the first letter of each of its words in uppercase.
Example: If the sentence is '' java developement kit '', the function returns '' JDK ''

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int indexOf(char Char, char* String, int startIndex);
int countWords(char *String);
int countChar(char Char, char *String);
void getAcronym(char *String, char *outString);

int main()
{
    char *Charstring = "Hello   therE chIld.   Test For   client FinitEc";
    char *Vowels     = "aeiouAEIOU";

    int CountOfVowels = 0;
    
    for (int i = 0; Vowels[i] != '\0'; i++)
    {
        CountOfVowels += countChar(Vowels[i], Charstring);
    }

    int length     = strlen(Charstring);
    int wordCount  = countWords(Charstring);
    int indxOfChar = 0;
    
    char Acronym[wordCount+1];
    getAcronym(Charstring, Acronym);

    printf("String:\t\t\'%s\'",     Charstring);
    printf("\nString[0]:\t%c",      Charstring[0]);
    printf("\nString[n-1]:\t%c",    Charstring[length-1]);

    indxOfChar = indexOf('c', Charstring, 0);
    while (indxOfChar != -1)
    {
        printf("\nIndex Of c:\t%d",indxOfChar); 
        indxOfChar = indexOf('c', Charstring, indxOfChar+1);
    } 

    printf("\nCount of e:\t%d",     countChar('e', Charstring));
    printf("\nCount of vwls:\t%d",  CountOfVowels);
    printf("\nCount of wrds:\t%d",  wordCount);
    printf("\nAcronym:\t%s",        Acronym);

    getchar();
}

int indexOf(char Char, char* String, int startIndex)
{
    if(String == 0 || startIndex > strlen(String))
        return -1;

    for (int index = startIndex; String[index] != '\0'; index++)
    {
        if(String[index] == Char)
            return index;
    }

    return -1;
}

int countWords(char *String)
{
    if(String == 0)
        return -1;

    bool OnAWord = false;
    int count    = 0;

    for (int index = 0; String[index] != '\0'; index++)
    {
        if(String[index] != ' ' && !OnAWord)
        {
            count++;
            OnAWord = true;
        }
        else 
        {
            if(String[index] == ' ' && OnAWord)
            {
                OnAWord = false;
            }
        }
    }
    return count;
}

int countChar(char Char, char *String)
{
    if(String == 0)
        return -1;

    int count = 0;

    for(int index = 0; String[index] != '\0'; index++)
    {
        if(String[index] == Char)
            count++;
    }

    return count;
}

void getAcronym(char *String, char *outString)
{
    if(String == 0 || outString == 0)
        return;

    bool OnAWord = false;
    int outIndex = 0;

    for(int index = 0; String[index] != '\0'; index++)
    {
        if(String[index] != ' ' && !OnAWord)
        {
            outString[outIndex++] = toupper(String[index]);
            OnAWord = true;
        }
        else 
        {
            if(String[index] == ' ' && OnAWord)
            {
                OnAWord = false;
            }
        }    
    }

    outString[outIndex] = '\0';
}