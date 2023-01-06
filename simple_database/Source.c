#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH 50
#define record_len 31
#define page_count 10
//glowna struktura elementu
struct rekord
{
	char autor[31];
	char tytul[31];
	char wydawnictwo[31];
	char l_str[10];
	char gatunek[31];
};

int sortuj_autor(const void *x, const void *y);
int sortuj_tytul(const void *x, const void *y);
FILE *fp;
FILE *pp;
errno_t err;
struct rekord r[LENGTH];//maksymalna liczba rekordow
int l_rekordow = 0 ;
int main(void)
{
	
	int a;
	int b[4];
	for (int index = 0; index < sizeof(b)/sizeof(b[0]); ++index)
	{
		b[index] = -1;
	}
	char wyszukanie[30];
	char temp[30];
	char modyfikacja[30];
	int k = -2;
	int m = -3;
	int sort;
	int v;
	char wstrzymanie[4];
	while (1)
	{
		printf("  Katalog biblioteczny\n");
		printf("  1. Wyswietl rekordy\n  2. Dodaj nowy rekord\n  3. Wyszukaj\n  4. Modyfikuj rekord\n  5. Usun rekord\n  6. Sprawdz liczbe rekordow w bazie\n  7. Zamknij program\n");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			err = fopen_s(&pp, "porzadkowa.txt", "r");
			if (err == 0)
			{
				fscanf_s(pp, "%d", &l_rekordow);
				fclose(pp);
			}
			else
				printf("nie mozna odczytac pliku\n");
			err = fopen_s(&fp, "dane.txt", "r");
			if (err == 0)
			{
				printf("Posiadane rekordy\n	Nazwisko i imie autora\t\t         Tytul\t       Wydawnictwo\tLiczba stron\t   Gatunek literacki\n");
				for (int index = 0; index < l_rekordow; ++index)
				{
					fscanf_s(fp, "%s", r[index].autor, 30);
					fscanf_s(fp, "%s", r[index].tytul, 30);
					fscanf_s(fp, "%s", r[index].wydawnictwo, 30);
					fscanf_s(fp, "%s", r[index].l_str, 9);
					fscanf_s(fp, "%s", r[index].gatunek, 30);
				} 
				for (int index = 0; index < l_rekordow; ++index)
				{
					printf("%30s\t", r[index].autor);
					printf("%22s\t", r[index].tytul);
					printf("%18s\t", r[index].wydawnictwo);
					printf("%8s\t", r[index].l_str);
					printf("%20s", r[index].gatunek);
					printf("\n");
				}
			}
			else
				printf("Nie mo�na wy�wietli� pliku\n");
			printf("\n");
			printf("1. sortuj wg. nazwiska autora\n");
			printf("2. sortowanie wg. tytulu utworu\n");
			scanf_s("%d", &sort);
			if (sort == 1)
			{
				qsort(r, l_rekordow, sizeof(struct rekord), sortuj_autor);
				for (int index = 0; index < l_rekordow; ++index)
				{
					printf("%30s\t", r[index].autor);
					printf("%22s\t", r[index].tytul);
					printf("%18s\t", r[index].wydawnictwo);
					printf("%8s\t", r[index].l_str);
					printf("%20s", r[index].gatunek);
					printf("\n");
				}
				printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
				if (scanf_s("%s", wstrzymanie, 3) != 1)
					;
				fclose(fp);
				system("cls");
			}
			else if(sort == 2)
			{
				qsort(r, l_rekordow, sizeof(struct rekord), sortuj_tytul);
				for (int i = 0; i < l_rekordow; ++i)
				{
					printf("%30s\t", r[i].autor);
					printf("%22s\t", r[i].tytul);
					printf("%18s\t", r[i].wydawnictwo);
					printf("%8s\t", r[i].l_str);
					printf("%20s", r[i].gatunek);
					printf("\n");
				}
				printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
				if (scanf_s("%s", wstrzymanie, 3) != 1)
					;
				fclose(fp);
				system("cls");
			}
			else 
			{
				printf("Podano inny parametr.\n");
				printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
				if (scanf_s("%s", wstrzymanie, 3) != 1)
					;
				fclose(fp);
				system("cls");
			}	
			break;
		case 2:
		
			err = fopen_s(&pp, "porzadkowa.txt", "r");
			if (err == 0)
			{
				fscanf_s(pp, "%d", &l_rekordow);
				fclose(pp);
			}
			else
				printf("nie mozna odczytac pliku\n");
			err = fopen_s(&fp, "dane.txt", "a+");
			if (err == 0)
			{
				printf("Uwaga! przy wprowadzaniu danych zastap znak spacji przez _\n");
				printf("podaj autora	");
				scanf_s("%s", r[l_rekordow].autor, 30);
				printf("podaj tytul		");
				scanf_s("%s", r[l_rekordow].tytul, 30);
				printf("podaj wydawnictwo	");
				scanf_s("%s", r[l_rekordow].wydawnictwo, 30);
				printf("podaj liczbe stron	");
				scanf_s("%s", r[l_rekordow].l_str, 9);
				printf("podaj gatunek	");
				scanf_s("%s", r[l_rekordow].gatunek, 30);
				fprintf(fp, "%s %s %s %s %s\n", r[l_rekordow].autor, r[l_rekordow].tytul, r[l_rekordow].wydawnictwo, r[l_rekordow].l_str, r[l_rekordow].gatunek);
				l_rekordow++;
				fclose(fp);
				printf("Dane zostaly zapisane\n");
				if (l_rekordow != 0)
				{
					err = fopen_s(&pp, "porzadkowa.txt", "w");
					if (err == 0)
					{
						fprintf(pp, "%d", l_rekordow);
						fclose(pp);
					}
				}
				printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
				if (scanf_s("%s", wstrzymanie, 3) != 1)
					;
				system("cls");
			}
			else
				printf("Nie mo�na wy�wietli� pliku\n");
			break;
		case 3:
			err = fopen_s(&pp, "porzadkowa.txt", "r");
			if (err == 0)
			{
				fscanf_s(pp, "%d", &l_rekordow);
				fclose(pp);
			}
			else
				printf("nie mozna odczytac pliku\n");
			err = fopen_s(&fp, "dane.txt", "r");
			if (err == 0)
			{
				for (int i = 0; i < l_rekordow; ++i)
				{
					fscanf_s(fp, "%s", r[i].autor, 30);
					fscanf_s(fp, "%s", r[i].tytul, 30);
					fscanf_s(fp, "%s", r[i].wydawnictwo, 30);
					fscanf_s(fp, "%s", r[i].l_str, 9);
					fscanf_s(fp, "%s", r[i].gatunek, 30);
				}
				fclose(fp);
			}
			for (int i = 0; i < 4; ++i)
			{
				b[i] = -1;
			}
			printf("Uwaga! Przy wprowadzaniu danych zastap znak spacji przez _\n Wyszukanie autora tylko przez podanie pelnego nazwiska i imienia\n");
			printf("Podaj wyraz do wyszukania:	");
			scanf_s("%s", &wyszukanie, 30);
			for (int i = 0; i < l_rekordow; ++i)
			{
				if (strcmp(r[i].autor, wyszukanie) == 0)
				{
					b[0] = i;
					break;
				}
			}
			for (int i = 0; i < l_rekordow; ++i)
			{
				if (strcmp(r[i].tytul, wyszukanie) == 0)
				{
					b[1] = i;
					break;
				}
			}
			for (int i = 0; i < l_rekordow; ++i)
			{
				if (strcmp(r[i].wydawnictwo, wyszukanie) == 0)
				{
					b[2] = i;
					break;
				}
			}
			for (int i = 0; i < l_rekordow; ++i)
			{
				if (strcmp(r[i].gatunek, wyszukanie) == 0)
				{
					b[3] = i;
					break;
				}
			}
			if (b[0] == (-1) && b[1] == (-1) && b[2] == (-1) && b[3] == (-1))
				printf("Nie znaleziono w bazie danych\n");
			if (b[0] != -1)
			{
				printf("Znaleziono w rekordzie:\n");
				printf("%s	", r[b[0]].autor);
				printf("%s	", r[b[0]].tytul);
				printf("%s	", r[b[0]].wydawnictwo);
				printf("%s	", r[b[0]].l_str);
				printf("%s	", r[b[0]].gatunek);
				printf("\n");
			}
			if (b[1] != (-1))
			{
				printf("Znaleziono w rekordzie:\n");
				printf("%s	", r[b[1]].autor);
				printf("%s	", r[b[1]].tytul);
				printf("%s	", r[b[1]].wydawnictwo);
				printf("%s	", r[b[1]].l_str);
				printf("%s	", r[b[1]].gatunek);
				printf("\n");
			}
			if (b[2] != (-1))
			{
				printf("Znaleziono w rekordzie:\n");
				printf("%s	", r[b[2]].autor);
				printf("%s	", r[b[2]].tytul);
				printf("%s	", r[b[2]].wydawnictwo);
				printf("%s	", r[b[2]].l_str);
				printf("%s	", r[b[2]].gatunek);
				printf("\n");
			}
			if (b[3] != (-1))
			{
				printf("Znaleziono w rekordzie:\n");
				printf("%s	", r[b[3]].autor);
				printf("%s	", r[b[3]].tytul);
				printf("%s	", r[b[3]].wydawnictwo);
				printf("%s	", r[b[3]].l_str);
				printf("%s	", r[b[3]].gatunek);
				printf("\n");
			}
			printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
			if (scanf_s("%s", wstrzymanie, 3) != 1)
				;
			system("cls");
			break;
		case 4:
			err = fopen_s(&pp, "porzadkowa.txt", "r");
			if (err == 0)
			{
				fscanf_s(pp, "%d", &l_rekordow);
				fclose(pp);
			}
			else
				printf("nie mozna odczytac pliku\n");
			err = fopen_s(&fp, "dane.txt", "r");
			if (err == 0)
			{
				for (int i = 0; i < l_rekordow; ++i)
				{
					fscanf_s(fp, "%s", r[i].autor, 30);
					fscanf_s(fp, "%s", r[i].tytul, 30);
					fscanf_s(fp, "%s", r[i].wydawnictwo, 30);
					fscanf_s(fp, "%s", r[i].l_str, 9);
					fscanf_s(fp, "%s", r[i].gatunek, 30);
				}
				fclose(fp);
			}
			printf("Podaj tytul rekordu, ktory chcesz zmodyfikowac:\t");
			scanf_s("%s", temp, 30);
			for (int i = 0; i < l_rekordow; ++i)
			{
				if (strcmp(r[i].tytul, temp) == 0)
				{
					m = i;
					break;
				}
			}
			if (m == (-3))
			{
				printf("Nie znaleziono rekordu\n");
				printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
				if (scanf_s("%s", wstrzymanie, 3) != 1)
					;
				system("cls");
			}
			else
			{
				printf("Znaleziono rekord %s %s %s %s %s \n", r[m].autor, r[m].tytul, r[m].wydawnictwo, r[m].l_str, r[m].gatunek);
				printf("Ktory element chcesz zmodyfikowac?\n	1 - autor	2 - tytul	3 - wydawnctwo	 4 - liczbe stron	5 - gatunek");
				scanf_s("%d", &v);
				switch (v)
				{
				case 1:
					err = fopen_s(&fp, "dane.txt", "w");
					if (err == 0)
					{
						printf("Podaj nowa wartosc\t");
						scanf_s("%s", &modyfikacja, 30);
						for (int i = 0; i < l_rekordow; ++i)
						{
							if (i == m)
								fprintf(fp, "%s %s %s %s %s\n", modyfikacja, r[i].tytul, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);
							else
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);

						}
						fclose(fp);
					}
					else
						printf("nie mozna odczytac pliku\n");
					break;
				case 2:
					err = fopen_s(&fp, "dane.txt", "w");
					if (err == 0)
					{
						printf("Podaj nowa wartosc\t");
						scanf_s("%s", &modyfikacja, 30);
						for (int i = 0; i < l_rekordow; ++i)
						{
							if (i == m)
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, modyfikacja, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);
							else
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);
						}
						fclose(fp);
					}
					else
						printf("nie mozna odczytac pliku\n");
					break;
				case 3:
					err = fopen_s(&fp, "dane.txt", "w");
					if (err == 0)
					{
						printf("Podaj nowa wartosc\t");
						scanf_s("%s", &modyfikacja, 30);
						for (int i = 0; i < l_rekordow; ++i)
						{
							if (i == m)
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, modyfikacja, r[i].l_str, r[i].gatunek);
							else
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);

						}
						fclose(fp);
					}
					else
						printf("nie mozna odczytac pliku\n");
					break;
				case 4:
					err = fopen_s(&fp, "dane.txt", "w");
					if (err == 0)
					{
						printf("Podaj nowa wartosc\t");
						scanf_s("%s", &modyfikacja, 30);
						for (int i = 0; i < l_rekordow; ++i)
						{
							if (i == m)
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, r[i].wydawnictwo, modyfikacja, r[i].gatunek);
							else
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);

						}
						fclose(fp);
					}
					else
						printf("nie mozna odczytac pliku\n");
					break;
				case 5:
					err = fopen_s(&fp, "dane.txt", "w");
					if (err == 0)
					{
						printf("Podaj nowa wartosc\t");
						scanf_s("%s", &modyfikacja, 30);
						for (int i = 0; i < l_rekordow; ++i)
						{
							if (i == m)
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, r[i].wydawnictwo, r[i].l_str, modyfikacja);
							else
								fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);

						}
						fclose(fp);
					}
					else
						printf("nie mozna odczytac pliku\n");
					break;
				default: printf("podano nieprawidlowy parametr\n");
					break;
				}
					printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
					if (scanf_s("%s", wstrzymanie, 3) != 1)
						;
					system("cls");
				
			}
			break;
		case 5:
			err = fopen_s(&pp, "porzadkowa.txt", "r");
			if (err == 0)
			{
				fscanf_s(pp, "%d", &l_rekordow);
				fclose(pp);
			}
			else
				printf("nie mozna odczytac pliku\n");
			err = fopen_s(&fp, "dane.txt", "r");
			if (err == 0)
			{
				for (int i = 0; i < l_rekordow; ++i)
				{
					fscanf_s(fp, "%s", r[i].autor, 30);
					fscanf_s(fp, "%s", r[i].tytul, 30);
					fscanf_s(fp, "%s", r[i].wydawnictwo, 30);
					fscanf_s(fp, "%s", r[i].l_str, 9);
					fscanf_s(fp, "%s", r[i].gatunek, 30);
				}
				fclose(fp);
			}

			printf("Podaj tytul rekordu, ktory chcesz usunac:\t");
			scanf_s("%s", temp, 30);
			for (int i = 0; i < l_rekordow; ++i)
			{
				if (strcmp(r[i].tytul, temp) == 0)
				{
					k = i;
					break;
				}
			}
			if (k == (-2))
				printf("Nie znaleziono rekordu\n");
			else
			{
				err = fopen_s(&fp, "dane.txt", "w");
				if (err == 0)
				{
					for (int i = 0; i < l_rekordow; ++i)
					{
						if (i == k)
							printf("Usunieto %s %s %s %s %s", r[i].autor, r[i].tytul, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);
						else
							fprintf(fp, "%s %s %s %s %s\n", r[i].autor, r[i].tytul, r[i].wydawnictwo, r[i].l_str, r[i].gatunek);

					}
				}
				fclose(fp);
				l_rekordow--;
				printf("\n");
				if (l_rekordow != 0)
				{
					err = fopen_s(&pp, "porzadkowa.txt", "w");
					if (err == 0)
					{
						fprintf(pp, "%d", l_rekordow);
						fclose(pp);
					}
				}
			}
				printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
				if (scanf_s("%s", wstrzymanie, 3) != 1)
					;
				system("cls");
			
			break;
		case 6:
			err = fopen_s(&pp, "porzadkowa.txt", "r");
			if (err == 0)
			{
				fscanf_s(pp, "%d", &l_rekordow);
				printf("Baza danych posiada %d rekordow\nMaksymalna liczba rekordow: %d\n", l_rekordow, LENGTH);
				printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
				if (scanf_s("%s", wstrzymanie, 3) != 1)
					;
				system("cls");
				fclose(pp);
			}
			else
				printf("Nie mo�na wy�wietli� pliku\n");
			break;
		case 7:	return 0; break;
		default: printf("podano nieprawidlowy parametr\n");
			printf("Wcisnij dowolny klawisz by wrocic do wyboru funkcji\t");
			if (scanf_s("%s", wstrzymanie, 3) != 1)
				;
			system("cls");

			break;
		}

	}
	return 0;
}

int sortuj_autor(const void *x, const void *y) {

	struct rekord const *pierwszy = x;
	struct rekord const *drugi = y;
	return strcmp((*pierwszy).autor, (*drugi).autor);
}
int sortuj_tytul(const void *x, const void *y)
{
	struct rekord const *pierwszy = x;
	struct rekord const *drugi = y;
	return strcmp((*pierwszy).tytul, (*drugi).tytul);

}