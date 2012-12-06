#ifndef TOPOLOGICALSORT_H_
#define TOPOLOGICALSORT_H_

#include "node.h"
#include "edge.h"
#include "graphs.h"
#include <vector>
#include <map>
#include <iostream>

namespace lib {

template<class T>
std::vector<int> topological_sort(DirectedGraph<T> g) {
    /*
     * 1. get the list of nodes
     * 2. calculate the indegree of each node
     * 3. list the nodes by indegree 0
     * 4. for each listed node, reduce the indegree of other node of the edge.
     */
    std::map<int, int> node_indegree;
    int current_zero_indegree_node_index = -1;
    std::vector<int> topological_order_of_nodes;

    for
    (auto nodeiter = g.nodes_begin(); nodeiter != g.nodes_end(); nodeiter++) {
        int node_ordinal = *nodeiter;
        int indegree = g.in_degree(node_ordinal);
        node_indegree[node_ordinal] = indegree;
        if(indegree == 0) {
            if (current_zero_indegree_node_index == -1) {
                current_zero_indegree_node_index++;
            }
            topological_order_of_nodes.push_back(node_ordinal);
        }
    }

    while
    (current_zero_indegree_node_index < topological_order_of_nodes.size()) {
        auto node_ordinal =
            topological_order_of_nodes[current_zero_indegree_node_index];

        std::vector<int> successors = g.successors(node_ordinal);
        for (int index = 0; index < successors.size(); index++) {
            int nodeord = successors[index];
            int indegree = node_indegree[nodeord];
            indegree--;
            node_indegree[nodeord] = indegree;
            if (indegree == 0) {
                topological_order_of_nodes.push_back(nodeord);
                node_indegree.erase(nodeord);
            }
        }
        current_zero_indegree_node_index++;
    }

    /*for (int i = 0; i < topological_order_of_nodes.size(); i++) {
        std::cout << topological_order_of_nodes[i] << std::endl;
    }*/

    return topological_order_of_nodes;
}
}

#endif /* TOPOLOGICALSORT_H_ */
