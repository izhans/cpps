#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shurberry", 145, 137, "fake_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target)
: AForm(name, 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
if (this != &other)
		AForm::operator=(other);
	return *this;
}
