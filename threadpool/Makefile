CXX = g++
CXXFLAGS = -Wall -g -c
BinName = Pool
SRC = $(wildcard ./*.cc)
OBJS = $(SRC:%.cc=%.o)

%.o : %.cc
	$(CXX) $(CXXFLAGS) $< -o $@

all : $(BinName)

$(BinName):$(OBJS)
	$(CXX) -o $@ $(OBJS) -lpthread

clean:
	@rm -rf *.o $(BinName)


