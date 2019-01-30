#pragma once

#include <string>

class User
{

	private:
		size_t userId, userPostCount;

		std::string userNickname;

	protected:


	public:
		User();
		User(std::string, size_t);
		User(std::string, size_t, size_t);

		size_t getId() const;
		size_t getPostCount() const;

		std::string getNickname() const;
		void setNickname(std::string);

		bool operator==(const User&) const;
};
