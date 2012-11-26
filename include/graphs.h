/**
 * graphs.h provides the interface for the basic graph types
 * @author GraphLib Team (?)
 * @version 0.1 11/23/2012
 */

#ifndef _GRAPHS_H
#define _GRAPHS_H

#include"graph.h"
#include<vector>

namespace lib {
	template <class T>
	class UndirectedGraph {
		Graph<T> g;

	public:
		//define copy, move and default constructors
		UndirectedGraph() = default;

		//move constructor
		UndirectedGraph(UndirectedGraph<T>&&) = default;
		UndirectedGraph<T>& operator=(UndirectedGraph<T>&&) = default;
		//copy constructor
		UndirectedGraph(UndirectedGraph<T> const&) = default;
		UndirectedGraph<T>& operator=(UndirectedGraph<T> const&) = default;

		//define destructor
		~UndirectedGraph() = default;

		typedef typename Graph<T>::node_iterator node_iterator;
		typedef typename Graph<T>::edge_iterator edge_iterator;
		node_iterator& nodes_begin() { return g.nodes_begin(); }
		node_iterator& nodes_end() { return g.nodes_end(); }
		edge_iterator& edges_begin() { return g.edges_begin(); }
		edge_iterator& edges_end() { return g.edges_end(); }

		//returns ordinal(index) of the newly added node
		int add_node(T &n) { return g.add_node(n); }
		
		//retuns ordinal(index) of the newly added edge
		int add_edge(int node1_ordinal, int node2_ordinal) { g.add_edge(node1_ordinal, node2_ordinal); }

		int num_nodes() { return g.num_nodes(); }
		int num_edges() { return g.num_edges(); }

		void delete_node(int node_ordinal) { g.delete_node(node_ordinal); }
		void delete_node_edges(int node_ordinal) { g.delete_node_edges(node_ordinal); }

		void delete_edge(int edge_ordinal) { g.delete_edge(edge_ordinal); }

		const T &get_node(int index) { return g.get_node(index); }

		const std::pair<int, int>& get_edge(int index) { return g.get_edge(index); }

		const std::vector<std::pair<std::string, std::string>>& get_node_attributes(int index) {
			return g.get_node_attributes(index);
		}
		
		const std::vector<std::pair<std::string, std::string>>& get_edge_attributes(int index) {
			return g.get_edge_attributes(index);
		}

		int get_node_index(const T& n) { return get_node_index(n); }

		//move constructor should prevent performance issues
		std::vector<int> neighbors(int node_ordinal) { return g.neighbors(node_ordinal); }

		std::vector<int> edges(int node_ordinal) { return g.get_edges_undirected(node_ordinal); }

		int degree(int node_ordinal) { return g.num_edges(node_ordinal); }
	};

	template <class T>
	class DirectedGraph {
		Graph<T> g;

	public:
		//define copy, move and default constructors
		DirectedGraph() = default;

		//move constructor
		DirectedGraph(DirectedGraph<T>&&) = default;
		DirectedGraph<T>& operator=(DirectedGraph<T>&&) = default;
		//copy constructor
		DirectedGraph(DirectedGraph<T> const&) = default;
		DirectedGraph<T>& operator=(DirectedGraph<T> const&) = default;

		//define destructor
		~DirectedGraph() = default;

		typedef typename Graph<T>::node_iterator node_iterator;
		typedef typename Graph<T>::edge_iterator edge_iterator;
		node_iterator& nodes_begin() { return g.nodes_begin(); }
		node_iterator& nodes_end() { return g.nodes_end(); }
		edge_iterator& edges_begin() { return g.edges_begin(); }
		edge_iterator& edges_end() { return g.edges_end(); }

		//returns ordinal(index) of the newly added node
		int add_node(T &n) { return g.add_node(n); }
		
		//retuns ordinal(index) of the newly added edge
		int add_edge(int node1_ordinal, int node2_ordinal) { g.add_edge(node1_ordinal, node2_ordinal); }

		int num_nodes() { return g.num_nodes(); }
		int num_edges() { return g.num_edges(); }

		void remove_node(int node_ordinal) { g.remove_node(node_ordinal); }
		void delete_node_edges(int node_ordinal) { 
			g.delete_node_edges(node_ordinal);
		}

		void remove_edge(int edge_ordinal) { g.remove_edge(edge_ordinal); }

		const T &get_node(int index) { return g.get_node(index); }

		const std::pair<int, int>& get_edge(int index) { return g.get_edge(index); }

		const std::vector<std::pair<std::string, std::string>>& get_node_attributes(int index) {
			return g.get_node_attributes(index);
		}
		
		const std::vector<std::pair<std::string, std::string>>& get_edge_attributes(int index) {
			return g.get_edge_attributes(index);
		}

		int get_node_index(const T& n) { return get_node_index(n); }

		//move constructor should prevent performance issues
		std::vector<int> neighbors(int node_ordinal) { return g.successors(node_ordinal); }
		std::vector<int> successors(int node_ordinal) { return g.successors(node_ordinal); }
		std::vector<int> predecessors(int node_ordinal) { return g.predecessors(node_ordinal); }

		std::vector<int> get_edges(int node_ordinal) { return g.get_edges_directed(node_ordinal); }
		std::vector<int> in_edges(int node_ordinal) { return g.in_edges(node_ordinal); }
		std::vector<int> out_edges(int node_ordinal) { return g.out_edges(node_ordinal); }

		int in_degree(int node_ordinal) { return g.num_in_edges(node_ordinal); }
		int out_degree(int node_ordinal) { return g.num_out_edges(node_ordinal); }
		int degree(int node_ordinal) { return g.num_edges(node_ordinal); }
	};
}
#endif
