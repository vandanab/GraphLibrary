/**
 * Unit Test for GraphLib
 * @author GraphLib Team (?)
 * @version 0.1 11/21/2012
*/

#include<iostream>
#include "graphs.h"
#include "topologicalsort.h"
#include "depthfirsttraversal.h"
#include "breadthfirsttraversal.h"

void test_topological_sort() {
	std::cout<<"Testing topological sort\n";
	lib::DirectedGraph<int> g1;
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

		std::vector<int> v = lib::topological_sort(g1);
		for (int i = 0; i < v.size(); i++) {
		    std::cout << v[i] << std::endl;
		}
}

void test_dft_digraph() {
	std::cout << "testing dft on directed graph\n";
	lib::DirectedGraph<int> g1;
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

			std::vector<int> v11 = lib::depthfirsttraversal(g1);
				for (int i = 0; i < v11.size(); i++) {
				    std::cout << v11[i] << std::endl;
				}
}

void test_dft_undigraph() {
	std::cout <<"Tetsing undirected graph dft\n";
	lib::UndirectedGraph<int> g1;
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

			std::vector<int> v11 = lib::depthfirsttraversal(g1);
				for (int i = 0; i < v11.size(); i++) {
				    std::cout << v11[i] << std::endl;
				}
}

void test_bft_digraph() {
	std::cout << "testing bft on directed graph\n";
	lib::DirectedGraph<int> g1;
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

			std::vector<int> v11 = lib::breadthfirsttraversal(g1);
				for (int i = 0; i < v11.size(); i++) {
				    std::cout << v11[i] << std::endl;
				}
}

void test_bft_undigraph() {
	std::cout <<"Tetsing undirected graph bft\n";
	lib::UndirectedGraph<int> g1;
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

			std::vector<int> v11 = lib::breadthfirsttraversal(g1);
				for (int i = 0; i < v11.size(); i++) {
				    std::cout << v11[i] << std::endl;
				}
}

void test_attributes() {
	lib::Graph<int> g1;
	int n1[6];	//node_ordinals
	int e1[7];	//edge_ordinals

	n1[0] = g1.add_node(1);
	n1[1] = g1.add_node(2);
	n1[2] = g1.add_node(3);
	n1[3] = g1.add_node(4);

	e1[0] = g1.add_edge(n1[0], n1[1]);
	e1[2] = g1.add_edge(n1[1], n1[2]);
	e1[4] = g1.add_edge(n1[2], n1[3]);
	e1[6] = g1.add_edge(n1[3], n1[1]);

	g1.add_node_attribute(n1[0], "id", 125);
	g1.add_edge_attribute(e1[0], "cost", 2);
	g1.add_node_attribute(n1[0], "color", "red");
	g1.add_edge_attribute(e1[0], "color", "blue");

	std::cout<<"node "<<n1[0]<<" color: "<<g1.get_node_string_attribute(n1[0], "color")<<std::endl;
	std::cout<<"edge "<<e1[0]<<" color: "<<g1.get_edge_string_attribute(e1[0], "color")<<std::endl;
	std::cout<<"node "<<n1[0]<<" id: "<<g1.get_node_attribute(n1[0], "id")<<std::endl;
	std::cout<<"edge "<<e1[0]<<" cost: "<<g1.get_edge_attribute(e1[0], "cost")<<std::endl;

	g1.print();

}

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

	test_attributes();
	test_topological_sort();
	test_dft_digraph();
	test_dft_undigraph();
	test_bft_digraph();
	test_bft_undigraph();

	return 0;
}
