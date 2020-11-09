SOURCES:=$(wildcard *.cc)
OBJECTS:=$(patsubst %.cc,%.o,$(SOURCES))
CXXFLAGS:=-g -Wall -std=c++11 -I include 

ELF:=main
LD_LIBRARY_PATH:=/home/cheng/20200130/lib*.so/lib

$(ELF):$(OBJECTS)
	$(CXX) $(CXXFLAGS) $^  -o $@  
clean:
	rm -rf $(OBJECTS) $(ELF)
