CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

LIBRARIES	:=
EXECUTABLE	:= main
OBJECTS := MModel.o MModel 

run: MModel.o
	$(CXX) $(CXX_FLAGS) -o MModel MModel.o
	./MModel
	make clean

MModel:
	$(CXX) $(CXX_FLAGS) -o MModel MModel.o
	
MModel.o: 
	$(CXX) $(CXX_FLAGS) -c MModel.cpp -o MModel.o

clean:
	rm $(OBJECTS)