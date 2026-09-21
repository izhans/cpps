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
		~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &b);

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
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
