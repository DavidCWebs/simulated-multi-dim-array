OBJECTS := $(wildcard *.cpp)
SOURCES := $(wildcard *.cpp) $(wildcard *.hpp)
main: $(SOURCES)
	g++ -W -Wall -std=c++11 -o bin/main $(OBJECTS)

c3d: three-d.c
	cc -W -Wall -o bin/c3d three-d.c
