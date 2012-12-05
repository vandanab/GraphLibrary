/**
 * graphs.h provides the interface for the basic graph types
 * @author GraphLib Team
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
		node_iterator nodes_begin() { return g.nodes_begin(); }
		node_iterator nodes_end() { return g.nodes_end(); }
		edge_iterator edges_begin() { return g.edges_begin(); }
		edge_iterator edges_end() { return g.edges_end(); }

		//returns ordinal(index) of the newly added node
		int add_node(T &n) { return g.add_node(n); }
		std::vector<int> add_nodes(std::vector<T> nodes_) { return g.add_nodes(nodes_); }
		template<typename... Nodes>	std::vector<int> add_nodes(T n, Nodes... nodes_) {
			return g.add_nodes(n, nodes_...);
		}
		
		//retuns ordinal(index) of the newly added edge
		int add_edge(int node1_ordinal, int node2_ordinal) { return g.add_edge(node1_ordinal, node2_ordinal); }
		std::vector<int> add_edges(std::vector<std::pair<int, int> > edges_) { return g.add_edges(edges_); }
		template<typename... Edges>	std::vector<int> add_edges(std::pair<int, int> e, Edges... edges_) {
			return g.add_edges(e, edges_...);
		}

		int num_nodes() { return g.num_nodes(); }
		int num_edges() { return g.num_edges(); }

		void delete_node(int node_ordinal) { g.delete_node(node_ordinal); }
		void delete_node_edges(int node_ordinal) { g.delete_node_edges(node_ordinal); }
		void delete_nodes(std::vector<int> ns) { g.delete_nodes(ns); }

		void delete_edge(int edge_ordinal) { g.delete_edge(edge_ordinal); }
		void delete_edges(std::vector<int> edges) { delete_edges(edges); }

		const T &get_node(int index) { return g.get_node(index); }
		std::vector<const T&> get_nodes() { return g.get_nodes(); }

		const std::pair<int, int>& get_edge(int index) { return g.get_edge(index); }

		void add_node_attribute(int node_ordinal, std::string key, double value) {
			g.add_node_attribute(node_ordinal, key, value);
		}
		void add_node_attribute(int node_ordinal, std::string key, std::string value) {
			g.add_node_attribute(node_ordinal, key, value);
		}
		double get_node_attribute(int node_ordinal, std::string key) {
			return g.get_node_attribute(node_ordinal, key);
		}
		std::string get_node_string_attribute(int node_ordinal, std::string key) {
			return g.get_node_string_attribute(node_ordinal, key);
		}
		std::vector<std::pair<std::string, double> > get_node_attributes(int node_ordinal) {
			return g.get_node_attributes(node_ordinal);
		}
		std::vector<std::pair<std::string, std::string> > get_node_string_attributes(int node_ordinal) {
			return g.get_node_string_attributes(node_ordinal);
		}

		void add_edge_attribute(int edge_ordinal, std::string key, double value) {
			g.add_edge_attribute(edge_ordinal, key, value);
		}
		void add_edge_attribute(int edge_ordinal, std::string key, std::string value) {
			g.add_edge_attribute(edge_ordinal, key, value);
		}
		double get_edge_attribute(int edge_ordinal, std::string key) {
			return g.get_edge_attribute(edge_ordinal, key);
		}
		std::string get_edge_string_attribute(int edge_ordinal, std::string key) {
			return g.get_edge_string_attribute(edge_ordinal, key);
		}
		std::vector<std::pair<std::string, double> > get_edge_attributes(int edge_ordinal) {
			return g.get_edge_attributes(edge_ordinal);
		}
		std::vector<std::pair<std::string, std::string> > get_edge_string_attributes(int edge_ordinal) {
			return g.get_edge_string_attributes(edge_ordinal);
		}

		void update_node(int node_ordinal, T n) { g.update_node(node_ordinal, n); }
		
		int get_node_index(const T& n) { return get_node_index(n); }

		//move constructor should prevent performance issues
		std::vector<int> neighbors(int node_ordinal) { return g.neighbors(node_ordinal); }
		std::vector<std::pair<int, int> > neighbors_with_edges(int node_ordinal) {
			return g.neighbors_with_edges(node_ordinal);
		}

		std::vector<int> get_edges(int node_ordinal) { return g.get_edges_undirected(node_ordinal); }

		int degree(int node_ordinal) { return g.num_edges(node_ordinal); }

		void print() { g.print(); }
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
		node_iterator nodes_begin() { return g.nodes_begin(); }
		node_iterator nodes_end() { return g.nodes_end(); }
		edge_iterator edges_begin() { return g.edges_begin(); }
		edge_iterator edges_end() { return g.edges_end(); }

		//returns ordinal(index) of the newly added node
		int add_node(T &n) { return g.add_node(n); }
		std::vector<int> add_nodes(std::vector<T> nodes_) { return g.add_nodes(nodes_); }
		template<typename... Nodes>	std::vector<int> add_nodes(T n, Nodes... nodes_) {
			return g.add_nodes(n, nodes_...);
		}
		
		//retuns ordinal(index) of the newly added edge
		int add_edge(int node1_ordinal, int node2_ordinal) { g.add_edge(node1_ordinal, node2_ordinal); }
		std::vector<int> add_edges(std::vector<std::pair<int, int> > edges_) { return g.add_edges(edges_); }
		template<typename... Edges>	std::vector<int> add_edges(std::pair<int, int> e, Edges... edges_) {
			return g.add_edges(e, edges_...);
		}

		int num_nodes() { return g.num_nodes(); }
		int num_edges() { return g.num_edges(); }

		void delete_node(int node_ordinal) { g.delete_node(node_ordinal); }
		void delete_nodes(std::vector<int> ns) { g.delete_nodes(ns); }
		void delete_node_edges(int node_ordinal) { 
			g.delete_node_edges(node_ordinal);
		}

		void delete_edge(int edge_ordinal) { g.delete_edge(edge_ordinal); }
		void delete_edges(std::vector<int> edges) { delete_edges(edges); }

		const T &get_node(int index) { return g.get_node(index); }
		std::vector<const T&> get_nodes() { return g.get_nodes(); }

		const std::pair<int, int>& get_edge(int index) { return g.get_edge(index); }

		void add_node_attribute(int node_ordinal, std::string key, double value) {
			g.add_node_attribute(node_ordinal, key, value);
		}
		void add_node_attribute(int node_ordinal, std::string key, std::string value) {
			g.add_node_attribute(node_ordinal, key, value);
		}
		double get_node_attribute(int node_ordinal, std::string key) {
			return g.get_node_attribute(node_ordinal, key);
		}
		std::string get_node_string_attribute(int node_ordinal, std::string key) {
			return g.get_node_string_attribute(node_ordinal, key);
		}
		std::vector<std::pair<std::string, double> > get_node_attributes(int node_ordinal) {
			return g.get_node_attributes(node_ordinal);
		}
		std::vector<std::pair<std::string, std::string> > get_node_string_attributes(int node_ordinal) {
			return g.get_node_string_attributes(node_ordinal);
		}

		void add_edge_attribute(int edge_ordinal, std::string key, double value) {
			g.add_edge_attribute(edge_ordinal, key, value);
		}
		void add_edge_attribute(int edge_ordinal, std::string key, std::string value) {
			g.add_edge_attribute(edge_ordinal, key, value);
		}
		double get_edge_attribute(int edge_ordinal, std::string key) {
			return g.get_edge_attribute(edge_ordinal, key);
		}
		std::string get_edge_string_attribute(int edge_ordinal, std::string key) {
			return g.get_edge_string_attribute(edge_ordinal, key);
		}
		std::vector<std::pair<std::string, double> > get_edge_attributes(int edge_ordinal) {
			return g.get_edge_attributes(edge_ordinal);
		}
		std::vector<std::pair<std::string, std::string> > get_edge_string_attributes(int edge_ordinal) {
			return g.get_edge_string_attributes(edge_ordinal);
		}

		void update_node(int node_ordinal, T n) { g.update_node(node_ordinal, n); }

		int get_node_index(const T& n) { return get_node_index(n); }

		//move constructor should prevent performance issues
		std::vector<int> neighbors(int node_ordinal) { return g.successors(node_ordinal); }
		std::vector<std::pair<int, int> > neighbors_with_edges(int node_ordinal) {
			return g.successors_with_edges(node_ordinal);
		}
		std::vector<int> successors(int node_ordinal) { return g.successors(node_ordinal); }
		std::vector<std::pair<int, int> > successors_with_edges(int node_ordinal) {
			return g.successors_with_edges(node_ordinal);
		}
		std::vector<int> predecessors(int node_ordinal) { return g.predecessors(node_ordinal); }

		std::vector<int> get_edges(int node_ordinal) { return g.get_edges_directed(node_ordinal); }
		std::vector<int> in_edges(int node_ordinal) { return g.in_edges(node_ordinal); }
		std::vector<int> out_edges(int node_ordinal) { return g.out_edges(node_ordinal); }

		int in_degree(int node_ordinal) { return g.num_in_edges(node_ordinal); }
		int out_degree(int node_ordinal) { return g.num_out_edges(node_ordinal); }
		int degree(int node_ordinal) { return g.num_edges(node_ordinal); }
		void print() { g.print(); }
	};
}
#endif
