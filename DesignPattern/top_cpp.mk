##--------------- Revision List ----------------
## 2015-06-11  lichao  create version
## 2015-06-15  lichao  add variable 'TOP_DIR'
## 2015-06-21  lichao  remove commented code & INCLUDEPATH += expand
## 2015-06-22  lichao  add variable 'EDEPS_OBJS' & delete unwanted code
## 2015-06-23  lichao  modify TestSupport objs directory
## 2015-06-23  lichao  modify variable INCLUDEPATH
##-----------------------------------------------------

CXX := g++
CXXFLAGS := -g -Wall -c
CPP_SRC := $(wildcard ./*.cpp)
OBJS := $(CPP_SRC:./%.cpp=./%.o)



all::$(OBJS)

clean::
	@rm -rf *.o
	@rm -rf $(TARGET)

%.o:%.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDEPATH) $<

