SOURCE:=$(wildcard *.cc)
tcpserver:$(SOURCE)
	g++  -g -Wall $^  -o $@  -std=c++11 -lpthread
clean:
	rm -rf tcpserver
