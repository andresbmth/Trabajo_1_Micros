cc = gcc
CFLAGS = -O3 -c -Wall

all:	obj 
	rm -f test.o
	$(cc) -o main.exe *.o -lpdcurses
	rm -f *.o	

test:	obj
	rm -f main.o
	$(cc) -o test.exe *.o -lpdcurses
	rm -f *.o	

obj:
	$(cc) $(CFLAGS) *.c

clean:
	rm -f main.exe
	rm -f test.exe
