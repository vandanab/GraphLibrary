/**
 * graph.h
 * @author: GraphLib Team (?)
 * Graph class which provides the interface for the basic structures
 * of a graph.
 */
#include<iterator>
#include<list>
#include<vector>
#include "edge.h"
#include "exceptions.h"
#include "node.h"

#ifndef GRAPH_H
#define GRAPH_H

namespace lib {
	template<class T>
	class Graph {
		typedef typename std::list<Node<T> >::iterator NodeIterType;
		typedef typename std::list<Edge>::iterator EdgeIterType;

		std::list<Node<T> > node_list;
		std::list<Edge> edge_list;
		
		std::vector<NodeIterType> nodes;
		std::vector<EdgeIterType> edges;

		NodeIterType& get_node_iter(int ordinal) {
			return nodes[ordinal];
		}

		template<typename... Nodes>
		void _add_nodes(T n, Nodes... nodes, std::vector<int>& ords) {
			ords.push_back(add_node(n));
			_add_nodes(nodes..., ords);
		}

		void _add_nodes() {}

		template<typename... Edges>
		void _add_edges(std::pair<int, int> e, Edges... edges, std::vector<int>& ords) {
			ords.push_back(add_edge(e.first, e.second));
			_add_nodes(edges..., ords);
		}

		void _add_edges() {}

		void _delete_edge(int edge_ordinal, bool in=false, bool out=false) {
			if(edges[edge_ordinal] == edge_list.end())
				throw InvalidAccessException("Edge does not exist");
			//remove itself from the vector in node object
			if(in) {
				int src_ordinal = (*edges[edge_ordinal]).get_source_node();
				(*nodes[src_ordinal]).delete_out_edge(edge_ordinal);
			}
			if(out) {
				int dest_ordinal = (*edges[edge_ordinal]).get_destn_node();
				(*nodes[dest_ordinal]).delete_in_edge(edge_ordinal);
			}
			edge_list.erase(edges[edge_ordinal]);
			edges[edge_ordinal] = edge_list.end();
		}

	public:
		//define copy, move and default constructors
		Graph() {}

		//move constructor
		Graph(Graph<T>&& g) = default;
		Graph<T>& operator=(Graph<T>&& g) = default;
		//copy constructor
		Graph(const Graph<T>& g) = default;
		Graph<T>& operator=(const Graph<T>& g) = default;

		//constructor taking vector of nodes or variadic template node objects
		Graph(std::vector<T> v);

		template<typename... Nodes>
		Graph(Nodes... nodes);

		//define destructor
		~Graph() = default;

		//graph operators
		//complement of a graph
		Graph<T>& operator!() {
			Graph<T> g();
			return g;
		}
		bool operator==(const Graph&) const {return true;}
		bool operator!=(const Graph&) const {return true;}

		//iterator classes
		class node_iterator : public std::iterator<std::bidirectional_iterator_tag, int> {
			
			//iterator over node ordinals
			NodeIterType current;
		public:
			//how to define the default constructor?
			node_iterator() {}
			node_iterator(NodeIterType x) : current(x) {}
			node_iterator(const node_iterator& it) : current(it.current) {}
			//throw exception when trying to increment beyond bounds?
			node_iterator& operator++() {++current; return *this;}
			node_iterator operator++(int) {node_iterator tmp(*this); operator++(); return tmp;}
			//throw exception when trying to decrement less than the lower bound
			node_iterator& operator--() {--current; return *this;}
			node_iterator operator--(int) {node_iterator tmp(*this); operator--(); return tmp;}

			bool operator==(const node_iterator& rhs) {return current==rhs.current;}
			bool operator!=(const node_iterator& rhs) {return current!=rhs.current;}
			int operator*() {return (*current).get_ordinal();}
		};

		//should we provide const_node_iterator?

		class edge_iterator : public std::iterator<std::bidirectional_iterator_tag, int> {
			
			//iterator over edge ordinals.
			EdgeIterType current;
		public:
			//how to define the default constructor?
			edge_iterator() {}
			edge_iterator(EdgeIterType x) : current(x) {}
			edge_iterator(const edge_iterator& it) : current(it.current) {}
			//throw exception when trying to increment beyond bounds?
			edge_iterator& operator++() {++current; return *this;}
			edge_iterator operator++(int) {edge_iterator tmp(*this); operator++(); return tmp;}
			//throw exception when trying to decrement less than the lower bound
			edge_iterator& operator--() {--current; return *this;}
			edge_iterator operator--(int) {edge_iterator tmp(*this); operator--(); return tmp;}

			bool operator==(const edge_iterator& rhs) {return current==rhs.current;}
			bool operator!=(const edge_iterator& rhs) {return current!=rhs.current;}
			int operator*() {return (*current).get_ordinal();}
		};

		//should we provide const_edge_iterator?

		node_iterator& nodes_begin() {
			node_iterator it(this.node_list.begin());
			return it;
		}
		node_iterator& nodes_end() {
			node_iterator it(this.node_list.end());
			return it;
		}
		edge_iterator& edges_begin() {
			edge_iterator it(this.edge_list.begin());
			return it;
		}
		edge_iterator& edges_end() {
			edge_iterator it(this.edge_list.end());
			return it;
		}

