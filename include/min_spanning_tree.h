/**
 * min_spanning_tree.h
 * author: GraphLib Team (?)
 * Minimum Spanning Tree function
 */
#include<queue>
#include<vector>
#include<limits>
#include<algorithm>
#include "graphs.h"

#ifndef MIN_SPANNING_TREE_H
#define MIN_SPANNING_TREE_H

namespace lib {
	class QueueNode {
	public:
		int node_ordinal;
		double weight;
		int parent_node_ordinal;
		int parent_edge;
		QueueNode(int n_o, double w) : node_ordinal(n_o), weight(w), parent_node_ordinal(-1), parent_edge(-1){}
		QueueNode() = default;
		QueueNode(QueueNode&& n) = default;
		QueueNode& operator=(QueueNode&& n) = default;
		QueueNode(const QueueNode& n) = default;
		QueueNode& operator=(const QueueNode& n) = default;
		~QueueNode() = default;
		bool operator<(const QueueNode& n) {
			if(weight > n.weight) return true;
			return false;
		}

		bool operator==(const QueueNode& n) {
			if(node_ordinal == n.node_ordinal) return true;
			return false;
		}
	};

	template<class T>
	//UndirectedGraph<T>& minimum_spanning_tree(UndirectedGraph<T> g) {
	void minimum_spanning_tree(UndirectedGraph<T> g) {
		//UndirectedGraph<T> g();
		std::vector<int> v;
		std::vector<QueueNode> node_queue;
		auto it1 = g.nodes_begin();
		QueueNode n = {*it1, 0};
		node_queue.push_back(n);
		g.add_node_attribute(*it1, "parent", -1);
		g.add_node_attribute(*it1, "parent_edge", -1);
		it1++;
		for(; it1 != g.nodes_end(); it1++) {
			n = {*it1, std::numeric_limits<double>::max()};
			g.add_node_attribute(*it1, "parent", -1);
			g.add_node_attribute(*it1, "parent_edge", -1);
			node_queue.push_back(n);
		}
		std::make_heap(node_queue.begin(), node_queue.end());

		while(!node_queue.empty()) {
			n = node_queue.front();
			pop_heap(node_queue.begin(), node_queue.end()); node_queue.pop_back();
			auto successors = g.neighbors_with_edges(n.node_ordinal);
			for(auto i = successors.begin(); i != successors.end(); i++) {
				int node_ord = (*i).first;
				int edge_ord = (*i).second;
				QueueNode temp(node_ord, 0);
				auto it = find(node_queue.begin(), node_queue.end(), temp);
				if(it != node_queue.end()) {
					auto w = g.get_edge_attribute(edge_ord, "weight");
					if(w < (*it).weight) {
						(*it).parent_node_ordinal = n.node_ordinal;
						(*it).parent_edge = edge_ord;
						(*it).weight = w;
						g.add_node_attribute((*it).node_ordinal, "parent", n.node_ordinal);
						g.add_node_attribute((*it).node_ordinal, "parent_edge", edge_ord);
						std::make_heap(node_queue.begin(), node_queue.end());
					}
				}
			}
		}

		for(auto c1 = g.nodes_begin(); c1 != g.nodes_end(); c1++) {
			std::cout<<*c1<<" parent_node:"<<g.get_node_attribute(*c1, "parent")<<" parent_edge:"<<g.get_node_attribute(*c1, "parent_edge")<<std::endl;
		}
	}
}
#endif
