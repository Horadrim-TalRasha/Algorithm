CXXFLAGS := -g -Wall -c
BinName = QuickSort
OBJS = wildcard *.o

%.o : %.cpp
	g++ -o $@ $(CXXFLAGS) $<

all : $(BinName)
	g++ -g -o $@ $(OBJS)

