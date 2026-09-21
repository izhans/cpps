#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name(""), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string name, int signGrade, int execGrade, const std::string target)
: _name(name),_signed(false), _signGrade(signGrade), _execGrade(execGrade), _target(target)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << ", form sign grade " << f.getSignGrade()
	<< ",form exec grade " << f.getExecGrade()
	<< ", is " << ((f.isSigned()) ? "signed" : "not signed");
	return out;
}
