
UNOFLAGS = -Wall -Werror -pedantic --std=c++11
debug = -g3
optimize = -O3
optimize_debug = -O3 -g3

Pack = Pack.h Pack_tests.cpp unit_test_framework.h \
	unit_test_framework.cpp
Card = Card.h Card_tests.cpp unit_test_framework.h \
	unit_test_framework.cpp
Player = Player.h Player_tests.cpp unit_test_framework.h \
	unit_test_framework.cpp

Player_tests.exe: $(Player)
	g++ $(UNOFLAGS) $(optimize) $(Player) -o Player_tests.exe

Card_tests.exe: $(Card)
	g++ $(UNOFLAGS) $(optimize) $(Card) -o Card_tests.exe

Pack_tests.exe: $(Pack)
	g++ $(UNOFLAGS) $(optimize) $(Pack) -o Pack_tests.exe

.PHONY: clean debug
clean:
	@rm -rfv *.exe