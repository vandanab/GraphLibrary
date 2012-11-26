/*
 * breadthfirstsearch.h
 *
 *  Created on: Nov 25, 2012
 *      Author:
 */

#ifndef BREADTHFIRSTSEARCH_H_
#define BREADTHFIRSTSEARCH_H_

namespace lib {
template <class T>
std::vector<int> breadthfirstsearch(Graph<T> g);

template <class T>
std::vector<int> breadthfirstsearch(Graph<T> g, int node_ordinal);
}


#endif /* BREADTHFIRSTSEARCH_H_ */
