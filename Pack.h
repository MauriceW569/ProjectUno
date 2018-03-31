#ifndef PACK_H
#define PACK_H

#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Card.h"

using namespace std;

class Pack {
public:
	Pack() {}
	~Pack() {}

	const int size() {
		return pack.size();
	}
	void shuffle() {
		srand(time(NULL));
		for (int times = 0; times < 7; times++) {
			for (int i = 0; i < size(); i++) {
				int r = i + (rand() % (size() - i));
				Card *temp = pack[i];
				pack[i] = pack[r];
				pack[r] = temp; 
			}
		}
		return;
	}
	Card *get_top_card() {
		return pack[size() - 1];
	}
	std::ostream& operator<<(std::ostream &os) {
		for (int i = 0; i < size(); i++) {
			os << (i + 1) << ": ";
			os << pack[i] << endl;
		}
		return os;
	}
	Card deal_card() {
		Card *card = get_top_card();
		pack.pop_back();
		return *card;
	}

private:
	vector<Card*> pack;
};

#endif /* PACK */