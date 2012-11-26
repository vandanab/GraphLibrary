#include "node.h"
#include "edge.h"
#include "graphs.h"
#include "topologicalsort.h"
#include <vector>
#include <map>
#include <iostream>

#ifndef TOPOLOGICALSORT_H_
#define TOPOLOGICALSORT_H_
namespace lib {
template <class T>
std::vector<int> topologicalsort(DirectedGraph<T> g) {
	/*
	 * 1. get the list of nodes
	 * 2. calculate the indegree of each node
	 * 3. list the nodes by indegree 0
	 * 4. for each listed node, reduce the indegree of other node of the edge.
	 */
	 std::map<int, int> node_indegree;
	 int zero_indegree_node_index = -1;
	 std::vector<int> topological_order_of_nodes;

     for(auto nodeiter = g.nodes_begin(); nodeiter != g.nodes_end; nodeiter++) {
    	 int node_ordinal = *nodeiter;
    	 int indegree =  g.in_degree(node_ordinal);
    	 node_indegree[node_ordinal] = indegree;
    	 if(zero_indegree_node_index == -1 && indegree == 0) {
    		 zero_indegree_node_index = node_ordinal;
    	 }
     }

     while(!node_indegree.empty()) {
		 if(zero_indegree_node_index == -1) {
			 std::cout << " Exception : Cannot do a topological ordering on the given graph \n";
			 topological_order_of_nodes.clear();
			 break;
		 }
		 node_indegree.erase(zero_indegree_node_index);
		 topological_order_of_nodes.push_back(zero_indegree_node_index);
		 auto successors = g.successors();
		 for(int nodeord = successors.begin(); nodeord != successors.end(); successors++) {
			 zero_indegree_node_index = -1;
			 int indegree = node_indegree[nodeord];
			 indegree--;
			 node_indegree[nodeord] = indegree;
			 if(zero_indegree_node_index == -1 && indegree == 0) {
				 zero_indegree_node_index = nodeord;
			 }
		 }
     }
			for(int i = 0; i < topological_order_of_nodes.size(); i++) {
				std::cout << topological_order_of_nodes[i] << std::endl;
			}

     return topological_order_of_nodes;
}
}

#endif /* TOPOLOGICALSORT_H_ */
