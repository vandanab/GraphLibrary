/**
 * path.h provides algorithms related to paths in graphs
 * 
 * 
 */

#ifndef PATH_H
#define PATH_H

#include "graph.h"
#include <vector>

namespace lib
{

	template <class T>
	bool is_path_exists(Graph<T> g, int node_source, int node_target);

	
	template <class T>
	std::vector<int> get_simple_path(Graph<T> g, int node_source, int node_target);


	template <class T>
	std::vector<int> get_shortest_path(Graph<T> g, int node_source, int node_target);

	
	template <class T>
	std::vector<Graph<T> > get_connected_components(Graph<T> g);
}

#endif
