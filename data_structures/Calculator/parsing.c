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
