#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Intern intern;
	Bureaucrat bob("Bob", 1);

	// ============================================================
	// SHRUBBERY CREATION
	// ============================================================

	std::cout << "===== SHRUBBERY CREATION =====" << std::endl;

	AForm *shrub = intern.makeForm("shrubbery creation", "garden");

	std::cout << *shrub << std::endl;
	bob.signForm(*shrub);
	bob.executeForm(*shrub);
	delete shrub;

	// ============================================================
	// ROBOTOMY REQUEST
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== ROBOTOMY REQUEST =====" << std::endl;

	AForm *robot = intern.makeForm("robotomy request", "Bender");

	std::cout << *robot << std::endl;
	bob.signForm(*robot);
	bob.executeForm(*robot);
	delete robot;

	// ============================================================
	// PRESIDENTIAL PARDON
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== PRESIDENTIAL PARDON =====" << std::endl;

	AForm *pardon = intern.makeForm("presidential pardon", "Arthur Dent");

	std::cout << *pardon << std::endl;
	bob.signForm(*pardon);
	bob.executeForm(*pardon);
	delete pardon;

	// ============================================================
	// INVALID FORM
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== INVALID FORM =====" << std::endl;

	AForm *invalid = intern.makeForm("coffee making form", "Bob");

	if (invalid)
	{
		std::cout << "ERROR: invalid form was created" << std::endl;
		delete invalid;
	}
	else
		std::cout << "Correctly refused to create invalid form." << std::endl;

	std::cout << std::endl;
	std::cout << "===== TESTS FINISHED =====" << std::endl;

	return 0;
}
