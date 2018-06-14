CC = gcc
CFLAGS  = -Wall -Werror -std=gnu11

.PHONY: clean

all: bin build default test

default: bin/turnset

test: bin/turnset-test
	bin/turnset-test

bin/turnset: build/main.o build/Funcs.o  build/Funcs_2.o bin
	$(CC) $(CFLAGS) build/main.o build/Funcs.o  build/Funcs_2.o -o bin/turnset

build/main.o: src/main.c src/Funcs.h  src/Funcs_2.h build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/Funcs.o: src/Funcs.c src/Funcs.h  src/Funcs_2.h build
	$(CC) $(CFLAGS) -c src/Funcs.c -o build/Funcs.o

build/Funcs_2.o: src/Funcs_2.c src/Funcs.h build
	$(CC) $(CFLAGS) -c src/Funcs_2.c -o build/Funcs_2.o

bin/turnset-test: build/main_test.o build/Funcs.o  build/Funcs_2.o bin
	$(CC) $(CFLAGS) build/main_test.o build/Funcs.o  build/Funcs_2.o -o bin/turnset-test


build/main_test.o: test/main.c thirdparty/ctest.h src/Funcs.h src/Funcs_2.h build
	$(CC) $(CFLAGS) -I thirdparty -I src  -c test/main.c -o build/main_test.o

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin
