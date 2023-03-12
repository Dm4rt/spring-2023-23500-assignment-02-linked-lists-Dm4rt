OBJECTS=List.o main.o Node.o OList.o 
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)
tests: tests.o OList.o List.o Node.o
	g++ -g -o tests OList.o List.o tests.o Node.o

main.o: main.cpp List.h OList.h Node.h

tests.o: tests.cpp List.h OList.h Node.h

List.o: List.cpp Node.h List.h

OList.o: OList.cpp Node.h OList.h

Node.o: Node.cpp Node.h


clean:
	rm -f $(OBJECTS) tests.o
