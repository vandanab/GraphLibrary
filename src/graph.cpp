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
#include "exceptions.h"

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

	Graph<T>::Graph(std::vector<T> v) : node_list(v.size()), edge_list(0), nodes(v.size()), edges(0) {
		for(i = 0; i < v.size(); i++) {
			add_node(v[i]);
		}
	}

	template<typename... Nodes>
	Graph<T>::Graph(Nodes... nodes) : node_list(sizeof...(nodes)), edge_list(0), nodes(sizeof...(nodes)), edges(0) {
		add_nodes(nodes);
	}*/

	//returns ordinal(index) of the newly added node
	template<class T>
	int Graph<T>::add_node(T n) {
		int ord = nodes.size();
		Node<T> node(n, ord);
		node_list.push_back(node);
		auto it = --node_list.end();
		nodes.push_back(it);
		return ord;
	}

	//we can experiment with batch add later
	template<class T>
	std::vector<int>& Graph<T>::add_nodes(std::vector<T> nodes_) {
		std::vector<int> ordinals(nodes_.size());
		for(int i = 0; i < nodes_.size(); i++) {
			ordinals.push_back(add_node(nodes_[i]));
		}
		return ordinals;
	}

	template<class T>
		template<typename... Nodes>
		std::vector<int>& Graph<T>::add_nodes(T n, Nodes... nodes_) {
			std::vector<int> ordinals(sizeof...(nodes_)+1);
			_add_nodes(n, nodes_..., ordinals);
			return ordinals;
		}
	
	template<class T>
	void Graph<T>::delete_node(int node_ordinal) {
		//make sure this whole operation is atomic
		//remove the corresponding edges
		delete_node_edges(node_ordinal);
		node_list.erase(nodes[node_ordinal]);
		//mark delete on the vector
		nodes[node_ordinal] = node_list.end();
	}

	//deletion assumes unidirectional edges
	template<class T>
	void Graph<T>::delete_node_edges(int node_ordinal) {
		NodeIterType node_itr = nodes[node_ordinal];
		if(node_itr == node_list.end())
			throw InvalidAccessException("Node does not exist");
		auto in_edges = (*node_itr).get_in_edges();
		auto out_edges = (*node_itr).get_out_edges();
		for(int i = 0; i < in_edges.size(); i++)
			std::cout<<in_edges[i];
		for(auto i = in_edges.begin(); i != in_edges.end(); i++) {
			edge_list.erase(edges[*i]);
		  edges[*i] = edge_list.end();
		}
		for(auto i = out_edges.begin(); i != out_edges.end(); i++) {
			edge_list.erase(edges[*i]);
		  edges[*i] = edge_list.end();
		}
	}

	template<class T>
	//std::vector<int> Node<T>::neighbors_undirected() {
	std::vector<int> Graph<T>::neighbors(int node_ordinal) {
		if(nodes[node_ordinal] == node_list.end())
			throw InvalidAccessException("Node does not exist");
		auto in_edges = (*nodes[node_ordinal]).get_in_edges();
		auto out_edges = (*nodes[node_ordinal]).get_out_edges();
		auto size = in_edges.size() + out_edges.size();
		std::vector<int> v(size);
		for (int i = 0; i < in_edges.size(); i++)
		{
			v.push_back((*(edges[in_edges[i]])).get_source_node());
		}
		for (int i = in_edges.size(); i < size; i++)
		{
			v.push_back((*(edges[out_edges[i-in_edges.size()]])).get_destn_node());
		}
		return v;
	}

	template<class T>
	std::vector<int> Graph<T>::successors(int node_ordinal) {
		if(nodes[node_ordinal] == node_list.end())
			throw InvalidAccessException("Node does not exist");
		auto out_edges = (*nodes[node_ordinal]).get_out_edges();
		std::vector<int> v(out_edges.size());
		for (int i = 0; i < out_edges.size(); i++)
			v.push_back((*(edges[out_edges[i]])).get_destn_node());
		return v;
	}

	template<class T>
	std::vector<int> Graph<T>::predecessors(int node_ordinal) {
		if(nodes[node_ordinal] == node_list.end())
			throw InvalidAccessException("Node does not exist");
		auto in_edges = (*nodes[node_ordinal]).get_in_edges();
		std::vector<int> v(in_edges.size());
		for (int i = 0; i < in_edges.size(); i++)
			v.push_back((*(edges[in_edges[i]])).get_source_node());
		return v;
	}

	template<class T>
	int Graph<T>::add_edge(int node1_ordinal, int node2_ordinal) {
		//Edge<T> edge( node1_ordinal, node2_ordinal);
		int ord = edges.size();
		Edge edge(node1_ordinal, node2_ordinal, ord);
		edge_list.push_back(edge);
		auto it = --edge_list.end();
		edges.push_back(it);
		(*nodes[node1_ordinal]).add_out_edge(ord);
		(*nodes[node2_ordinal]).add_in_edge(ord);	
		return ord;
	}

	template<class T>
	std::vector<int>& Graph<T>::add_edges(std::vector<std::pair<int, int>> edges_) {
		std::vector<int> ordinals(edges_.size());
		for(int i = 0; i < edges_.size(); i++) {
			ordinals.push_back(add_edge(edges_[i].first, edges_[i].second));
		}
		return ordinals;
	}

	template<class T>
		template<typename... Edges>
		std::vector<int>& Graph<T>::add_edges(std::pair<int, int> e, Edges... edges_) {
			std::vector<int> ordinals(sizeof...(edges_)+1);
			_add_edges(e, edges_..., ordinals);
			return ordinals;
		}

	//assumes unidirectional edges
	template<class T>
	void Graph<T>::delete_edge(int edge_ordinal) {
		if(edges[edge_ordinal] == edge_list.end())
			throw InvalidAccessException("Edge does not exist");
		//remove itself from the vector in node object
		int src_ordinal = (*edges[edge_ordinal]).get_source_node();
		(*nodes[src_ordinal]).delete_out_edge(edge_ordinal);
		int dest_ordinal = (*edges[edge_ordinal]).get_destn_node();
		(*nodes[dest_ordinal]).delete_in_edge(edge_ordinal);

		edge_list.erase(edges[edge_ordinal]);
		edges[edge_ordinal] = edge_list.end();
	}

	template<class T>
	const T& Graph<T>::get_node(int node_ordinal) {
		auto it = nodes[node_ordinal];
		if(it == node_list.end()) {
			throw InvalidAccessException();
		}
		return const_cast<T&>((*nodes[node_ordinal]).get_val());
	}

	template<class T>
	std::vector<const T&> Graph<T>::get_nodes() {
		std::vector<const T&> v(node_list.size());
		for(auto it = nodes_begin(); it != nodes_end(); it++) {
			v.push_back(*it);
		}
		return v;
	}

	template<class T>
	const std::vector<std::pair<std::string, std::string>>& Graph<T>::get_node_attributes(int node_ordinal) {
		if(nodes[node_ordinal] == node_list.end())
			throw InvalidAccessException("Node does not exist");
		return const_cast<std::vector<std::pair<std::string, std::string>>>((*nodes[node_ordinal]).get_attributes());
	}

	template<class T>
	const std::pair<int, int>& Graph<T>::get_edge(int index) {
		return const_cast<std::pair<int, int>&>((*edges[index]).get_edge());
	}

	template<class T>
	const std::vector<std::pair<std::string, std::string>>& Graph<T>::get_edge_attributes(int index) {
		if(edges[index] == edge_list.end())
			throw InvalidAccessException("Edge does not exist");
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
			std::vector<int> v_edges = (*n_it).get_out_edges();
		 	std::cout<<(*n_it).get_ordinal()<<" -> ";
			for(int i = 0; i < v_edges.size(); i++) {
				(*edges[v_edges[i]]).print_nodes();
			}
			std::cout<<std::endl;
		}
	}
}
/*
int main() {
	lib::Graph<std::string> g;
	std::string node1 = "red", node2 = "blue";
	int n1 = g.add_node(node1);
	int n2 = g.add_node(node2);
	g.add_edge(n1, n2);
	g.print();
	return 0;
}*/

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

	return 0;
}
