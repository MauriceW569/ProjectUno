#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Pack.h"

struct Player {
public:
	Player(string name_in) : name(name_in) {}
	~Player() {}

	const int hand_size() {
		return hand.size();
	}
	void deal(Pack *pack, vector<Player> players) {
		for (int i = 0; i < 5; i++)
			for (int i = 0; i < int(players.size()); i++)
				players[i].grab_card(*pack);
		return;
	}
	void play_card(Card card) {}
	void grab_card(Pack &pack) {}

private:
	vector<Card> hand;
	string name;
};

struct Group {
public:
	Group() : player_count(0) {}
	Group(int player_count_in, vector<string> names)
		: group_names(names), player_count(player_count_in) {
		for (int i = 0; i < player_count; i++)
			group.push_back(new Player(group_names[i]));
	}

private:
	vector<Player*> group;
	vector<string> group_names;
	int player_count;
};


#endif