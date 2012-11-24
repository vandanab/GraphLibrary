/**
 * graph.cpp
 * @author: GraphLib Team(?)
 * Implementation of the graph interface.
 */
#include<initializer_list>
#include<iostream>
#include "edge.h"
#include "node.h"
#include "graph.h"

namespace lib {
	//understand difference between default and the following defined constructor
	//and accordingly make the choice.
	/*
	template<class T>
	Graph<T>::Graph() : edge_list({}), node_list({}), nodes({}), edges({}) {
	}

	//define destructor
	template<class T>
	Graph<T>::~Graph() {}
	*/

	//returns ordinal(index) of the newly added node
	template<class T>
	int Graph<T>::add_node(T &n) {
		int ord = nodes.size();
		Node<T> node(n, ord);
		node_list.push_back(node);
		auto it = --node_list.end();
		nodes.push_back(it);
		return ord;
	}

	//retuns ordinal(index) of the newly added edge
	template<class T>
	int Graph<T>::add_edge(int node1_ordinal, int node2_ordinal) {
		//Edge<T> edge( node1_ordinal, node2_ordinal);
		int ord = edges.size();
		Edge edge(node1_ordinal, node2_ordinal, ord);
		edge_list.push_back(edge);	
		auto it = --edge_list.end();
		edges.push_back(it);
		return ord;
	}

	//add in-edge iterator in the node
	template<class T>
	int Graph<T>::add_node_inEdge(int node_ordinal, int edge_ordinal) {
		(*nodes[node_ordinal]).add_inEdge(edges[edge_ordinal]);
	}

	//add out-edge iterator in the node
	template<class T>
	int Graph<T>::add_node_outEdge(int node_ordinal, int edge_ordinal) {
		(*nodes[node_ordinal]).add_outEdge(edges[edge_ordinal]);
	}

	template<class T>
	void Graph<T>::remove_node(int node_ordinal) {
		//make sure this whole operation is atomic
		//remove the corresponding edges
		delete_node_edges(node_ordinal);
		node_list.erase(nodes[node_ordinal]);
		//mark delete on the vector
		nodes[nodes.begin() + node_ordinal] = nullptr;
	}

	//deletion assumes unidirectional edges
	template<class T>
	void Graph<T>::delete_node_edges(int node_ordinal) {
		NodeIterType node_itr = nodes[node_ordinal];
		auto edges = (*node_itr).get_inEdges();
		for(auto i = edges.begin(); i != edges.end(); i++) {
			edges[(*i).get_ordinal()] = nullptr;
			edge_list.erase(*i);
		}
		auto edges = (*node_itr).get_outEdges();
		for(auto i = edges.begin(); i != edges.end(); i++) {
			edges[(*i).get_ordinal()] = nullptr;
			edge_list.erase(*i);
		}
	}

	//assumes unidirectional edges
	template<class T>
	void Graph<T>::remove_edge(int edge_ordinal) {
		//remove itself from the vector in node object
		edge_list.erase(edges[edge_ordinal]);
		edges[edge_ordinal] = nullptr;
	}

	//remove in and out edges from the source and destination nodes resp.
	template<class T>
	int Graph<T>::remove_nodes_inOutEdges(int edge_ordinal) {
		int node_ordinal1 = (*edges[edge_ordinal]).get_source_node();
		int node_ordinal2 = (*edges[edge_ordinal]).get_destn_node();
		(*nodes[node_ordinal1]).remove_outEdge(edge_ordinal);
		(*nodes[node_ordinal2]).remove_inEdge(edge_ordinal);
	}

	//remove out edges from the source and destination nodes
	template<class T>
	int Graph<T>::remove_nodes_outEdges(int edge_ordinal) {
		int node_ordinal1 = (*edges[edge_ordinal]).get_source_node();
		int node_ordinal2 = (*edges[edge_ordinal]).get_destn_node();
		(*nodes[node_ordinal1]).remove_outEdge(edge_ordinal);
		(*nodes[node_ordinal2]).remove_outEdge(edge_ordinal);
	}

	//using variadic templates
	//void add_nodes()
	//void add_edges()

	template<class T>
	const T& Graph<T>::get_node(int index) {
		return const_cast<T>((*nodes[index]).val);
	}

	template<class T>
	const std::vector<std::pair<std::string, std::string>>& Graph<T>::get_node_attributes(int index) {
		return const_cast<std::vector<std::pair<std::string, std::string>>>((*nodes[index]).get_attributes());
	}

	template<class T>
	const std::pair<int, int>& Graph<T>::get_edge(int index) {
		return const_cast<std::pair<int, int>&>((*edges[index]).get_edge());
	}

	template<class T>
	const std::vector<std::pair<std::string, std::string>>& Graph<T>::get_edge_attributes(int index) {
		return const_cast<std::vector<std::pair<std::string, std::string>>>((*edges[index]).get_attributes());
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
