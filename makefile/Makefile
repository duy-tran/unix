CC = gcc
CFLAGS = -Wall -c
LFLAGS = -Wall -o
OUTPUT = run
LIBS = -L. -lcmps
#INCLUDES = -I../path/to/include

run: main.o
	$(CC) $(LFLAGS) $(OUTPUT) main.o $(LIBS)

main.o: main.c functions.h factorial.h hello.h
	$(CC) $(CFLAGS) main.c $INCUDES

factorial.o: factorial.c factorial.h
		$(CC) $(CFLAGS) factorial.c

hello.o: hello.c hello.h
		$(CC) $(CFLAGS) hello.c

library: factorial.o hello.o
	ar rcs libscmps.a factorial.o hello.o

.PHONY: clean
clean:
	rm -rf *.o libcmps.a run