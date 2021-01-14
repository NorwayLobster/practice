SOURCES:=$(wildcard *.cc)
OBJECTS:=$(patsubst %.cc,%.o,$(SOURCES))
CXXFLAGS:=-g -Wall -fpic -std=c++11 -lcrypt -lpthread -I ../include -I /usr/include/mysql/ -lmysqlclient 
ELF:=libcheng.so
$(ELF):$(OBJECTS)
	$(CXX) -shared $^ -o ../lib/$@
clean:
	rm -rf $(OBJECTS) 
