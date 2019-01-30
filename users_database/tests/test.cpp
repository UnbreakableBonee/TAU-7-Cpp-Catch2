#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../include/userDatabase.h"

class UserDatabaseInh : public UserDatabase
{
  public:
    void setDatabase(std::map<size_t, User> _database)
    {
        userStorage = _database;
    };

	std::map<size_t, User> getDatabase()
    {
        return userStorage;
    };
};

TEST_CASE("Database tests - getting users","[testDatabase][crud][getAll]")
{

	SECTION("Database creation.")
    {
        REQUIRE_NOTHROW([]() {UserDatabase testDatabase; return testDatabase; }());
    }

    SECTION("Database - getAll() on empty database should return empty list of users.")
    {
		UserDatabase testDatabase;

		std::list<User> resultList = testDatabase.getAll();

        REQUIRE(resultList.size() == 0);
    }

	SECTION("Database - getAll() should return correct database.")
    {

        UserDatabaseInh testDatabase;

        std::map<size_t, User> expectedMap = {
        	{0, User("UserTestOne", 0)},
        	{1, User("UserTestTwo", 1)},
        	{2, User("UserTestThree", 2)}
        };

        testDatabase.setDatabase(expectedMap);

        std::list<User> expectedList;

        for (auto u : expectedMap)
        {
            expectedList.push_back(u.second);
        }

        REQUIRE(testDatabase.getAll() == expectedList);
    }

}

SCENARIO("Database tests - other operations", "[testDatabase][crud]")
{
	using namespace Catch::Matchers;
	GIVEN("The database is available with mocked data")
    {
        UserDatabaseInh testDatabase;
        std::map<size_t, User> testDatabaseStorage = {
        	{1, User("TestUser1", 1)},
        	{2, User("TestUser2", 2)}
		};

        testDatabase.setDatabase(testDatabaseStorage);

        std::list<User> testList;

        for (auto u : testDatabase.getDatabase())
		{
			testList.push_back(u.second);
		}

        CHECK(testDatabase.getAll() == testList);

        WHEN("User was added to database")
        {
            REQUIRE_NOTHROW(testDatabase.addUser({"TestUser3", 3}));
            THEN("the database should contain TestUser3 record")
            {
                testList.push_back({"TestUser3", 3});
                CHECK(testDatabase.getAll() == testList);
            }
        }

        WHEN("One element was removed")
        {
            REQUIRE_NOTHROW(testDatabase.eraseUser(1));
            THEN("the database should contain TestUser3 record")
            {
                testList.pop_front();
                CHECK(testDatabase.getAll() == testList);
            }
        }

        WHEN("We try to remove nonexistent user")
        {
            THEN("exception should be thrown")
            {
                REQUIRE_THROWS_AS(testDatabase.eraseUser(100), std::out_of_range);
            }
            THEN("exception should contain correct text")
            {
				REQUIRE_THROWS_WITH(testDatabase.eraseUser(100),
                     EndsWith( "not found" ) ||  StartsWith( "user" ));
            }
        }

		WHEN("We try to remove existing user")
        {
        	testList.pop_front();
            THEN("no exception should be thrown during removal")
            {
                REQUIRE_NOTHROW(testDatabase.eraseUser(1));
            }

            THEN("database shouldn't contain user we just removed")
            {
            	testDatabase.eraseUser(1);
				CHECK(testDatabase.getAll() == testList);
            }
        }
    }
}
