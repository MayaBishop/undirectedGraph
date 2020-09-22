# List all the drivers
all: undirectedGraphdriver
 
undirectedGraphdriver: undirectedGraphtest.cpp undirectedGraph.cpp undirectedGraph.h PriorityQueue.cpp PriorityQueue.h Vertex.cpp Vertex.h Edge.cpp Edge.h
	g++ -std=c++11 -o  undirectedGraphdriver undirectedGraphtest.cpp undirectedGraph.cpp PriorityQueue.cpp Vertex.cpp Edge.cpp

# List all the executables under 'all:'
clean:
	rm undirectedGraphdriver
