#Makefile
#please dont delete the two types of compiler, they are different for ubuntu and ming.
CXX=g++-4.7 -std=c++11
#CXX=g++
#TARGET=graph_test
TARGET=perf
#TARGET=graph
OBJDIR=objs
OBJS=$(addprefix $(OBJDIR)/,graph.o graphs.o edge.o node.o unit_test.o path.o topologicalsort.o depthfirsttraversal.o breadthfirsttraversal.o attribute_service.o bipartite.o min_spanning_tree.o utils.o perf.o)
GMLPARSER_DIR=../../gml-parser
GMLPARSER_OBJS=$(addprefix $(GMLPARSER_DIR)/,gml_parser.o gml_scanner.o)
SRCDIR=../src
TESTDIR=../test
INCDIR=../include
GMLINCDIR=../../gml-parser
BOOSTINCDIR=../../boost_1_52_0
BOOSTLIBPATH=../../boost_1_52_0/stage/lib

VPATH=./src;./test

## Default rule executed

#$(TARGET): $(OBJDIR) | $(GMLPARSER_OBJS) $(OBJS)
#	$(CXX) -g -o $(TARGET) $(GMLPARSER_OBJS) $(OBJS)

$(TARGET): $(OBJDIR) | $(GMLPARSER_OBJS) $(OBJS)
	$(CXX) -g -o $(TARGET) $(GMLPARSER_OBJS) $(OBJS) -L$(BOOSTLIBPATH) -lboost_graph -lboost_regex

$(OBJDIR):
	mkdir $(OBJDIR)

$(GMLPARSER_DIR)/gml_scanner.o: $(GMLPARSER_DIR)/gml_scanner.c
	$(CXX) -g -Wno-write-strings -I$(GMLINCDIR) -c -o $@ $^

$(GMLPARSER_DIR)/gml_parser.o: $(GMLPARSER_DIR)/gml_parser.c
	$(CXX) -g -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/edge.o: $(SRCDIR)/edge.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/node.o: $(SRCDIR)/node.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/unit_test.o: $(TESTDIR)/unit_test.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/perf.o: $(TESTDIR)/perf.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -I$(BOOSTINCDIR) -c -o $@ $^

$(OBJDIR)/graphs.o: $(SRCDIR)/graphs.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/topologicalsort.o: $(SRCDIR)/topologicalsort.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/depthfirsttraversal.o: $(SRCDIR)/depthfirsttraversal.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/breadthfirsttraversal.o: $(SRCDIR)/breadthfirsttraversal.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/attribute_service.o: $(SRCDIR)/attribute_service.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/path.o: $(SRCDIR)/path.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/bipartite.o: $(SRCDIR)/bipartite.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/utils.o: $(SRCDIR)/utils.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/min_spanning_tree.o: $(SRCDIR)/min_spanning_tree.cpp
	$(CXX) -g -I$(INCDIR) -c -o $@ $^

$(OBJDIR)/graph.o: $(SRCDIR)/graph.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

clean:
	rm $(TARGET) $(OBJS)

#node: node.o edge.o
#	$(CXX) -g -o node node.o edge.o
