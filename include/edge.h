/**
 * edge.h
 * @author: GraphLib Team (?)
 * Edge class representing the edges in the graph structure.
 */
#include<list>
#include<vector>
#include<utility>
#ifndef EDGE_H
#define EDGE_H

//IMPORTANT: Should Edge be a templatized class? As of now we don't let the user
//create an object of edge type or represent edges other than in form of node ordinals?

namespace lib {
	class Edge {
		int ordinal;
		int node1_ord;
		int node2_ord;
		std::vector<std::pair<std::string, std::string> > attributes;
	public:
		Edge() = default;
		Edge(const Edge &e) = default;

		~Edge() = default;

		Edge(int node1_ordinal, int node2_ordinal, int ord);

		int get_source_node() { return node1_ord; }

		int get_destn_node() { return node2_ord; }

		int get_ordinal() { return ordinal; }

		//update attributes
		// returns the index of the newly added attribute
		int add_attribute(std::pair<std::string, std::string> attribute);

		std::pair<std::string, std::string> get_attribute(int index);

		std::pair<std::string, std::string> get_attribute(std::string key);

		std::string get_attribute_value(std::string key);

		std::vector<std::pair<std::string, std::string>>& get_attributes();

		std::pair<int, int>& get_edge() {
			//get rid of this naked new
			std::pair<int, int> *e = new std::pair<int, int>(node1_ord, node2_ord);
			return *e;
		}

		//instead implement >>ostream operator
		void print_node_ordinals();
	};
}
#endif
