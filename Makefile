#Makefile

gxx=g++

edge.o: edge.cpp edge.h
	$(gxx) -std=c++11 -g -c edge.cpp

node.o: node.cpp node.h edge.h
	$(gxx) -std=c++11 -g -c node.cpp

#node: node.o edge.o
#	$(gxx) -std=c++11 -g -o node node.o edge.o

graph.o: graph.cpp graph.h
	$(gxx) -std=c++11 -g -c graph.cpp

graph: graph.o edge.o node.o
	$(gxx) -std=c++11 -g -o graph edge.o node.o graph.o

clean:
	#rm node node.o edge.o graph.o graph 
	rm node.o edge.o graph.o graph 
