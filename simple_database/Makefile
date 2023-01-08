all: main.o sorting.o	
	gcc -g -o base main.o sorting.o

main.o: main.c
	gcc -g -c main.c

sorting.o: sorting.c
	gcc -g -c sorting.c

clean:
	del base.exe main.o sorting.o