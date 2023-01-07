/*
Program będzie pobierał od użytkownika ciąg znaków będący wyrażeniem arytmetycznym, wyrażenie w notacji infixowej.
Program na podstawie danych wejściowch dokona konwersji na postać postfixową, utworzy drzewo, rozwiąże je i zwróci wynik działania. 
obsługiwane działania to dodawanie, odejmowanie, mnożenie, dzielenie, obsługa nawiasów
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inc\parsing.h"
#define str_len 30


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