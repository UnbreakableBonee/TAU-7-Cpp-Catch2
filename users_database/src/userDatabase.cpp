#include "userDatabase.h"

UserDatabase::UserDatabase() : userIdCounter(0)
{

}

std::list<User> UserDatabase::getAll()
{
	std::list<User> listOfUsers;

    for(auto u : userStorage)
	{
		listOfUsers.push_back(u.second);
	}

	return listOfUsers;
}

void UserDatabase::addUser(User _new)
{
	userStorage[_new.getId()] = _new;
}

User UserDatabase::getUser(size_t _id)
{
	if (userStorage.count(_id) == 0)
	{
		throw std::out_of_range("user was not found");
	}

	return userStorage.at(_id);
}

void UserDatabase::eraseUser(size_t _id)
{

	if (userStorage.count(_id) == 0)
	{
		throw std::out_of_range("user was not found");
	}

	userStorage.erase(_id);
}
