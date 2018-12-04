Client.exe: Client.o LinkedList.o Graph.o
		g++ Client.o Graph.o LinkedList.o -o Client.exe

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

Graph.o: Graph.cpp Graph.h LinkedList.o
	g++ -c Graph.cpp LinkedList.o

Client.o:Client.cpp
	g++ -c Client.cpp

clean:
		${RM} *.o Client.exe
