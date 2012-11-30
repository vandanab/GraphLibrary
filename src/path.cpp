/**
 * path.cpp provides algorithms related to paths in graphs
 * 
 * 
 */

#include "graph.h"
#include "path.h"
#include <vector>


namespace lib
{

	template <class T>
	bool is_path_exists(Graph<T> g, int node_source, int node_target)
	{
		return get_simple_path(g, node_source, node_target).size() > 0;
	}



	template <class T>
        std::vector<int> get_simple_path(Graph<T> g, int node_source, int node_target)
	{
		std::vector<int> simple_path;
		std::vector<int> visited;
		visited.push_back(node_source);
		simple_path = search_path(g, node_target, visited);	
		return simple_path;		
	}


	template <class T>
	std::vector<int> search_path(Graph<T> g, int node_target, std::vector<int> visited)
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
	


	/*template <class T>
	bool contains(std::vector<T> data, T val)
	{
		for (T datum : data)
			if (data == val) return true;
		return false;
	}*/
}
