CXXFLAGS=-std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic -ggdb

all: ladder_main dijkstras_main

ladder_main: src/ladder.o
	g++ $(CXXFLAGS) src/ladder_main.cpp src/ladder.o -o ladder_main

src/ladder.o:
	g++ $(CXXFLAGS) -c src/ladder.cpp -o src/ladder.o

dijkstras_main: src/dijkstras.o
	g++ $(CXXFLAGS) src/dijkstras_main.cpp src/dijkstras.o -o dijkstras_main

src/dijkstras.o:
	g++ $(CXXFLAGS) -c src/dijkstras.cpp -o src/dijkstras.o

clean:
	rm -rf main src/*.o