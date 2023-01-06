/*
Program będzie pobierał od użytkownika ciąg znaków będący wyrażeniem arytmetycznym, wyrażenie w notacji infixowej.
Program na podstawie danych wejściowch dokona konwersji na postać postfixową, utworzy drzewo, rozwiąże je i zwróci wynik działania. 
obsługiwane działania to dodawanie, odejmowanie, mnożenie, dzielenie, obsługa nawiasów
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parsing.h"
#include "tree.h"
#define str_len 30

void userParse(char* inpString)
{
    printf("Podaj wyrazenie arytmetyczne, dozwolone znaki: + - * /: \n");
    fgets(inpString,str_len,stdin);
}
int characterCompare(char* inpString, int index)
{
    if(*(inpString+index)== '+' ||*(inpString+index)== '-' ||*(inpString+index)== '*' ||*(inpString+index)== '/')
        return 1;
    else
    return 0;
}
//łańcuch znaków jest w porządku jeśli zaczyna się od liczby, potem znaki przeplatają sie z liczbami
int parsingIsValid(char *inpString) // funckja zwraca 0 jesli dane są w dobrej formie, -1 jesli w zlej
{   
    int length = 0; // with NULL terminator
    int index = 0;
    while (*(inpString + index) != 0) // liczenie długosci łancucha
    ++index;
    *(inpString + index - 1) = 0; // usuwamy znak \n z łańcucha wejściowego
    length = index;
    index = 0;
    int index2 = 0;
    while (index != length)
    {
    if (characterCompare(inpString, index))
    {
        if (index2 == index)
        {
            printf("Invalid data\n");
            return -1;
        }
        for (; index2 < index; ++index2)
        {
            if (isdigit(*(inpString + index2)) != 0)
                continue;
            else
                printf("Invalid data\n");
            return -1;
        }
        index2 = index + 1;
    }
    ++index;
    }
    printf("Input data is valid\n");
    return 0;
}

int main (int argc, char** argv)
{   
    int abortFlag = 0;
    char inputString[str_len] = {0};
    do
    {
        userParse(inputString);
        if (strncmp(inputString,"q",1)==0)
        abortFlag = 1;
        else if(parsingIsValid(inputString) == 0)
        {
            
        }



    } while (abortFlag == 0);

    return 0;
}