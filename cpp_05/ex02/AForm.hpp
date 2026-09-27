#ifndef AFORM_H
# define AFORM_H

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
		std::string _target;
	public:
		AForm();
		AForm(const std::string name, int signGrade, int execGrade, std::string target);
		virtual ~AForm() = 0;
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		std::string getTarget() const;

		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const &executor) const;
		virtual void performAction() const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
