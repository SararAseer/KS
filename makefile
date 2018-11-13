all: KS.o 
	gcc KS.o

a.out: KS.o
	gcc KS.o

KS.o: KS.c 
	gcc -c KS.c

run: a.out
	./a.out

clean: KS.o
	rm *.o

