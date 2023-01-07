# all: main.o libparse.a	
# 	gcc -g -o calc main.o -L. -lparse
all: main.o parsing.o	
	gcc -g -o calc main.o parsing.o

main.o: main.c
	gcc -g -c main.c

# libparse.a: parsing.o
# 	ar rsc libparse.a parsing.o

parsing.o: parsing.c
	gcc -g -c parsing.c

clean:
	del calc.exe parsing.o libparse.a main.o