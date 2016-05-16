run: main.c
		gcc -o run main.o -L. -lcmps

main.o: main.c functions.h factorial.h hello.h
		gcc -c main.c

factorial.o: factorial.c factorial.h
		gcc -c factorial.c

hello.o: hello.c hello.h
		gcc -c hello.c

library : factorial.o hello.o
		ar rcs libcmps.a factorial.o hello.o

.PHONY: clean # when file clean already exists => call command "clean"
clean:
		rm -rf *.o run
		ls