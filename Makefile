#Makefile
#please dont delete the two types of compiler, they are different for ubuntu and ming.
#CC=g++-4.7 -std=c++0x
CC=g++
#TARGET=graph_test
TARGET=graph
OBJDIR=objs
OBJS=$(addprefix $(OBJDIR)/,graph.o graphtypes.o edge.o node.o unit_test.o)
SRCDIR=src
TESTDIR=test
INCDIR=include

VPATH=./src;./test

## Default rule executed
$(TARGET): $(OBJDIR) | $(OBJS)
	$(CC) -g -o $(TARGET) $(OBJS)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/edge.o: $(SRCDIR)/edge.cpp
	$(CC) -g -I$(INCDIR) -c -o $@ $^

$(OBJDIR)/node.o: $(SRCDIR)/node.cpp
	$(CC) -g -I$(INCDIR) -c -o $@ $^

$(OBJDIR)/unit_test.o: $(TESTDIR)/unit_test.cpp
	$(CC) -g -I$(INCDIR) -c -o $@ $^

$(OBJDIR)/graphtypes.o: $(SRCDIR)/graphtypes.cpp
	$(CC) -g -I$(INCDIR) -c -o $@ $^

$(OBJDIR)/graph.o: $(SRCDIR)/graph.cpp
	$(CC) -g -I$(INCDIR) -c -o $@ $^

clean:
	rm graph $(OBJS)

#node: node.o edge.o
#	$(CC) -g -o node node.o edge.o
