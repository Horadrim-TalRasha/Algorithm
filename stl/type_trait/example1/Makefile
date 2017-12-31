CXX := g++
CXXFLAGS := -g -Wall -c
CPP_SRCS := $(wildcard *.cpp)
CPP_OBJS := $(CPP_SRCS:%.cpp=%.o)
TARGET := Gundam_design

all::$(TARGET)

$(TARGET)::$(CPP_OBJS)
	$(CXX) -g -Wall -o $@ $(CPP_OBJS)

%.o::%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean::
	@rm -f *.o
	@rm -f $(TARGET)

.PHONY: clean all
