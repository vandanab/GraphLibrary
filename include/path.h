/**
 * path.h provides algorithms related to paths in graphs
 * 
 * 
 */

#ifndef PATH_H
#define PATH_H

#include "graph.h"
#include "breadthfirsttraversal.h"
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <limits>


namespace lib
{

	template <class T>
	bool is_path_exists(T g, int node_source, int node_target)
	{
		 return get_simple_path(g, node_source, node_target).size() > 0;
	}

	
	template <class T>
	std::vector<int> get_simple_path(T g, int node_source, int node_target)
	{
		std::vector<int> simple_path;
                std::vector<int> visited;
                visited.push_back(node_source);
                simple_path = search_path(g, node_target, visited);
                return simple_path;

	}



	template <class T>
        std::vector<int> search_path(T g, int node_target, std::vector<int> visited)
        {
                std::vector<int> path;
                auto successors = g.successors(visited[visited.size() - 1]);

                for(int succ : successors)
                {
                        // To avoid cycles
                        //if (contains(visited, succ)) continue;

                        if (succ == node_target)
                        {
                                visited.push_back(succ);
                                return visited;
                        }

                        else
                        {
                                visited.push_back(succ);
                                path = search_path(g, node_target, visited);
                                if (path.size() <= 0)
                                        visited.erase(visited.end() - 1);
                                else
                                        break;
                        }
                }
                return path;
        }


	template <class T>
        bool contains(std::vector<T> data, T val)
        {
                for (T datum : data)
                        if (data == val) return true;
                return false;
        }

	

	template <class T>
	std::vector<int> get_shortest_path(T g, int node_source, int node_target)
	{
		 //Step1: Initialization
                auto iter = g.nodes_begin();
                std::vector<int> shortest_path;
                for (; iter != g.nodes_end(); iter++)
                {
                        if (*iter == node_source)
                                g.add_node_attribute(*iter, "tentativedistance", 0);
                        else
                                g.add_node_attribute(*iter, "tentativedistance",std::numeric_limits<double>::max());
                        g.add_node_attribute(*iter, "visited", 0);

                }

                std::queue<int> node_queue;
                node_queue.push(node_source);
                int lastvisitednode = -1;
                int curr_node,  curr_parent, curr_count;

                // Step 2: This is equivalent to a weighted BFS
                while (lastvisitednode != node_target && node_queue.size() != 0)
                {
                        curr_node = node_queue.pop();
                        auto curr_succ = g.get_successors_with_edges(curr_node);
                        auto curr_distance = g.get_node_attribute(curr_node, "tentativedistance");
                        auto it = curr_succ.begin();
                        for(; it != curr_succ.end(); it++)
                        {
                                double edge_weight = g.get_edge_attribute(*it.second(),"weight");
                                double succ_distance = g.get_node_attribute(*it.first(), "tentativedistance");
                                bool succ_visited = g.get_node_attribute(*it.first(), "visited");
                                if (!succ_visited && (curr_distance + edge_weight) < succ_distance)
                                {
                                        g.add_node_attribute(*it.first(), "tentativedistance", curr_distance + edge_weight);
                                        g.add_node_attribute(*it.first(), "parent", curr_node);
                                        node_queue.push(*it.first());
                                }
                        }
                        g.add_node_attribute(curr_node, "visited", 1);
                        lastvisitednode = curr_node;
                }


		//Step 3: Checking if there indeed exists a path. Else, the target node would have never been visited.
                //              If paths exists, then its the shortest path from node_source. Hence return it.
                if(lastvisitednode == node_target)
                {
                        curr_parent = -1;curr_node = node_target;
                        while (curr_node != node_source)
                        {
                                curr_parent = (int) g.get_node_attribute(curr_node, "parent");
                                shortest_path.push_back(curr_parent);
                                curr_node = curr_parent;
                        }
                }

                return std::reverse(shortest_path.begin(), shortest_path.end());

	}

	
	template <class T>
	std::vector<Graph<T> > get_connected_components(T g)
	{
		 std::vector<std::vector<int> > components;
                std::list<int> remaining_nodes;
                std::vector<std::list<int>::iterator> toberemoved;
                std::list<int>::iterator curr;
                int visitednodecount = 0;

                //Step 1: Initialization - Gather all unvisited nodes   
                auto iter = g.nodes_begin();

                for (; iter != g.nodes_end(); iter++)
                {
                        remaining_nodes.push_back(*iter);
                }

                //Step 2: Call BFS from the first unvisited node
                while(visitednodecount < g.num_nodes())
                {
                        int start_node = remaining_nodes.front();
                        //start_node = get_unvisited_node(g, visited);
                        std::vector<int> component = lib::breadthfirsttraversal(g, start_node);
                        components.push_back(component);
                        visitednodecount += component.size();

                        //Traverse remaining nodes and remove those that were visited by this BFS
                        for(; curr != remaining_nodes.end(); curr++)
                        {
                                for(int node: component)
                                {
                                        if (*curr == node)
                                                toberemoved.push_back(curr);
                                }
                        }

                        for(auto iter: toberemoved)
                                remaining_nodes.erase(iter);

                }

                return components;	
	}
}

#endif
