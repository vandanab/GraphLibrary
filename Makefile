#Makefile
CC=g++-4.7 -std=c++11
TARGET=graph
OBJDIR=objs
OBJS=$(addprefix $(OBJDIR)/,graph.o edge.o node.o)
SRCDIR=src
INCDIR=include

VPATH=./src

## Default rule executed
$(TARGET): $(OBJS) | $(OBJDIR)
	$(CC) -g -o $(TARGET) $(OBJS)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/edge.o: $(SRCDIR)/edge.cpp
	$(CC) -g -I$(INCDIR) -c -o $@ $^ 

$(OBJDIR)/node.o: $(SRCDIR)/node.cpp
	$(CC) -g -I$(INCDIR) -c -o $@ $^ 

$(OBJDIR)/graph.o: $(SRCDIR)/graph.cpp
	$(CC) -g -I$(INCDIR) -c -o $@ $^ 

clean:
	rm graph $(OBJS)

#node: node.o edge.o
#	$(CC) -g -o node node.o edge.o
