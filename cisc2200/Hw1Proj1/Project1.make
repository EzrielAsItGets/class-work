all: Project1 clean

Project1: proj1.o VectorBag.o
	c++ -o Project1 proj1.o VectorBag.o
	
VectorBag.o: VectorBag.cpp VectorBag.h BagInterface.h
	c++ -c VectorBag.cpp

proj1.o: proj1.cpp VectorBag.h
	c++ -c proj1.cpp

clean:
	rm -f *.o
