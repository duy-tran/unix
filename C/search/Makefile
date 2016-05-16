OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
#Get all .cpp files, return all .o 
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall -o
run: $(OBJECTS)
		$(CC) $(LFLAGS) run $(OBJECTS)

main.o: main.cpp copy.h generateFileName.h fileName.h
		$(CC) $(CFLAGS) main.cpp

copy.o: copy.cpp copy.h
		$(CC) $(CFLAGS) copy.cpp

generateFileName.o: generateFileName.cpp generateFileName.h
		$(CC) $(CFLAGS) generateFileName.cpp

fileName.o: fileName.cpp fileName.h
		$(CC) $(CFLAGS) fileName.cpp

.PHONY: clean # when file clean already exists => call command "clean"
clean:
		rm -rf *.o run