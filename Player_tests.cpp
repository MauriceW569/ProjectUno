#include <iostream>
#include <string>
#include <cassert>

#include "unit_test_framework.h"
#include "Card.h"
#include "Player.h"
#include "Pack.h"

using namespace std;

TEST(test_defualt_constructor) {
	Player player;
	ASSERT_EQUAL(player.get_name(), "");
}

TEST(test_custom_constructor) {
	Player player("Maurice");
	ASSERT_EQUAL(player.get_name(), "Maurice");
}

TEST_MAIN()