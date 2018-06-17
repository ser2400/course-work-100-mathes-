.PHONY: all clean

base:	mkDir base.o
	gcc build/src/base.o -o bin/100sp

base.o:	src/base.c
	gcc -Wall -c src/base.c -o build/src/base.o

clean:
	rm -r build

mkDir:
	mkdir bin
	mkdir build
	mkdir build/src

rmDir: 
	rm -r bin
	rm -r build

tests: build/test/main.o
	gcc build/test/main.o -o bin/tests

build/test/main.o: test/main.c
	gcc -I src -c test/main.c -o build/test/main.o