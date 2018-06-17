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

