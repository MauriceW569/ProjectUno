
GameFLAGS = -Wall -Werror -pedantic --std=c++11
debug = -g3
optimize = -O3
optimize_debug = -O3 -g3

game:
	g++ $(GameFLAGS) $(optimize_debug) Pack.h Card.h game.cpp -o game.exe

game_test:
	g++ $(GameFLAGS) $(optimize) Pack.h Card.h game.cpp -o game.exe

game_debug:
	g++ $(GameFLAGS) $(debug) Pack.h Card.h game.cpp -o game.exe

.PHONY: clean
clean:
	rm -rv *.exe