/*
 * depthfirstsearch.h
 *
 *  Created on: Nov 25, 2012
 *      Author:
 */

#ifndef DEPTHFIRSTTRAVERSAL_H_
#define DEPTHFIRSTTRAVERSAL_H_

#include <vector>
#include "node.h"
#include "graphs.h"
#include "edge.h"
#include <stack>
#include <algorithm>

namespace lib {

/**
 * These methods assume no cycles in given graph.
 */

template<class T>
std::vector<int> depthfirsttraversal(T g) {
    return depthfirsttraversal(g, *(g.nodes_begin()));
}

template<class T>
std::vector<int> depthfirsttraversal(T g, int node_ordinal) {

    std::vector<int> dfsnodes;
    std::stack<int> nodestack;
    nodestack.push(node_ordinal);
    while (!nodestack.empty()) {
        int current_node = nodestack.top();
        nodestack.pop();
        auto findvalue =
            std::find(dfsnodes.begin(), dfsnodes.end(), current_node);
        if(findvalue != dfsnodes.end()) {
            continue;
        }
        dfsnodes.push_back(current_node);
        auto successors = g.neighbors(current_node);
        for (int index = 0; index != successors.size(); index++) {
            int nodeord = successors[index];
            nodestack.push(nodeord);
        }
    }
    return dfsnodes;

}
}

#endif /* DEPTHFIRSTTRAVERSAL_H_ */
