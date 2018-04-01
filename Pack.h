#ifndef PACK_H
#define PACK_H

#include <array>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "Card.h"

using namespace std;

class Pack {
public:
	Pack() {}
	~Pack() {}

	const int size() const {
		return cards.size();
	}
	void shuffle() {
		srand(time(NULL));
		for (int times = 0; times < 7; times++) {
			for (int i = 0; i < size(); i++) {
				int r = i + (rand() % (size() - i));
				Card *temp = cards[i];
				cards[i] = cards[r];
				cards[r] = temp; 
			}
		}
		return;
	}
	Card *get_top_card() {
		return cards[size() - 1];
	}
	std::ostream& operator<<(std::ostream &os) {
		for (int i = 0; i < size(); i++) {
			os << (i + 1) << ": ";
			os << cards[i] << endl;
		}
		return os;
	}
	Card deal_card() {
		Card *card = get_top_card();
		cards.pop_back();
		return *card;
	}

private:
	static const int PACK_SIZE = 108;
	std::array<Card*, PACK_SIZE> cards;
	int next;

	void add_all_cards() {
		
	}

};

#endif /* PACK */