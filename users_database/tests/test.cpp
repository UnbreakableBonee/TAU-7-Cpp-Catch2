#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../include/user_database.h"

TEST_CASE("User creation first test", "[User]")
{
	REQUIRE(user("test", 0).getPostCount() == 0);
}

