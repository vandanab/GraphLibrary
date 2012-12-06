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
#include <algorithm>
#include <limits>

namespace lib
{

template<class T>
bool is_bipartite(T g)
{
	std::pair<std::vector<int>, std::vector<int> > bipartitenodes = get_bipartite_nodes(g);
	return (bipartitenodes.first.size() > 0);
}



template<class T>
std::pair<std::vector<int>, std::vector<int> > get_bipartite_nodes(T g)
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

	auto iter = nodes.begin();
	std::vector<int> left, right;
	std::pair<std::vector<int>, std::vector<int> > bipartitenodes;
	for (; iter != nodes.end(); iter++)
	{
		if(iter->second == 0)
			left.push_back(iter->first);
		else
			right.push_back(iter->first);
	}
	bipartitenodes.first = left;
	bipartitenodes.second = right;
	return bipartitenodes;
}


template <class T>
std::vector<int> get_maximum_matching(UndirectedGraph<T> g)
{

	std::pair<std::vector<int>, std::vector<int> > bipartitenodes = get_bipartite_nodes(g);
	T n1, n2;
	int source, sink;
	std::vector<int> source_edges, sink_edges;
	if (bipartitenodes.first().size() > 0)
	{
		//Step 1: Add a new source node, add edges from source to left half of bipartite nodes
		source = g.add_node(n1);
		sink = g.add_node(n2);
		
		for(int node :  bipartitenodes.first())
		{
			source_edges.push_back(g.add_edge(source, node));
		}
		for(int node :  bipartitenodes.second())
		{
			sink_edges.push_back(g.add_edge(node, sink));
		} 
	}

	//Step 2: Maximum matching will be the maximum flow in the graph
	int** capacity = (int**) malloc(sizeof(int*) * g.num_nodes());
	int index, row, col;
	for(index = 0; index < g.num_nodes(); index++)
		capacity[index] = (int*) malloc(sizeof(int) * g.num_nodes());
	for(row = 0; row < g.num_nodes(); row++)
		for(col = 0; col < g.num_nodes(); col++)
			capacity[row][col] = 0;
	for(int node : bipartitenodes.first())
		capacity[source][node] = 1;
	for(int node : bipartitenodes.second())
		capacity[node][sink] = 1;
	for(int node : bipartitenodes.first())
	{
		auto succs = g.successors(node);
		for(int succ : succs)
			capacity[node][succ] = 1;
	}
	std::vector<int> matching = get_max_flow(g, source, sink, capacity);


	//Step 3: Remove all extraneous nodes and edges added
	for(int edge : source_edges)
		g.delete_edge(edge);
	for(int edge: sink_edges)
		g.delete_edge(edge);
	g.delete_node(source);
	g.delete_node(sink);

	return matching;
	
}


template <class T>
std::vector<int> get_max_flow(UndirectedGraph<T> g, int node_source, int node_sink, int** capacity)
{
	std::vector<int> flow_edges;
	
	while(1)
	{
		std::vector<int> path = get_flow_path(g, node_source, node_sink, capacity);
		
		// TODO: Implement this - Push the bipartite edge
		if(path.size() > 0)
		{
			auto iter = g.edges_begin();
			for (; iter < g.edges_end(); iter++)
			{
				std::pair<int,int> edge = g.get_edge(*iter);
				if (edge.first() == path[1] && edge.second() == path[2])
					flow_edges.push_back(*iter);
			}
		} 
		else
			break;
	}

	return flow_edges;
}


template <class T>
std::vector<int> get_flow_path(UndirectedGraph<T> g, int node_source, int node_sink, int** capacity)
{

	std::queue<int> que;
	que.push(node_source);
	g.add_node_attribute(node_source, "visited", 1);
	int where, prev;
	int from[g.num_nodes()];
	bool exitwhile;
	int index;
	for(index = 0; index < g.num_nodes(); index++)
		from[index] = -1;
	while(que.size() > 0 && exitwhile == false)
	{
		where = que.pop();
		auto succs = g.successors(where);
		for(int succ : succs)
		{
			if(g.get_node_attribute(succ, "visited") != 1 && g.get_node_attribute(where, "capacity") > 0)
			{
				que.push(succ);
				g.add_node_attribute(succ, "visited", 1);
				from[succ] = where;
				if (succ == node_sink)
				{
					exitwhile = true;
					break;
				}
			}
		}
	}

	where = node_sink;
	double path_cap = std::numeric_limits<double>::max();
	
	while (from[where] > -1)
	{
		prev = from[where];
		path_cap = (path_cap < capacity[prev][where]) ? path_cap : capacity[prev][where]; 
		where = prev;
	}

	where = node_sink;
	while (from[where] > -1)
	{
		prev = from[where];
		capacity[prev][where] -= path_cap;
		capacity[where][prev] += path_cap;
		where = prev;
	}

	std::vector<int> path;
	where = node_sink;
	if(path_cap != std::numeric_limits<double>::max())
	{
		while(from[where] > -1)
		{
			if (from[where] != node_source && from[where] != node_sink)
			path.push_back(from[where]);
			where = from[where];
		}
	}

	return std::reverse(path.begin(), path.end());
		
}
}

#endif /* BIPARTITE_H_ */
