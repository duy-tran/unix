OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c)) 
#Get all .c files, return all .o 
run: $(OBJECTS)
		gcc -o run $(OBJECTS)

main.o: main.c functions.h 
		gcc -c main.c

factorial.o: factorial.c factorial.h
		gcc -c factorial.c

hello.o: hello.c hello.h
		gcc -c hello.c
.PHONY: clean # when file clean already exists => call command "clean"
clean:
		rm -rf *.o run
		ls