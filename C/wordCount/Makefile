OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall -o
run: $(OBJECTS)
		$(CC) $(LFLAGS) run $(OBJECTS)

main.o: main.cpp count.h
		$(CC) $(CFLAGS) main.cpp

count.o: count.cpp count.h
		$(CC) $(CFLAGS) count.cpp

.PHONY: clean # when file clean already exists => call command "clean"
clean:
		rm -rf *.o run