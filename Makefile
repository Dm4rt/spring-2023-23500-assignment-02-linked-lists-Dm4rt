OBJECTS=List.o main.o Node.o OList.o
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

List.o: List.cpp Node.h List.h

OList.o: OList.cpp Node.h OList.h

main.o: main.cpp List.h OList.h Node.h

Node.o: Node.cpp Node.h


clean:
	rm -f $(OBJECTS)
