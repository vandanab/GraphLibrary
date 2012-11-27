/*
 * breadthfirstsearch.h
 *
 *  Created on: Nov 25, 2012
 *      Author:
 */

#ifndef BREADTHFIRSTTRAVERSAL_H_
#define BREADTHFIRSTTRAVERSAL_H_

#include <vector>
#include "node.h"
#include "graphs.h"
#include "edge.h"
#include <queue>
#include <algorithm>

namespace lib {

/**
 * These methods assume no cycles in given graph.
 */

template<class T>
std::vector<int> breadthfirsttraversal(T g) {
    return breadthfirsttraversal(g, *(g.nodes_begin()));
}

template<class T>
std::vector<int> breadthfirsttraversal(T g, int node_ordinal) {

    std::vector<int> bfsnodes;
    std::queue<int> nodequeue;
    nodequeue.push(node_ordinal);
    while (!nodequeue.empty()) {
        int current_node = nodequeue.front();
        nodequeue.pop();
        auto findvalue =
            std::find(bfsnodes.begin(), bfsnodes.end(), current_node);
        if(findvalue != bfsnodes.end()) {
            continue;
        }
        bfsnodes.push_back(current_node);
        auto successors = g.neighbors(current_node);
        for (int index = 0; index != successors.size(); index++) {
            int nodeord = successors[index];
            nodequeue.push(nodeord);
        }
    }
    return bfsnodes;

}
}

#endif /* BREADTHFIRSTTRAVERSAL_H_ */
