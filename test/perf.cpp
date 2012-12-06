#include<chrono>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/breadth_first_search.hpp>
#include<boost/pending/indirect_cmp.hpp>
#include<boost/range/irange.hpp>
#include "graph.h"
#include "utils.h"
#include "breadthfirsttraversal.h"

//boost test
using namespace boost;
template < typename TimeMap > class bfs_time_visitor:public default_bfs_visitor {
  typedef typename property_traits < TimeMap >::value_type T;
public:
  bfs_time_visitor(TimeMap tmap, T & t):m_timemap(tmap), m_time(t) { }
  template < typename Vertex, typename Graph >
    void discover_vertex(Vertex u, const Graph & g) const
  {
    put(m_timemap, u, m_time++);
  }
  TimeMap m_timemap;
  T & m_time;
};

void boost_test(const std::string& filename) {
	typedef boost::adjacency_list<vecS, vecS, undirectedS, property<vertex_name_t, std::string>, property<edge_weight_t, double> > BoostGraph;

	std::ifstream in(filename.c_str());

	BoostGraph bg;
	dynamic_properties dp;
	dp.property("id", get(vertex_name, bg));
	dp.property("weight", get(edge_weight, bg));
	bool status = read_graphviz(in, bg, dp, "id");
	
	//start timing as graph has been created
	auto t1 = std::chrono::system_clock::now();
	typedef graph_traits < BoostGraph >::vertex_descriptor Vertex;
	typedef graph_traits < BoostGraph >::vertices_size_type Size;
	typedef Size* Iiter;

	int N = num_vertices(bg);	
	std::vector < Size > dtime(N);
	
	Size time = 0;
	bfs_time_visitor < Size * > vis(&dtime[0], time);
	breadth_first_search(bg, vertex(0, bg), visitor(vis));

  std::vector<graph_traits<BoostGraph>::vertices_size_type > discover_order(N);
  integer_range < int >range(0, N);
  std::copy(range.begin(), range.end(), discover_order.begin());
  std::sort(discover_order.begin(), discover_order.end(),
            indirect_cmp < Iiter, std::less < Size > >(&dtime[0]));
	auto t2 = std::chrono::system_clock::now();
	auto dms = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
	std::cout << "breadth first search using boost library on the network dataset karate took " << dms.count() << " microseconds\n";
	//stop timing

  std::cout << "order of discovery: ";
  for (int i = 0; i < N; ++i)
    std::cout << discover_order[i] << " ";
  std::cout << std::endl;
}

void graphlib_test(const std::string &filename) {
	lib::Graph<int> g = lib::import_gml(filename);

	//start timing
	auto t1 = std::chrono::system_clock::now();
	std::vector<int> v = lib::breadthfirsttraversal(g);
	auto t2 = std::chrono::system_clock::now();
	auto dms = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
	std::cout << "breadth first search using graph library on the network dataset karate took " << dms.count() << " microseconds\n";
	//stop timing

	for(int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	boost_test("karate.gv");
	graphlib_test("karate.gml");
	return 0;
}
