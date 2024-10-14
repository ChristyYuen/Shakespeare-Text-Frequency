CXX = g++
CXXFLAGS = -Wall -std=c++11 

OBJECTS = linkedlist.o shake.o

shakespeare: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o shake linkedlist.o shake.o

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CXX) -g $(CXXFLAGS) -c linkedlist.cpp
	
shakespeare.o: linkedlist.cpp linkedlist.h shake.cpp
	$(CXX) -g $(CXXFLAGS) -c shake.cpp

clean: 
	rm -f *.o
	rm shake
