main : main.o lib/add.o lib/subtract.o lib/multiply.o lib/divide.o
	gcc -o main main.o lib/add.o lib/subtract.o lib/multiply.o lib/divide.o

main.o : main.c
	gcc -c main.c

add.o : add.c
	gcc -c add.c

subtract.o : subtract.c
	gcc -c subtract.c

multiply.o : multiply.c
	gcc -c multiply.c

divide.o : divide.c
	gcc -c divide.c

clean : 
	rm -f main main.o lib/add.o lib/subtract.o lib/multiply.o lib/divide.o
