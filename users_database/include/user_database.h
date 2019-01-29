#pragma once

#include "user.h"

#include <map>

class user_database
{
	private:
		size_t userIdCounter;

		std::map<size_t, user> userStorage;

	protected:


	public:
		user_database();

};
