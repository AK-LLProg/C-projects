#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "inc/sorting.h"
#define LENGTH 50
#define record_len 31
#define page_count 10

typedef struct rekord
{
	char autor[record_len];
	char tytul[record_len];
	char wydawnictwo[record_len];
	char l_str[page_count];
	char gatunek[record_len];
}rekord;


int sortuj_autor(const void *x, const void *y) 
{
	rekord const *pierwszy = x;
	rekord const *drugi = y;
	return strcmp((*pierwszy).autor, (*drugi).autor);
}
int sortuj_tytul(const void *x, const void *y)
{
	rekord const *pierwszy = x;
	rekord const *drugi = y;
	return strcmp((*pierwszy).tytul, (*drugi).tytul);
}