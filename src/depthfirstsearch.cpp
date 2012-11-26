/*
 * depthfirstsearch.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: shiva
 */

#include "depthfirstsearch.h"


namespace lib {

/**
 * These methods assume no cycles in given graph.
 */

template <class T>
std::vector<int> depthfirstsearch(Graph<T> g) {
	return depthfirstsearch(g, *(g.nodes_begin()));
}

template <class T>
std::vector<int> depthfirstsearch(Graph<T> g, int node_ordinal){
	/*
		 * possible improvement :
		 * To detect cycle count the number of nodes going into the nodestack
		 * If they exceed the node count of the graph, there is cycle
		 * throw exception and exit
		 */

		std::vector<int> dfsnodes;
		std::stack<int> nodestack;
		nodestack.push(node_ordinal);
		while(!nodestack.empty()) {
			int current_node = nodestack.pop();
			dfsnodes.push_back(current_node);
			auto successors = g.successors(current_node);
			for(int nodeord = successors.begin(); nodeord != successors.end(); successors++) {
				nodestack.push(node_ordinal);
			}
		}
		return dfsnodes;

}
}
