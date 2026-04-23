#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

static void print_atrib(std::string str);

PhoneBook::PhoneBook()
{
	this->_next = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact contact)
{
	_contacts[_next % MAX_CONTACTS] = contact;
	_next++;
}

/**
 * @brief list all contacts
 */
void PhoneBook::listContacts()
{
	int n = (_next < MAX_CONTACTS) ? _next : MAX_CONTACTS;
	std::cout << "|Index     |First name|Last name |Nickname  |" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		print_atrib(_contacts[i].getFirstName());
		std::cout << '|';
		print_atrib(_contacts[i].getLastName());
		std::cout << '|';
		print_atrib(_contacts[i].getNickname());
		std::cout << '|' << std::endl;
	}
}

static void print_atrib(std::string str)
{
	std::cout.width(10);
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << str;
}

/**
 * @brief lists all the info of the contact at the given index
 */
void PhoneBook::listContact(int index)
{
	if (index < _next)
		_contacts[index].showFullInfo();
	else
		std::cout << "Contact cannot be found" << std::endl;
}

int PhoneBook::getNext()
{
	return _next;
}

