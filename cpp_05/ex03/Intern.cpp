#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm *createShrubbery(const std::string &target);
AForm *createRobotomy(const std::string &target);
AForm *createPardon(const std::string &target);

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

static const std::string types[3] =
{
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

static AForm *(*formCreators[3])(const std::string &) =
{
	createShrubbery,
	createRobotomy,
	createPardon
};

AForm *Intern::makeForm(std::string type, std::string target) const
{
	for (int i = 0; i < 3; i++)
	{
		if (type == types[i])
		{
			std::cout << "Intern creates " << type << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Intern couldn't create " << type << std::endl;
	return NULL;
}

AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *createPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
