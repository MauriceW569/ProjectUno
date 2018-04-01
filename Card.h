#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
	static constexpr const char* const YELLOW = "Yellow";
	static constexpr const char* const BLUE = "Blue";
	static constexpr const char* const GREEN = "Green";
	static constexpr const char* const RED = "Red";
	
	static constexpr const char* const WILD = "Wild";	
	static constexpr const char* const SKIP = "Skip";
	static constexpr const char* const DRAW_TWO = "Draw Two";
	static constexpr const char* const DRAW_FOUR = "Draw Four";
	static constexpr const char* const REVERSE = "Reverse";

	static constexpr const char* const ZERO = "Zero";
	static constexpr const char* const ONE = "One";
	static constexpr const char* const TWO = "Two";
	static constexpr const char* const THREE = "Three";
	static constexpr const char* const FOUR = "Four";
	static constexpr const char* const FIVE = "Five";
	static constexpr const char* const SIX = "Six";
	static constexpr const char* const SEVEN = "Seven";
	static constexpr const char* const EIGHT = "Eight";
	static constexpr const char* const NINE = "Nine";

	Card() : rank(ONE), color(YELLOW) {}

	Card(const string rank_in) : rank(rank_in), color("") {}

	Card(const string rank_in, const string color_in)
		: rank(rank_in), color(color_in) {}

	// --- Getters ---
	const string get_rank() const {
		return rank;
	}
	const string get_color() const {
		return color;
	}

	// --- Operators ---
	const bool operator==(const Card rhs) const {
		return (rank == rhs.rank) && (color == rhs.color);
	}
	const bool operator!=(const Card rhs) const {
		return (rank != rhs.rank) || (color != rhs.color);
	}
	friend ostream& operator<<(ostream &os, const Card &card) {
		os << card.color << " " << card.rank;
		return os;
	}
	
private:
	string rank;
	string color;
};

#endif /* CARD_H */