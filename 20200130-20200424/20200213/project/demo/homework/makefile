SOURCES:=$(wildcard *.cc)
OBJECTS:=$(patsubst %.cc,%.o,$(SOURCES))
CXXFLAGS:=-g -Wall
ELF:=main
LD_LIBRARY_PATH:=/home/cheng/20200130/lib*.so/lib

$(ELF):$(OBJECTS)
	$(CXX)  $^  -o $@ 
homework.o:homework.cc
	$(CXX)  $(CXXFLAGS) -c $^ -I include -o $@ 
clean:
	rm -rf $(OBJECTS) $(ELF)
