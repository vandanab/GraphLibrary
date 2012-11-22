#include<initializer_list>
#include<iostream>
#include "edge.h"
#include "node.h"
#include "graph.h"

namespace lib {
	template<class T>
	Graph<T>::Graph() : edge_list({}), node_list({}), nodes({}), edges({}) {
	}

	//define destructor
	template<class T>
	Graph<T>::~Graph() {}

	//returns ordinal(index) of the newly added node
	template<class T>
	int Graph<T>::add_node(T &n) {
		Node<T> node(n);
		node_list.push_back(node);
		if(node_list.size() == 1)
			current_last_node = node_list.begin();
		else
			current_last_node++;
		nodes.push_back(current_last_node);
		/*
		auto it = node_list.end()--;
		nodes.push_back(it);*/
		return nodes.size() - 1;
	}

	//retuns ordinal(index) of the newly added edge
	template<class T>
	int Graph<T>::add_edge(int node1_ordinal, int node2_ordinal) {
		//Edge<T> edge( node1_ordinal, node2_ordinal);
		Edge edge(node1_ordinal, node2_ordinal);
		edge_list.push_back(edge);
		if(edge_list.size() == 1)
			current_last_edge = edge_list.begin();
		else
			current_last_edge++;
		edges.push_back(current_last_edge);
		(*nodes[node1_ordinal]).update_edges(current_last_edge);
		(*nodes[node2_ordinal]).update_edges(current_last_edge);
		/*
		auto it = edge_list.end()--;
		edges.push_back(it);
		(*nodes[node1_ordinal]).update_edges(it);
		(*nodes[node2_ordinal]).update_edges(it);
		*/
		return edges.size() - 1;
	}

	template<class T>
	void Graph<T>::remove_node(int node_ordinal) {
		//make sure this whole operation is atomic
		//remove the corresponding edges
		node_list.erase(nodes[node_ordinal]);
		//mark delete on the vector
		nodes[nodes.begin() + node_ordinal] = nullptr;
	}

	template<class T>
	void Graph<T>::remove_edge(int edge_ordinal) {
		edge_list.erase(edges[edge_ordinal]);
		// remove the edge from its correspoinding nodes
		// finding an edge in the node vector is a problem
		edges[edge_ordinal] = nullptr;
	}

	//using variadic templates
	//void add_nodes()
	//void add_edges()

	//confusion should return lib::Node object or the user node type object
	template<class T>
	const T &Graph<T>::get_node(int index) {
		return const_cast<T>((*nodes[index]).val);
	}

	// how to report error if not found?
	// should we return pair?
	template<class T>
	int Graph<T>::get_node_index(const T& n) {
		int i = 0;
		for(; i < nodes.size(); i++) {
			if((*nodes[i]).val == n)
				return i;
		}
		//or throw exception
		return -1;
	}

	// should we implement the iterators?

	//currently for debugging purposes
	template<class T>
	void Graph<T>::print() {
		for(auto n_it = node_list.begin(); n_it != node_list.end(); n_it++) {
			(*n_it).print();
		}
	}
}

/*int main() {
	lib::Graph<std::string> g;
	std::string node1 = "red", node2 = "blue";
	int n1 = g.add_node(node1);
	int n2 = g.add_node(node2);
	g.add_edge(n1, n2);
	g.print();
	return 0;
}*/
