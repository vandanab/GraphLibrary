/**
 * Unit Test for GraphLib
 * @author GraphLib Team
 */

#include<iostream>
#include "graphs.h"
#include "topologicalsort.h"
#include "depthfirsttraversal.h"
#include "breadthfirsttraversal.h"
#include "utils.h"
#include "min_spanning_tree.h"
#include "bipartite.h"
#include "path.h"

void test_topological_sort() {
    std::cout << "Testing topological sort\n";
    lib::DirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);

    std::vector<int> v = lib::topological_sort(g1);
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

void test_dft_digraph() {
    std::cout << "testing dft on directed graph\n";
    lib::DirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);

    std::vector<int> v11 = lib::depthfirsttraversal(g1);
    for (int i = 0; i < v11.size(); i++) {
        std::cout << v11[i] << std::endl;
    }
}

void test_dft_undigraph() {
    std::cout << "Tetsing undirected graph dft\n";
    lib::UndirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);

    std::vector<int> v11 = lib::depthfirsttraversal(g1);
    for (int i = 0; i < v11.size(); i++) {
        std::cout << v11[i] << std::endl;
    }
}

void test_bft_digraph() {
    std::cout << "testing bft on directed graph\n";
    lib::DirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);

    std::vector<int> v11 = lib::breadthfirsttraversal(g1);
    for (int i = 0; i < v11.size(); i++) {
        std::cout << v11[i] << std::endl;
    }
}

void test_bft_undigraph() {
    std::cout << "Tetsing undirected graph bft\n";
    lib::UndirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);

    std::vector<int> v11 = lib::breadthfirsttraversal(g1);
    for (int i = 0; i < v11.size(); i++) {
        std::cout << v11[i] << std::endl;
    }
}

void test_bipartite_digraph() {
    std::cout << "testing bipartite on directed graph\n";
    lib::DirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[3]);
    e1[2] = g1.add_edge(n1[4], n1[5]);
    e1[3] = g1.add_edge(n1[2], n1[5]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[2], n1[5]);

    std::map<int, int> nodemap = lib::is_bipartite(g1);
    for (auto it = nodemap.begin(); it != nodemap.end(); it++)
        std::cout << (*it).first << " => " << (*it).second << std::endl;
}

void test_bipartite_undigraph() {
    std::cout << "testing bipartite on undirected graph\n";
    lib::UndirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[3]);
    e1[2] = g1.add_edge(n1[4], n1[5]);
    e1[3] = g1.add_edge(n1[2], n1[5]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[2], n1[5]);

    std::map<int, int> nodemap = lib::is_bipartite(g1);
    for (auto it = nodemap.begin(); it != nodemap.end(); it++)
        std::cout << (*it).first << " => " << (*it).second << std::endl;
}

void test_notbipartite_undigraph() {
    std::cout << "Testing undirected graph bipartite\n";
    lib::UndirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);

    std::map<int, int> nodemap = lib::is_bipartite(g1);
    for (auto it = nodemap.begin(); it != nodemap.end(); it++)
        std::cout << (*it).first << " => " << (*it).second << std::endl;
}

void test_attributes() {
    lib::Graph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    n1[0] = g1.add_node(1);
    n1[1] = g1.add_node(2);
    n1[2] = g1.add_node(3);
    n1[3] = g1.add_node(4);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[6] = g1.add_edge(n1[3], n1[1]);

    g1.add_node_attribute(n1[0], "id", 125);
    g1.add_edge_attribute(e1[0], "cost", 2);
    g1.add_node_attribute(n1[0], "color", "red");
    g1.add_edge_attribute(e1[0], "color", "blue");

    std::cout << "node " << n1[0] << " color: "
            << g1.get_node_string_attribute(n1[0], "color") << std::endl;
    std::cout << "edge " << e1[0] << " color: "
            << g1.get_edge_string_attribute(e1[0], "color") << std::endl;
    std::cout << "node " << n1[0] << " id: "
            << g1.get_node_attribute(n1[0], "id") << std::endl;
    std::cout << "edge " << e1[0] << " cost: "
            << g1.get_edge_attribute(e1[0], "cost") << std::endl;

    g1.print();

}

void test_graph_import_export() {
    lib::Graph<int> g1 = lib::import_gml("input_graph.gml");

    std::cout << "imported graph :: no. of nodes: " << g1.num_nodes()
            << " no. of edges: " << g1.num_edges();

    g1.export_as_gml("output_graph.gml");
}

void test_min_spanning_tree() {
    lib::UndirectedGraph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);
    e1[6] = g1.add_edge(n1[3], n1[5]);

    for (int i = 0; i < 7; i++) {
        g1.add_edge_attribute(e1[i], "weight", 2);
    }

    std::cout << "testing min spanning tree..." << std::endl;
    g1.print();

    lib::minimum_spanning_tree(g1);

}

void test_simple_path() {

    lib::Graph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);
    e1[6] = g1.add_edge(n1[3], n1[5]);

    std::cout << "testing get simple path..." << std::endl;
    g1.print();

    std::vector<int> path_nodes = lib::get_simple_path(g1, 0, 5);
    for (int node : path_nodes)
        std::cout << node << "-->";

}

void test_is_path_exists() {
    lib::Graph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);
    //e1[6] = g1.add_edge(n1[3], n1[5]);

    std::cout << "testing is simple path..." << std::endl;
    g1.print();

    std::cout << lib::is_path_exists(g1, 0, 5);

}

int main() {
    //en.wikipedia.org/wiki/Graph_theory
    lib::Graph<int> g1;
    int n1[6]; //node_ordinals
    int e1[7]; //edge_ordinals

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    n1[0] = g1.add_node(a);
    n1[1] = g1.add_node(b);
    n1[2] = g1.add_node(c);
    n1[3] = g1.add_node(d);
    n1[4] = g1.add_node(e);
    n1[5] = g1.add_node(f);

    e1[0] = g1.add_edge(n1[0], n1[1]);
    e1[1] = g1.add_edge(n1[0], n1[4]);
    e1[2] = g1.add_edge(n1[1], n1[2]);
    e1[3] = g1.add_edge(n1[1], n1[4]);
    e1[4] = g1.add_edge(n1[2], n1[3]);
    e1[5] = g1.add_edge(n1[3], n1[4]);
    e1[6] = g1.add_edge(n1[3], n1[5]);

    std::cout << "no. of nodes: " << g1.num_nodes() << " no. of edges: "
            << g1.num_edges() << std::endl;
    g1.print();
    g1.export_as_gml("graph.gml");

    g1.delete_node(n1[4]);
    g1.delete_edge(e1[2]);

    try {
        std::cout << g1.get_node(n1[4]);
    } catch (...) {
        std::cout << "expected exception on accessing deleted element"
                << std::endl;
    }

    std::cout << "no. of nodes: " << g1.num_nodes() << " no. of edges: "
            << g1.num_edges() << std::endl;
    g1.print();

    test_attributes();
    test_topological_sort();
    test_dft_digraph();
    test_dft_undigraph();
    test_bft_digraph();
    test_bft_undigraph();
    test_bipartite_digraph();
    test_bipartite_undigraph();
    test_notbipartite_undigraph();
    test_min_spanning_tree();
    test_graph_import_export();

    return 0;
}
