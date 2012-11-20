#include<list>

#ifndef EDGE_H
#define EDGE_H
//#include "node.h"
//This include is in case we want to pass the graph to any of the
//edge apis. Can be removed if we don't need it.

namespace lib {
	//template <class T>
	class Edge {
		int node1_ord;
		int node2_ord;
		//pair<list<Node<T> >::iterator, list<Node<T> >::iterator> my_nodes;
	public:
		Edge();
		Edge(const Edge &e);

		~Edge();

		Edge(int node1_ordinal, int node2_ordinal);

		//Will need to figure out a way to define this kind of constructor.
		//Edge(Graph &g, int node1_ordinal, int node2_ordinal);

		//void set_node_pair(const list<Node<T> >::iterator n1, const list<Node<T> >::iterator n2);

		void print_node_ordinals();
	};
}
#endif
