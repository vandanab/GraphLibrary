/**
 * edge.h
 * @author: GraphLib Team
 * Edge class representing the edges in the graph structure.
 */

#include<list>
#include<vector>
#include<utility>
#include "attribute_service.h"
#ifndef EDGE_H
#define EDGE_H

namespace lib {
	class Edge {
		int ordinal;
		int node1_ord;
		int node2_ord;
		AttributeService attribute_service;
	public:
		Edge() = default;
		Edge(const Edge &e) = default;

		~Edge() = default;

		Edge(int node1_ordinal, int node2_ordinal, int ord);

		int get_source_node() { return node1_ord; }

		int get_destn_node() { return node2_ord; }

		int get_ordinal() { return ordinal; }

		AttributeService& get_attribute_service() {
			return attribute_service;
		}

		std::pair<int, int>& get_edge() {
			//TODO:get rid of this naked new
			std::pair<int, int> *e = new std::pair<int, int>(node1_ord, node2_ord);
			return *e;
		}

		//instead implement >>ostream operator
		void print_nodes();
	};
}
#endif
