#Makefile

.PHONY: all clean

all: bin build base

base:	build/src/base.o build/src/functions.o
	gcc build/src/base.o build/src/functions.o -o bin/100sp

build/src/base.o: src/base.c src/functions.h
	gcc -Wall -c src/base.c -o $@

build/src/functions.o:	src/functions.c src/functions.h
	gcc -Wall -c src/functions.c -o $@

clean:
	rm -rf build bin

bin:
	mkdir bin

build:
	mkdir -p build/src

build_t:
	mkdir -p build/test

test: build/test/main.o build_t
	gcc build/test/main.o -o bin/tests

build/test/main.o: test/main.c
	gcc -I src -c test/main.c -o build/test/main.o