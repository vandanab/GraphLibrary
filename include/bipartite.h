/*
 * bipartite.h
 *
 *  Created on: Dec 1, 2012
 *      Author:
 */

#ifndef BIPARTITE_H_
#define BIPARTITE_H_

#include <graphs.h>
#include <node.h>
#include <edge.h>
#include <vector>
#include <map>
#include <queue>

namespace lib
{

template<class T>
std::map<int, int> is_bipartite(T g)
{
	int start = *(g.nodes_begin());
	std::queue<int> nodeque;
	std::list<int> visitedlist;
	std::map<int, int> nodes;
	nodeque.push(start);
	bool fail = false;

	while (!fail) {
		while(!nodeque.empty() && !fail) {
			int ordinal = nodeque.front();
			nodeque.pop();
			visitedlist.push_back(ordinal);
			int group = nodes[ordinal];

			auto successors = g.neighbors(ordinal);
			for (int index = 0; index != successors.size(); index++) {
				auto findvalue =
					nodes.find(successors[index]);
				if(findvalue == nodes.end()) {
					int val = (group+1) % 2;
					nodes[successors[index]] = val;
				}
				else {
					if((findvalue)->second != (group+1)%2) {
						std::cout << "This graph is not bipartite!\n";
						nodes.clear();
						fail = true;
					}
				}
				auto finditer =
					std::find(visitedlist.begin(), visitedlist.end(), successors[index]);
				if(finditer == visitedlist.end()) {
					nodeque.push( successors[index]);
				}
			}
		}

		if (nodes.size() < g.num_nodes()) {
			for (auto node = g.nodes_begin() ; node != g.nodes_end(); node++ ) {
				auto findnode = nodes.find(*node);
				if(findnode == nodes.end()) {
					nodeque.push(*node);
				}
			}
		}
		else {
			break;
		}
	}

	if(!fail)
		std::cout << "Awesome - This graph is bipartite!\n";
	return nodes;
}

}

#endif /* BIPARTITE_H_ */
