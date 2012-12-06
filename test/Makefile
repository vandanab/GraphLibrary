#Makefile
#please dont delete the two types of compiler, they are different for ubuntu and ming.
CXX=g++-4.7 -std=c++11
#CXX=g++
#TARGET=graph_test
CFLAGS=-O3
TARGET=perf
#TARGET=graph
OBJDIR=objs
#OBJS=$(addprefix $(OBJDIR)/,graph.o graphs.o edge.o node.o unit_test.o path.o topologicalsort.o depthfirsttraversal.o breadthfirsttraversal.o attribute_service.o bipartite.o min_spanning_tree.o utils.o perf.o)
OBJS=$(addprefix $(OBJDIR)/,graph.o graphs.o edge.o node.o breadthfirsttraversal.o attribute_service.o utils.o perf.o)
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

$(TARGET): $(OBJDIR) | $(GMLPARSER_OBJS) $(OBJS)
	$(CXX) -g -o $(TARGET) $(GMLPARSER_OBJS) $(OBJS) -L$(BOOSTLIBPATH) -lboost_graph -lboost_regex

$(OBJDIR):
	mkdir $(OBJDIR)

$(GMLPARSER_DIR)/gml_scanner.o: $(GMLPARSER_DIR)/gml_scanner.c
	#$(CXX) -g -Wno-write-strings -I$(GMLINCDIR) -c -o $@ $^
	$(CXX) -g -Wno-write-strings -I$(GMLINCDIR) -c $(CFLAGS) -o $@ $^

$(GMLPARSER_DIR)/gml_parser.o: $(GMLPARSER_DIR)/gml_parser.c
	#$(CXX) -g -I$(GMLINCDIR) -c -o $@ $^
	$(CXX) -g -I$(GMLINCDIR) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/edge.o: $(SRCDIR)/edge.cpp
	#$(CXX) -g -I$(INCDIR) -c -o $@ $^
	$(CXX) -g -I$(INCDIR) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/node.o: $(SRCDIR)/node.cpp
	#$(CXX) -g -I$(INCDIR) -c -o $@ $^
	$(CXX) -g -I$(INCDIR) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/perf.o: $(TESTDIR)/perf.cpp
	#$(CXX) -g -I$(INCDIR) -I$(BOOSTINCDIR) -c -o $@ $^
	$(CXX) -g -I$(INCDIR) -I$(BOOSTINCDIR) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/graphs.o: $(SRCDIR)/graphs.cpp
	#$(CXX) -g -I$(INCDIR) -c -o $@ $^
	$(CXX) -g -I$(INCDIR) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/breadthfirsttraversal.o: $(SRCDIR)/breadthfirsttraversal.cpp
	#$(CXX) -g -I$(INCDIR) -c -o $@ $^
	$(CXX) -g -I$(INCDIR) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/attribute_service.o: $(SRCDIR)/attribute_service.cpp
	#$(CXX) -g -I$(INCDIR) -c -o $@ $^
	$(CXX) -g -I$(INCDIR) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/utils.o: $(SRCDIR)/utils.cpp
	#$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/graph.o: $(SRCDIR)/graph.cpp
	#$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c $(CFLAGS) -o $@ $^

clean:
	rm $(TARGET) $(OBJS)

#node: node.o edge.o
#	$(CXX) -g -o node node.o edge.o
