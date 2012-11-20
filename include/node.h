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
		T val;
		// for now the attributes are assumed to be string key-value pairs
		std::vector<std::pair<std::string, std::string> > attributes;
		//vector<list<Edge<T> >::iterator> my_edges;
		std::vector<std::list<Edge>::iterator> my_edges;

	public:
		Node();
		Node(const Node<T> &n);
		Node(const T &n);
		~Node();
		//void update_edges(list<Edge<T> >::iterator it);
		void update_edges(std::list<Edge>::iterator it);

		//define == operator based on the user object equal
		bool operator==(const Node &other) const;

		// returns the index of the newly added attribute
		int add_attribute(std::pair<std::string, std::string> attribute);

		std::pair<std::string, std::string> get_attribute(int index);

		std::pair<std::string, std::string> get_attribute(std::string key);

		std::string get_attribute_value(std::string key);

		void print();
	};

	template<class T>
	Node<T>::Node() : attributes(0), my_edges(0){
	}

	template<class T>
	Node<T>::Node(const Node<T> &n) {
		val = n.val;
		attributes = n.attributes;
		my_edges = n.my_edges;
	}

	template<class T>
	Node<T>::Node(const T &n) : attributes(0), my_edges(0), val(n) {
	}
		//define regular constructors
		//define move and copy constructors
		//define destructor
	template<class T>
	Node<T>::~Node() {}

	template<class T>
	//void Node::update_edges(list<Edge<T>>::iterator it) {
	void Node<T>::update_edges(std::list<Edge>::iterator it) {
		my_edges.push_back(it);
	}

	//define == operator based on the user object equal
	template<class T>
	bool Node<T>::operator==(const Node &other) const {
		return val == other.val;
	}

	// returns the index of the newly added attribute
	template<class T>
	int Node<T>::add_attribute(std::pair<std::string, std::string> attribute) {
		attributes.push_back(attribute);
		return attributes.size() - 1;
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
		//vector<list<Edge<T>>::iterator>::iterator it;
		std::vector<std::list<Edge>::iterator>::iterator it;
		std::cout << val << " -> ";
		for(it = my_edges.begin(); it != my_edges.end(); it++) {
			(*(*it)).print_node_ordinals();
		}
		std::cout << std::endl;
	}
}
#endif
