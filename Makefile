#Makefile
#please dont delete the two types of compiler, they are different for ubuntu and ming.
CC=gcc
#CXX=g++-4.7 -std=c++11
CXX=g++
TARGET=graph_test
#TARGET=graph
OBJDIR=objs
OBJS=$(addprefix $(OBJDIR)/,graph.o graphs.o edge.o node.o unit_test.o path.o topologicalsort.o depthfirsttraversal.o breadthfirsttraversal.o attribute_service.o bipartite.o utils.o)
GMLPARSER_DIR=../gml-parser
GMLPARSER_OBJS=$(addprefix $(GMLPARSER_DIR)/,gml_parser.o gml_scanner.o)
SRCDIR=src
TESTDIR=test
INCDIR=include
GMLINCDIR=../gml-parser

VPATH=./src;./test

## Default rule executed
$(TARGET): $(OBJDIR) | $(GMLPARSER_OBJS) $(OBJS)
	$(CXX) -g -o $(TARGET) $(GMLPARSER_OBJS) $(OBJS)

$(OBJDIR):
	mkdir $(OBJDIR)

$(GMLPARSER_DIR)/gml_scanner.o: $(GMLPARSER_DIR)/gml_scanner.c
	$(CXX) -g -I$(GMLINCDIR) -c -o $@ $^

$(GMLPARSER_DIR)/gml_parser.o: $(GMLPARSER_DIR)/gml_parser.c
	$(CXX) -g -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/edge.o: $(SRCDIR)/edge.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/node.o: $(SRCDIR)/node.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

$(OBJDIR)/unit_test.o: $(TESTDIR)/unit_test.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

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

$(OBJDIR)/graph.o: $(SRCDIR)/graph.cpp
	$(CXX) -g -I$(INCDIR) -I$(GMLINCDIR) -c -o $@ $^

clean:
	rm $(TARGET) $(OBJS)

#node: node.o edge.o
#	$(CC) -g -o node node.o edge.o
