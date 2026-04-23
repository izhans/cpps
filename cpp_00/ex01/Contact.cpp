#include "Contact.hpp"

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
					std::string phoneNumber, std::string darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

Contact::~Contact() {}

std::string Contact::getFirstName()
{
	return this->_firstName;
}

std::string Contact::getLastName()
{
	return this->_lastName;
}

std::string Contact::getNickname()
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return this->_darkestSecret;
}
