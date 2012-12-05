/**
 * node.h
 * @author: GraphLib Team
 * Node class representing the nodes of the graph structure.
 */
#include<list>
#include<string>
#include<vector>
#include<iostream>
#include "edge.h"
#include "attribute_service.h"

// ref: http://stackoverflow.com/questions/6807369/undefined-reference-to-constructor-generic-class?rq=1

#ifndef NODE_H
#define NODE_H

namespace lib {
	template<class T>
	class Node {
		int ordinal;
		T val;
		AttributeService attribute_service;
		std::vector<int> in_edges;
		std::vector<int> out_edges;
	public:
		Node() = default;

		//move constructor
		Node(Node<T>&&) = default;
		Node<T>& operator=(Node<T>&&) = default;
		//copy constructor
		Node(const Node<T> &n) = default;
		Node<T>& operator=(Node<T> const&) = default;

		//actual value constructor
		Node(const T &n, int ord) : attribute_service(), in_edges(0), out_edges(0), val(n), ordinal(ord) {}
	
		~Node() = default;
		//void update_edges(list<Edge<T> >::iterator it);
		void add_in_edge(int edge_ordinal) {
			in_edges.push_back(edge_ordinal);
		}
		void add_out_edge(int edge_ordinal) {
			out_edges.push_back(edge_ordinal);
		}

		void update_node(T n) { val = n.val; }

		void delete_in_edge(int edge_ordinal) {
			for(int i = 0; i < in_edges.size(); i++) {
				if(in_edges[i] == edge_ordinal) {
					in_edges.erase(in_edges.begin() + i);
				}
			}
		}

		void delete_out_edge(int edge_ordinal) {
			for(int i = 0; i < out_edges.size(); i++) {
				if(out_edges[i] == edge_ordinal)
					out_edges.erase(out_edges.begin() + i);
			}
		}

		AttributeService& get_attribute_service() {
			return attribute_service;
		}

		std::vector<int> get_in_edges() { return in_edges; }

		std::vector<int> get_out_edges() { return out_edges; }

		T& get_val() { return val; }

		bool operator==(const Node &other) const;

		int get_ordinal() { return ordinal; }

		void print();
	};

	/*
	template<class T>
	//this constructor should not be allowed
	//basically a node without a value is useless
	Node<T>::Node() : attributes(0), in_edges(0), out_edges(0){
	}

	template<class T>
	Node<T>::Node(const Node<T> &n) {
		val = n.val;
		attributes = n.attributes;
		my_edges = n.my_edges;
		ordinal = n.ord;
	}

	template<class T>
	Node<T>::~Node() {}
	*/

	//define == operator based on the user object equal
	template<class T>
	bool Node<T>::operator==(const Node &other) const {
		//do we need to check for equal attributes too?
		return val == other.val && ordinal == other.ordinal;
	}

	template<class T>
	void Node<T>::print() {
		//we have to find a way to print edges now.
		//std::vector<std::list<Edge>::iterator>::iterator it;
		std::cout << val << " -> ";
		/*
		for(it = inEdges.begin(); it != inEdges.end(); it++) {
			(*(*it)).print_nodes();
		}
		for(it = outEdges.begin(); it != outEdges.end(); it++) {
			(*(*it)).print_nodes();
		}*/
		std::cout << std::endl;
	}

}
#endif
