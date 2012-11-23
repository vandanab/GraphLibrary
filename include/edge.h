#include<list>
#include<vector>
#include<utility>
#ifndef EDGE_H
#define EDGE_H
//#include "node.h"
//This include is in case we want to pass the graph to any of the
//edge apis. Can be removed if we don't need it.

namespace lib {
	//template <class T>
	class Edge {
		int ordinal;
		int node1_ord;
		int node2_ord;
		std::vector<std::pair<std::string, std::string> > attributes;
		//pair<list<Node<T> >::iterator, list<Node<T> >::iterator> my_nodes;
	public:
		Edge() = default;
		Edge(const Edge &e) = default;

		~Edge() = default;

		Edge(int node1_ordinal, int node2_ordinal, int ord);

		int get_source_node() {
			return node1_ord;
		}

		int get_destn_node() {
			return node2_ord;
		}

		int get_ordinal() {
			return ordinal;
		}

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

		//Will need to figure out a way to define this kind of constructor.
		//Edge(Graph &g, int node1_ordinal, int node2_ordinal);

		//void set_node_pair(const list<Node<T> >::iterator n1, const list<Node<T> >::iterator n2);

		//instead implement >>ostream operator
		void print_node_ordinals();
	};
}
#endif
