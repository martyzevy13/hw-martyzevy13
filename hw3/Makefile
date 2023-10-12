# You can add on to this file but you are not allowed to change the setup
# provided below or the location of this file. If you do, you will fail
# the auto-graded tests and likely receive a harsh penalty.

CXX = g++
CPPFLAGS = -g -Wall -std=c++11

all: doublet 

doublet: doublet.cpp MinHeap.h
	$(CXX) $(CPPFLAGS) $^ -o $@

# ADD WHATEVER ELSE YOU NEED HERE
.PHONY: clean
clean:
	rm -f *.o doublet
