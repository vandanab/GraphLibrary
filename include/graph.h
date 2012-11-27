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

		node_iterator nodes_begin() {
			node_iterator it(this->node_list.begin());
			return it;
		}
		node_iterator nodes_end() {
			node_iterator it(this->node_list.end());
			return it;
		}
		edge_iterator edges_begin() {
			edge_iterator it(this->edge_list.begin());
			return it;
		}
		edge_iterator edges_end() {
			edge_iterator it(this->edge_list.end());
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
		if(nodes[node_ordinal] == node_list.end())
			throw InvalidAccessException("Node does not exist");
		std::vector<int> in_edges = (*nodes[node_ordinal]).get_in_edges();
		std::vector<int> out_edges = (*nodes[node_ordinal]).get_out_edges();
		for(int i = 0; i < in_edges.size(); i++) {
			delete_edge(in_edges[i]);
		}	
		for(int i = 0; i != out_edges.size(); i++) {
			delete_edge(out_edges[i]);
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
		for (int i = 0; i < out_edges.size(); i++)
		{
			v.push_back((*(edges[out_edges[i]])).get_destn_node());
		}
		return v;
	}

	template<class T>
	std::vector<int> Graph<T>::successors(int node_ordinal) {
		if(nodes[node_ordinal] == node_list.end())
			throw InvalidAccessException("Node does not exist");
		auto out_edges = (*nodes[node_ordinal]).get_out_edges();
		std::vector<int> v;
		for (int i = 0; i < out_edges.size(); i++)
			v.push_back((*(edges[out_edges[i]])).get_destn_node());
		return v;
	}

	template<class T>
	std::vector<int> Graph<T>::predecessors(int node_ordinal) {
		if(nodes[node_ordinal] == node_list.end())
			throw InvalidAccessException("Node does not exist");
		auto in_edges = (*nodes[node_ordinal]).get_in_edges();
		std::vector<int> v;
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
		if(nodes[src_ordinal] != node_list.end())
			(*nodes[src_ordinal]).delete_out_edge(edge_ordinal);
		int dest_ordinal = (*edges[edge_ordinal]).get_destn_node();
		if(nodes[dest_ordinal] != node_list.end())
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
#endif
