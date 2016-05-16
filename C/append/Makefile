OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall -o
run: $(OBJECTS)
		$(CC) $(LFLAGS) run $(OBJECTS)

main.o: main.cpp append.h
		$(CC) $(CFLAGS) main.cpp

append.o: append.cpp append.h
		$(CC) $(CFLAGS) append.cpp

.PHONY: clean # when file clean already exists => call command "clean"
clean:
		rm -rf *.o run