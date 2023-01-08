#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inc\parsing.h"
#define str_len 30

void userParse(char* inpString)
{
    printf("Podaj wyrazenie arytmetyczne, dozwolone znaki: + - * /: \n");
    char c;
    //while((c = getchar()) != '\n' && c != EOF)
    fflush(stdin);
    fgets(inpString,str_len,stdin);

}
int characterCompare(char* inpString, int index)
{
    if(*(inpString+index)== '+' ||*(inpString+index)== '-' ||*(inpString+index)== '*' ||*(inpString+index)== '/')
        return 1;
    else
    return 0;
}
int openBracket(char* inpString, int index)
{
     if(*(inpString+index)== '(')
        return 1;
    else
    return 0;
}
int closedBracket(char* inpString, int index)
{
     if(*(inpString+index)== ')')
        return 1;
    else
    return 0;
}
//łańcuch znaków jest w porządku jeśli zaczyna się od liczby, potem znaki przeplatają sie z liczbami
int parsingIsValid(char *inpString) // funckja zwraca 0 jesli dane są w dobrej formie, -1 jesli w zlej
{   
    int length = 0; // with NULL terminator
    int index = 0;
    int bracketFlag = 0;
    while (*(inpString + index) != 0) // liczenie długosci łancucha
    ++index;
    *(inpString + index - 1) = 0; // usuwamy znak \n z łańcucha wejściowego
    length = index;
    index = 0;
    int index2 = 0;
    while (index < length-1)
    {
    if (*(inpString+ index) == ')' && bracketFlag > 0)
    {
        bracketFlag--;
        index2 = index;
        ++index;
        continue;
    }
    else if ((*(inpString+ index) == ')' && bracketFlag == 0))
    {
        printf("Invalid data\n");
        return -1;
    }
    if (characterCompare(inpString, index))
    {
        if (index2 == index && bracketFlag == 0)
        {
            printf("Invalid data\n");
            return -1;
        }
        for (; index2 < index; ++index2)
        {
            if (isdigit(*(inpString + index2)) != 0)
                continue;
            else if (*(inpString + index2) == '-')
            {
                if (isdigit(*(inpString + index2 + 1)) == 0) // sytuacja: dwa minusy obok siebie
                {
                    printf("Invalid data\n");
                    return -1;
                }
            }
            else if (*(inpString + index2) == ')')
            {
                continue;
            }
            else
            {
                printf("Invalid data\n");
                return -1;
            }
        }
        index2 = index + 1;
    } else if (openBracket(inpString, index)) {
        int index3 = index + 1;
        int index4 = index3;
        int length3 = 0;
        while (index3 < length - 1) {
            if (closedBracket(inpString, index3)) {
                length3 = index3 - index4;
                break;
            }
            index3++;
        }
        if (length3 == 0) {
            printf("Invalid data\n");
            return -1;
        }
        index3 = index4;
        int start_value = index3;
        while (index3 < length3 + start_value) {
            if (index3 == index + 1 &&
                characterCompare(inpString,
                                 index3))   // pierwszy znak po (, sytuacja (-
                                            // jest dopuszczalna, inne nie
            {
                if (*(inpString + index3) == '-') {
                    if (isdigit(*(inpString + index3 + 1)) ==
                        0)   // sytuacja: dwa minusy obok siebie
                    {
                        printf("Invalid data\n");
                        return -1;
                    } else {
                        ++index3;
                        continue;
                    }
                } else {
                    printf("Invalid data\n");
                    return -1;
                }
            } else if (characterCompare(inpString, index3)) {
                for (; index4 < index3; ++index4) {
                    if (isdigit(*(inpString + index4)) != 0)
                        continue;
                    else {
                        printf("Invalid data\n");
                        return -1;
                    }
                }
                index4 = index3 + 1;
            }
            ++index3;
        }
        if (index4 == index3) {
            printf("Invalid data\n");
            return -1;
        }
        ++index2;
        ++bracketFlag;
    }
    ++index;
    }
    if (index2 == index)
    {
        printf("Invalid data\n");
        return -1;
    }
    printf("Input data is valid\n");
    return 0;
}
