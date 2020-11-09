SOURCES:=$(wildcard *.cc)
OBJECTS:=$(patsubst %.cc,%.o,$(SOURCES))
CXXFLAGS:=-g -Wall -std=c++11
ELF:=main
var:=mmap
LD_LIBRARY_PATH:=/home/cheng/20200130/lib*.so/lib

$(ELF):$(OBJECTS)
	$(CXX)  $^  -o $@ 
$(var).o:$(var).cc
	$(CXX)  $(CXXFLAGS) -c $^ -I include -o $@ 
clean:
	rm -rf $(OBJECTS) $(ELF)
