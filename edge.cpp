#include<iostream>
#include "edge.h"

namespace lib {
	Edge::Edge() {}

	Edge::Edge(const Edge &e) {
		node1_ord = e.node1_ord;
		node2_ord = e.node2_ord;
	}

	Edge::Edge(int node1_ordinal, int node2_ordinal) {
		node1_ord = node1_ordinal;
		node2_ord = node2_ordinal;
	}

	Edge::~Edge() {}

/*
	Edge::Edge(Graph &g, int node1_ordinal, int node2_ordinal) {
		if(node1_ordinal > 0 && node1_ordinal < g.nodes.size() && node2_ordinal > 0 && node2_ordinal < g.nodes.size()) {
			this.node1_ord = node1_ordinal;
			this.node2_ord = node2_ordinal;
			this.set_node_pair(const_cast<list<Node<T>>::iterator>(g.nodes[node1_ordinal]), const_cast<list<Node<T>>::iterator>(g.nodes[node2_ordinal]));
		} else {
			//create nodes in the graph or throw exception
		}
	}

	void Edge::set_node_pair(const list<Node<T>>::iterator n1, const list<Node<T>>::iterator n2) {
		this.my_nodes(n1, n2);
	}
*/

	void Edge::print_node_ordinals() {
		std::cout << "(" << node1_ord << ", " << node2_ord << ")";
	}
}
