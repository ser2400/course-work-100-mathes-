CC = gcc
CFLAGS  = -Wall -Werror -std=gnu11

.PHONY: clean

all: bin build default test

default: bin/base

bin/base:   build/Base.exe bin
	$(CC) $(CFLAGS) build/Base.exe -o bin/base

build/Base.exe: src/Base.c build
	$(CC) $(CFLAGS) -c src/Base.c -o build/Base.exe

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin
