g++ -fpic -g -Wall -c print.cc  -o print.o
g++ -shared print.o -o /lib/libprint.so
