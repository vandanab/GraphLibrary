#include<iostream>
#include "edge.h"

namespace lib {
	/*
	Edge::Edge() {}

	Edge::Edge(const Edge &e) {
		node1_ord = e.node1_ord;
		node2_ord = e.node2_ord;
	}
	
	Edge::~Edge() {}
	*/

	Edge::Edge(int node1_ordinal, int node2_ordinal, int ord) {
		ordinal = ord;
		node1_ord = node1_ordinal;
		node2_ord = node2_ordinal;
	}

	// returns the index of the newly added attribute
	int Edge::add_attribute(std::pair<std::string, std::string> attribute) {
		attributes.push_back(attribute);
		return attributes.size() - 1;
	}

	std::vector<std::pair<std::string, std::string>>& Edge::get_attributes() {
		return attributes;
	}

	std::pair<std::string, std::string> Edge::get_attribute(int index) {
		return attributes[index];
	}

	std::pair<std::string, std::string> Edge::get_attribute(std::string key) {
		std::vector<std::pair<std::string, std::string> >::iterator i;
		for(i = attributes.begin(); i < attributes.end(); i++) {
			if((*i).first == key)
				return *i;
		}
	}

	std::string Edge::get_attribute_value(std::string key) {
		std::pair<std::string, std::string> attrib = get_attribute(key);
		return attrib.second;
	}
	
	void Edge::print_node_ordinals() {
		std::cout << "(" << node1_ord << ", " << node2_ord << ")";
	}
}
