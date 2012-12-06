/**
 * edge.cpp
 * @author: GraphLib Team
 */
#include<iostream>
#include "edge.h"

namespace lib {

    Edge::Edge(int node1_ordinal, int node2_ordinal, int ord) : attribute_service() {
        ordinal = ord;
        node1_ord = node1_ordinal;
        node2_ord = node2_ordinal;
    }

    void Edge::print_nodes() {
        std::cout << "(" << node1_ord << ", " << node2_ord << ")";
    }
}
