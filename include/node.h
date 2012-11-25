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
		Node(const T &n, int ord) : attributes(0), in_edges(0), out_edges(0), val(n), ordinal(ord) {}
	
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
			for(auto i = in_edges.begin(); i != in_edges.end(); i++) {
				if(*i == edge_ordinal) {
					in_edges.erase(i);
				}
			}
		}

		void delete_in_edges() { in_edges.clear(); }
		void delete_out_edges() { out_edges.clear(); }

		void delete_out_edge(int edge_ordinal) {
			for(auto i = out_edges.begin(); i != out_edges.end(); i++) {
				if(*i == edge_ordinal) {
					out_edges.erase(i);
				}
			}
		}

		std::vector<int> get_in_edges() { return in_edges; }

		std::vector<int> get_out_edges() { return out_edges; }

		T& get_val() { return val; }

		bool operator==(const Node &other) const;

		// returns the index of the newly added attribute
		int add_attribute(std::pair<std::string, std::string> attribute);

		std::pair<std::string, std::string> get_attribute(int index);

		std::pair<std::string, std::string> get_attribute(std::string key);

		std::string get_attribute_value(std::string key);

		std::vector<std::pair<std::string, std::string>>& get_attributes();

		//std::vector<int> neighbors_undirected();
		//std::vector<int> neighbors_directed();

		//all nodes it is connected to or which connect to it

		//std::vector<int> get_edges_undirected();
		//std::vector<int> get_edges_directed();
		
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

	/*
	template<class T>
	std::vector<int> Node<T>::neighbors_directed() {
		return successors();
	}*/

	/*
	template<class T>
	std::vector<int> Node<T>::get_edges_undirected() {
		long size = inEdges.size() + outEdges.size();
		std::vector<int> v(size);
		for (long i = 0; i < inEdges.size(); i++)
		{
			v.push_back((*inEdges[i]).get_ordinal());
		}
		for (long i = outEdges.size(); i < size; i++)
		{
			v.push_back((*outEdges[i]).get_ordinal());
		}
		return v;
	}

	template<class T>
	std::vector<int> Node<T>::get_edges_directed() {
		return out_edges();
	}*/
}
#endif
