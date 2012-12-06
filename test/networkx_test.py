import networkx as nx
from datetime import datetime, timedelta

def networkx_test(filename):
	G = nx.read_gml(filename)
	t1 = datetime.now()
	a = nx.bfs_successors(G, 1)
	t2 = datetime.now()
	timedelta(0, 4, 316543)
	c = t2-t1
	print a
	print "breadth first search using networkx graph on network dataset karate took ", c.microseconds, " microseconds"

if __name__ == "__main__":
	networkx_test("karate.gml")
