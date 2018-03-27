#include <iostream>
#include <fstream>
#include <string>

#include "Pack.h"
#include "Card.h"

using namespace std;

int main() {
	ifstream color_in;
	ifstream rank_in;

	color_in.open("card_colors.txt");
	rank_in.open("card_ranks.txt");

	Pack pack(color_in, rank_in);
	pack.print_pack(cout);
	
	return 0;
}