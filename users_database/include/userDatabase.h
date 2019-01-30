#pragma once

#include <stdexcept>

#include "user.h"

#include <map>
#include <list>

class UserDatabase
{
	private:

	protected:
		size_t userIdCounter;

		std::map<size_t, User> userStorage;


	public:
		UserDatabase();
		std::list<User> getAll();

		User getUser(size_t);

		void addUser(User);
		void eraseUser(size_t);

};
