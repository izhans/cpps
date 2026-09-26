#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy Request Form", 72, 45, "fake_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("Robotomy Request Form", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	std::cout << "trrrr brrr * drilling noises *" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << getTarget() << std::endl;
}
