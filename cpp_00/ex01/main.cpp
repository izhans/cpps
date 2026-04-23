#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static void print_menu();
static Contact createContact();
static bool getStr(std::string askFor, std::string *var);

int main(void)
{
	std::string opt;
	PhoneBook pb = PhoneBook();

	do
	{
		print_menu();
		if (!getStr("Option:", &opt) || "EXIT" == opt)
            break;
		else if ("ADD" == opt)
		{
			Contact c = createContact();
			pb.addContact(c);
		}
		else if ("SEARCH" == opt)
		{
			if (pb.getNext() == 0)
			{
				std::cout << "There are no contacts" << std::endl;
				continue;
			}
			
			pb.listContacts();
			
			std::string c;
			getStr("Which contact do you wanna see?", &c);

			if (c.length() != 1 || c.find_first_of("0123456789") != 0)
			{
				std::cout << "Not showing any contact" << std::endl;
				continue;
			}

			int n = c[0] - '0';
			pb.listContact(n);
		}
		else
			std::cout << "Invalid option" << opt << std::endl;
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

static Contact createContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter the contact details. Details cannot be empty" << std::endl;

	getStr("First Name", &firstName);
	getStr("Last Name", &lastName);
	getStr("Nickname", &nickname);
	getStr("Phone number", &phoneNumber);
	getStr("Darkest secret", &darkestSecret);

	return Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

static bool getStr(std::string askFor, std::string *var)
{
	if (std::cin.eof())
		return false;
	do
	{
		std::cout << askFor << std::endl;
		std::getline(std::cin, *var);
	} while (var->empty());
	

	if (std::cin.fail())
		return false;
	return true;
}
