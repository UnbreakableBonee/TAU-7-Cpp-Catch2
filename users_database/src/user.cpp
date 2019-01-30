#include "user.h"

User::User(): userNickname(""), userId(0), userPostCount(0)
{

}

User::User(std::string _nickname, size_t _id) : userNickname(_nickname), userId(_id), userPostCount(0)
{

}

User::User(std::string _nickname, size_t _id, size_t _postcount) : userNickname(_nickname), userId(_id), userPostCount(_postcount)
{

}

size_t User::getId() const
{
	return userId;
}

size_t User::getPostCount() const
{
	return userPostCount;
}

std::string User::getNickname() const
{
	return userNickname;
}

void User::setNickname(std::string _nickname)
{
	userNickname = _nickname;
}

bool User::operator==(const User &_user) const
{

	return
	(
		(this->userId == _user.userId) &&
		(this->userNickname == _user.userNickname) &&
		(this->userPostCount == _user.userPostCount)
	);
}
