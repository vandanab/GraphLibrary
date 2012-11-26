/*
 * depthfirstsearch.h
 *
 *  Created on: Nov 25, 2012
 *      Author: shiva
 */

#ifndef DEPTHFIRSTSEARCH_H_
#define DEPTHFIRSTSEARCH_H_


namespace lib {
template <class T>
std::vector<int> depthfirstsearch(Graph<T> g);

template <class T>
std::vector<int> depthfirstsearch(Graph<T> g, int node_ordinal);
}

#endif /* DEPTHFIRSTSEARCH_H_ */
