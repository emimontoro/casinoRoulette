CC = g++
CFLAGS = -Wall -Werror -g

main: main.o player.o
	$(CC) $(CFLAGS) main.o player.o -o main

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

player.o: player.cpp 
	$(CC) $(CFLAGS) -c player.cpp

clean: rm -f *.o
