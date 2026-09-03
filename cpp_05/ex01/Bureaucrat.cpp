#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(42) {}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Bureaucrat::incrementGrade()
{
	if (_grade -1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade +1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::signForm(Form &f)
{
	if (f.isSigned())
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because it's alredy signed" << std::endl;
		return ;
	}
	try
	{
		f.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because their grade is too low" << std::endl;
		return ;
	}
	std::cout << _name << " signed " << f.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
