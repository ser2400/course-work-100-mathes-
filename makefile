all:prog
prog:Base.o
  gcc Base.o -o prog.exe
Base.o:Base.cpp
  gcc -c Base.cpp
clean:
  rm -rm *.o
