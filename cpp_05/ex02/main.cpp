#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "===== FORM NOT SIGNED TEST =====" << std::endl;

	Bureaucrat bob("Bob", 1);
	ShrubberyCreationForm form("garden");

	std::cout << "Form before execution: " << form << std::endl;

	try
	{
		std::cout << "Trying to execute unsigned form..." << std::endl;
		form.execute(bob);
		std::cout << "ERROR: exception was not thrown" << std::endl;
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cout << "Caught FormNotSignedException: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught unexpected exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== SIGN AND EXECUTE =====" << std::endl;

	try
	{
		form.beSigned(bob);
		std::cout << "Form signed successfully." << std::endl;

		form.execute(bob);
		std::cout << "Form executed successfully." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
