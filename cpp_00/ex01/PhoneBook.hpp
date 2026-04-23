#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
private:
	Contact _contacts[MAX_CONTACTS];
	int _next;
public:
	PhoneBook();
	~PhoneBook();

	void addContact(Contact contact);
	void listContacts();
	void listContact(int index);
	int getNext();
};

#endif
