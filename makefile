#Makefile

.PHONY: all clean

all: base

base:	clean build bin build/src/base.o build/src/functions.o
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

test: bin/main_test
	bin/main_test

bin/main_test: bin build_t build/test/main.o build/test/functions.o
	gcc build/test/main.o build/test/functions.o -o bin/main_test

build/test/main.o: test/main.c src/functions.h
	gcc -I src -c test/main.c -o build/test/main.o

build/test/base.o: src/base.c src/functions.h
	gcc -Wall -c src/base.c -o $@

build/test/functions.o:	src/functions.c src/functions.h
	gcc -Wall -c src/functions.c -o $@


build_t:
	mkdir -p build/test
