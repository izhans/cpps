#include "Bureaucrat.hpp"

int main()
{
	std::cout << "===== CONSTRUCTORS =====" << std::endl;

	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
		std::cout << "Name: " << a.getName() << std::endl;
		std::cout << "Grade: " << a.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== INVALID CONSTRUCTORS =====" << std::endl;

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== INCREMENT =====" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 3);
		std::cout << "Before: " << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After:  " << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After:  " << bob << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "This should not catch anything: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== INCREMENT AT GRADE 1 =====" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		std::cout << "Before: " << boss << std::endl;
		boss.incrementGrade();
		std::cout << "After:  " << boss << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== DECREMENT =====" << std::endl;

	try
	{
		Bureaucrat charlie("Charlie", 148);
		std::cout << "Before: " << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After:  " << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After:  " << charlie << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "This should not catch anything: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== DECREMENT AT GRADE 150 =====" << std::endl;

	try
	{
		Bureaucrat worker("Worker", 150);
		std::cout << "Before: " << worker << std::endl;
		worker.decrementGrade();
		std::cout << "After:  " << worker << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== OPERATOR << =====" << std::endl;

	try
	{
		Bureaucrat alice("Alice", 42);
		std::cout << alice << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
