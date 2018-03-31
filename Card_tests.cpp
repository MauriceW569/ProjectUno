#include <iostream>
#include <string>
#include <cassert>

#include "unit_test_framework.h"
#include "Card.h"

using namespace std;

TEST(test_default_constructor) {
	Card card;
	ASSERT_EQUAL(card.get_color(), Card::COLOR_YELLOW);
	ASSERT_EQUAL(card.get_rank(), Card::RANK_ONE);
}

TEST(test_custom_constructor) {
	Card card(Card::RANK_DRAW_FOUR, Card::COLOR_BLUE);
	ASSERT_EQUAL(card.get_color(), Card::COLOR_BLUE);
	ASSERT_EQUAL(card.get_rank(), Card::RANK_DRAW_FOUR);
}

TEST(test_get_rank) {
	Card card;
	ASSERT_EQUAL(card.get_rank(), Card::RANK_ONE);
}

TEST_MAIN()