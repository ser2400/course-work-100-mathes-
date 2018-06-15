CC = gcc
CFLAGS  = -Wall -Werror -std=gnu11

.PHONY: clean

all: bin build default test

default: bin/base

test: bin/base-test
    bin/base-test

bin/base:   build/Base.exe build/Funcs.o  build/Funcs_2.o bin
    $(CC) $(CFLAGS) build/Base.exe build/Funcs.o  build/Funcs_2.o -o bin/base

build/Base.exe: src/Base.c src/Funcs.h  src/Funcs_2.h build
    $(CC) $(CFLAGS) -c src/Base.c -o build/Base.exe

build/Funcs.o:  src/Funcs.c src/Funcs.h  src/Funcs_2.h build
    $(CC) $(CFLAGS) -c src/Funcs.c -o build/Funcs.o

build/Funcs_2.o:    src/Funcs_2.c src/Funcs.h build
    $(CC) $(CFLAGS) -c src/Funcs_2.c -o build/Funcs_2.o

bin/base-test:  build/Base_test.o build/Funcs.o  build/Funcs_2.o bin
    $(CC) $(CFLAGS) build/Base_test.o build/Funcs.o  build/Funcs_2.o -o bin/base-test


build/Base_test.o:  test/Base.c thirdparty/ctest.h src/Funcs.h src/Funcs_2.h build
    $(CC) $(CFLAGS) -I thirdparty -I src  -c test/Base.c -o build/Base_test.o

build:
    mkdir build

bin:
    mkdir bin

clean:
    rm -rf build bin
