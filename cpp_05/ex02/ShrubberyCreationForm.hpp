#ifndef SHURBERRYCREATIONFORM_HPP
# define SHURBERRYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target; // ? aqui o protected en AForm ???
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name, std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};

#endif
