/**
 * edge.cpp
 * @author: GraphLib Team
 * Edge implementation. Possible because edge is not templatized.
 */
#include<iostream>
#include "edge.h"

namespace lib {
	/*
	Edge::Edge() {}

	Edge::Edge(const Edge &e) {
		node1_ord = e.node1_ord;
		node2_ord = e.node2_ord;
	}
	
	Edge::~Edge() {}
	*/

	Edge::Edge(int node1_ordinal, int node2_ordinal, int ord) : attribute_service() {
		ordinal = ord;
		node1_ord = node1_ordinal;
		node2_ord = node2_ordinal;
	}

	void Edge::print_nodes() {
		std::cout << "(" << node1_ord << ", " << node2_ord << ")";
	}
}
