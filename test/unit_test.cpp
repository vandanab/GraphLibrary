/**
 * Unit Test for GraphLib
 * @author GraphLib Team (?)
 * @version 0.1 11/21/2012
*/

#include<iostream>
#include"graph.h"

int main()
{
	//en.wikipedia.org/wiki/Graph_theory
	lib::Graph<int> g1;
	int n1[6];	//node_ordinals
	int e1[7];	//edge_ordinals

	int a = 1, b = 2, c = 3, d = 4, e = 5,  f = 6;
	
	n1[0] = g1.add_node(a);
	n1[1] = g1.add_node(b);
	n1[2] = g1.add_node(c);
	n1[3] = g1.add_node(d);
	n1[4] = g1.add_node(e);
	n1[5] = g1.add_node(f);

	e1[0] = g1.add_edge(n1[0], n1[1]);
	e1[1] = g1.add_edge(n1[0], n1[4]);
	e1[2] = g1.add_edge(n1[1], n1[2]);
	e1[3] = g1.add_edge(n1[1], n1[4]);
	e1[4] = g1.add_edge(n1[2], n1[3]);
	e1[5] = g1.add_edge(n1[3], n1[4]);
	e1[6] = g1.add_edge(n1[3], n1[5]);

	std::cout << "no. of nodes: " << g1.num_nodes() << " no. of edges: " << g1.num_edges() << std::endl;
	g1.print();

	g1.delete_node(n1[4]);
	g1.delete_edge(e1[2]);

	try {
		std::cout << g1.get_node(n1[4]);
	}
	catch(...) {
		std::cout << "expected exception on accessing deleted element" << std::endl;
	}

	std::cout << "no. of nodes: " << g1.num_nodes() << " no. of edges: " << g1.num_edges() << std::endl;
	g1.print();

	return 0;
}
