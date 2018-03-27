#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

struct Color {
	Color(string color_in) : color(color_in) {}
	
	const string colors[4] = {"RED", "BLUE", "GREEN", "YELLOW"};
	string color;
};

class Card {
	public:
		Card(Color color_in, string function_in)
		: color(color_in), function(function_in) {}

		const string get_color() {
			return color.color;
		}
		const string get_function() {
			return function;
		}
	
	private:
		Color color;
		string function;
};

#endif /* CARD_H */