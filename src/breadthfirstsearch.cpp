/*
 * breadthfirstsearch.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author:
 */

#include "breadthfirstsearch.h"
#include <vector>
#include <stack>
#include <queue>

namespace lib {

/**
 * These methods assume no cycles in given graph.
 */

template <class T>
std::vector<int> breadthfirstsearch(Graph<T> g) {
	return breadthfirstsearch(g, *(g.nodes_begin()));
}

template <class T>
std::vector<int> breadthfirstsearch(Graph<T> g, int node_ordinal) {
	/*
	 * possible improvement :
	 * To detect cycle count the number of nodes going into the nodeque
	 * If they exceed the node count of the graph, there is cycle
	 * throw exception and exit
	 */

	std::vector<int> bfsnodes;
	std::queue<int> nodeque;
	nodeque.push(node_ordinal);
	while(!nodeque.empty()) {
		int current_node = nodeque.pop();
		bfsnodes.push_back(current_node);
		auto successors = g.successors(current_node);
		for(int nodeord = successors.begin(); nodeord != successors.end(); successors++) {
			nodeque.push(node_ordinal);
		}
	}
	return bfsnodes;
}
}



