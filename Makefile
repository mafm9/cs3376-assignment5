SHELL = /bin/sh
FLAGS = -Wall
CC = g++

all:    p1 p2 dynpipe

p1:     TwoPipesTwoChildren.cpp
	$(CC) $(FLAGS) -g -o $@ TwoPipesTwoChildren.cpp

p2:     TwoPipesThreeChildren.cpp
	$(CC) $(FLAGS) -g -o $@ TwoPipesThreeChildren.cpp

dynpipe:     dynpipe.cpp
	$(CC) $(Flags) -g -o $@ dynpipe.cpp

clean:
	rm p1 p2 dynpipe
