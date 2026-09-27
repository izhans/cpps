#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	// ============================================================
	// CONSTRUCTION
	// ============================================================

	std::cout << "===== CONSTRUCTION =====" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;

		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ============================================================
	// SIGNING WITH INSUFFICIENT GRADE
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== SIGNING WITH INSUFFICIENT GRADE =====" << std::endl;

	Bureaucrat low("Low", 150);
	ShrubberyCreationForm shrub("garden");

	std::cout << low << std::endl;
	std::cout << shrub << std::endl;

	low.signForm(shrub);

	std::cout << shrub << std::endl;

	// ============================================================
	// SUCCESSFUL SIGNING
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== SUCCESSFUL SIGNING =====" << std::endl;

	Bureaucrat high("High", 1);

	std::cout << high << std::endl;

	high.signForm(shrub);

	std::cout << shrub << std::endl;

	// ============================================================
	// SIGNING ALREADY SIGNED FORM
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== SIGNING ALREADY SIGNED FORM =====" << std::endl;

	high.signForm(shrub);

	// ============================================================
	// EXECUTE UNSIGNED FORM
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== EXECUTE UNSIGNED FORM =====" << std::endl;

	RobotomyRequestForm unsignedRobot("Wall-E");

	try
	{
		high.executeForm(unsignedRobot);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ============================================================
	// EXECUTE WITH INSUFFICIENT GRADE
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== EXECUTE WITH INSUFFICIENT GRADE =====" << std::endl;

	Bureaucrat executor("Executor", 140);
	ShrubberyCreationForm shrub2("forest");

	executor.signForm(shrub2);
	executor.executeForm(shrub2);

	// ============================================================
	// SHRUBBERY CREATION
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== SHRUBBERY CREATION =====" << std::endl;

	ShrubberyCreationForm shrub3("home");

	high.signForm(shrub3);
	high.executeForm(shrub3);

	std::cout << "Check that home_shrubbery was created." << std::endl;

	// ============================================================
	// ROBOTOMY REQUEST
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== ROBOTOMY REQUEST =====" << std::endl;

	Bureaucrat robotBoss("RobotBoss", 1);
	RobotomyRequestForm robot("Marvin");

	robotBoss.signForm(robot);

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Attempt " << i + 1 << ":" << std::endl;
		robotBoss.executeForm(robot);
	}

	// ============================================================
	// PRESIDENTIAL PARDON
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== PRESIDENTIAL PARDON =====" << std::endl;

	PresidentialPardonForm pardon("Ford Prefect");

	robotBoss.signForm(pardon);
	robotBoss.executeForm(pardon);

	// ============================================================
	// COPY CONSTRUCTORS
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== COPY CONSTRUCTORS =====" << std::endl;

	ShrubberyCreationForm originalShrub("original");
	ShrubberyCreationForm copiedShrub(originalShrub);

	RobotomyRequestForm originalRobot("original");
	RobotomyRequestForm copiedRobot(originalRobot);

	PresidentialPardonForm originalPardon("original");
	PresidentialPardonForm copiedPardon(originalPardon);

	std::cout << "Original shrub: " << originalShrub << std::endl;
	std::cout << "Copied shrub: " << copiedShrub << std::endl;

	std::cout << "Original robot: " << originalRobot << std::endl;
	std::cout << "Copied robot: " << copiedRobot << std::endl;

	std::cout << "Original pardon: " << originalPardon << std::endl;
	std::cout << "Copied pardon: " << copiedPardon << std::endl;

	// ============================================================
	// POLYMORPHISM
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== POLYMORPHISM =====" << std::endl;

	AForm *forms[3];

	forms[0] = new ShrubberyCreationForm("polymorphism");
	forms[1] = new RobotomyRequestForm("robot");
	forms[2] = new PresidentialPardonForm("criminal");

	for (int i = 0; i < 3; i++)
	{
		std::cout << *forms[i] << std::endl;
		high.signForm(*forms[i]);
		high.executeForm(*forms[i]);
		delete forms[i];
	}

	// ============================================================
	// FINAL
	// ============================================================

	std::cout << std::endl;
	std::cout << "===== ALL TESTS FINISHED =====" << std::endl;

	return 0;
}
