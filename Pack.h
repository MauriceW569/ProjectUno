#ifndef PACK_H
#define PACK_H

#include <string>
#include <vector>
#include <fstream>

#include "Card.h"

using namespace std;

class Pack {
	public:
		Pack(ifstream &colors, ifstream &ranks) {
			string color_input, rank_input;
			
			while (colors >> color_input)
				color_vec.push_back(color_input);
			while (ranks >> rank_input)
				rank_vec.push_back(rank_input);
			
			for (int c = 0; c < int(color_vec.size()); c++) {
				for (int r = 0; r < int(rank_vec.size()); r++) {
					Color color(color_vec[c]);
					Card *card = new Card(color, rank_vec[r]);
					pack.push_back(card);
				}
			}
		}

		~Pack() {}

		const int size() {
			return pack.size();
		}

		void shuffle() {

		}

		void print_pack(std::ostream& os) {
			for (int i = 0; i < size(); i++) {
				os << pack[i]->get_color();
				os << " ";
				os << pack[i]->get_function();
				os << endl;
			}
		}

	private:
		vector<string> rank_vec;
		vector<string> color_vec;
		vector<Card*> pack;
};

#endif /* PACK */