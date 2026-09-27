#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery Creation Form", 145, 137, "fake_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::performAction() const
{
	std::ofstream file((getTarget() + "_shrubbery").c_str());

	if (!file.is_open())
		throw std::runtime_error("Could not create shrubbery file");

	file << "       /\\\n";
	file << "      /  \\\n";
	file << "     /++++\\\n";
	file << "    /  /\\  \\\n";
	file << "   /  /  \\  \\\n";
	file << "  /  /++++\\  \\\n";
	file << " /__/______\\__\\\n";

	file.close();
}
