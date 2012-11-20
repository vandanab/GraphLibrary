#include<list>
#include<vector>
#include "edge.h"
#include "node.h"

#ifndef GRAPH_H
#define GRAPH_H

namespace lib {
	template <class T>
	class Graph {
		typedef typename std::list<Node<T> >::iterator NodeIterType;
		typedef typename std::list<Edge>::iterator EdgeIterType;

		std::list<Node<T> > node_list;
		NodeIterType current_last_node;
		
		//list<Edge<T>> edge_list;
		std::list<Edge> edge_list;
		EdgeIterType current_last_edge;

		//We need to take care of the last element iterator in the node
		//and edge list.
		//Two ways of doing it: maintain current_last_pointer (implemented)
		//or maintain pointer to a the dummy_last_node and call list.insert()
		//list.insert() returns iterator to the newly inserted element and
		//instead of push_back use insert to insert before the dummy_last_element.
		//P.S. insert cannot be called on list.end()

		std::vector<NodeIterType> nodes;
		//vector<list<Edge<T>>::iterator> edges;
		std::vector<EdgeIterType> edges;
	public:
		//define copy, move and default constructors
		Graph();

		~Graph();

		//define destructor

		//returns ordinal(index) of the newly added node
		int add_node(T &n);
		
		//retuns ordinal(index) of the newly added edge
		int add_edge(int node1_ordinal, int node2_ordinal);

		int num_nodes() { return node_list.size(); }
		int num_edges() { return edge_list.size(); }

		void remove_node(int node_ordinal);

		void remove_edge(int edge_ordinal);

		//using variadic templates
		//void add_nodes()
		//void add_edges()

		//confusion should return lib::Node object or the user node type object
		const T &get_node(int index);

		// how to report error if not found?
		// should we return pair?
		int get_node_index(const T& n);

		// should we implement the iterators?
		
		//currently for debugging purposes
		void print();
	};
}
#endif
