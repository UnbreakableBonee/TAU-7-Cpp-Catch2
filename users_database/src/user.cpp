#include "user.h"

user::user(std::string _nickname, size_t _id) : userNickname(_nickname), userId(_id), userPostCount(0)
{

}

size_t user::getId()
{
	return userId;
}

size_t user::getPostCount()
{
	return userPostCount;
}

std::string user::getNickname()
{
	return userNickname;
}

void user::setNickname(std::string _nickname)
{
	userNickname = _nickname;
}
