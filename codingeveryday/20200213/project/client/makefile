SOURCES=$(wildcard *.cc)
OBJECTS=$(patsubst %.cc,%.o,$(SOURCES))
LD_LIBRARY_PATH:=/home/cheng/20200213/project/lib
#CXXFLAGS:=-g -Wall -std=c++11 -lcrypt -lpthread  -I ../include
CXXFLAGS:=-g -Wall -fpic -std=c++11 -lcrypt -lpthread -I ../include -I /usr/include/mysql/ -lmysqlclient 
ELF:=client
$(ELF):$(OBJECTS)
#	$(CXX)  $^ -o $@ $(CXXFLAGS) -L $(LD_LIBRARY_PATH)
	$(CXX)  $^ -L $(LD_LIBRARY_PATH) -lcheng -Wl,-rpath=$(LD_LIBRARY_PATH) -o $@  $(CXXFLAGS) 
#$(OBJECTS):$(SOURCES)
#	$(CXX)  $(CXXFLAGS) -c $^  -o $@ 
clean:
	rm -rf $(OBJECTS) $(ELF)
