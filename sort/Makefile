## Data              Author               Content
## 2015-07-25        lichao              Create Version

CXX := g++
CXXFLAGS := -g -Wall -c
BinName := QuickSort
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

%.o : %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

$(BinName) : $(OBJS)
	$(CXX) -o $@ -g -Wall $(OBJS)

clean::
	@rm -rf $(OBJS) $(BinName)

