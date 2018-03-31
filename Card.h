#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
	static constexpr const char* const COLOR_YELLOW = "Yellow";
	static constexpr const char* const COLOR_BLUE = "Blue";
	static constexpr const char* const COLOR_GREEN = "Green";
	static constexpr const char* const COLOR_RED = "Red";
	static constexpr const char* const COLOR_NONE = "None";	

	static constexpr const char* const RANK_ONE = "One";
	static constexpr const char* const RANK_TWO = "Two";
	static constexpr const char* const RANK_THREE = "Three";
	static constexpr const char* const RANK_FOUR = "Four";
	static constexpr const char* const RANK_FIVE = "Five";
	static constexpr const char* const RANK_SIX = "Six";
	static constexpr const char* const RANK_SEVEN = "Seven";
	static constexpr const char* const RANK_EIGHT = "Eight";
	static constexpr const char* const RANK_NINE = "Nine";
	static constexpr const char* const RANK_SKIP = "Skip";
	static constexpr const char* const RANK_DRAW_TWO = "Draw Two";
	static constexpr const char* const RANK_DRAW_FOUR = "Draw Four";
	static constexpr const char* const RANK_REVERSE = "Reverse";
	static constexpr const char* const RANK_WILD = "Wild";

	Card() 
		: rank(RANK_ONE), color(COLOR_YELLOW) {}

	Card(const string rank_in, const string color_in)
		: rank(rank_in), color(color_in) {}

	const string get_rank() const {
		return rank;
	}
	const string get_color() const {
		return color;
	}
	bool operator==(const Card rhs) const {
		return (rank == rhs.rank) && (color == rhs.color);
	}
	bool operator!=(const Card rhs) const {
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