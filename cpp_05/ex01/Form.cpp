#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name(""), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string name, int signGrade, int execGrade)
: _name(name),_signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << ", form sign grade " << f.getSignGrade()
	<< ",form exec grade " << f.getExecGrade()
	<< ", is " << ((f.isSigned()) ? "signed" : "not signed");
	return out;
}
