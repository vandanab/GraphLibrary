#include<iterator>
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
		//list<Edge<T>> edge_list;
		std::list<Edge> edge_list;
		
		std::vector<NodeIterType> nodes;
		//vector<list<Edge<T>>::iterator> edges;
		std::vector<EdgeIterType> edges;

		NodeIterType& get_node_iter(int ordinal) {
			return nodes[ordinal];
		}
		
		friend class path_iterator;

	public:
		//define copy, move and default constructors
		Graph() = default;

		//move constructor
		Graph(Graph<T>&&) = default;
		Graph<T>& operator=(Graph<T>&&) = default;
		//copy constructor
		Graph(Graph<T> const&) = default;
		Graph<T>& operator=(Graph<T> const&) = default;

		//define destructor
		~Graph() = default;

		//iterator classes
		
		class node_iterator : public std::iterator<std::bidirectional_iterator_tag, int> {
			
			//iterator over node ordinals
			//can we extend the list iterator itself. We will just override the derefrencing operator?

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
			//can we extend the list iterator itself. We will just override the derefrencing operator?

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

		//operators
		bool operator==(const Graph&) const;
		bool operator!=(const Graph&) const;

		node_iterator& node_begin() {
			node_iterator it(this.node_list.begin());
			return it;
		}
		node_iterator& node_end() {
			node_iterator it(this.node_list.end());
			return it;
		}
		edge_iterator& edge_begin() {
			edge_iterator it(this.edge_list.begin());
			return it;
		}
		edge_iterator& edge_end() {
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

		const T &get_node(int index);

		const std::pair<int, int>& get_edge(int index);

		const std::vector<std::pair<std::string, std::string>>& get_node_attributes(int index);
		
		const std::vector<std::pair<std::string, std::string>>& get_edge_attributes(int index);

		// how to report error if not found?
		// should we return pair?
		int get_node_index(const T& n);
		
		//currently for debugging purposes
		//implement >>ostream operator instead
		void print();
	};
}
#endif