		//path iterator
		class path_iterator : public std::iterator<std::bidirectional_iterator_tag, int> {
			
			//iterator over edge ordinals
			std::vector<EdgeIterType> path_edges;
			std::vector<EdgeIterType>::iterator current;
		public:
			//no default constructor.
			path_iterator() = delete;
			path_iterator(std::vector<EdgeIterType> es) : path_edges(es) { 
				current = path_edges.begin();
			}
			path_iterator(const path_iterator& it) : path_edges(it.path_edges) {
				current = path_edges.begin();
			}

			path_iterator& operator++() {
				++current;
				return *this;
			}

			path_iterator operator++(int) {
				path_iterator tmp(*this);
				operator++();
				return tmp;
			}
			
			//throw exception when trying to decrement less than the lower bound
			path_iterator& operator--() {
				--current;
				return *this;
			}
			path_iterator operator--(int) {path_iterator tmp(*this); operator--(); return tmp;}

			bool operator==(const path_iterator& rhs) {
				return current==rhs.current && path_edges==rhs.path_edges;
			}
			bool operator!=(const path_iterator& rhs) {
				return current!=rhs.current || path_edges!=rhs.path_edges;
			}
			int operator*() {return (*(*current)).get_ordinal();}
		};

		
		//structural
		
		//returns ordinal(index) of the newly added node
		int add_node(T n);
		
		//retuns ordinal(index) of the newly added edge
		int add_edge(int node1_ordinal, int node2_ordinal);
		
		int num_nodes() { return node_list.size(); }
		int num_edges() { return edge_list.size(); }
		
		//for graph types
		int num_in_edges(int node_ordinal) { return (*nodes[node_ordinal]).get_in_edges().size(); }
		int num_out_edges(int node_ordinal) { return (*nodes[node_ordinal]).get_out_edges().size(); }
		int num_edges(int node_ordinal) { 
			return (num_in_edges(node_ordinal) + num_out_edges(node_ordinal));
		}

		void delete_node(int node_ordinal);
		void delete_node_edges(int node_ordinal);

		void delete_edge(int edge_ordinal);

		//using vector
		std::vector<int>& add_nodes(std::vector<T> nodes);
		
		std::vector<int>& add_edges(std::vector<std::pair<int, int>> edges);
		
		void delete_nodes(std::vector<int> ns) {
			for(auto i = ns.begin(); i < ns.end(); i++) {
				delete_node(*i);
			}
		}

		void delete_edges(std::vector<int> edges) {
			for(auto i = edges.begin(); i < edges.end(); i++) {
				delete_edge(*i);
			}
		}

		//using variadic templates
		template<typename... Nodes>
		std::vector<int>& add_nodes(T n, Nodes... nodes);

		template<typename... Edges>
		std::vector<int>& add_edges(std::pair<int, int> e, Edges... edges);

		void update_node_edges(int node_ordinal, EdgeIterType it) {
			(*nodes[node_ordinal]).update_edges(it);
		}

		const T& get_node(int node_ordinal);

		std::vector<const T&> get_nodes();
		
		std::vector<int> neighbors(int node_ordinal);
		std::vector<int> successors(int node_ordinal);
		std::vector<int> predecessors(int node_ordinal);

		const std::pair<int, int>& get_edge(int edge_ordinal);

		//for graph types
		/*
		std::vector<int> neighbors_undirected(int node_ordinal) {
			return (*nodes[node_ordinal]).neighbors_undirected(); 
		}
		std::vector<int> neighbors_directed(int node_ordinal) {
			return (*nodes[node_ordinal]).neighbors_directed(); 
		}
		std::vector<int> successors(int node_ordinal) { return (*nodes[node_ordinal]).successors(); }
		std::vector<int> predecessors(int node_ordinal) {  return (*nodes[node_ordinal]).predecessors(); }*/

		std::vector<int> get_edges_undirected(int node_ordinal) { 
			std::vector<int> edges_ = (*nodes[node_ordinal]).get_in_edges();
			std::vector<int> edgeso_ = (*nodes[node_ordinal]).get_out_edges();
			edges_.insert(edges_.end(), edgeso_.begin(), edgeso_.end());
			return edges_;
		}
		std::vector<int> get_edges_directed(int node_ordinal) { 
			return (*nodes[node_ordinal]).get_out_edges();
		}
		std::vector<int> in_edges(int node_ordinal) { return (*nodes[node_ordinal]).in_edges(); }
		std::vector<int> out_edges(int node_ordinal) { return (*nodes[node_ordinal]).out_edges(); }

		const std::vector<std::pair<std::string, std::string>>& get_node_attributes(int index);
		
		const std::vector<std::pair<std::string, std::string>>& get_edge_attributes(int index);

		void update_node(int node_ordinal, T n) {
			(*nodes[node_ordinal]).update_node(n);
		}

		// how to report error if not found?
		// should we return pair?
		int get_node_index(const T& n);
		
		//currently for debugging purposes
		//implement >>ostream operator instead
		void print();
	};
}
#endif
