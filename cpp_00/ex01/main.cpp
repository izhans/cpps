#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static void print_menu();
static void addContact();
static void searchContact();
static bool getStr(std::string askFor, std::string *var);

PhoneBook pb;

int main(void)
{
	std::string opt;
	pb = PhoneBook();

	do
	{
		if (std::cin.eof())
			break;
		
		print_menu();

		if (!getStr("Option:", &opt) || "EXIT" == opt)
            break;
		else if ("ADD" == opt)
			addContact();
		else if ("SEARCH" == opt)
			searchContact();
		else
			std::cout << "Invalid option " << opt << std::endl;
	} while (true);
	
	return 0;
}

static void print_menu()
{
	std::cout << "Select one option:" << std::endl;
	std::cout << "\tADD" << std::endl;
	std::cout << "\tSEARCH" << std::endl;
	std::cout << "\tEXIT" << std::endl;
}

static void addContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter the contact details. Details cannot be empty" << std::endl;

	if (!getStr("First Name", &firstName) 
		|| !getStr("Last Name", &lastName)
		|| !getStr("Nickname", &nickname)
		|| !getStr("Phone number", &phoneNumber)
		|| !getStr("Darkest secret", &darkestSecret))
		return;
	
	Contact c = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	pb.addContact(c);
}

static void searchContact()
{
	if (pb.getNext() == 0)
	{
		std::cout << "There are no contacts" << std::endl;
		return;
	}
	
	pb.listContacts();
	
	std::string c;
	if (!getStr("Which contact do you wanna see?", &c))
		return;

	if (c.length() != 1 || c.find_first_of("0123456789") != 0)
	{
		std::cout << "Not showing any contact" << std::endl;
		return;
	}

	int n = c[0] - '0';
	pb.listContact(n);
}

static bool getStr(std::string askFor, std::string *var)
{
	do
	{
		std::cout << askFor << std::endl;
		std::cout << "> ";
		std::getline(std::cin, *var);
		
		if (std::cin.eof())
			return false;
	} while (var->empty());
	
	return true;
}
