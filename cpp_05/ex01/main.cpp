#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "===== BUREAUCRAT BASIC TEST =====" << std::endl;

	try
	{
		Bureaucrat alice("Alice", 42);

		std::cout << alice << std::endl;
		std::cout << "Name: " << alice.getName() << std::endl;
		std::cout << "Grade: " << alice.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== FORM BASIC TEST =====" << std::endl;

	try
	{
		Form form("ImportantForm", 50, 100);

		std::cout << form << std::endl;
		std::cout << "Name: " << form.getName() << std::endl;
		std::cout << "Signed: " << form.isSigned() << std::endl;
		std::cout << "Sign grade: " << form.getSignGrade() << std::endl;
		std::cout << "Exec grade: " << form.getExecGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== INVALID FORM GRADES =====" << std::endl;

	try
	{
		Form tooHigh("TooHighForm", 0, 50);
		std::cout << tooHigh << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << "Caught Form::GradeTooHighException: " << e.what() << std::endl;
	}

	try
	{
		Form tooLow("TooLowForm", 151, 50);
		std::cout << tooLow << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << "Caught Form::GradeTooLowException: " << e.what() << std::endl;
	}

	try
	{
		Form tooHighExec("TooHighExec", 50, 0);
		std::cout << tooHighExec << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << "Caught Form::GradeTooHighException: " << e.what() << std::endl;
	}

	try
	{
		Form tooLowExec("TooLowExec", 50, 151);
		std::cout << tooLowExec << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << "Caught Form::GradeTooLowException: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== SUCCESSFUL SIGNING =====" << std::endl;

	try
	{
		Bureaucrat alice("Alice", 25);
		Form form("Contract", 50, 100);

		std::cout << "Before: " << form << std::endl;

		alice.signForm(form);

		std::cout << "After:  " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== FAILED SIGNING =====" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 100);
		Form form("SecretForm", 50, 100);

		std::cout << "Before: " << form << std::endl;

		bob.signForm(form);

		std::cout << "After:  " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== SIGNING ALREADY SIGNED FORM =====" << std::endl;

	try
	{
		Bureaucrat alice("Alice", 25);
		Form form("AlreadySigned", 50, 100);

		alice.signForm(form);
		std::cout << "After first signing:  " << form << std::endl;

		alice.signForm(form);
		std::cout << "After second signing: " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== BOUNDARY SIGNING =====" << std::endl;

	try
	{
		Bureaucrat exactGrade("ExactGrade", 50);
		Form form("BoundaryForm", 50, 100);

		std::cout << "Before: " << form << std::endl;
		exactGrade.signForm(form);
		std::cout << "After:  " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
