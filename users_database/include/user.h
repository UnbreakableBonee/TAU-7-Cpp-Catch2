#pragma once

#include <string>

class user
{

	private:
		size_t userId, userPostCount;

		std::string userNickname;

	protected:


	public:
		user(std::string, size_t);

		size_t getId();
		size_t getPostCount();

		std::string getNickname();
		void setNickname();
};
