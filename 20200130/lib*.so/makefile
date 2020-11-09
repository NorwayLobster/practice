SOURCES:=$(wildcard *.cc)
OBJECTS:=$(patsubst %.cc,%.o,$(SOURCES))
CXXFLAGS:=-g -Wall -fpic
ELF:=libcheng.so
$(ELF):$(OBJECTS)
	$(CXX) -shared $^ -o ./lib/$@
print.o:print.cc
	$(CXX)  $(CXXFLAGS) -c $^ -o $@
add.o:add.cc
	$(CXX)  $(CXXFLAGS) -c $^ -o $@
clean:
	rm -rf $(OBJECTS) $(ELF)
