UNOFLAGS = -Wall -Werror -pedantic --std=c++11
debug = -O3

Files = Pack.h Pack_tests.cpp Card.h Card_tests.cpp \
	Player.h Player_tests.cpp unit_test_framework.h \
	unit_test_framework.cpp

Pack_srcs = $(wildcard Pack*.[^exe]*) unit_test_framework.h \
	unit_test_framework.cpp
Card_srcs = $(wildcard Card*.[^exe]*) unit_test_framework.h \
	unit_test_framework.cpp
Player_srcs = $(wildcard Player*.[^exe]*) unit_test_framework.h \
	unit_test_framework.cpp

all: Player_tests.exe Card_tests.exe Pack_tests.exe

Player_tests.exe: $(Player_srcs)
	g++ $(UNOFLAGS) $(debug) $(Player_srcs) -o $@

Card_tests.exe: $(Card_srcs)
	g++ $(UNOFLAGS) $(debug) $(Card_srcs) -o $@

Pack_tests.exe: $(Pack_srcs)
	g++ $(UNOFLAGS) $(debug) $(Pack_srcs) -o $@

test: Player_tests.exe Pack_tests.exe Card_tests.exe
	./Player_tests.exe 
	./Card_tests.exe
	./Pack_tests.exe

backup:
	@if [ ! -d .__uno_cache__ ]; then \
		mkdir -v .__uno_cache__/ & fi;
	@rm -rfv .__uno_cache__/* &
	@cp -v *.[^exe]* .__uno_cache__ &

clean:
	rm -rfv *.exe

debug: clean
debug: debug=-g3
debug: test

.PHONY: clean debug

info: help
help:
	@printf "Usage: make [<uno_targets>] ...\n  \
	These are Project Uno targets used in various situations\n\n  \
	all [default]		Makes all executables.\n  \
	Player_tests.exe	Makes Player_tests.exe target executable.\n  \
	Card_tests.exe	Makes Card_tests.exe target executable.\n  \
	Pack_tests.exe	Makes Pack_tests.exe target executable.\n  \
	test			Makes all targets and runs test executables.\n  \
	backup		Creates backup folder for Uno files.\n  \
	clean			Clears all build output.\n  \
	debug			Adds debugging flag to compilation.\n  \
	help, info		Displays this message.\n\n\
	Report all bugs to email <mcwas@umich.edu>"

.SUFFIXES: