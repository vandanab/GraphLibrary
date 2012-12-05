/**
* import / export utilties
* @author GraphLib Team
* @version 0.1 12/02/2012
*/
#ifndef _UTILS_H
#define _UTILS_H

#include<string>
#include"graph.h"

namespace lib {
	template <typename T>
	void export_to_gml(lib::Graph<T>* g, std::string filename);

	Graph<int> import_gml(std::string filename);

	template <typename T>
	void export_to_gml(lib::Graph<T>* g, std::string filename)
	{
		std::ofstream os{filename};

		os << "graph [" << std::endl;
		//todo: add directed/undirected
		for (auto n_it = g->nodes_begin(); n_it != g->nodes_end(); n_it++) {
			os << "node [" << std::endl;
			os << "id " << ((*n_it) + 1) << std::endl;
			os << "label " << "\"" << ((*n_it) + 1) << "\"" << std::endl;
			os << "]" << std::endl;
		}
		for (auto n_it = g->nodes_begin(); n_it != g->nodes_end(); n_it++) {
			std::vector<int> v_edges = g->out_edges(*n_it);
			for(int i = 0; i < v_edges.size(); i++) {
				os << "edge [" << std::endl;
				std::pair<int, int> e = g->get_edge(v_edges[i]);
				os << "source " << e.first << std::endl;
				os << "target " << e.second << std::endl;
				os << "]" << std::endl;
			}
		}
		os << "]" << std::endl;
	}	
}
#endif