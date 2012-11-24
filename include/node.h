/**
 * node.h
 * @author: GraphLib Team (?)
 * Node class representing the nodes of the graph structure.
 */
#include<list>
#include<string>
#include<utility>
#include<vector>
#include<iostream>
#include "edge.h"

// ref: http://stackoverflow.com/questions/6807369/undefined-reference-to-constructor-generic-class?rq=1

#ifndef NODE_H
#define NODE_H

namespace lib {
	template<class T>
	class Node {
		int ordinal;
		T val;
		// for now the attributes are assumed to be string key-value pairs
		std::vector<std::pair<std::string, std::string> > attributes;
		//vector<list<Edge<T> >::iterator> my_edges;
		std::vector<std::list<Edge>::iterator> my_edges;

	public:
		Node() = default;

		//move constructor
		Node(Node<T>&&) = default;
		Node<T>& operator=(Node<T>&&) = default;
		//copy constructor
		Node(const Node<T> &n) = default;
		Node<T>& operator=(Node<T> const&) = default;

		//actual value constructor
		Node(const T &n, int ord) : attributes(0), my_edges(0), val(n), ordinal(ord) {
		}
	
		~Node() = default;
		//void update_edges(list<Edge<T> >::iterator it);
		void update_edges(std::list<Edge>::iterator it);

		void update_node(T n) { val = n.val; }

		// the complication of this logic suggests that we should maintain list of edge ordinals instead of the Edge iterators?
		void delete_edge(int edge_ordinal) {
			for(auto i = my_edges.begin(); i != my_edges.end(); i++) {
				if((*(*i)).get_ordinal() == edge_ordinal) {
					my_edges.erase(i);
				}
			}
		}

		T& get_val() { return val; }

		std::vector<std::list<Edge>::iterator>& get_edges() {
			return my_edges;
		}

		int get_num_edges() { return my_edges.size(); }

		bool operator==(const Node &other) const;

		// returns the index of the newly added attribute
		int add_attribute(std::pair<std::string, std::string> attribute);

		std::pair<std::string, std::string> get_attribute(int index);

		std::pair<std::string, std::string> get_attribute(std::string key);

		std::string get_attribute_value(std::string key);

		std::vector<std::pair<std::string, std::string>>& get_attributes();
		
		int get_ordinal() { return ordinal; }

		void print();
	};

	/*
	template<class T>
	//this constructor should not be allowed
	//basically a node without a value is useless
	Node<T>::Node() : attributes(0), my_edges(0){
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

	template<class T>
	void Node<T>::update_edges(std::list<Edge>::iterator it) {
		my_edges.push_back(it);
	}

	//define == operator based on the user object equal
	template<class T>
	bool Node<T>::operator==(const Node &other) const {
		//do we need to check for equal attributes too?
		return val == other.val && ordinal == other.ordinal;
	}

	// returns the index of the newly added attribute
	template<class T>
	int Node<T>::add_attribute(std::pair<std::string, std::string> attribute) {
		attributes.push_back(attribute);
		return attributes.size() - 1;
	}

	template<class T>
	std::vector<std::pair<std::string, std::string>>& Node<T>::get_attributes() {
		return attributes;
	}

	template<class T>
	std::pair<std::string, std::string> Node<T>::get_attribute(int index) {
		return attributes[index];
	}

	template<class T>
	std::pair<std::string, std::string> Node<T>::get_attribute(std::string key) {
		std::vector<std::pair<std::string, std::string> >::iterator i;
		for(i = attributes.begin(); i < attributes.end(); i++) {
			if((*i).first == key)
				return *i;
		}
	}

	template<class T>
	std::string Node<T>::get_attribute_value(std::string key) {
		std::pair<std::string, std::string> attrib = get_attribute(key);
		return attrib.second;
	}

	template<class T>
	void Node<T>::print() {
		std::vector<std::list<Edge>::iterator>::iterator it;
		std::cout << ordinal << " -> ";
		for(it = my_edges.begin(); it != my_edges.end(); it++) {
			(*(*it)).print_nodes();
		}
		std::cout << std::endl;
	}
}
#endif
