Client.exe: Client.o LinkedList.o Graph.o
		g++ Client.o Graph.o LinkedList.o -o Client.exe

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

Client.o:Client.cpp
	g++ -c Client.cpp


run: Client.exe
	./Client.exe; make clean

clean:
		${RM} *.o Client.exe
