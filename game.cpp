#include <iostream>
#include <fstream>
#include <string>

#include "Pack.h"
#include "Card.h"

using namespace std;

int main() {
	Pack pack;
	pack.print_pack(cout);
	pack.shuffle();
	pack.print_pack(cout);
	return 0;
}