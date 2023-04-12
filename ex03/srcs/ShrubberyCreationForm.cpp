/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 12:52:45 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#define FORM_NAME_ "ShrubberyCreationForm"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form(FORM_NAME_, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_("default") {
	std::cout << "[ShrubberyCreationForm] default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string Target ) : Form(FORM_NAME_, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_(Target) {
	std::cout << "[ShrubberyCreationForm] typed constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :	Form(other), Target_(other.getTarget()) {
	std::cout << "[ShrubberyCreationForm] copy constructor called." << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		Form::operator=(other);
		this->Target_ = other.getTarget();
	}
	std::cout << "[ShrubberyCreationForm] asignment called." << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "[ShrubberyCreationForm] destructor called." << std::endl;
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return this->Target_;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	if (this->checkRequirement(executor)) {
		std::string	filename = this->Target_ + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (!file.is_open()) {
			std::cerr << "Unable to open '" << filename << "'." << std::endl;
			return ;
		}
		for (int i = 0; i < 10; i++) {
			file << "     *\n    ***\n   *****\n  *******\n *********\n***********\n    |||\n" << std::endl;
		}
		file.close();
	}
}
